cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_COMPILER "g++")
project(
    SeyedKhande
    LANGUAGES C CXX
    VERSION 1.0.0
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(app 
            main.cpp
            src/GameManager.cpp
            src/Hero.cpp
            src/AghaShahriar.cpp
            src/AminEmeni.cpp
            src/BigTaha.cpp
            src/DaniGolang.cpp
            src/PouyaKazhDam.cpp
            src/SmallTaha.cpp
            src/WhiteDoctor.cpp
            )
include_directories(include)




