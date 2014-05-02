/**
 * \file main.cpp
 * \brief Main.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \date 2014
 * \copyright WTFPL version 2
 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#include <iostream>
#include <sysexits.h>

#include "foobar.hpp"


int main (int argc, char ** argv)
{
    if (argc > 1)
    {
        std::cerr << "Error: too many arguments." << std::endl;
        std::cerr << "Usage: " << argv[0] << std::endl;
        return EX_USAGE;
    }

    /* Trying to output the hello world with a foobar.
     */
    std::cout << ">> foobar f (\"Hello, World\", 0);" << std::endl;
    std::cout << ">> std::cout << f << std::endl;" << std::endl;

    foobar f ("Hello, World", 0);
    std::cout << f << std::endl;

    /* Not the expected output ?! (Remember, the foobar message is cut at the
     * first space !)
     */
    std::cout << std::endl << "???" << std::endl << std::endl;

    /**
     * Trying again...
     */
    std::cout << ">> foobar hello (\"Hello,\", 1);" << std::endl;
    std::cout << ">> foobar world (\"World\", 1);" << std::endl;
    std::cout << ">> std::cout << std::cout << hello.message () << \" \" << world.message () << std::endl;" << std::endl;

    foobar hello ("Hello,", 1);
    foobar world ("World", 1);

    std::cout << hello.message () << " " << world.message () << std::endl;

    std::cout << std::endl << "Success !" << std::endl;


    return 0;
}
