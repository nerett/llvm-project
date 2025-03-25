#ifndef LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDINFO_H
#define LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace QFieldOp {
enum OperandType : unsigned {
  OPERAND_QFIELDM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace QFieldOp

} // end namespace llvm

#endif
