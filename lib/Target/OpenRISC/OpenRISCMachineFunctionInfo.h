//===- OpenRISCMachineFuctionInfo.h - OpenRISC machine func info -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares OpenRISC-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISCMACHINEFUNCTIONINFO_H
#define OPENRISCMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

/// OpenRISCMachineFunctionInfo - This class is derived from MachineFunction and
/// contains private OpenRISC target-specific information for each MachineFunction.
class OpenRISCMachineFunctionInfo : public MachineFunctionInfo {
  virtual void anchor();
public:
  OpenRISCMachineFunctionInfo() {}

  explicit OpenRISCMachineFunctionInfo(MachineFunction &MF) {}
};

} // End llvm namespace

#endif
