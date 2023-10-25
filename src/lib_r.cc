#include "lib_r.h"

#include <boost/regex.hpp>
#include <iostream>

void replace_and_print(const std::string& str, const std::string& pattern)
{
    std::ostream_iterator<char> out(std::cout);
    boost::regex_replace(
        out,
        str.begin(),
        str.end(),
        boost::regex{pattern},
        "*",
        boost::match_default | boost::format_all);
}
