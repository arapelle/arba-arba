#include <arba/arba/version.hpp>
#include <arba/appt/application/program.hpp>
#include <arba/dirn/d2/directions4.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "arba-arba-" << ARBA_ARBA_VERSION << std::endl;
    appt::program program(argc, argv);
    std::cout << program.args().program_path() << std::endl;
    for (dirn::direction4 dir : dirn::directions4::directions)
        std::cout << dirn::directions4::to_string_view(dir) << std::endl;
    return EXIT_SUCCESS;
}
