set -x
cd `pwd`/build &&
rm -r * &&
cmake .. &&
make