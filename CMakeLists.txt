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
        VERSION 0.1.0
        DESCRIPTION "A set of tiny but useful C++ libraries."
        HOMEPAGE_URL "https://github.com/arapelle/arba"
        LANGUAGES CXX)

include(CTest)

add_subdirectory(strn)
add_subdirectory(wgen)

include(GNUInstallDirs)
install_cmake_uninstall_script(${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME} ALL)
