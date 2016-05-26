project(SDK_CommandPluginExample)

# cmake_minimum_required(VERSION 3.1)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Get the packages needed to use the SDK
find_package(Cubit REQUIRED CONFIG)
include_directories(${CUBIT_INCLUDE_DIRS})

set(SRC
    MCNPInput.cpp
    MCNPInput.hpp
    dataref.hpp
    GeometryContext.hpp
    GeometryContext.cpp
    geometry.hpp
    geometry.cpp
    version.hpp
    volumes.hpp
    volumes.cpp
    MyPlugin.cpp
    MyPlugin.hpp
    MCNPImportCommand.cpp
    MCNPImportCommand.hpp)

add_library(import_mcnp_plugin MODULE ${SRC})
target_link_libraries(import_mcnp_plugin cubiti cubit_util )
