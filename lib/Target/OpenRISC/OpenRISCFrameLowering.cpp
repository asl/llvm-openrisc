//===-- OpenRISCFrameLowering.cpp - OpenRISC Frame Information ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the OpenRISC implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "OpenRISCFrameLowering.h"
#include "OpenRISCInstrInfo.h"
#include "OpenRISCMachineFunctionInfo.h"
#include "llvm/Function.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

bool OpenRISCFrameLowering::hasFP(const MachineFunction &MF) const {
  assert(0 && "Unimplemented");
}

void OpenRISCFrameLowering::emitPrologue(MachineFunction &MF) const {
  assert(0 && "Unimplemented");
}

void OpenRISCFrameLowering::emitEpilogue(MachineFunction &MF,
                                         MachineBasicBlock &MBB) const {
  assert(0 && "Unimplemented");
}
