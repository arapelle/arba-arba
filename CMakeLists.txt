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
set(PROJECT_VERSION 0.27.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION}
    DESCRIPTION "A set of tiny but useful C++ libraries."
    HOMEPAGE_URL "https://github.com/arapelle/arba"
    LANGUAGES CXX)
message(STATUS "PROJECT: ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

## C++ gathering target

trioption(BUILD_${PROJECT_NAME} "Indicates if we build a SHARED library." ON)
trioption(BUILD_${PROJECT_NAME}-static "Indicates if we build a STATIC library." ON)
trioption(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not." OFF)
trioption(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not." OFF)

if(BUILD_${PROJECT_NAME} STREQUAL OFF AND BUILD_${PROJECT_NAME}-static STREQUAL OFF)
    message(FATAL_ERROR "You did not choose which target(s) to build (SHARED, STATIC).")
endif()
if(NOT BUILD_${PROJECT_NAME} STREQUAL OFF)
    add_library(${PROJECT_NAME} INTERFACE)
endif()
if(NOT BUILD_${PROJECT_NAME}-static STREQUAL OFF)
    add_library(${PROJECT_NAME}-static INTERFACE)
endif()

## Generated/Configured headers:
generate_version_macro_header(generated_version_header
                              ${project_namespace}_${project_base_name}
                              ${project_namespace}/${project_base_name}/version.hpp)

if(TARGET ${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}/include
        FILES ${generated_version_header}
    )
endif()
if(TARGET ${PROJECT_NAME}-static)
    target_sources(${PROJECT_NAME}-static PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}/include
        FILES ${generated_version_header}
    )
endif()

### Add sub-projects and link with them:
set(libraries
    core
    strn
    itru
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
    if(TARGET ${PROJECT_NAME})
        if(TARGET ${project_namespace}-${library})
            target_link_libraries(${PROJECT_NAME} INTERFACE ${project_namespace}-${library})
        endif()
    endif()
    if(TARGET ${PROJECT_NAME}-static)
        if(TARGET ${project_namespace}-${library}-static)
            target_link_libraries(${PROJECT_NAME}-static INTERFACE ${project_namespace}-${library}-static)
        elseif(TARGET ${project_namespace}-${library})
            get_target_property(target_type ${project_namespace}-${library} TYPE)
            if (target_type STREQUAL "INTERFACE_LIBRARY")
                target_link_libraries(${PROJECT_NAME}-static INTERFACE ${project_namespace}-${library})
            endif ()
        endif()
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

## Add examples:
if(BUILD_${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
