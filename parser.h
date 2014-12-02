/* 
 * File:   parser.h
 * Author: demiin
 *
 * Created on November 29, 2014, 1:08 PM
 */

#ifndef PARSER_H
#define	PARSER_H

#include <string>
#include <map>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

class parser {
public:
    parser();
    virtual ~parser();
    
    vector<pair<string, string>> div_to_replace;
    
    bool needColor(string line);
    map <string, string> get_reg_rereg_visit(string line);
    string getFilial(string line);
    string getYear(string line);
    string changeDiv(string line);
    
private:

};

#endif	/* PARSER_H */

