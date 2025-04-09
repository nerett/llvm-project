let TargetPrefix = "qfield" in {  // All intrinsics start with "llvm.qfield.".

 def int_qfield_putpixel: ClangBuiltin<"sim_put_pixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 def int_qfield_flush: ClangBuiltin<"sim_flush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 } // TargetPrefix = "qfield"
