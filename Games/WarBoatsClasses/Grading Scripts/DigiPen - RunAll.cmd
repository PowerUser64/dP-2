@echo off
call setvc12-32.bat

SET total_number_of_tests=13
SET current_test_number=0
SET total_percentage=0
SET message=
SET user_files=Ocean.cpp
SET tablen_files=%user_files% Ocean.h

:PRE_TEST
SET /A current_test_number=%current_test_number% + 1
SET message= Result
GOTO TEST%current_test_number%

:TEST1
SET output_folder=DriverSampleTestsScripts
echo running driver sample test 0
call Run-test.cmd 0 "" %output_folder%\test0.txt driver_sample_test0.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST2
echo running driver sample test 1
call Run-test.cmd 0 "" %output_folder%\test1.txt driver_sample_test1.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST3
echo running driver sample test 2
call Run-test.cmd 0 "" %output_folder%\test2.txt driver_sample_test2.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST4
echo running driver sample test 3
call Run-test.cmd 0 "" %output_folder%\test3.txt driver_sample_test3.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST5
SET output_folder=DriverBigTestsScripts
echo running driver big test 1
call Run-test.cmd 0 "" "%output_folder%\out-5-10-10-ff.txt" driver_big1.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST6
echo running driver big test 2
call Run-test.cmd 0 "" "%output_folder%\out-5-10-10-tf.txt" driver_big2.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST7
echo running driver big test 3
call Run-test.cmd 0 "" "%output_folder%\out-5-10-10-tt.txt" driver_big3.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST8
echo running driver big test 4
call Run-test.cmd 0 "" "%output_folder%\out-5-8-12-ff.txt" driver_big4.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST9
echo running driver big test 5
call Run-test.cmd 0 "" "%output_folder%\out-5-8-12-tf.txt" driver_big5.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST10
echo running driver big test 6
call Run-test.cmd 0 "" "%output_folder%\out-5-8-12-tt.txt" driver_big6.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST11
echo running driver big test 7
call Run-test.cmd 0 "" "%output_folder%\out-99-30-30-ff.txt" driver_big7.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST12
echo running driver big test 8
call Run-test.cmd 0 "" "%output_folder%\out-99-30-30-tf.txt" driver_big8.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST13
echo running driver big test 9
call Run-test.cmd 0 "" "%output_folder%\out-99-30-30-tt.txt" driver_big9.cpp PRNG.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )


:FAIL
if %RETURNVALUE% equ 0 SET message= %message%: PASSED, SHOULD HAVE FAILED
if %RETURNVALUE% equ 1 SET message= %message%: BUILD_FAIL
if %RETURNVALUE% equ 2 SET message= %message%: DIFF_FAIL
if %RETURNVALUE% equ 3 SET message= %message%: MEMORY_LEAK
if %RETURNVALUE% equ 4 SET message= %message%: DIFF_AND_LEAK
echo %message%
IF %current_test_number% equ %total_number_of_tests% ( GOTO TABLEN ) ELSE ( GOTO PRE_TEST )


:PASS
echo %message%: PASSED
@echo off
SET /A total_percentage= %total_percentage% + %percentage%
IF %current_test_number% equ %total_number_of_tests% ( GOTO TABLEN ) ELSE ( GOTO PRE_TEST )

:TABLEN
SET /A total_percentage= %total_percentage% / %total_number_of_tests%

echo running tablen

setlocal ENABLEDELAYEDEXPANSION

set TAB_FAIL=0
for %%f in (%tablen_files%) do ( 
tablen.exe %%f > tablen_out.txt 
for %%i in (tablen_out.txt) do ( 
set LOCAL_FAIL=0
if %%~zi gtr 0 set LOCAL_FAIL=1
if !LOCAL_FAIL! equ 1 set TAB_FAIL=1
if !LOCAL_FAIL! equ 1 echo "%%f" Failed the tablen test
)
)
endlocal & (
set TAB_FAIL=%TAB_FAIL%
)

if %TAB_FAIL% equ 0 GOTO TABLEN_PASSED

:TABLEN_FAIL
SET /A total_percentage= %total_percentage% - 5
echo Result: FAILED: -5%
echo ************************************************  
GOTO DONE

:TABLEN_PASSED
echo Result: PASSED
echo ************************************************  

:DONE

del tablen_out.txt
echo Final Grade: %total_percentage%%%

pause
@echo on