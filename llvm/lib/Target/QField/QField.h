#ifndef LLVM_LIB_TARGET_QField_QField_H
#define LLVM_LIB_TARGET_QField_QField_H

#include "MCTargetDesc/QFieldMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define QFIELD_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define QFIELD_DUMP(Color) {}

#define QFIELD_DUMP_RED QFIELD_DUMP(llvm::raw_ostream::RED)
#define QFIELD_DUMP_GREEN QFIELD_DUMP(llvm::raw_ostream::GREEN)
#define QFIELD_DUMP_YELLOW QFIELD_DUMP(llvm::raw_ostream::YELLOW)
#define QFIELD_DUMP_CYAN QFIELD_DUMP(llvm::raw_ostream::CYAN)
#define QFIELD_DUMP_MAGENTA QFIELD_DUMP(llvm::raw_ostream::MAGENTA)
#define QFIELD_DUMP_WHITE QFIELD_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class QFieldTargetMachine;
class FunctionPass;
class QFieldSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerQFieldMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerQFieldMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createQFieldISelDag(QFieldTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_QField_QField_H