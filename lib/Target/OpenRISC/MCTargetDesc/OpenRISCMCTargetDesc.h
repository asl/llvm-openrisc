//===-- OpenRISCMCTargetDesc.h - OpenRISC Target Descriptions ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides OpenRISC specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef OpenRISCMCTARGETDESC_H
#define OpenRISCMCTARGETDESC_H

namespace llvm {
class Target;

extern Target TheOpenRISCTarget;

} // End llvm namespace

// Defines symbolic names for OpenRISC registers.
// This defines a mapping from register name to register number.
#define GET_REGINFO_ENUM
#include "OpenRISCGenRegisterInfo.inc"

// Defines symbolic names for the OpenRISC instructions.
#define GET_INSTRINFO_ENUM
#include "OpenRISCGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "OpenRISCGenSubtargetInfo.inc"

#endif
