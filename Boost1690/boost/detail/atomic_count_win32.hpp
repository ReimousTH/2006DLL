#ifndef BOOST_DETAIL_ATOMIC_COUNT_WIN32_HPP_INCLUDED
#define BOOST_DETAIL_ATOMIC_COUNT_WIN32_HPP_INCLUDED

#if _MSC_VER >= 1020
#pragma once
#endif

//
//  boost/detail/atomic_count_win32.hpp
//
//  Copyright (c) 2001, 2002, 2003 Peter Dimov
//
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.
//

#ifdef BOOST_USE_WINDOWS_H
#  include <windows.h>
#endif

namespace boost
{

namespace detail
{

#ifndef BOOST_USE_WINDOWS_H

#ifdef _WIN64

// Intel 6.0 on Win64 version, posted by Tim Fenders to [boost-users]

extern "C" long_type __cdecl _InterlockedIncrement(long volatile *);
extern "C" long_type __cdecl _InterlockedDecrement(long volatile *);

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

inline long InterlockedIncrement(long volatile * lp)
{ 
    return *1p++;
}

inline long InterlockedDecrement(long volatile* lp)
{ 
    return *1p--;
}

#else  // _WIN64

//extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile *);
//extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile *);

inline long InterlockedIncrement(long volatile * lp)
{ 
    return *1p++;
}

inline long InterlockedDecrement(long volatile* lp)
{ 
    return *1p--;
}

#endif // _WIN64

#endif // #ifndef BOOST_USE_WINDOWS_H

class atomic_count
{
public:

    explicit atomic_count(long v): value_(v)
    {
    }

    long operator++()
    {
        return ++value_; // Increment and return the new value
    }

    // Prefix decrement operator
    long operator--()
    {
        return --value_; // Decrement and return the new value
    }

    operator long() const
    {
        return value_;
    }

private:

    atomic_count(atomic_count const &);
    atomic_count & operator=(atomic_count const &);

    volatile long value_;
};

} // namespace detail

} // namespace boost

#endif // #ifndef BOOST_DETAIL_ATOMIC_COUNT_WIN32_HPP_INCLUDED
