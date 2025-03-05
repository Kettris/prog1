@echo off
chcp 1251 > log
del log

set MAIN="main.cpp menu_functions.cpp menu_items.cpp"
set EXE=writers_lessons.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%MAIN%" -o %EXE%

%EXE%