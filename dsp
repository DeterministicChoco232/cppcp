#!/bin/bash

if [[ $(pwd) == "$HOME/cppcp" ]]; then
	if [ $1 = "-n" ]; then
		name=$(echo $2 | cut -d'.' -f1)
	else
		name=$(echo $1 | cut -d'.' -f1)
	fi

	echo ${name} > .stor/source.txt
    if [ ! -f .stor/${name}.html ]; then
		python3 .py/generateProblem.py
    fi
	html2text .stor/${name}.html > .stor/${name}.txt
	python3 .py/generateProblem2.py
	if [[ $1 != "-n" ]]; then
		less .stor/${name}.txt
	fi
fi
