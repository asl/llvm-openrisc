; RUN: llc -march=mips64el -mcpu=mips64r1 < %s | FileCheck %s

define i64 @f0(i64 %a0, i64 %a1) nounwind readnone {
entry:
; CHECK: daddu
  %add = add nsw i64 %a1, %a0
  ret i64 %add
}

define i64 @f1(i64 %a0, i64 %a1) nounwind readnone {
entry:
; CHECK: dsubu
  %sub = sub nsw i64 %a0, %a1
  ret i64 %sub
}

define i64 @f4(i64 %a0, i64 %a1) nounwind readnone {
entry:
; CHECK: and
  %and = and i64 %a1, %a0
  ret i64 %and
}

define i64 @f5(i64 %a0, i64 %a1) nounwind readnone {
entry:
; CHECK: or
  %or = or i64 %a1, %a0
  ret i64 %or
}

define i64 @f6(i64 %a0, i64 %a1) nounwind readnone {
entry:
; CHECK: xor
  %xor = xor i64 %a1, %a0
  ret i64 %xor
}

define i64 @f7(i64 %a0) nounwind readnone {
entry:
; CHECK: daddiu
  %add = add nsw i64 %a0, 20
  ret i64 %add
}

define i64 @f8(i64 %a0) nounwind readnone {
entry:
; CHECK: daddiu
  %sub = add nsw i64 %a0, -20
  ret i64 %sub
}

define i64 @f9(i64 %a0) nounwind readnone {
entry:
; CHECK: andi
  %and = and i64 %a0, 20
  ret i64 %and
}

define i64 @f10(i64 %a0) nounwind readnone {
entry:
; CHECK: ori
  %or = or i64 %a0, 20
  ret i64 %or
}

define i64 @f11(i64 %a0) nounwind readnone {
entry:
; CHECK: xori
  %xor = xor i64 %a0, 20
  ret i64 %xor
}
