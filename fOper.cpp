/* 
 * File:   fOper.cpp
 * Author: demiin
 * 
 * Created on November 19, 2013, 10:34 PM
 */

#include <ios>
#include <QtCore/qstring.h>
#include <iomanip>
#include "fOper.h"

fOper::fOper() {
    _frID = 0;
}


fOper::~fOper() {
}

void fOper::fClose()
{
    close(_frID);
    rFile.close();
    close(_fwID);
    wFile.close();
}

bool fOper::fROpen(string filename)
{
    rFile.open(filename.c_str(), ios::in);
    if (!rFile)
    {
        perror("open");
        msg.print(EFATAL, "Could't open file " + filename);
        return false;
    }

    //msg.print(EINFO, "Opened file " + string(filename));
    return true;
}

bool fOper::fWOpen(string filename)
{
    wFile.open(filename.c_str(), ios::out);
    if (!wFile)
    {
        perror("open");
        msg.print(EFATAL, "Could't open file " + filename);
        return false;
    }

    //msg.print(EINFO, "Opened file " + string(filename));
    return true;
}

size_t fOper::readline(string* line) 
{
    getline(rFile, (*line));
    return (*line).length();
}

size_t fOper::writeLine(string line) 
{
    wFile << line << endl;
    return 0;
}


bool fOper::atEnd() 
{
    return rFile.eof();
}
