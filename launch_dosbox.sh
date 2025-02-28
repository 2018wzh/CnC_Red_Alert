#!/bin/sh
ROOT_FOLDER=`pwd`
# Note: openwatcom should be placed in watcom/
dosbox-x -c "MOUNT C $ROOT_FOLDER/openwatcom" -c "MOUNT D $ROOT_FOLDER"
