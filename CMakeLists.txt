cmake_minimum_required (VERSION 3.7)

# Configure informations project ------------------------------
project ("GNU Laby")
SET (EXEC_NAME "laby")

option(ENABLE_DEBUG OFF)
option(ENABLE_TESTS OFF)

if (ENABLE_DEBUG)
    MESSAGE("-- Debug mode")
    SET (CMAKE_CXX_FLAGS "-std=c++11 -Wall -g -O0")
else ()
    MESSAGE("-- Release mode")
    SET (CMAKE_CXX_FLAGS "-std=c++11 -O3")
endif ()

if (ENABLE_TESTS)
    MESSAGE("-- Enable test")
    SET (TEST_NAME ${EXEC_NAME}_tester)
    enable_testing()
    add_subdirectory(tests)
endif ()

# Configure include directories -------------------------------
#INCLUDE_DIRECTORIES (inc)

# Configure path ----------------------------------------------
SET (SRCS_PATH "${PROJECT_SOURCE_DIR}/src/")
SET (INCS_PATH "${PROJECT_SOURCE_DIR}/src/")

# Include file ------------------------------------------------
FILE (GLOB DOTC ${SRCS_PATH}*.cpp)
FILE (GLOB DOTH ${INCS_PATH}*.hpp)
if (ENABLE_TESTS)
    FILE (GLOB TESTC ${PROJECT_SOURCE_DIR}/tests/*.cpp)
    FILE (GLOB TESTH ${PROJECT_SOURCE_DIR}/tests/*.hpp)
endif ()

# Create source file ------------------------------------------
SET (SRC ${DOTC} ${DOTH})
if (ENABLE_TESTS)
    SET (TESTSRC ${TESTC} ${TESTH})
endif ()

# Add executable ----------------------------------------------
add_executable(${EXEC_NAME} ${SRC})

if (ENABLE_TESTS)
    add_library(${TEST_NAME} ${TESTSRC})
    target_link_libraries(${EXEC_NAME} ${TEST_NAME})
endif ()
