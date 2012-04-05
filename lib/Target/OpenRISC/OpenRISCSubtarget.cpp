//===-- OpenRISCSubtarget.cpp - OpenRISC Subtarget Information -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OpenRISC specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "OpenRISCSubtarget.h"
#include "OpenRISC.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "OpenRISCGenSubtargetInfo.inc"

using namespace llvm;

void OpenRISCSubtarget::anchor() { }

OpenRISCSubtarget::OpenRISCSubtarget(const std::string &TT,
                                     const std::string &CPU,
                                     const std::string &FS) :
  OpenRISCGenSubtargetInfo(TT, CPU, FS) {
  std::string CPUName = "generic";

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);
}
