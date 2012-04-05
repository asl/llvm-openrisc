//==-- OpenRISC.h - Top-level interface for representation -*- C++ -*----===-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM OpenRISC backend.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_OPENRISC_H
#define LLVM_TARGET_OPENRISC_H

#include "MCTargetDesc/OpenRISCMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class OpenRISCTargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createOpenRISCISelDag(OpenRISCTargetMachine &TM,
                                      CodeGenOpt::Level OptLevel);

} // end namespace llvm;

#endif
