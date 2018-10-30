cmake_minimum_required (VERSION 3.7)

# Configure informations project ------------------------------
project ("GNU Laby")
SET (EXEC_NAME "laby")

option(DEBUG ON)

if (DEBUG)
    MESSAGE("-- Debug mode")
    SET (CMAKE_CXX_FLAGS "-std=c++11 -Wall -g -O0")
else ()
    MESSAGE("-- Release mode")
    SET (CMAKE_CXX_FLAGS "-std=c++11 -O3")
endif ()

# Configure include directories -------------------------------
INCLUDE_DIRECTORIES (inc)

# Configure path ----------------------------------------------
SET (SRCS_PATH "${PROJECT_SOURCE_DIR}/src/")
SET (INCS_PATH "${PROJECT_SOURCE_DIR}/inc/")

# Include file ------------------------------------------------
FILE (GLOB DOTC ${SRCS_PATH}*.cpp)
FILE (GLOB DOTH ${INCS_PATH}*.hpp)
SET (SRC ${DOTC} ${DOTH})

# Add executable ----------------------------------------------
add_executable(${EXEC_NAME} ${SRC})