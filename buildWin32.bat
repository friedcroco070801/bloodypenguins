@echo off

call config.bat

cocos compile -p win32 -m release -o .\bin --vs 2017

pause