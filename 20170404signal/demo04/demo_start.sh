#!/bin/sh
WHOAMI=`whoami`
PID=`ps -u $WHOAMI | grep myreadd | awk '{print $1}'`

if (test "$PID" = "") then
	./myreadd
fi