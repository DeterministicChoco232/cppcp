#!/bin/bash

if [[ $(pwd) == "$HOME/cppcp" ]]; then
    if [[ $1 = "-n" ]]; then
        name=$(echo $2 | cut -d'.' -f1)
    else
        name=$(echo $1 | cut -d'.' -f1)
    fi

    echo ${name} > .stor/source.txt
    if [[ "${name:0:1}" == "t" ]]; then
        site="timus"
    else
        site="cf"
    fi
    if [[ ! -f .stor/problemstatement.html ]]; then
        python3 .py/${site}GenProbHtml.py
        html2text .stor/problemstatement.html > .stor/problemstatement.txt
        python3 .py/${site}GenProbTxt.py
    fi
    if [[ $1 != "-n" ]]; then
        less .stor/problemstatement.txt
    fi
fi

