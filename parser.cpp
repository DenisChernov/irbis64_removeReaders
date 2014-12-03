/* 
 * File:   parser.cpp
 * Author: demiin
 * 
 * Created on November 29, 2014, 1:08 PM
 */

#include "parser.h"

parser::parser() 
{
    div_to_replace.push_back(make_pair("Ф 1 ИЗ", "Ф 1 ИО"));
    div_to_replace.push_back(make_pair("Ф 25 ИК", "Ф 25 ИО"));
//    div_to_replace.push_back(make_pair("Ф 1 ИЗ", "Ф 1 ИО"));
//    div_to_replace.push_back(make_pair("Ф 1 ИЗ", "Ф 1 ИО"));
}

parser::~parser() {
}

bool parser::needColor(string line) 
{
    boost::regex re("(#51:|#52:|#40:).*");
    boost::smatch result;
    boost::regex_match(line, result, re);
    if (result[1] != "")
        return true;
    else
        return false;
}

map <string,string> parser::get_reg_rereg_visit(string line) 
{
    map<string, string> res;
    boost::regex re("(#51:|#52:|#40:)(.*)");
    boost::smatch result;
    boost::regex_match(line, result, re);
    if (result[1] != "")
        res[result[1]] = result[2];
    else
        res["error"] = "error";
    
    return res;
}

string parser::getFilial(string line) 
{
    string filial;
    
    boost::regex re_r(".*\\^[Vv]([ФЗЧСЛКЦГБАОДИ\\s0-9]*).*");
    boost::smatch result;
    boost::regex_match(line, result, re_r);
    if (result[1] != "")
    {
        if (result[1] == "Ф 2")
            filial = "Ф 2 ИО";
        else
        if (result[1] == "Ф 24")
            filial = "Ф 24 ИО";
        else
        if (result[1] == "Ф 7")
            filial = "Ф 7 ИО";
        else
            filial = changeDiv(result[1]);
    
        return filial;
    }
    else
    {
        boost::regex re_v(".*\\^[Cc]([ФЗСЛКЧЦГБАОДИ\\s0-9]*).*");
        boost::regex_match(line, result, re_v);
        if (result[1] != "")
        {
            if (result[1] == "Ф 2")
                filial = "Ф 2 ИО";
            else
            if (result[1] == "Ф 24")
                filial = "Ф 24 ИО";
            else
            if (result[1] == "Ф 7")
                filial = "Ф 7 ИО";
            else
                filial = changeDiv(result[1]);
            
            return filial;
        }
    }
    
    return "error";
}

string parser::getYear(string line) 
{
    boost::regex re(".*\\^[Dd](\\d{4}).*");
    boost::smatch result;
    boost::regex_match(line, result, re);
    if (result[1] != "")
        return string(result[1]);
    else
        return "0";
}

string parser::changeDiv(string line) 
{
    vector<pair<string, string>>::const_iterator it = div_to_replace.begin();
    while (it != div_to_replace.end())
    {
        boost::ireplace_all(line, it->first, it->second);
        it++;
    }
    return line;
}

bool parser::checkIn(string line) 
{
    boost::regex re("(#51:|#52:|#40:|#10:|#11:|#12:|#21:|#50:|#67:|#16:|#19:|#20:|#1006:|#691:|#33:|#31:|#1005:|#1007:|#920:|#907:|#30:|#3001:).*");
    boost::smatch result;
    boost::regex_match(line, result, re);
    if (result[1] != "")
        return true;
    
    return false;
}

bool parser::closedFilial(string line) 
{
    for (size_t i = 0; i < sizeof(closed_filials) / sizeof(*closed_filials); i++)
    {
        boost::regex re(".*(" + closed_filials[i] + ").*");
        boost::smatch result;
        boost::regex_match(line, result, re);
        if (result[1] != "")
            return true;
    }
    return false;
}
