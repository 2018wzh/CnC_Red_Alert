@echo off
set DESTINATION=INCLUDE

if not exist "%DESTINATION%" mkdir "%DESTINATION%"

copy /Y "AUDIO\*.h" "%DESTINATION%" 
copy /Y "AUDIO\*.inc" "%DESTINATION%" 

copy /Y "RAWFILE\*.h" "%DESTINATION%" 

copy /Y "KEYBOARD\*.h" "%DESTINATION%" 
copy /Y "KEYBOARD\*.inc" "%DESTINATION%" 

copy /Y "MISC\*.h" "%DESTINATION%" 

copy /Y "TILE\*.h" "%DESTINATION%" 

copy /Y "WSA\*.h" "%DESTINATION%" 

copy /Y "EXAMPLE\*.h" "%DESTINATION%" 

copy /Y "FONT\*.h" "%DESTINATION%" 

copy /Y "MONO\*.h" "%DESTINATION%" 

copy /Y "MOVIE\*.h" "%DESTINATION%" 

copy /Y "SHAPE\*.h" "%DESTINATION%" 
copy /Y "SHAPE\*.inc" "%DESTINATION%" 

copy /Y "TIMER\*.h" "%DESTINATION%" 

copy /Y "DIPTHONG\*.h" "%DESTINATION%" 

copy /Y "IFF\*.h" "%DESTINATION%" 

copy /Y "DRAWBUFF\*.h" "%DESTINATION%" 
copy /Y "DRAWBUFF\*.inc" "%DESTINATION%" 

copy /Y "PALETTE\*.h" "%DESTINATION%" 

copy /Y "MEM\*.h" "%DESTINATION%" 
copy /Y "MEM\*.inc" "%DESTINATION%" 

copy /Y "PLAYCD\*.h" "%DESTINATION%" 

copy /Y "PROFILE\*.h" "%DESTINATION%" 
copy /Y "PROFILE\*.inc" "%DESTINATION%" 

copy /Y "WINCOMM\*.h" "%DESTINATION%" 

copy /Y "WSA\*.h" "%DESTINATION%" 

copy /Y "WW_WIN\*.h" "%DESTINATION%" 

echo All files copied successfully.
