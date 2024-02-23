
call "setup_msvc.bat"

cd .

if "%1"=="" (nmake  -f qube_servo2_quick_start_groupA.mk all) else (nmake  -f qube_servo2_quick_start_groupA.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1