cmake_minimum_required(VERSION 3.10)

project(panda-engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VS_STARTUP_PROJECT sandbox)

# Add subdirectories
add_subdirectory(panda-engine)
add_subdirectory(sandbox)