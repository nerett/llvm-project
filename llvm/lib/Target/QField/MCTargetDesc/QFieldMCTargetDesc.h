#ifndef LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H
#define LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H

// Defines symbolic names for QField registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "QFieldGenRegisterInfo.inc"

// Defines symbolic names for the QField instructions.
#define GET_INSTRINFO_ENUM
#include "QFieldGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCTARGETDESC_H
