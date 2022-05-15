cmake_minimum_required(VERSION 3.16)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package arba:
find_package(arba 0.23 CONFIG REQUIRED)
# Use arba release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba::arba)
# Use arba release static target:
#target_link_libraries(${PROJECT_NAME} PRIVATE arba::arba-static)
