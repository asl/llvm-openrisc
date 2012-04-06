//==-- OpenRISCInstrInfo.h - OpenRISC Instruction Information ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OpenRISC implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_OPENRISCINSTRINFO_H
#define LLVM_TARGET_OPENRISCINSTRINFO_H

#include "OpenRISCRegisterInfo.h"
#include "llvm/Target/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "OpenRISCGenInstrInfo.inc"

namespace llvm {

class OpenRISCTargetMachine;

class OpenRISCInstrInfo : public OpenRISCGenInstrInfo {
  const OpenRISCRegisterInfo RI;
  OpenRISCTargetMachine &TM;
public:
  explicit OpenRISCInstrInfo(OpenRISCTargetMachine &TM);

  /// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
  /// such, whenever a client has an instance of instruction info, it should
  /// always be able to get register info as well (through this method).
  ///
  virtual const TargetRegisterInfo &getRegisterInfo() const { return RI; }

  void copyPhysReg(MachineBasicBlock &MBB,
                   MachineBasicBlock::iterator I, DebugLoc DL,
                   unsigned DestReg, unsigned SrcReg,
                   bool KillSrc) const;
};

}

#endif
