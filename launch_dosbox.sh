#!/bin/sh
ROOT_FOLDER=`pwd`
# Note: openwatcom should be placed in watcom/
dosbox-x -conf dosbox.conf -set "ver=7.1" -set "lfn=true" -c "MOUNT C $ROOT_FOLDER/watcom" -c "MOUNT D $ROOT_FOLDER" -c "mode con lines=60" -c "mode con cols=132"
