#!/bin/bash

PICSDIR=/home/dinesh/pictures
WEBDIR=/var/www/dinesh/webcam

while true; do
	DISKFULL=$(df -h $WEBDIR | grep -v File | awk '{print $5}' | cut -d "%" -f1 -)

	DATE=$(date + %Y%m%d)
	HOUR=$(date + %H)
	$(mkdir $WEBDIR/"$DATE")
	
	while [ $HOUR -ne "00" ]; do
		DESTDIR=$WEBDIR/"$DATE"/"$HOUR"
		$(mkdir "$DESTDIR")
		$(mv $PICDIR/*.jpg "$DESTDIR"/)
		sleep 3600
		HOUR=$(date + %H)
	done
	
done

