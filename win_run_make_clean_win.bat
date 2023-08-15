rmdir  build\build.windows /s /q


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


echo ******
cmake -G"Visual Studio 15 2017 Win64" ../../   -DCMAKE_BUILD_TYPE=Debug


echo ******
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\MSBuild.exe"    ALL_BUILD.vcxproj  /property:Platform=x64  /property:Configuration=Debug /verbosity:quiet

cd ..
cd ..

cd Host

cd bin

cd Debug

echo Executing the Debug

GameEngineTest.exe

echo ######################################################## END

echo Start Time: %START_TIME%
echo End Time: %TIME%

pause
