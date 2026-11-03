@echo off
if "%~1"=="" (
    echo Cach dung: hw ten-bai
    exit /b 1
)
cd /d "%~dp0"
copy /y "WORKING\test.py" "HOMEWORK\%~1.py"
git add HOMEWORK
git commit -m "Them bai"
git push