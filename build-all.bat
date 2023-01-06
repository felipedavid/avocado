@echo off

if not exist bin/ (
    echo "Creating bin directory..."
    mkdir bin
)

echo "Building everything..."

pushd engine
call build.bat
popd
if %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL%)

pushd testbed
call build.bat
popd
if %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL%)

echo "All assemblies built successfully."
