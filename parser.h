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
    string closed_filials[2] = {"Ф 15", "Ф 14"};
    
    bool needColor(string line);
    map <string, string> get_reg_rereg_visit(string line);
    string getFilial(string line);
    string getYear(string line);
    string changeDiv(string line);
    bool checkIn(string line);
    bool closedFilial(string line);
    
private:

};

#endif	/* PARSER_H */

