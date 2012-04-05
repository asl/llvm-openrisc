//===-- OpenRISCRegisterInfo.td - OpenRISC Register defs --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the OpenRISC register file
//===----------------------------------------------------------------------===//

class OpenRISCReg<bits<4> num, string n> : Register<n> {
  field bits<4> Num = num;
  let Namespace = "OpenRISC";
}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

def ZERO : OpenRISCReg<0, "r0">;
def SP  : OpenRISCReg<0, "r1">;
def FP  : OpenRISCReg<0, "r2">;
def R3  : OpenRISCReg<0, "r3">;
def R4  : OpenRISCReg<0, "r4">;
def R5  : OpenRISCReg<0, "r5">;
def R6  : OpenRISCReg<0, "r6">;
def R7  : OpenRISCReg<0, "r7">;
def R8  : OpenRISCReg<0, "r8">;
def LR  : OpenRISCReg<0, "r9">;
def R10 : OpenRISCReg<0, "r10">;
def R11 : OpenRISCReg<0, "r11">;
def R12 : OpenRISCReg<0, "r12">;
def R13 : OpenRISCReg<0, "r13">;
def R14 : OpenRISCReg<0, "r14">;
def R15 : OpenRISCReg<0, "r15">;
def R16 : OpenRISCReg<0, "r16">;
def R17 : OpenRISCReg<0, "r17">;
def R18 : OpenRISCReg<0, "r18">;
def R19 : OpenRISCReg<0, "r19">;
def R20 : OpenRISCReg<0, "r20">;
def R21 : OpenRISCReg<0, "r21">;
def R22 : OpenRISCReg<0, "r22">;
def R23 : OpenRISCReg<0, "r23">;
def R24 : OpenRISCReg<0, "r24">;
def R25 : OpenRISCReg<0, "r25">;
def R26 : OpenRISCReg<0, "r26">;
def R27 : OpenRISCReg<0, "r27">;
def R28 : OpenRISCReg<0, "r28">;
def R29 : OpenRISCReg<0, "r29">;
def R30 : OpenRISCReg<0, "r30">;
def R31 : OpenRISCReg<0, "r31">;

def PC  : OpenRISCReg<0, "pc">;

//===----------------------------------------------------------------------===//
//  Register Classes
//===----------------------------------------------------------------------===//

def GR32 : RegisterClass<"OpenRISC", [i32], 32,
    (add (sequence "R%u", 3, 8), (sequence "R%u", 10, 31), LR, SP, FP, ZERO)>;
