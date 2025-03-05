#include "TargetInfo/QFieldTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheQFieldTarget() {
  static Target TheQFieldTarget;
  return TheQFieldTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQFieldTargetInfo() {
  RegisterTarget<Triple::QField> X(getTheQFieldTarget(), "QField", "QField 32",
                                   "QField");
}
