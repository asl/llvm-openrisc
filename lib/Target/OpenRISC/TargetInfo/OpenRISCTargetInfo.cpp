//===-- OpenRISCTargetInfo.cpp - OpenRISC Target Implementation -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "OpenRISC.h"
#include "llvm/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheOpenRISCTarget;

extern "C" void LLVMInitializeOpenRISCTargetInfo() { 
  RegisterTarget<Triple::or32> 
    X(TheOpenRISCTarget, "openrisc", "OpenRISC [demonstration]");
}
