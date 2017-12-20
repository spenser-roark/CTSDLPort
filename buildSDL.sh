# We're just gonna assume we're doing this from the build directory
cd ~/Programs/csdl/build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
make install
