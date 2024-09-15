#!/bin/bash

if [[ $(pwd) == "$HOME/cppcp" ]]; then
    if [[ $# == 0 ]]; then
        name=$(cat .stor/source.txt)
    else
        name=$(echo $1 | cut -d'.' -f1)
    fi

    i=0
    name1=.stor/inp
    name2=.stor/out
    if [[ ! -f .exec/${name}.out ]]; then
		clang++ -g -fsanitize=address,undefined -fno-omit-frame-pointer -include-pch libraries/bits/stdc++.h "${name}.cpp" -std=c++20 -Wno-vla -o ".exec/${name}.out"
    fi
    dsp -n ${name}
    chmod +x .exec/${name}.out
    while [[ -f "${name1}${i}.txt" && -f "${name2}${i}.txt" ]]; do
        echo -e "\n${i}. Input:"
        cat "${name1}${i}.txt"
        echo -e "\n\nOutput:"
        cat "${name1}${i}.txt" | ".exec/${name}.out"
        echo -e "\nExpected Output:"
        cat "${name2}${i}.txt"
        echo
        i=$((i+1))
    done
fi

