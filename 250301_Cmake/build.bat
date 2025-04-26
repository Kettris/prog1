@echo off
setlocal EnableDelayedExpansion
set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja
chcp 65001
set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%
cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

mkdir multi_level_menu
mkdir Quick_Sort
mkdir vector_list

copy ..\%SOURCE_FOLDER%\multi_level_menu\build_run.bat .\multi_level_menu
copy ..\%SOURCE_FOLDER%\Quick_Sort\run_Quick_Sort.bat .\Quick_Sort
copy ..\%SOURCE_FOLDER%\long_number\run_long_number.bat .\long_number
copy ..\%SOURCE_FOLDER%\vector_list\run_vector_list.bat .\vector_list

copy ..\run_test.bat .

pause
