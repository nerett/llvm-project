#ifndef LLVM_LIB_TARGET_QField_QField_H
#define LLVM_LIB_TARGET_QField_QField_H

#include "llvm/Support/raw_ostream.h"

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

#endif // LLVM_LIB_TARGET_QField_QField_H