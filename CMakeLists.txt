cmake_minimum_required(VERSION 3.0)

project(Eq2deg)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include ${CMAKE_SOURCE_DIR})
link_directories(/usr/local/lib)

# C++ library
add_library (Eq2deg SHARED Eq2deg.cpp)
add_library (Eq2degComp SHARED Eq2degComp.cpp)
target_link_libraries (Eq2degComp Eq2deg)

# Construction of the main program for real roots equations
add_executable (solver solver.cpp)
target_link_libraries (solver Eq2deg)

# Construction of the general main program
add_executable (solverc solverc.cpp)
target_link_libraries (solverc Eq2degComp)

# Unitary Test
enable_testing()

# Register the test binary target
add_executable (testEq2deg testEq2deg.cpp)

# Tell the test binary that it depends on all those libraries
target_link_libraries (testEq2deg Eq2degComp
                       boost_unit_test_framework boost_system)

# Tell how to test, i.e., how to run the test binaries 
# and collect the results
add_test (testEq2deg testEq2deg)

# Map the checker to ctest
add_custom_target (check
  COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS testEq2deg)

# Doxygen
find_package(Doxygen)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_LOCAL_METHODS)
doxygen_add_docs(docs)
