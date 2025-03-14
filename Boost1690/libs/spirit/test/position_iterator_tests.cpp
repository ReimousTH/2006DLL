/*=============================================================================
    Spirit v1.6.1
    Copyright (c) 2003 Giovanni Bajo
    http://spirit.sourceforge.net/

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
=============================================================================*/

#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <boost/config.hpp>
#include <boost/concept_check.hpp>

// JDG 4-15-03 Borland: must include basics.hpp before MPL
#include <boost/spirit/core/basics.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/for_each.hpp>

// Our baby
#include <boost/spirit/iterator/position_iterator.hpp>

#if !(BOOST_WORKAROUND(BOOST_MSVC, < 1300) && defined(BOOST_DINKUMWARE_STDLIB))
#  define MSVC6_STDLIB
#endif

using namespace std;
using namespace boost::spirit;
namespace mpl = boost::mpl;

///////////////////////////////////////////////////////////////////////////////
namespace test_impl {

template <typename IterT>
void InstanciateTestOne(void)
{
    IterT();

    // Check that the iterator is a full non-mutable forward iterator
    typedef boost::ForwardIteratorConcept<IterT> concept_t;
    boost::function_requires<concept_t>();
}

struct InstanciateTest
{
    template <typename BaseIterT>
    void operator()(BaseIterT )
    {
        InstanciateTestOne<position_iterator<BaseIterT> >();
    }
};

///////////////////////////////////////////////////////////////////////////////
} /* namespace test_impl */

// These tests are defined after main() to be absolutely sure that the
//  instantiation test will happen before any other (since it's mainly
//  a compile-time test).
void CheckInstantiation(void);
void CheckConstructors(void);
void CheckBasicFunctionality(void);
void CheckColumnCounting(void);

void CheckInstantiation(void)
{
    typedef mpl::list
    <
        char*
        ,const char*
        ,string::iterator
        ,string::const_iterator

        // MSVC6 standard library is so broken you cannot use ANY iterator on it
        // (std::vector would be an exception because the iterator type is actually
        //  a pointer to the value_type)
#ifdef MSVC6_STDLIB
        ,vector<short>::iterator
        ,vector<long>::const_iterator
        ,list<float>::iterator
        ,list<double>::const_iterator
#endif
    > iter_list_t;

    mpl::for_each<iter_list_t>(test_impl::InstanciateTest());
}

int main(void)
{
    CheckInstantiation();
    CheckConstructors();
    CheckBasicFunctionality();
    CheckColumnCounting();

    cout << "Test completed successfully" << endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
namespace test_impl {

template <typename IterT>
void CheckIncrement(IterT iter)
{
    IterT end;

    // Check also that copy construction and assignment do not
    //  interfere with increment
    IterT iter2(iter);
    IterT iter3 = iter;

    assert(iter != end);
    assert(iter2 != end);
    assert(iter3 != end);
    assert(*iter == '0');

    ++iter;
    ++iter2;
    ++iter3;
    assert(iter == iter2);
    assert(iter == iter3);
    assert(*iter == *iter2);
    assert(*iter == *iter3);
    assert(iter.get_position() == iter2.get_position());
    assert(iter.get_position() == iter3.get_position());
    assert(*iter == '1');

    assert(*iter++ == '1');
    assert(*iter2++ == '1');
    assert(*iter3++ == '1');
    assert(*iter == *iter2);
    assert(*iter == *iter3);
    assert(iter.get_position() == iter2.get_position());
    assert(iter.get_position() == iter3.get_position());
    assert(*iter == '2');

    ++iter; ++iter; ++iter; ++iter; ++iter; ++iter; ++iter;
    assert(*iter == '9');
    ++iter;
    assert(iter == end);

    // Check that one after end is no more end
    ++iter;
    assert(iter != end);
}

template <typename IterT>
void CheckLineCounting(IterT iter)
{
    IterT end;

    assert(*iter == '\n' || *iter == '\r');
    assert(iter.get_position().line == 1);
    ++iter; // 0
    assert(iter.get_position().line == 2);
    ++iter; // 1
    ++iter; // 2
    ++iter; // 3
    ++iter; // newline
    assert(*iter == '\n' || *iter == '\r');
    ++iter; // 4
    assert(iter.get_position().line == 3);
    ++iter; // 5
    ++iter; // 6
    ++iter; // 7
    ++iter; // newline
    assert(*iter == '\n' || *iter == '\r');
    ++iter; // 8
    assert(iter.get_position().line == 4);
    ++iter; // 9
    ++iter; // newline
    assert(*iter == '\n' || *iter == '\r');
    ++iter; // end
    assert(iter == end);
}

template <typename IterT>
void CheckColumnCounting_Tab4(IterT iter)
{
    IterT end;

    // Don't call set_tabchars() here because
    //  default must be 3.
    assert(*iter == '\t');
    assert(iter.get_position().column == 1);
    ++iter; // 0
    assert(iter.get_position().column == 5);
    ++iter; // 1
    assert(iter.get_position().column == 6);
    ++iter; // 2
    assert(iter.get_position().column == 7);
    ++iter; // 3
    assert(iter.get_position().column == 8);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 9);
    ++iter; // 4
    assert(iter.get_position().column == 13);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 14);
    ++iter; // 5
    assert(iter.get_position().column == 17);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 18);
    ++iter; // end
    assert(iter == end);
}

template <typename IterT>
void CheckColumnCounting_Tab3(IterT iter)
{
    IterT end;

    iter.set_tabchars(3);

    // Check also that tab settings propagates through
    //  assignment and copy construction
    IterT iter2(iter);
    IterT iter3; iter3 = iter2;

    assert(*iter == '\t');
    assert(iter.get_position().column == 1);
    ++iter; // 0
    ++iter2; ++iter3;
    assert(iter.get_position().column == 4);
    assert(iter2.get_position().column == 4);
    assert(iter3.get_position().column == 4);
    ++iter; // 1
    assert(iter.get_position().column == 5);
    ++iter; // 2
    assert(iter.get_position().column == 6);
    ++iter; // 3
    assert(iter.get_position().column == 7);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 8);
    ++iter; // 4
    assert(iter.get_position().column == 10);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 11);
    ++iter; // 5
    assert(iter.get_position().column == 13);
    ++iter; // tab
    assert(*iter == '\t');
    assert(iter.get_position().column == 14);
    ++iter; // end
    assert(iter == end);
}

const string line1 = "abcd";
const string line2 = "efgh";
const string linebuf = "\n" + line1 + "\n" + line2 + "\n";

template <typename IterT>
void AssertIterString(IterT begin, IterT end, string s)
{
#ifndef MSVC6_STDLIB
    assert(string(begin, end) == s);
#else
    string::iterator sbegin = s.begin(), send = s.end();

    while (begin != end)
    {
        assert(*begin == *sbegin);
        assert(sbegin != send);
        ++begin;
        ++sbegin;
    }
#endif
}

template <typename IterT>
void CheckEmptySequence(void)
{
    typedef IterT iter_t;
    char a[10];

    // Check construction with empty sequence, and
    //  correct propagation of the information
    iter_t iter(a,a, "");
    iter_t iter2(iter);
    iter_t iter3; iter3 = iter;

    assert(iter == iter_t());
    assert(iter2 == iter_t());
    assert(iter3 == iter_t());
}

template <typename IterC>
void CheckConstructors(void)
{
    char a[20];
    std::string name = "abc";

    file_position posc(name,1,1);
    typedef IterC iterc_t;

    assert(iterc_t(a,a+20,name).get_position() == posc);
    assert(iterc_t(a,a+20,name,1).get_position() == posc);
    assert(iterc_t(a,a+20,name,1,1).get_position() == posc);
    assert(iterc_t(a,a+20,posc).get_position() == posc);

    // Check copy constructor and assignment. Notice that we want
    //  an implicit copy constructor.
    iterc_t ic1(a,a+20,name);
    iterc_t ic2 = ic1;
    iterc_t ic3; ic3 = ic1;
    assert(ic1 == ic2);
    assert(ic1 == ic3);
    assert(ic1.get_position() == ic2.get_position());
    assert(ic1.get_position() == ic3.get_position());

    // Check construction with an empty sequence
    CheckEmptySequence<iterc_t>();
}


///////////////////////////////////////////////////////////////////////////////
} /* namespace test_impl */


void CheckConstructors(void)
{
    test_impl::CheckConstructors
    <
        position_iterator<char*, file_position>
    >();
}

void CheckBasicFunctionality(void)
{
    const char* a = "0123456789";
    typedef const char* iter_t;

    test_impl::CheckIncrement(position_iterator<iter_t>(a, a+10, ""));

    const char* b = "\n0123\r\n4567\n89\n\r";

    test_impl::CheckLineCounting(position_iterator<iter_t>(b, b+15, ""));
}


void CheckColumnCounting(void)
{
    const char* a = "\t0123\t4\t5\t";
    typedef const char* iter_t;

    test_impl::CheckColumnCounting_Tab4(position_iterator<iter_t>(a, a+10, ""));
    test_impl::CheckColumnCounting_Tab3(position_iterator<iter_t>(a, a+10, ""));
}

