@echo off
call setvc12-32.bat

SET total_number_of_tests=8
SET current_test_number=0
SET total_percentage=0
SET message=
SET user_files=Circle.cpp Rectangle.cpp Polygon.cpp Shape.cpp Shape_With_Vertices.cpp
SET tablen_files=%user_files% Circle.h Rectangle.h Polygon.h Shape.h Shape_With_Vertices.h

:PRE_TEST
SET /A current_test_number=%current_test_number% + 1
SET message= Result
GOTO TEST%current_test_number%

:TEST1
echo running test 1 circle
call Run-test.cmd 0 "" output_test1_circle.txt main_test1_circle.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST2
echo running test 2 circle
call Run-test.cmd 1 "" "" main_test2_circle.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 1 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST3
echo running test 1 rectangle
call Run-test.cmd 0 "" output_test1_rectangle.txt main_test1_rectangle.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST4
echo running test 2 rectangle
call Run-test.cmd 1 "" "" main_test2_rectangle.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 1 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST5
echo running test 1 polygon
call Run-test.cmd 0 "" output_test1_polygon.txt main_test1_polygon.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST6
echo running test 2 polygon
call Run-test.cmd 1 "" "" main_test2_polygon.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 1 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST7
echo running test polymorphism
call Run-test.cmd 0 "" output_test_polymorphism.txt main_test_polymorphism.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 0 ( GOTO FAIL ) ELSE ( GOTO PASS )

:TEST8
echo running test abstract
call Run-test.cmd 1 "" "" main_test5_abstract.cpp Point.cpp %user_files%
IF %RETURNVALUE% neq 1 ( GOTO FAIL ) ELSE ( GOTO PASS )

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