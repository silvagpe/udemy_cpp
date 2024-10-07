# GTest

```
sudo apt-get install libgtest-dev

```

```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/libgtest*.a /usr/lib/

```

 Certifique-se de que o CMake está configurado corretamente
Após instalar e compilar o Google Test, verifique se você está linkando as bibliotecas corretamente no seu CMakeLists.txt. Por exemplo, o arquivo deve incluir:
```
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Encontra o Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(MyTest my_test.cpp)

# Linka a biblioteca do Google Test
target_link_libraries(MyTest ${GTEST_LIBRARIES} pthread)

```