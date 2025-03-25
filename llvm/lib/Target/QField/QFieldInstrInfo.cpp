#include "QFieldInstrInfo.h"
#include "QField.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "QFieldGenInstrInfo.inc"

#define DEBUG_TYPE "QField-inst-info"

QFieldInstrInfo::QFieldInstrInfo() : QFieldGenInstrInfo() { QFIELD_DUMP_GREEN }
