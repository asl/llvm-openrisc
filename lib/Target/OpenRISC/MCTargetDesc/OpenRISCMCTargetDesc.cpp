//===-- OpenRISCMCTargetDesc.cpp - OpenRISC Target Descriptions ------------===//
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

#include "OpenRISCMCTargetDesc.h"
#include "OpenRISCMCAsmInfo.h"
#include "InstPrinter/OpenRISCInstPrinter.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "OpenRISCGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "OpenRISCGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "OpenRISCGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createOpenRISCMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitOpenRISCMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createOpenRISCMCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitOpenRISCMCRegisterInfo(X, OpenRISC::PC);
  return X;
}

static MCSubtargetInfo *createOpenRISCMCSubtargetInfo(StringRef TT, StringRef CPU,
                                                      StringRef FS) {
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitOpenRISCMCSubtargetInfo(X, TT, CPU, FS);
  return X;
}

static MCCodeGenInfo *createOpenRISCMCCodeGenInfo(StringRef TT, Reloc::Model RM,
                                                  CodeModel::Model CM,
                                                  CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  X->InitMCCodeGenInfo(RM, CM, OL);
  return X;
}

static MCInstPrinter *createOpenRISCMCInstPrinter(const Target &T,
                                                  unsigned SyntaxVariant,
                                                  const MCAsmInfo &MAI,
                                                  const MCInstrInfo &MII,
                                                  const MCRegisterInfo &MRI,
                                                  const MCSubtargetInfo &STI) {
  if (SyntaxVariant == 0)
    return new OpenRISCInstPrinter(MAI, MII, MRI);
  return 0;
}

extern "C" void LLVMInitializeOpenRISCTargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfo<OpenRISCMCAsmInfo> X(TheOpenRISCTarget);

  // Register the MC codegen info.
  TargetRegistry::RegisterMCCodeGenInfo(TheOpenRISCTarget,
                                        createOpenRISCMCCodeGenInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheOpenRISCTarget, createOpenRISCMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheOpenRISCTarget,
                                    createOpenRISCMCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheOpenRISCTarget,
                                          createOpenRISCMCSubtargetInfo);

  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(TheOpenRISCTarget,
                                        createOpenRISCMCInstPrinter);
}
