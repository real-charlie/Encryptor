cmake_minimum_required(VERSION 3.20)
project(Encryptor C)

set(CMAKE_C_STANDARD 11)

add_executable(Encryptor main.c src/IO/traverse.c src/IO/traverse.h src/path/path.c src/path/path.h src/shared.c src/shared.h)
