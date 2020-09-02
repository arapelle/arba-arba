#include <core/version.hpp>
#include <core/uuid.hpp>
#include <strn/version.hpp>
#include <strn/string64.hpp>
#include <strn/io.hpp>
#include <wgen/version.hpp>
#include <wgen/default_syllabary.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    core::uuid id("ced1cc82-37ea-450f-a5ec-00e3c10a00f2");
    std::cout << id << std::endl;
    wgen::default_syllabary syllabary;
    strn::string64 word = syllabary.random_name64(6);
    std::cout << word << std::endl;
    return EXIT_SUCCESS;
}
