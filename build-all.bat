@echo off

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
