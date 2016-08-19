#!/bin/bash
for filename in `ls *cpp`
do 
mv $filename "noi"$filename
done