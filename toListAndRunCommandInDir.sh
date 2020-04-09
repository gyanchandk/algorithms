#!/bin/bash

input="/home/gyanchand/dir1/temp"

while IFS= read -r dirName
do
  ( cd $dirName && ls )
done < "$input"
