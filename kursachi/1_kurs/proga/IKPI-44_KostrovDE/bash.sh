#!/bin/bash

cat zastavka.txt;
./c.exe;
"D:\maxima-5.47.0\bin\wxmaxima.exe" --eval "kpm.mac";
start "" "Пояснительная записка.docx";
