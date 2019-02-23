#!/bin/bash

test_prog () {
    echo "testing $3..."
    log=$(diff <(echo "$1") <(echo "$2"))
    if [ $? = 0 ]; then
        echo "ok"
    else
        echo "$3 differs : wrinting differ output in log_$3.txt"
        echo "$log" &> log_$3.txt
    fi
}

mine_obj=$(./my_objdump $@ 2>&1 | cat -e)
true_obj=$(objdump -fs $@ 2>&1 | cat -e)

mine_nm=$(./my_nm $@ 2>&1 | cat -e)
true_nm=$(nm -p $@ 2>&1 | cat -e)

test_prog "$mine_nm" "$true_nm" "nm"
test_prog "$mine_obj" "$true_obj" "objdump"
