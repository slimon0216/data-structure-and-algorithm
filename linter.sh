#!/bin/bash

# Author: boook
# Clang-format: google style
# This script will use clang-format to standardize the format of
# all the files or specific file in the directory. (This script
# will skip the files under `.git` and `external` directory)
#
# Install clang-format:
#     mac OS:
#        $ brew install clang-format
#     Ubuntu: (If facing version problem, see reference d.)
#        $ sudo apt install clang-format-15
#
# Usage:
# 1. add `-i` to check and auto-fix the format
# 2. use `-s` to show the diffence between clang-format (default not display)
# 3. use `-d [base_dir]` to scan all the file under [base_dir]
#    default: the $(pwd) directory
# 4. use `-f [file_path]` to only do things to the [file_path]
#
# e.g.
# 1. Just check, do not auto fix
#    $ ./linter.sh
#    $ ./linter.sh -d ./src
#    $ ./linter.sh -f ./src/main.cpp
# 2. Check and auto fix all the file
#    $ ./linter.sh -i
#    $ ./linter.sh -i -d ./src
#    $ ./linter.sh -i -f ./src/main.cpp

# Reference:
#   a. https://unix.stackexchange.com/questions/494143/recursive-shell-script-to-list-files
#   b. https://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
#   c. https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
#   d. https://blog.csdn.net/sinat_34986308/article/details/116116780

formatter=$(which clang-format) || formatter=$(which clang-format-15) || { echo "clang-format not found"; exit 1; }
red='\033[0;31m'
no_color='\033[0m'

# Parse arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -i) Fix="-i" ;;
        -s|--show) show_detail='True' ;;
        -f|--target) target="$2"; shift ;;
        -d|--dir) base_dir="$2"; shift ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

if [ -n "$target" ] && [ -n "$base_dir" ]; then
    echo "Too many parameter"; exit 1 ;
fi

# Default fix all the file under $(pwd)
if [ -z "$base_dir" ]; then
    base_dir="$(pwd)"
fi

# format the file
exec_fix () {
    echo "[Command] $formatter $Fix $1"
    if [ -n "$show_detail" ]; then
        diff <(cat "$1") <("$formatter" "$1") &
    else
        diff <(cat "$1") <("$formatter" "$1") > /dev/null || echo -e "${red} [Need Linter] $1 ${no_color}" &
    fi
    "$formatter" $Fix "$1" > /dev/null
}

# format all the file under the directory
walk_dir () {
    shopt -s nullglob dotglob

    for pathname in "$1"/*; do
        case $pathname in
            *.git|*external|*build) continue;
        esac
        if [ -d "$pathname" ]; then
            walk_dir "$pathname"
        else
            case "$pathname" in *.cpp|*.h|*.hpp)
                exec_fix "$pathname"
            esac
        fi
    done
}

if [ -n "$target" ]; then
    exec_fix "$target"
else
    walk_dir "$base_dir"
fi

wait