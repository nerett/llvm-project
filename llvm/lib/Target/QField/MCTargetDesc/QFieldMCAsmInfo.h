#ifndef LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCASMINFO_H
#define LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class QFieldELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit QFieldELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QFIELD_MCTARGETDESC_QFIELDMCASMINFO_H