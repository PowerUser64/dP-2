SET RETURNVALUE=0

setlocal ENABLEDELAYEDEXPANSION
SET LOCALRETURNVALUE=0
rem **************************************************
rem **************************************************
SET arg_count=0
FOR %%x in (%*) do (
call SET /A arg_count+=1
SET arg!arg_count!=%%x
)

IF !arg_count! lss 3 GOTO END

SET passing_value=%arg1%
SET input=%arg2%
SET output=%arg3%

IF !arg_count! lss 4 GOTO END

SET counter=4

SET c_files=!arg%counter%!
:GET_FILES
IF !counter! equ !arg_count! ( GOTO END_GET_FILES )
SET /A counter+=1
SET c_files=%c_files% !arg%counter%!
GOTO GET_FILES
:END_GET_FILES
rem **************************************************
rem **************************************************

SET ms_flags= /W3 /WX /sdl /Od /Oy- /EHsc
SET files_to_delete= *.exe *.pdb *.obj "StudentOutput%current_test_number%.txt" "drout%current_test_number%.txt" "memLeak%current_test_number%.txt" "ms_report%current_test_number%.txt" "fc_report%current_test_number%.txt"
SET verbose=0

CL.exe /nologo %ms_flags% %c_files% /Fems%current_test_number%.exe > "ms_report%current_test_number%.txt" 2>&1
IF NOT EXIST ms%current_test_number%.exe GOTO BUILDING_FAIL

IF %input% equ "" ( GOTO NO_INPUT )
ms%current_test_number%.exe < %input% > "StudentOutput%current_test_number%.txt"
GOTO DIFF

:NO_INPUT
ms%current_test_number%.exe > "StudentOutput%current_test_number%.txt"

:DIFF
FC %output% StudentOutput%current_test_number%.txt > "fc_report%current_test_number%.txt"
if %errorlevel% neq 0 GOTO DIFF_FAIL

GOTO MEMORY

:BUILDING_FAIL
SET LOCALRETURNVALUE=1
if %verbose% equ 0 GOTO SKIP
echo ************************************************
echo ******************BUILD ERROR*******************  
echo ************************************************    
more "gcc_report%current_test_number%.txt"
:SKIP

GOTO DONE

:DIFF_FAIL
SET LOCALRETURNVALUE=2
if %verbose% equ 0 GOTO SKIP
echo ************************************************
echo ******************DIFF ERROR********************  
echo ************************************************    
more "fc_report%current_test_number%.txt"
:SKIP

:MEMORY
IF %input% equ "" ( GOTO MEM_NO_INPUT )
drmemory.exe 2> "memLeak%current_test_number%.txt" -results_to_stderr -batch -exit_code_if_errors 1 -- ms%current_test_number%.exe < %input% > "drout%current_test_number%.txt"
IF %errorlevel% neq 0 ( GOTO MEMORY_LEAK ) ELSE ( GOTO DONE )


:MEM_NO_INPUT
drmemory.exe 2> "memLeak%current_test_number%.txt" -results_to_stderr -batch -exit_code_if_errors 1 -- ms%current_test_number%.exe > "drout%current_test_number%.txt"
IF %errorlevel% neq 0 ( GOTO MEMORY_LEAK ) ELSE ( GOTO DONE )

:MEMORY_LEAK
IF %LOCALRETURNVALUE% equ 2 (SET LOCALRETURNVALUE= 4) ELSE (SET LOCALRETURNVALUE= 3)
if %verbose% equ 0 GOTO SKIP
echo ************************************************
echo **************MEMORY LEAK ERROR*****************  
echo ************************************************ 
more "memLeak%current_test_number%.txt"
:SKIP

:DONE
IF %LOCALRETURNVALUE% equ %passing_value% ( SET local_percentage=100 ) ELSE ( SET local_percentage=0 )
del %files_to_delete%
endlocal & (
set RETURNVALUE=%LOCALRETURNVALUE%
set percentage=%local_percentage%
)