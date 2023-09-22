cmake_minimum_required(VERSION 3.26)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package arba-arba:
find_package(arba-arba 0.27.0 CONFIG REQUIRED)
# Use arba-arba release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba-arba)
# Use arba-arba release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE arba-arba-static)
