@echo off
chcp 65001
cd build_ninja
ctest -j --output-on-failure
pause