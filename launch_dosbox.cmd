set ROOT_FOLDER=%~dp0
dosbox-x -conf dosbox.conf -set "ver=7.1" -set "lfn=true" -c "MOUNT C D:\watcom" -c "MOUNT D %ROOT_FOLDER%"
