set -x
set -e

cd `pwd`/build/ &&
rm -rf ./* &&
cmake .. &&
make
cd ..
cp -r `pwd`/src/include `pwd`/lib