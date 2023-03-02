set -e

rm -r build
mkdir build
pushd .
cd build
cmake ..
cmake --build .
popd