@echo off
setlocal EnableDelayedExpansion

set c_filenames=
for /R %%f in (*.c) do (
    set c_filenames=!c_filenames! %%f
)

set assembly=testbed
set compiler_flags=-g
set include_flags=-Isrc -I../engine/src/
set linker_flags=-L../bin/ -lengine.lib
set defines=-D_DEBUG -D_IMPORT

echo "Building %assembly%..."
clang %c_filenames% %compiler_flags% -o ../bin/%assembly%.exe %defines% %include_flags% %linker_flags%
