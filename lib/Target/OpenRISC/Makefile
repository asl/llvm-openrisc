##===- lib/Target/OpenRISC/Makefile ------------------------*- Makefile -*-===##
# 
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source 
# License. See LICENSE.TXT for details.
# 
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMOpenRISCCodeGen
TARGET = OpenRISC

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = OpenRISCGenRegisterInfo.inc OpenRISCGenInstrInfo.inc \
		OpenRISCGenAsmWriter.inc \
		OpenRISCGenDAGISel.inc OpenRISCGenCallingConv.inc \
		OpenRISCGenSubtargetInfo.inc

DIRS = InstPrinter TargetInfo MCTargetDesc

include $(LEVEL)/Makefile.common

