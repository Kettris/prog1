@echo off
chcp 1251 > log
del log

set MAIN="quick_sort.cpp main.cpp"
set EXE=Quick_Sort.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" %MAIN% -o %EXE%

%EXE%