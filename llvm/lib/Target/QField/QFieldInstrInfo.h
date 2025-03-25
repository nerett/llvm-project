#ifndef LLVM_LIB_TARGET_QFIELD_QFIELDINSTRINFO_H
#define LLVM_LIB_TARGET_QFIELD_QFIELDINSTRINFO_H

#include "QFieldRegisterInfo.h"
#include "MCTargetDesc/QFieldInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "QFieldGenInstrInfo.inc"

namespace llvm {

class QFieldSubtarget;

class QFieldInstrInfo : public QFieldGenInstrInfo {
public:
  QFieldInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QFIELD_QFIELDINSTRINFO_H
