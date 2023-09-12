cmake_minimum_required(VERSION 2.8)

project("breakpad_lite_test")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
message( STATUS "The comipler ${CMAKE_CXX_COMIPLER} has no C++ 11 suport. Please use a different C++ comipler.")
endif()

include_directories(${CMAKE_SOURCE_DIR}/../output/include)
link_directories(${CMAKE_SOURCE_DIR}/../output/lib)
message(STATUS "breakpad header path: ${CMAKE_SOURCE_DIR}/../output/include")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} breakpad_lite pthread)