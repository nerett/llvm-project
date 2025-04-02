#ifndef LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H
#define LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createQFieldMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createQFieldAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createQFieldELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for QField registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "QFieldGenRegisterInfo.inc"

// Defines symbolic names for the QField instructions.
#define GET_INSTRINFO_ENUM
#include "QFieldGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H
