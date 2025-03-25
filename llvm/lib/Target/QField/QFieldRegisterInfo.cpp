#include "QFieldRegisterInfo.h"
#include "QField.h"
#include "QFieldFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "QFieldGenRegisterInfo.inc"

QFieldRegisterInfo::QFieldRegisterInfo() : QFieldGenRegisterInfo(QField::R0) {
  QFIELD_DUMP_GREEN
}
const MCPhysReg *
QFieldRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  QFIELD_DUMP_GREEN
  return CSR_QField_SaveList;
}

BitVector QFieldRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  QFIELD_DUMP_GREEN
  QFieldFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(QField::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(QField::R2);
  }
  return Reserved;
}

bool QFieldRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool QFieldRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  QFIELD_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register QFieldRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  QFIELD_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? QField::R2 : QField::R1;
}

const uint32_t *
QFieldRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  QFIELD_DUMP_GREEN
  return CSR_QField_RegMask;
}
