#!/usr/bin/env bash

#Este comando é usado para aumentar o limite do stack

ulimit -s 67108864

./bin/run.out "$1" "$2"