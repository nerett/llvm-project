#include "TargetInfo/QFieldTargetInfo.h"
#include "QField.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheQFieldTarget() {
  QFIELD_DUMP_YELLOW
  static Target TheQFieldTarget;
  return TheQFieldTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQFieldTargetInfo() {
  QFIELD_DUMP_YELLOW
  RegisterTarget<Triple::qfield> X(getTheQFieldTarget(), "qfield",
                                "QField (quadratic field) target for MIPT LLVM course", "QFIELD");
}
