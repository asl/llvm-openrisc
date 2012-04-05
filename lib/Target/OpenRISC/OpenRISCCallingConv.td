//==- OpenRISCCallingConv.td - Calling Conv. for OpenRISC -*- tablegen -*---==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for OpenRISC architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// OpenRISC Return Value Calling Convention
//===----------------------------------------------------------------------===//
def RetCC_OpenRISC : CallingConv<[
  // i32 are returned in registers R11, R12
  CCIfType<[i32], CCAssignToReg<[R11, R12]>>
]>;

//===----------------------------------------------------------------------===//
// OpenRISC Argument Calling Conventions
//===----------------------------------------------------------------------===//
def CC_OpenRISC : CallingConv<[
  // Promote i8 arguments to i32.
  CCIfType<[i8], CCPromoteToType<i32>>,
  // Promote i8 arguments to i32.
  CCIfType<[i16], CCPromoteToType<i32>>,

  // The first 6 integer arguments of non-varargs functions are passed in
  // integer registers.
  CCIfNotVarArg<CCIfType<[i32], CCAssignToReg<[R3, R4, R5, R6, R7, R8]>>>,

  // Integer values get stored in stack slots that are 4 bytes in
  // size and 4-byte aligned.
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;
