#!/bin/sh
ROOT_FOLDER=`pwd`
# Note: openwatcom should be placed in watcom/
dosbox-x -set "dos xms=true" -set "dos xmslimit=64" -set "dos emslimit=64" -c "MOUNT C $ROOT_FOLDER/watcom" -c "MOUNT D $ROOT_FOLDER" -c "mode con lines=60" -c "mode con cols=132"
