#!/bin/bash

"./clean.sh"
echo "~~~ADDRESS SANITIZER~~~"
"./build_debug_asan.sh"
cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../ || exit 1

"./clean.sh"
echo "~~~MEMORY SANITIZER~~~"
"./build_debug_msan.sh"
cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../ || exit 1

"./clean.sh"
echo "~~~UNDEFINED BEHAVIOR SANITIZER~~~"
"./build_debug_ubsan.sh"
cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../ || exit 1

"./clean.sh"
echo "~~~COVERAGE BUILD~~~"
"./build_gcov.sh"
cd ./func_tests/scripts/ || exit 1
./func_tests.sh
cd ../../ || exit 1

"./collect_coverage.sh"
