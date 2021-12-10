@echo off
ArraySeven.exe < test%1.txt > out.txt
fc out.txt out%1.txt
pause