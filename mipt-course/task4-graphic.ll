define dso_local void @app() {
entry:
    call void @llvm.qfield.putpixel(i32 42, i32 42, i32 -1)
    call void @llvm.qfield.flush()
    ret void
}

declare void @llvm.qfield.putpixel(i32, i32, i32)

declare void @llvm.qfield.flush()
