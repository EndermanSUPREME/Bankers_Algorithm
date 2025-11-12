#!/bin/bash

show_help() {
    echo "Usage: $0 [compile|run_all|help]"
    echo
    echo "Options:"
    echo "  help          Show this page"
    echo "  compile       Compile Bankers"
    echo "  run_all       Run Bankers against data1-3.txt files"
    echo
    echo "Examples:"
    echo "  ./bankers data1.txt"
}

if [ $# -ne 1 ]; then
    show_help
    exit
fi

mode=$1

if [ "$mode" = "compile" ]; then
    echo "[*] Compiling Bankers Program. . ."
    g++ main.cpp bankers.cpp -o bankers -Wall
elif [ "$mode" = "run_all" ]; then
    echo "[*] Compiling Bankers Program. . ."
    g++ main.cpp bankers.cpp -o bankers -Wall && (
        echo "[*] Running Bankers against data1-3.txt files. . ."
        echo "--------------------------------------------------"
        ./bankers ./data1.txt; echo
        ./bankers ./data2.txt; echo
        ./bankers ./data3.txt; echo
    )
else
    show_help
fi