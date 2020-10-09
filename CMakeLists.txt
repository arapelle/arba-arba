cmake_minimum_required(VERSION 3.16)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

include(CMakePrintHelpers)
include(cmtk/CppProject)

#-----
# PROJECT

check_cmake_binary_dir()
set_build_type_if_undefined()

#-----
# C++ PROJECT

project(arba
        VERSION 0.15
        DESCRIPTION "A set of tiny but useful C++ libraries."
        HOMEPAGE_URL "https://github.com/arapelle/arba"
        LANGUAGES CXX)

include(CTest)
include(GNUInstallDirs)

# Project targets
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}-static INTERFACE)

# List of sub-projects:
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

# Add sub-projects and link with them:
set(arba_shared_targets "")
set(arba_static_targets "")
foreach(library ${libraries})
    add_subdirectory(${library})
    if(TARGET ${library})
        target_link_libraries(${PROJECT_NAME} INTERFACE ${library})
        list(APPEND arba_shared_targets ${library})
    endif()
    if(TARGET ${library}-static)
        target_link_libraries(${PROJECT_NAME}-static INTERFACE ${library}-static)
        list(APPEND arba_static_targets ${library}-static)
    endif()
endforeach()

# Export targets
set(arba_targets "")
if(arba_shared_targets)
    list(APPEND arba_targets ${PROJECT_NAME})
endif()
if(arba_static_targets)
    list(APPEND arba_targets ${PROJECT_NAME}-static)
endif()
install(TARGETS ${arba_targets} EXPORT ${PROJECT_NAME})
install(EXPORT ${PROJECT_NAME}
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
        NAMESPACE ${PROJECT_NAME}::)

# Install package
install_package(${PROJECT_NAME}
                UNINSTALL_ALL
                INPUT_PACKAGE_CONFIG_FILE ${PROJECT_NAME}-config.cmake.in
                EXPORT_NAMES ${PROJECT_NAME})
