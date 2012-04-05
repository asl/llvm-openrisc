//==- OpenRISCTargetMachine.h - Define TargetMachine for OpenRISC -*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the OpenRISC specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_TARGET_OPENRISC_TARGETMACHINE_H
#define LLVM_TARGET_OPENRISC_TARGETMACHINE_H

#include "OpenRISCInstrInfo.h"
#include "OpenRISCISelLowering.h"
#include "OpenRISCFrameLowering.h"
#include "OpenRISCSelectionDAGInfo.h"
#include "OpenRISCRegisterInfo.h"
#include "OpenRISCSubtarget.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

/// OpenRISCTargetMachine
///
class OpenRISCTargetMachine : public LLVMTargetMachine {
  OpenRISCSubtarget        Subtarget;
  const TargetData         DataLayout;       // Calculates type size & alignment
  OpenRISCInstrInfo        InstrInfo;
  OpenRISCTargetLowering   TLInfo;
  OpenRISCSelectionDAGInfo TSInfo;
  OpenRISCFrameLowering    FrameLowering;

public:
  OpenRISCTargetMachine(const Target &T, StringRef TT,
                        StringRef CPU, StringRef FS, const TargetOptions &Options,
                        Reloc::Model RM, CodeModel::Model CM,
                        CodeGenOpt::Level OL);

  virtual const TargetFrameLowering *getFrameLowering() const {
    return &FrameLowering;
  }
  virtual const OpenRISCInstrInfo *getInstrInfo() const  { return &InstrInfo; }
  virtual const TargetData *getTargetData() const     { return &DataLayout;}
  virtual const OpenRISCSubtarget *getSubtargetImpl() const { return &Subtarget; }

  virtual const TargetRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }

  virtual const OpenRISCTargetLowering *getTargetLowering() const {
    return &TLInfo;
  }

  virtual const OpenRISCSelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }

  virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);
}; // OpenRISCTargetMachine.

} // end namespace llvm

#endif // LLVM_TARGET_OPENRISC_TARGETMACHINE_H
