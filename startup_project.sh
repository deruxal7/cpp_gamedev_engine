#!/bin/bash

cd build

if [ $? -ne 0 ]; then
  echo "Error: Could not change directory to build"
  exit 1
fi

echo "Cmaking..."
cmake ..

if [ $? -ne 0 ]; then
  echo "Error: CMake failed"
  exit 1
fi

echo "Success!"
echo ""

echo "Do \"make\"..."

make

if [ $? -ne 0 ]; then
  echo "Error: Make failed"
  exit 1
fi

echo "Success!"
echo ""

echo "Starting project..."

./CacTusEngine

cd ..

exit 0