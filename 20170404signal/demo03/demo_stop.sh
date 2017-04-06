#!/bin/sh
WHOAMI=`whoami`
PID=`ps -u $WHOAMI | grep demod | awk '{print $1}'`

if (test "$PID" != "") then
	kill $PID
fi