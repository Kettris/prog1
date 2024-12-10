@echo off
chcp 1251 > log
del log

set MAIN=task5.cpp
set EXE=task5.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" %MAIN% -o %EXE%

%EXE%