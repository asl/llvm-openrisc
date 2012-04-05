//===-- OpenRISCTargetMachine.cpp - Define TargetMachine for OpenRISC -----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Top-level implementation for the OpenRISC target.
//
//===----------------------------------------------------------------------===//

#include "OpenRISCTargetMachine.h"
#include "OpenRISC.h"
#include "llvm/PassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeOpenRISCTarget() {
  // Register the target.
  RegisterTargetMachine<OpenRISCTargetMachine> X(TheOpenRISCTarget);
}

OpenRISCTargetMachine::OpenRISCTargetMachine(const Target &T,
                                         StringRef TT,
                                         StringRef CPU,
                                         StringRef FS,
                                         const TargetOptions &Options,
                                         Reloc::Model RM, CodeModel::Model CM,
                                         CodeGenOpt::Level OL)
  : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS),
    // FIXME: Check TargetData string.
    DataLayout("E-p:32:32:32-i8:8:8-i16:16:16-i32:32:32-n32"),
    InstrInfo(*this), TLInfo(*this), TSInfo(*this),
    FrameLowering(Subtarget) { }

namespace {
/// OpenRISC Code Generator Pass Configuration Options.
class OpenRISCPassConfig : public TargetPassConfig {
public:
  OpenRISCPassConfig(OpenRISCTargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  OpenRISCTargetMachine &getOpenRISCTargetMachine() const {
    return getTM<OpenRISCTargetMachine>();
  }

  virtual bool addInstSelector();
};
} // namespace

TargetPassConfig *OpenRISCTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new OpenRISCPassConfig(this, PM);
}

bool OpenRISCPassConfig::addInstSelector() {
  // Install an instruction selector.
  PM.add(createOpenRISCISelDag(getOpenRISCTargetMachine(), getOptLevel()));
  return false;
}
