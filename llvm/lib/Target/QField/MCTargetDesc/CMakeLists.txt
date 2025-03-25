add_llvm_component_library(LLVMQFieldDesc
  QFieldMCTargetDesc.cpp
  QFieldMCAsmInfo.cpp
  QFieldInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  QFieldInfo

  ADD_TO_COMPONENT
  QField
 )
