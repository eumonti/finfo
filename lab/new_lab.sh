#!/bin/bash
arr=( $(find -type d -name 'lab*' | sort) )
lastnum=${arr[-1]:5:2}
num=$((lastnum + 1))
printf -v f_num "%02d" $num
newdir="lab${f_num}"
mkdir -p "${newdir}/bin"
cp -R lab01/.vscode "${newdir}"
code "${newdir}"
