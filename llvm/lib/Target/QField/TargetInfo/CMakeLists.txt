add_llvm_component_library(LLVMQFieldInfo
  QFieldTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  QField
  )
