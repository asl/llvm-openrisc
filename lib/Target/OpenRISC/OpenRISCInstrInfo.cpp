//===-- OpenRISCInstrInfo.cpp - OpenRISC Instruction Information -----------===//
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

#include "OpenRISCInstrInfo.h"
#include "OpenRISC.h"
#include "OpenRISCMachineFunctionInfo.h"
#include "OpenRISCTargetMachine.h"
#include "llvm/Function.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_CTOR
#include "OpenRISCGenInstrInfo.inc"

using namespace llvm;

OpenRISCInstrInfo::OpenRISCInstrInfo(OpenRISCTargetMachine &tm)
  : OpenRISCGenInstrInfo(OpenRISC::ADJCALLSTACKDOWN, OpenRISC::ADJCALLSTACKUP),
    RI(tm, *this), TM(tm) {}
