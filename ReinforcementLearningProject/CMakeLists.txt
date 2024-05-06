# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(ReinforcementLearningProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Generate executable
add_executable(ReinforcementLearningProject ${SOURCES})
