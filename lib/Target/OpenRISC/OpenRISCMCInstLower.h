//===-- OpenRISCMCInstLower.h - Lower MachineInstr to MCInst ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISC_MCINSTLOWER_H
#define OPENRISC_MCINSTLOWER_H

#include "llvm/Support/Compiler.h"

namespace llvm {
  class AsmPrinter;
  class MCContext;
  class MCInst;
  class MCOperand;
  class MCSymbol;
  class MachineInstr;
  class MachineModuleInfoMachO;
  class MachineOperand;
  class Mangler;

  /// OpenRISCMCInstLower - This class is used to lower an MachineInstr
  /// into an MCInst.
class LLVM_LIBRARY_VISIBILITY OpenRISCMCInstLower {
  MCContext &Ctx;
  Mangler &Mang;

  AsmPrinter &Printer;
public:
  OpenRISCMCInstLower(MCContext &ctx, Mangler &mang, AsmPrinter &printer)
    : Ctx(ctx), Mang(mang), Printer(printer) {}
  void Lower(const MachineInstr *MI, MCInst &OutMI) const;
};

}

#endif
