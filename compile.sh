#!/bin/bash

set -e

export GTEST_COLOR=1

# if [ -d build ]; then
#     rm -r build
# fi

pushd .
mkdir -p build
cd build
cmake ..
cmake --build .
popd

ctest --test-dir build --output-on-failure
