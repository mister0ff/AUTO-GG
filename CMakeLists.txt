cmake_minimum_required(VERSION 3.10)
project(MinecraftHack)

set(CMAKE_CXX_STANDARD 17)

# Incluir diretórios
include_directories(include)

# Arquivos fonte
set(SOURCES src/main.cpp)

# Biblioteca compartilhada
add_library(minecraft_hack SHARED ${SOURCES})

target_link_libraries(minecraft_hack dl)
