//===-- OpenRISCMCAsmInfo.h - OpenRISC asm properties ----------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the OpenRISCMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISCTARGETASMINFO_H
#define OPENRISCTARGETASMINFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class StringRef;
  class Target;

  class OpenRISCMCAsmInfo : public MCAsmInfo {
    virtual void anchor();
  public:
    explicit OpenRISCMCAsmInfo(const Target &T, StringRef TT);
  };

} // namespace llvm

#endif
