/*=============================================================================
    Spirit v1.6.1
    Copyright (c) 2002-2003 Joel de Guzman
    http://spirit.sourceforge.net/

    Permission to copy, use, modify, sell and distribute this software is
    granted provided this copyright notice appears in all copies. This
    software is provided "as is" without express or implied warranty, and
    with no claim as to its suitability for any purpose.
=============================================================================*/
////////////////////////////////////////////////////////////////////////////
//
//  HTML/XML like tag matching grammar
//  { demonstrates phoenix and closures and parametric parsers ]
//
//  [ JDG 6/30/2002 ]
//
////////////////////////////////////////////////////////////////////////////
#include "boost/spirit/core.hpp"
#include "boost/spirit/attribute.hpp"
#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;
using namespace phoenix;

////////////////////////////////////////////////////////////////////////////
//
//  HTML/XML like tag matching grammar
//
////////////////////////////////////////////////////////////////////////////
struct tags_closure : boost::spirit::closure<tags_closure, string> {

    member1 tag;
};

struct tags : public grammar<tags> {

    template <typename ScannerT>
    struct definition {

        definition(tags const& /*self*/)
        {
            element = start_tag >> *element >> end_tag;

            start_tag =
                    '<'
                >>  lexeme_d
                    [
                        (+alpha_p)
                        [
                            //  construct string from arg1 and arg2 lazily
                            //  and assign to element.tag

                            element.tag = construct_<string>(arg1, arg2)
                        ]
                    ]
                >> '>';

            end_tag = "</" >> f_str_p(element.tag) >> '>';
        }

        rule<ScannerT, tags_closure::context_t> element;
        rule<ScannerT> start_tag, end_tag;

        rule<ScannerT, tags_closure::context_t> const&
        start() const { return element; }
    };
};

////////////////////////////////////////////////////////////////////////////
//
//  Main program
//
////////////////////////////////////////////////////////////////////////////
int
main()
{
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\tHTML/XML like tag matching parser demo \n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type an HTML/XML like nested tag input...or [q or Q] to quit\n\n";
    cout << "Example: <html><head></head><body></body></html>\n\n";

    tags p;    //  Our parser

    string str;
    while (getline(cin, str))
    {
        if (str[0] == 'q' || str[0] == 'Q')
            break;

        parse_info<> info = parse(str.c_str(), p, space_p);

        if (info.full)
        {
            cout << "-------------------------\n";
            cout << "Parsing succeeded\n";
            cout << "-------------------------\n";
        }
        else
        {
            cout << "-------------------------\n";
            cout << "Parsing failed\n";
            cout << "stopped at: \": " << info.stop << "\"\n";
            cout << "-------------------------\n";
        }
    }

    cout << "Bye... :-) \n\n";
    return 0;
}


