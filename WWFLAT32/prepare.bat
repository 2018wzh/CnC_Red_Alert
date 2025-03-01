@echo off
set DESTINATION=INCLUDE

if not exist "%DESTINATION%" mkdir "%DESTINATION%"

copy /Y "AUDIO\*.h" "%DESTINATION%" 
copy /Y "AUDIO\*.inc" "%DESTINATION%" 

copy /Y "FILE\*.h" "%DESTINATION%" 

copy /Y "KEYBOARD\*.h" "%DESTINATION%" 
copy /Y "KEYBOARD\*.inc" "%DESTINATION%" 

copy /Y "MISC\*.h" "%DESTINATION%" 

copy /Y "TILE\*.h" "%DESTINATION%" 

copy /Y "WSA\*.h" "%DESTINATION%" 

copy /Y "DESCMGMT\*.h" "%DESTINATION%" 

copy /Y "FONT\*.h" "%DESTINATION%" 

copy /Y "MONO\*.h" "%DESTINATION%" 

copy /Y "SHAPE\*.h" "%DESTINATION%" 
copy /Y "SHAPE\*.inc" "%DESTINATION%" 

copy /Y "TIMER\*.h" "%DESTINATION%" 

copy /Y "DIPTHONG\*.h" "%DESTINATION%" 

copy /Y "IFF\*.h" "%DESTINATION%" 

copy /Y "MCGAPRIM\*.h" "%DESTINATION%" 
copy /Y "MCGAPRIM\*.inc" "%DESTINATION%" 

copy /Y "PALETTE\*.h" "%DESTINATION%" 

copy /Y "VIDEO\*.h" "%DESTINATION%" 

copy /Y "MEM\*.h" "%DESTINATION%" 
copy /Y "MEM\*.inc" "%DESTINATION%" 

copy /Y "PLAYCD\*.h" "%DESTINATION%" 

copy /Y "SVGAPRIM\*.inc" "%DESTINATION%" 

copy /Y "WINDOWS\*.h" "%DESTINATION%" 

echo All files copied successfully.
