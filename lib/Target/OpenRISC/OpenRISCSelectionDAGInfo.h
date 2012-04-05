//==-- OpenRISCSelectionDAGInfo.h - OpenRISC SelectionDAG Info ---*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the OpenRISC subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISCSELECTIONDAGINFO_H
#define OPENRISCSELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class OpenRISCTargetMachine;

class OpenRISCSelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit OpenRISCSelectionDAGInfo(const OpenRISCTargetMachine &TM);
  ~OpenRISCSelectionDAGInfo();
};

}

#endif // OPENRISCSELECTIONDAGINFO_H
