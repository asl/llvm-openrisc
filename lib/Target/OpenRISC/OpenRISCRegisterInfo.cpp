//===-- OpenRISCRegisterInfo.cpp - OpenRISC Register Information ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OpenRISC implementation of the TargetRegisterInfo
// class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "openrisc-reg-info"

#include "OpenRISCRegisterInfo.h"
#include "OpenRISC.h"
#include "OpenRISCMachineFunctionInfo.h"
#include "OpenRISCTargetMachine.h"
#include "llvm/Function.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_REGINFO_TARGET_DESC
#include "OpenRISCGenRegisterInfo.inc"

using namespace llvm;

OpenRISCRegisterInfo::OpenRISCRegisterInfo(OpenRISCTargetMachine &tm,
                                           const TargetInstrInfo &tii)
  : OpenRISCGenRegisterInfo(OpenRISC::PC), TM(tm), TII(tii) {
}

const uint16_t *
OpenRISCRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  const TargetFrameLowering *TFI = MF->getTarget().getFrameLowering();

  return (TFI->hasFP(*MF) ? CSR_FP_SaveList : CSR_SaveList);
}


BitVector
OpenRISCRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();

  Reserved.set(OpenRISC::SP);
  Reserved.set(OpenRISC::PC);
  Reserved.set(OpenRISC::ZERO);

  // Mark frame pointer as reserved if needed.
  if (TFI->hasFP(MF))
    Reserved.set(OpenRISC::FP);

  return Reserved;
}

const TargetRegisterClass*
OpenRISCRegisterInfo::getPointerRegClass(unsigned Kind) const {
  assert(0 && "Unimplemented");
}


void
OpenRISCRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                      int SPAdj, RegScavenger *RS) const {
  assert(0 && "Unimplemented");
}

unsigned
OpenRISCRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  const TargetFrameLowering *TFI = MF.getTarget().getFrameLowering();

  return TFI->hasFP(MF) ? OpenRISC::FP : OpenRISC::SP;
}
