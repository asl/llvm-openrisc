//===-- OpenRISCAsmPrinter.cpp - OpenRISC LLVM assembly writer -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to the OpenRISC assembly language.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "asm-printer"
#include "OpenRISC.h"
#include "OpenRISCInstrInfo.h"
#include "OpenRISCMCInstLower.h"
#include "OpenRISCTargetMachine.h"
#include "InstPrinter/OpenRISCInstPrinter.h"
#include "llvm/Constants.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Module.h"
#include "llvm/Assembly/Writer.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Target/Mangler.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

namespace {
  class OpenRISCAsmPrinter : public AsmPrinter {
  public:
    OpenRISCAsmPrinter(TargetMachine &TM, MCStreamer &Streamer)
      : AsmPrinter(TM, Streamer) {}

    virtual const char *getPassName() const {
      return "OpenRISC Assembly Printer";
    }

    void EmitInstruction(const MachineInstr *MI);
  };
} // end of anonymous namespace


//===----------------------------------------------------------------------===//
void OpenRISCAsmPrinter::EmitInstruction(const MachineInstr *MI) {
  OpenRISCMCInstLower MCInstLowering(OutContext, *Mang, *this);

  MCInst TmpInst;
  MCInstLowering.Lower(MI, TmpInst);
  OutStreamer.EmitInstruction(TmpInst);
}

// Force static initialization.
extern "C" void LLVMInitializeOpenRISCAsmPrinter() {
  RegisterAsmPrinter<OpenRISCAsmPrinter> X(TheOpenRISCTarget);
}
