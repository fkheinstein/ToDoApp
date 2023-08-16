@rem rmdir  build\build.windows /s /q

echo ######################################################## Start

set START_TIME=%time%
echo ########################################################
echo Build This Application
echo ########################################################
echo




mkdir  build
cd build
mkdir  build.windows
cd build.windows

del CMakeCache.txt

echo ******
cmake -G "Visual Studio 16 2019"   ../../   -DCMAKE_BUILD_TYPE=Debug -DCMAKE_UNITY_BUILD=ON

echo ######################################################## END

echo Start Time: %START_TIME%
echo End Time: %TIME%

pause
