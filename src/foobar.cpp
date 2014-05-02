/**
 * \file foobar.cpp
 * \brief Foobar.
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
#include "foobar.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor.
////////////////////////////////////////////////////////////////////////////////

foobar::foobar (void)
{
}

foobar::foobar (const foobar & f)
: _message (f._message), _value (f._value)
{
}

foobar::foobar (const std::string & message, unsigned int value)
: _value (value)
{
    set_message (message);
}

foobar::~foobar (void)
{
}

////////////////////////////////////////////////////////////////////////////////
// Getters.
////////////////////////////////////////////////////////////////////////////////

std::string foobar::message (void) const
{
    return _message;
}

unsigned int foobar::value (void) const
{
    return _value;
}

////////////////////////////////////////////////////////////////////////////////
// Setters.
////////////////////////////////////////////////////////////////////////////////

void foobar::set_message (const std::string & message)
{
    _message = message;
    size_t first_space = _message.find_first_of (' ');
    if (first_space != std::string::npos)
        _message.erase (first_space);
}

void foobar::set_value (unsigned int value)
{
    _value = value;
}

////////////////////////////////////////////////////////////////////////////////
// Misc.
////////////////////////////////////////////////////////////////////////////////

void foobar::swap (foobar & f)
{
    std::swap (_message, f._message);
    std::swap (_value, f._value);
}

foobar & foobar::operator= (foobar f)
{
    this->swap (f);
    return * this;
}

std::ostream & foobar::write_to (std::ostream & os) const
{
    os << message () << " " << value ();
    return os;
}

std::istream & foobar::read_from (std::istream & is)
{
    unsigned int value;
    std::string message;

    is >> message >> value;
    if (! is.fail ())
    {
        foobar f (message, value);
        this->swap (f);
    }

    return is;
}


////////////////////////////////////////////////////////////////////////////////
// Friend functions.
////////////////////////////////////////////////////////////////////////////////

void swap (foobar & a, foobar & b)
{
    a.swap (b);
}

std::ostream & operator<< (std::ostream & os, const foobar & f)
{
    return f.write_to (os);
}

std::istream & operator>> (std::istream & is, foobar & f)
{
    return f.read_from (is);
}
