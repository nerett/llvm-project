#include "QFieldTargetMachine.h"
#include "QField.h"
#include "TargetInfo/QFieldTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQFieldTarget() {
  // Register the target.
  QFIELD_DUMP_CYAN
  RegisterTargetMachine<QFieldTargetMachine> A(getTheQFieldTarget());
}

QFieldTargetMachine::QFieldTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  QFIELD_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// QField Code Generator Pass Configuration Options.
class QFieldPassConfig : public TargetPassConfig {
public:
  QFieldPassConfig(QFieldTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  QFieldTargetMachine &getQFieldTargetMachine() const {
    return getTM<QFieldTargetMachine>();
  }

  bool addInstSelector() override {
    QFIELD_DUMP_CYAN
    addPass(createQFieldISelDag(getQFieldTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *QFieldTargetMachine::createPassConfig(PassManagerBase &PM) {
  QFIELD_DUMP_CYAN
  return new QFieldPassConfig(*this, PM);
}

TargetLoweringObjectFile *QFieldTargetMachine::getObjFileLowering() const {
  QFIELD_DUMP_CYAN
  return TLOF.get();
}
