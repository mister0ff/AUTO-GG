# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MinecraftHack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Remover dependência do JNI
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNO_JNI")

# Diretórios de inclusão
include_directories(include)

# Arquivo principal
set(SOURCES src/main.cpp)

# Biblioteca compartilhada
add_library(minecraft_hack SHARED ${SOURCES})

# Linkar bibliotecas do sistema
target_link_libraries(minecraft_hack dl pthread)

# Definir saída do arquivo
set_target_properties(minecraft_hack PROPERTIES PREFIX "")
set_target_properties(minecraft_hack PROPERTIES OUTPUT_NAME "minecraft_hack")
