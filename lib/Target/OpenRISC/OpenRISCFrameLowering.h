//- OpenRISCFrameLowering.h - Define frame lowering for OpenRISC --*- C++ -*--//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISC_FRAMEINFO_H
#define OPENRISC_FRAMEINFO_H

#include "OpenRISC.h"
#include "OpenRISCSubtarget.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
  class OpenRISCSubtarget;

class OpenRISCFrameLowering : public TargetFrameLowering {
protected:
  const OpenRISCSubtarget &STI;

public:
  explicit OpenRISCFrameLowering(const OpenRISCSubtarget &sti)
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 8, 0), STI(sti) {
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF) const;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const;

  bool hasFP(const MachineFunction &MF) const;
};

} // End llvm namespace

#endif
