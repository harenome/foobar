/**
 * \file foobar.hpp
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
#ifndef __FOOBAR_HPP__
#define __FOOBAR_HPP__

#include <string>
#include <istream>
#include <ostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////
// Class.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief foobar class.
 */
class foobar
{
public:
    ////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor.
    ////////////////////////////////////////////////////////////////////////////
    /**
     * \brief Constructor.
     */
    foobar (void);

    /**
     * \brief Copy constructor.
     * \param d foobar.
     */
    foobar (const foobar & f);

    /**
     * \brief Constructor.
     * \param message Message.
     * \param value Value.
     * \warning The message will be cut at the first space !
     */
    foobar (const std::string & message, unsigned int value);

    /**
     * \brief Destructor.
     */
    ~foobar (void);

    ////////////////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////////////////
    /**
     * \brief Get the message.
     * \return Message.
     */
    std::string message (void) const;

    /**
     * \brief Get the value.
     * \return value.
     */
    unsigned int value (void) const;

    ////////////////////////////////////////////////////////////////////////////
    // Setters.
    ////////////////////////////////////////////////////////////////////////////
    /**
     * \brief Set the message.
     * \param m Message.
     * \warning The message will be cut at the first space !
     */
    void set_message (const std::string & message);

    /**
     * \brief Set the value.
     * \param v Value.
     */
    void set_value (unsigned int value);

    ////////////////////////////////////////////////////////////////////////////
    // Misc.
    ////////////////////////////////////////////////////////////////////////////
    /**
     * \brief Swap with another foobar;
     * \param[in,out] f Foobar.
     */
    void swap (foobar & f);

    /**
     * \brief Operator \c =.
     * \param f Foobar.
     */
    foobar & operator= (foobar f);

    /**
     * \brief Write the foobar to an output stream.
     * \param[in,out] os Output stream.
     * \return \c os.
     */
    std::ostream & write_to (std::ostream & os) const;

    /**
     * \brief Read the foobar from an input stream.
     * \param[in,out] is Input stream.
     * \return \c is.
     */
    std::istream & read_from (std::istream & is);

private:
    std::string _message;   /**<- Message. */
    unsigned int _value;    /**<- Value. */
};

////////////////////////////////////////////////////////////////////////////////
// Friend functions.
////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Swap two foobar.
 * \param[in,out] a Foobar 1.
 * \param[in,out] b Foobar 2.
 */
void swap (foobar & a, foobar & b);

/**
 * \brief Write a foobar to an output stream.
 * \param[in,out] os Output stream.
 * \param[in] f Foobar.
 * \return \c os.
 * \relates foobar
 */
std::ostream & operator<< (std::ostream & os, const foobar & f);

/**
 * \brief Read a foobar from an input stream.
 * \param[in,out] is Input stream.
 * \param[in,out] f Foobar.
 * \return \c is.
 * \relates foobar
 */
std::istream & operator>> (std::istream & is, foobar & f);

#endif /* __FOOBAR_HPP__ */
