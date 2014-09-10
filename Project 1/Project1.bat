@ECHO OFF
CLS

:MENU
ECHO.
ECHO.                         David Walker - Project 1
ECHO.
ECHO  ..............................................................................
ECHO               PRESS 1, 2 OR 3 to select your task, or 4 to EXIT
ECHO  ..............................................................................
ECHO.
ECHO 1 - Project 1a 
ECHO.    ** Uses only techniques covered. **
ECHO.
ECHO 2 - Project 1b
ECHO.    ** Uses techniques not covered. Has optional parameters. **
ECHO.    ** Parameters are: -e, -v **
ECHO.
ECHO 3 - Project 1c
ECHO.    ** Uses techniques not covered. Has optional parameters. **
ECHO.    ** Parameters are: -h, -e, -v, -d, -l **
ECHO.
ECHO 4 - EXIT
ECHO.
ECHO.        ** Builds with optional parameters are NOT run with parameters. **
ECHO.
SET /P M=Type 1, 2, 3, or 4 then press ENTER: 
IF %M%==1 GOTO 1A
IF %M%==2 GOTO 1B
IF %M%==3 GOTO 1C
IF %M%==4 GOTO EOF

:1A
start Project1a\project1a.exe
CLS
GOTO MENU
:1B
start Project1b\project1b.exe
CLS
GOTO MENU
:1C
start Project1c\project1c.exe
CLS
GOTO MENU
:EOF
exit /b