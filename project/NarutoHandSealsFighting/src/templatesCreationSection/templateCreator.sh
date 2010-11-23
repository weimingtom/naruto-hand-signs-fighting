#!/bin/bash

SOURCE_DIR="../../src/templatesCreationSection/sourceRawImages/"
DEST_DIR="../movesTemplates/"

#check if the Makefile was properly run before the launch of this script
if [ ! -x createTemplates ];
then
	make
fi

for file in $SOURCE_DIR*.png; do
	path="$file"
	fileName="${path##$SOURCE_DIR}"
	echo "input fileName: $fileName"
	destFile="$DEST_DIR""$fileName"
	echo "destination file: $destFile"
	./createTemplates $path $destFile
done

