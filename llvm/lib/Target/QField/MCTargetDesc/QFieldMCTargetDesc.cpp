#include "../QField.h"
#include "llvm/Support/raw_ostream.h"

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQFieldTargetMC() { QFIELD_DUMP_MAGENTA }
