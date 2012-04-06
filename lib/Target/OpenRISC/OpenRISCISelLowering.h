//===-- OpenRISCISelLowering.h - OpenRISC DAG Lowering Interface --*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that OpenRISC uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_OpenRISC_ISELLOWERING_H
#define LLVM_TARGET_OpenRISC_ISELLOWERING_H

#include "OpenRISC.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/Target/TargetLowering.h"

namespace llvm {
  namespace OpenRISCISD {
    enum {
      FIRST_NUMBER = ISD::BUILTIN_OP_END,

      /// Return with a flag operand. Operand 0 is the chain operand.
      RET_FLAG,

      /// CALL - These operations represent an abstract call instruction, which
      /// includes a bunch of information.
      CALL
    };
  }

  class OpenRISCSubtarget;
  class OpenRISCTargetMachine;

  class OpenRISCTargetLowering : public TargetLowering {
  public:
    explicit OpenRISCTargetLowering(OpenRISCTargetMachine &TM);

    /// LowerOperation - Provide custom lowering hooks for some operations.
    virtual SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const;

    /// getTargetNodeName - This method returns the name of a target specific
    /// DAG node.
    virtual const char *getTargetNodeName(unsigned Opcode) const;

  private:
    const OpenRISCSubtarget &Subtarget;
    const OpenRISCTargetMachine &TM;
    const TargetData *TD;

    SDValue LowerCCCCallTo(SDValue Chain, SDValue Callee,
                           CallingConv::ID CallConv, bool isVarArg,
                           bool isTailCall,
                           const SmallVectorImpl<ISD::OutputArg> &Outs,
                           const SmallVectorImpl<SDValue> &OutVals,
                           const SmallVectorImpl<ISD::InputArg> &Ins,
                           DebugLoc dl, SelectionDAG &DAG,
                           SmallVectorImpl<SDValue> &InVals) const;

    SDValue LowerCCCArguments(SDValue Chain,
                              CallingConv::ID CallConv,
                              bool isVarArg,
                              const SmallVectorImpl<ISD::InputArg> &Ins,
                              DebugLoc dl,
                              SelectionDAG &DAG,
                              SmallVectorImpl<SDValue> &InVals) const;

    SDValue LowerCallResult(SDValue Chain, SDValue InFlag,
                            CallingConv::ID CallConv, bool isVarArg,
                            const SmallVectorImpl<ISD::InputArg> &Ins,
                            DebugLoc dl, SelectionDAG &DAG,
                            SmallVectorImpl<SDValue> &InVals) const;

    SDValue LowerCall(SDValue Chain, SDValue Callee, CallingConv::ID CallConv,
                      bool isVarArg, bool doesNotRet, bool &isTailCall,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals,
                      const SmallVectorImpl<ISD::InputArg> &Ins,
                      DebugLoc dl, SelectionDAG &DAG,
                      SmallVectorImpl<SDValue> &InVals) const;

    SDValue LowerFormalArguments(SDValue Chain,
                                 CallingConv::ID CallConv, bool isVarArg,
                                 const SmallVectorImpl<ISD::InputArg> &Ins,
                                 DebugLoc dl, SelectionDAG &DAG,
                                 SmallVectorImpl<SDValue> &InVals) const;

    SDValue LowerReturn(SDValue Chain,
                        CallingConv::ID CallConv, bool isVarArg,
                        const SmallVectorImpl<ISD::OutputArg> &Outs,
                        const SmallVectorImpl<SDValue> &OutVals,
                        DebugLoc dl, SelectionDAG &DAG) const;
  };
} // namespace llvm

#endif // LLVM_TARGET_OPENRISC_ISELLOWERING_H
