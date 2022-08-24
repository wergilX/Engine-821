git submodule init
git submodule update

#FMT
mkdir external/fmt/build
cmake \
-DFMT_TEST=OFF \
-DFMT_FUZZ=OFF \
-DFMT_CUDA_TEST=OFF \
-DFMT_MODULE=OFF \
-S external/fmt -B external/fmt/build
make -j8 -C external/fmt/build

#SDL
mkdir external/sdl/build
cmake -S external/sdl -B external/sdl/build
make -j8 -C external/sdl/build