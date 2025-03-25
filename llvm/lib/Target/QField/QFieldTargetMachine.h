#ifndef LLVM_LIB_TARGET_QFIELD_QFIELDTARGETMACHINE_H
#define LLVM_LIB_TARGET_QFIELD_QFIELDTARGETMACHINE_H

#include "QFieldSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheQFieldTarget;

class QFieldTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  QFieldSubtarget Subtarget;

public:
  QFieldTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const QFieldSubtarget *getSubtargetImpl(const Function &) const override {
    QFIELD_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_QFIELD_QFIELDTARGETMACHINE_H
