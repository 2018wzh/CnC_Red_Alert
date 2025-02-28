#!/bin/sh
ROOT_FOLDER=`pwd`
# Note: openwatcom should be placed in watcom/
dosbox-x -c "MOUNT C $ROOT_FOLDER/watcom" -c "MOUNT D $ROOT_FOLDER" -c "mode con lines=60" -c "mode con cols=132"
