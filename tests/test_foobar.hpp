/**
 * \file test_foobar.hpp
 * \brief Test foobar.
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
#include <string>
#include <limits>
#include <cxxtest/TestSuite.h>

#include "foobar.hpp"

/**
 * \brief Test class for \ref foobar.
 * \sa foobar
 */
class test_suite_foobar: public CxxTest::TestSuite
{
private:
    static const unsigned int _messages_length = 3;
    static const unsigned int _values_length = 4;
    std::string _messages[_messages_length];
    unsigned int _values[_values_length];

public:
    /**
     * \brief Test fixture called before each test.
     */
    void setUp (void)
    {
        std::string message_0 ("");
        std::string message_1 ("Message");
        std::string message_2 ("Message with spaces");
        _messages[0] = message_0;
        _messages[1] = message_1;
        _messages[2] = message_2;

        unsigned int value_0 = std::numeric_limits<unsigned int>::min ();
        unsigned int value_1 = value_0 + 1;
        unsigned int value_2 = std::numeric_limits<unsigned int>::max ();
        unsigned int value_3 = value_2 - 1;
        _values[0] = value_0;
        _values[1] = value_1;
        _values[2] = value_2;
        _values[3] = value_3;
    }

    /**
     * \brief Test fixture called after each test.
     */
    void tearDown (void)
    {
    }

    /**
     * \brief Test foobar::foobar(void)
     * \test foobar::foobar(void)
     */
    void test_constructor_void (void)
    {
        foobar * f;
        TS_ASSERT_THROWS_NOTHING (f = new foobar ())

        delete f;
    }

    /**
     * \brief Test foobar::foobar(const std::string &, unsigned int)
     * \test foobar::foobar(const std::string &, unsigned int)
     */
    void test_constructor_string_int (void)
    {
        foobar * f[3][4];

        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                TS_ASSERT_THROWS_NOTHING (f[i][j] = new foobar (_messages[i], _values[j]))
                delete f[i][j];
            }
    }

    /**
     * \brief Test foobar::foobar(const foobar &)
     * \test foobar::foobar(const foobar &)
     */
    void test_copy_constructor (void)
    {
        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                foobar * copy;
                foobar f (_messages[i], _values[j]);
                TS_ASSERT_THROWS_NOTHING (copy = new foobar (f))
                delete copy;
            }
    }

    /**
     * \brief Test foobar::message
     * \test foobar::message
     */
    void test_message (void)
    {
        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                foobar f (_messages[i], _values[j]);
                std::string expected (_messages[i]);
                size_t first_space = expected.find_first_of (' ');
                if (first_space != std::string::npos)
                    expected.erase (first_space);

                TS_ASSERT_EQUALS (f.message (), expected);
            }
    }

    /**
     * \brief Test foobar::value
     * \test foobar::value
     */
    void test_value (void)
    {
        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                foobar f (_messages[i], _values[j]);
                TS_ASSERT_EQUALS (f.value (), _values[j]);
            }

    }

    /**
     * \brief Test foobar::value
     * \test foobar::value
     */
    void test_set_message (void)
    {
        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                for (unsigned int k = 0; k < _messages_length; ++k)
                {
                    foobar f (_messages[i], _values[j]);
                    f.set_message(_messages[k]);
                    std::string expected (_messages[k]);
                    size_t first_space = expected.find_first_of (' ');
                    if (first_space != std::string::npos)
                        expected.erase (first_space);

                    TS_ASSERT_EQUALS (f.message (), expected);
                }
            }
    }

    /**
     * \brief Test foobar::value
     * \test foobar::value
     */
    void test_set_value (void)
    {
        for (unsigned int i = 0; i < _messages_length; ++i)
            for (unsigned int j = 0; j < _values_length; ++j)
            {
                for (unsigned int k = 0; k < _values_length; ++k)
                {
                    foobar f (_messages[i], _values[j]);
                    f.set_value(_values[k]);

                    TS_ASSERT_EQUALS (f.value (), _values[k]);
                }
            }
    }
};
