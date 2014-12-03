/* 
 * File:   frmCheckParser.h
 * Author: demiin
 *
 * Created on November 29, 2014, 12:22 PM
 */

#ifndef _FRMCHECKPARSER_H
#define	_FRMCHECKPARSER_H

#include "ui_frmCheckParser.h"
#include "fOper.h"
#include "msgs.h"
#include <string>
#include <iostream>
#include <time.h>
#include <boost/lexical_cast.hpp>



struct reg_rereg_visits
{   
    map<string, vector <string>> regs;
    map<string, vector <string>> reregs;
    map<string, vector <string>> visits;
    
    void clear()
    {
        regs.clear();
        reregs.clear();
        visits.clear();
    }
};

class frmCheckParser : public QMainWindow {
    Q_OBJECT
public:
    frmCheckParser();
    virtual ~frmCheckParser();
    
private:
    
    Ui::frmCheckParser frmParser;
    fOper f;
    msgs message;
    size_t countRecords = 0;
    size_t curRecord = 0;
    size_t SHIFT_YEAR = 3;
    
    reg_rereg_visits currentReaderData;
    vector<string> filialsToDel;
    vector<string> newRecord;
    
    size_t getCountReaders();
    vector<string> readRecord();
    
    void printRecord(vector<string> record);
    void doRecord();
    string curYear();
    size_t shiftYear();
    bool checkIn(string filial);
    void printParsedRecord();
    void eraseDeletedFilials();
    void writeRecord();
    void autoRemakeRDR();
    
private slots:    
    void slot_ParseRecord();
    void slot_Begin();
    void slot_End();
    void slot_Left();
    void slot_Right();
};

#endif	/* _FRMCHECKPARSER_H */
