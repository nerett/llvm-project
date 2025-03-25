#include "MCTargetDesc/QFieldInfo.h"
#include "QField.h"
#include "QFieldInstPrinter.h"
#include "QFieldMCAsmInfo.h"
#include "TargetInfo/QFieldTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "QFieldGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "QFieldGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "QFieldGenSubtargetInfo.inc"

static MCRegisterInfo *createQFieldMCRegisterInfo(const Triple &TT) {
  QFIELD_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitQFieldMCRegisterInfo(X, QField::R0);
  return X;
}

static MCInstrInfo *createQFieldMCInstrInfo() {
  QFIELD_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitQFieldMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createQFieldMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  QFIELD_DUMP_MAGENTA
  return createQFieldMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createQFieldMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  QFIELD_DUMP_MAGENTA
  MCAsmInfo *MAI = new QFieldELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(QField::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createQFieldMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  QFIELD_DUMP_MAGENTA
  return new QFieldInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQFieldTargetMC() {
  QFIELD_DUMP_MAGENTA
  Target &TheQFieldTarget = getTheQFieldTarget();
  RegisterMCAsmInfoFn X(TheQFieldTarget, createQFieldMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheQFieldTarget, createQFieldMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheQFieldTarget, createQFieldMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheQFieldTarget,
                                          createQFieldMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheQFieldTarget, createQFieldMCInstPrinter);
}
