add_llvm_component_group(QField)

add_llvm_target(QFieldCodeGen
  QFieldTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  QFieldInfo

  ADD_TO_COMPONENT
  QField
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
