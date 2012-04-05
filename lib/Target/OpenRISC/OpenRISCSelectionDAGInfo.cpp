//===-- OpenRISCSelectionDAGInfo.cpp - OpenRISC SelectionDAG Info ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the OpenRISCSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "openrisc-selectiondag-info"
#include "OpenRISCTargetMachine.h"
using namespace llvm;

OpenRISCSelectionDAGInfo::OpenRISCSelectionDAGInfo(const OpenRISCTargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

OpenRISCSelectionDAGInfo::~OpenRISCSelectionDAGInfo() {
}
