@echo off

call config.bat

cocos compile -p android -m release -o .\bin --ap android-28 --app-abi armeabi-v7a armeabi-v7a:x86

pause