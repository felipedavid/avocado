@echo off
setlocal EnableDelayedExpansion

set c_filenames=
for /R %%f in (*.c) do (
    set c_filenames=!c_filenames! %%f
)

set assembly=engine
set compiler_flags=-g -shared -Wvarargs -Wall -Werror
set include_flags=-Isrc -I%VULKAN_SDK%/Include
set linker_flags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
set defines=-D_DEBUG -DAV_EXPORT -D_CRT_SECURE_NO_WARNINGS

echo "Building %assembly%..."
clang %c_filenames% %compiler_flags% -o ../bin/%assembly%.dll %defines% %include_flags% %linker_flags%
