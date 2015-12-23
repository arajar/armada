@echo off 
SET MAKETOOL=..\tools\premake\release\premake5.exe

%MAKETOOL% --arch=x86 --to=vs2015\x86 vs2015
%MAKETOOL% --arch=x64 --to=vs2015\x64 vs2015