//===-- OpenRISCInstrInfo.td - OpenRISC Instruction defs ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the OpenRISC instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "OpenRISCInstrFormats.td"

//===----------------------------------------------------------------------===//
// Type Constraints.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Type Profiles.
//===----------------------------------------------------------------------===//
def SDT_ORCallSeqStart : SDCallSeqStart<[SDTCisVT<0, i32>]>;
def SDT_ORCallSeqEnd   : SDCallSeqEnd<[SDTCisVT<0, i32>, SDTCisVT<1, i32>]>;

//===----------------------------------------------------------------------===//
// OpenRISC Specific Node Definitions.
//===----------------------------------------------------------------------===//
//===----------------------------------------------------------------------===//
def retflag       : SDNode<"OpenRISCISD::RET_FLAG", SDTNone,
                           [SDNPHasChain, SDNPOptInGlue]>;
def callseq_start :  SDNode<"ISD::CALLSEQ_START", SDT_ORCallSeqStart,
                            [SDNPHasChain, SDNPOutGlue]>;
def callseq_end   :  SDNode<"ISD::CALLSEQ_END",   SDT_ORCallSeqEnd,
                            [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue]>;

//===----------------------------------------------------------------------===//
// OpenRISC Operand Definitions.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// OpenRISC Complex Pattern Definitions.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Pattern Fragments
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction list..
//===----------------------------------------------------------------------===//

let neverHasSideEffects = 1 in
def NOP : OpenRISCInst<(outs), (ins), "l.nop", []>;

let isReturn = 1, isTerminator = 1, isBarrier = 1 in {
  def RET  : OpenRISCInst<(outs), (ins),
                          "l.jr r9 # FIXME: delay slot",
                          [(retflag)]>;
}


// ADJCALLSTACKDOWN/UP implicitly use/def SP because they may be expanded into
// a stack adjustment and the codegen must know that they may modify the stack
// pointer before prolog-epilog rewriting occurs.
// Pessimistically assume ADJCALLSTACKDOWN / ADJCALLSTACKUP will become
// sub / add which can clobber SP.
let Defs = [SP], Uses = [SP] in {
def ADJCALLSTACKDOWN : OpenRISCInst<(outs), (ins i32imm:$amt),
                                    "#ADJCALLSTACKDOWN",
                                    [(callseq_start timm:$amt)]>;
def ADJCALLSTACKUP   : OpenRISCInst<(outs), (ins i32imm:$amt1, i32imm:$amt2),
                                    "#ADJCALLSTACKUP",
                                    [(callseq_end timm:$amt1, timm:$amt2)]>;
}

//===----------------------------------------------------------------------===//
// Non-Instruction Patterns
