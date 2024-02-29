@echo off
setlocal

:: Rutas de origen y destino, por ejemplo, si es en C: ejecutar como administrador

set _fuente=C:\carpetaA
: : Si no existe carpeta de destino crea la carpeta
set _destino=C:\carpetaB

:: Opciones de copia (puedes ajustar según tus necesidades)
set _que=/COPYALL /B /SEC /MIR
set _opciones=/R:0 /W:0 /LOG:log.txt /NFL /NDL

:: Ejecutar Robocopy
robocopy %_fuente% %_destino% %_que% %_opciones%

endlocal
echo "CS TERMINADO CORRECTAMENTE"
pause
