cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)
include(cmtk/CppProject)
include(CMakePrintHelpers)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ MULTI-PROJECT

set(PROJECT_NAME "arba-arba")
set(project_namespace "arba")
set(project_base_name "arba")
set(PROJECT_VERSION 0.26.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
    DESCRIPTION "A set of tiny but useful C++ libraries."
    HOMEPAGE_URL "https://github.com/arapelle/arba"
    LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

## C++ gathering target

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}-static INTERFACE)

trioption(BUILD_${PROJECT_NAME} "Indicates if we build a SHARED library." ON)
trioption(BUILD_${PROJECT_NAME}-static "Indicates if we build a STATIC library." ON)
trioption(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not." OFF)
trioption(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not." OFF)

## Generated/Configured headers:
generate_version_macro_header(generated_version_header
                              ${project_namespace}_${project_base_name}
                              ${project_namespace}/${project_base_name}/version.hpp)

target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}/include FILES ${generated_version_header})

### Add sub-projects and link with them:
set(libraries
    core
    strn
    wgen
    cryp
    seri
    dirn
    inis
    math
    grid
    evnt
    vlfs
    rsce
    appt
)

foreach(library ${libraries})
    add_subdirectory(${project_namespace}-${library})
    if(TARGET ${project_namespace}-${library})
        target_link_libraries(${PROJECT_NAME} INTERFACE ${project_namespace}-${library})
    endif()
    if(TARGET ${project_namespace}-${library}-static)
        target_link_libraries(${PROJECT_NAME}-static INTERFACE ${project_namespace}-${library}-static)
    endif()
endforeach()

### Export targets
install_cpp_library(
    SHARED ${PROJECT_NAME}
    STATIC ${PROJECT_NAME}-static
    EXPORT ${PROJECT_NAME}-targets
)

# Install package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE cmake/config/package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME} ALL FILENAME uninstall.cmake)

## Add tests:
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
