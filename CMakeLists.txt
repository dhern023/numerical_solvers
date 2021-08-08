cmake_minimum_required(VERSION 3.11)

project("numerical_solvers")

# Target
set(PROJECT_NAME numerical_solvers)

# Source groups
include_directories(
	${PROJECT_SOURCE_DIR}/numerical_solvers
)

file(GLOB all_SRCS
	${PROJECT_SOURCE_DIR}/numerical_solvers/*.h
    ${PROJECT_SOURCE_DIR}/numerical_solvers/*.cpp
)

# Target
add_library(${PROJECT_NAME} STATIC ${all_SRCS})

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME})