project(ComponentExample)

cmake_minimum_required(VERSION 2.8)

# Get the packages needed to use the SDK
find_package(Cubit REQUIRED CONFIG)
include_directories(${CUBIT_INCLUDE_DIRS})

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

find_package(MOAB REQUIRED)
include_directories(${MOAB_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(cmd)

set(MYCOMP_MOCS
    MenuManager.hpp)

qt4_wrap_cpp(moc_src ${MYCOMP_MOCS})

set(MYCOMP_SRCS
    ${moc_src}
    MyComp.cpp
    MyComp.hpp
    MenuManager.cpp)

# Setup swig. For more information see
set(DOT_I_DEPENDS ${MYCOMP_SRCS})
set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set_source_files_properties(mycomp.i PROPERTIES CPLUSPLUS ON OBJECT_DEPENDS "${DOT_I_DEPENDS}")
set(SWIG_MODULE_mycomp_EXTRA_DEPS ${DOT_I_DEPENDS})

# Create the python library using swig
swig_add_module(mycomp python mycomp.i ${MYCOMP_SRCS})
swig_link_libraries(mycomp
                    component clarogui navigation pickwidget cubiti clarofw
                    ${PYTHON_LIBRARIES} ${MOAB_LIBARARIES})
