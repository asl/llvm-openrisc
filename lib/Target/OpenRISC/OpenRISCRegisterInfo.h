//=- OpenRISCRegisterInfo.h - OpenRISC Register Information Impl -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OpenRISC implementation of the MRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_OPENRISCREGISTERINFO_H
#define LLVM_TARGET_OPENRISCREGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "OpenRISCGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class OpenRISCTargetMachine;

struct OpenRISCRegisterInfo : public OpenRISCGenRegisterInfo {
private:
  OpenRISCTargetMachine &TM;
  const TargetInstrInfo &TII;
public:
  OpenRISCRegisterInfo(OpenRISCTargetMachine &tm, const TargetInstrInfo &tii);

  const uint16_t *getCalleeSavedRegs(const MachineFunction *MF = 0) const;

  BitVector getReservedRegs(const MachineFunction &MF) const;
  const TargetRegisterClass* getPointerRegClass(unsigned Kind = 0) const;

  void eliminateFrameIndex(MachineBasicBlock::iterator II,
                           int SPAdj, RegScavenger *RS = NULL) const;
  unsigned getFrameRegister(const MachineFunction &MF) const;
};

} // end namespace llvm

#endif // LLVM_TARGET_OPENRISCREGISTERINFO_H
