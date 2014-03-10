cmake_minimum_required(VERSION 2.8)
project(libprecision)

set(CMAKE_BUILD_TYPE Release CACHE STRING "Built type." FORCE)
set(LIBPRECISION_BUILD_SHARED_LIBS TRUE CACHE BOOL "Build shared libraries.")
set(LIBPRECISION_BUILD_DOCS TRUE CACHE BOOL "Build Doxygen documentation.")
set(LIBPRECISION_BUILD_TESTS TRUE CACHE BOOL "Build libprecision tests.")

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(LIBPRECISION_BUILD_SHARED_LIBS)
	set(LIB_TYPE SHARED)
else()
	set(LIB_TYPE STATIC)
endif()

set(SRC_DIR "src")
set(INC_DIR "include")

set(
	SOURCES
	${INC_DIR}/${CMAKE_PROJECT_NAME}/libprecision.hpp
)