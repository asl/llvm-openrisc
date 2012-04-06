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
def LO16 : SDNodeXForm<imm, [{
  // Transformation function: return low 16 bits.
  return getI16Imm(N->getZExtValue() & 0xFFFFULL);
}]>;

def HI16 : SDNodeXForm<imm, [{
  // Transformation function: return bits 16-31.
  return getI16Imm(N->getZExtValue() >> 16);
}]>;

def i32lo16 : PatLeaf<(i32 imm), [{  
  // i32lo16 predicate - true if the 32-bit immediate has only rightmost 16
  // bits set.
  return ((N->getZExtValue() & 0FFFFULL) == N->getZExtValue());
}], LO16>;

def i32hi16 : PatLeaf<(i32 imm), [{  
  // i32lo16 predicate - true if the 32-bit immediate has only leftmost 16
  // bits set.
  return ((N->getZExtValue() & 0xFFFF0000ULL) == N->getZExtValue());
}], HI16>;

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

let isReMaterializable = 1, isAsCheapAsAMove = 1 in {
def MOV32ri16hi : OpenRISCInst<(outs GR32:$rD), (ins i32imm:$K),
                               "l.movhi\t{$rD, $K}",
                               [(set GR32:$rD, i32hi16:$K)]>;
}

let isCommutable = 1 in {
def OR32rr : OpenRISCInst<(outs GR32:$rD), (ins GR32:$rA, GR32:$rB),
                          "l.or\t{$rD, $rA, $rB}",
                          [(set GR32:$rD, (or GR32:$rA, GR32:$rB))]>;
}

//===----------------------------------------------------------------------===//
// Non-Instruction Patterns
