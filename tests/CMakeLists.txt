cmake_minimum_required( VERSION 2.8 )
project( libprecision_tests )


set( TEST_SOURCES
	tests/src/tests.cpp
)

LINK_LIBRARIES()
add_executable( ${CMAKE_PROJECT_NAME} ${TEST_SOURCES})

include_directories(include/)

target_link_libraries(${CMAKE_PROJECT_NAME} gtest libprecision)

add_custom_command(
	TARGET ${CMAKE_PROJECT_NAME}
	POST_BUILD
	COMMAND ${CMAKE_PROJECT_NAME}
)
