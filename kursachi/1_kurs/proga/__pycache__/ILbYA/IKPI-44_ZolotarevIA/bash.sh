#!/bin/bash

cat zastavka.txt;
./c.exe;
"D:\maxima-5.47.0\bin\wxmaxima.exe" --eval "kpm.wxmx";
start "" "Пояснительная записка.docx";
