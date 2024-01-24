#!/bin/bash

if [[ $(pwd) == "$HOME/cppcp" ]]; then
    if [[ $# == 0 ]] || [[ ! $1 = "-n" ]]; then
		if [[ $# -eq 0 ]]; then
			name=$(cat .stor/source.txt)
		else
			name=$(echo $1 | cut -d'.' -f1)
		fi
        if [[ "${name:0:1}" == "t" ]]; then
            mv ${name}.cpp timus
        else
            mv ${name}.cpp completed
        fi
    fi
    rm -rf .stor/*
fi

