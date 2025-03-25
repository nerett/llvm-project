add_llvm_component_group(QField)

set(LLVM_TARGET_DEFINITIONS QField.td)

tablegen(LLVM QFieldGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM QFieldGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM QFieldGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM QFieldGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM QFieldGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM QFieldGenCallingConv.inc -gen-callingconv)
tablegen(LLVM QFieldGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(QFieldCommonTableGen)

add_llvm_target(QFieldCodeGen
  QFieldTargetMachine.cpp
  QFieldRegisterInfo.cpp
  QFieldInstrInfo.cpp
  QFieldSubtarget.cpp
  QFieldAsmPrinter.cpp
  QFieldISelDagToDag.cpp
  QFieldISelLowering.cpp
  QFieldMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  QFieldInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  QField
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
