/*
 * File:   frmCheckParser.cpp
 * Author: demiin
 *
 * Created on November 29, 2014, 12:22 PM
 */

#include "frmCheckParser.h"
#include "parser.h"

frmCheckParser::frmCheckParser() {
    frmParser.setupUi(this);
    connect(frmParser.pbGetParsed, SIGNAL(clicked()), this, SLOT(slot_ParseRecord()));
    connect(frmParser.pbBegin, SIGNAL(clicked()), this, SLOT(slot_Begin()));
    connect(frmParser.pbEnd, SIGNAL(clicked()), this, SLOT(slot_End()));
    connect(frmParser.pbLeft, SIGNAL(clicked()), this, SLOT(slot_Left()));
    connect(frmParser.pbRight, SIGNAL(clicked()), this, SLOT(slot_Right()));

    
    message.print(EINFO, "current year: " + curYear());
    message.print(EINFO, "shift year: " + boost::lexical_cast<string>(shiftYear()));
    message.print(EINFO, "countRecords: " + QString::number(getCountReaders()).toStdString());
    
    emit slot_Begin();
}

size_t frmCheckParser::shiftYear() 
{
    return boost::lexical_cast<size_t>(curYear()) - SHIFT_YEAR;
}


string frmCheckParser::curYear() {
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [5];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,5,"%Y",timeinfo);
    
    return string(buffer);
}


frmCheckParser::~frmCheckParser() {

}

size_t frmCheckParser::getCountReaders() {
    f.fROpen("rdr.txt");
    string line = "";
    while (!f.atEnd())
    {
        f.readline(&line);
        if (line.find("*****") == 0)
            countRecords++;
    }
    f.fClose();
    
    return countRecords;
}

void frmCheckParser::slot_ParseRecord() {

}

vector<string> frmCheckParser::readRecord() 
{
    vector<string> record;
    
    f.fROpen("rdr.txt");
    string line;
    size_t rec = 1;
    
    if (frmParser.leRecordNumber->text().length())
    {
        while (rec != frmParser.leRecordNumber->text().toInt())
        {
            f.readline(&line);
            if (line.find("*****") == 0)
                rec++;
        }
        f.readline(&line);
        
        frmParser.leRecordNumber->clear();
    }
    else
    {
        if (curRecord != 1)
        {
            while (rec != curRecord)
            {
                f.readline(&line);
                if (line.find("*****") == 0)
                    rec++;
            }
            f.readline(&line);
        }
    }
    curRecord = rec;
    while (line.find("*****") != 0)
    {
        line[line.length()-1] = '\0';
        record.push_back(line);
        f.readline(&line);
    }
    
//    if (line.find("*****") == 0)
//        record.pop_back();
    f.fClose();
    
    return record;
}

void frmCheckParser::slot_Begin() {
    message.print(EINFO, "Начало файла");
    curRecord = 1;
    frmParser.pbBegin->setEnabled(false);
    frmParser.pbEnd->setEnabled(true);
    frmParser.pbLeft->setEnabled(false);
    frmParser.pbRight->setEnabled(true);
    
    doRecord();
}

void frmCheckParser::slot_End() {
    message.print(EINFO, "Конец файла");
    curRecord = countRecords;
    frmParser.pbBegin->setEnabled(true);
    frmParser.pbLeft->setEnabled(true);
    frmParser.pbRight->setEnabled(false);
    frmParser.pbEnd->setEnabled(false);
    
    doRecord(); 
}

void frmCheckParser::slot_Left() {
    message.print(EINFO, "Сдвиг влево. Текущая запись: " + QString::number(--curRecord).toStdString());
    if (curRecord < countRecords)
    {
        frmParser.pbRight->setEnabled(true);
        frmParser.pbEnd->setEnabled(true);
    }
    else
        frmParser.pbEnd->setEnabled(false);
    
    if (curRecord == 1)
    {
        frmParser.pbLeft->setEnabled(false);
        frmParser.pbBegin->setEnabled(false);
    }
    doRecord();   
}

void frmCheckParser::slot_Right() 
{
    message.print(EINFO, "Сдвиг вправо. Текущая запись: " + QString::number(++curRecord).toStdString());
    if (curRecord == countRecords)
    {
        frmParser.pbRight->setEnabled(false);
        frmParser.pbEnd->setEnabled(false);
    }
    else
    {
        frmParser.pbLeft->setEnabled(true);
        frmParser.pbBegin->setEnabled(true);
    }  
    
    doRecord();
}

void frmCheckParser::printRecord(vector<string> record) 
{
    parser pars;
    size_t curPos = 0;
    frmParser.lwSource->clear();
    vector<string>::const_iterator it = record.begin();
    while (it != record.end())
    {
        frmParser.lwSource->addItem(QString::fromStdString(it->data()));
        pars.needColor(it->data()) == true ? frmParser.lwSource->item(curPos)->setBackgroundColor(Qt::green) : frmParser.lwSource->item(curPos)->setBackgroundColor(Qt::white);
        it++;
        curPos++;
    }
}

void frmCheckParser::doRecord() 
{
    currentReaderData.clear();
    frmParser.lwParsed->clear();
    parser pars;
    vector<string> currentRecord = readRecord();
    map<string, string> field;
    map<string, string>::iterator fldIt;
    map<string, vector <string>>::const_iterator itFilial;
    printRecord(currentRecord);
    
    vector<string>::const_iterator it = currentRecord.begin();
    while (it != currentRecord.end())
    {
        field = pars.get_reg_rereg_visit(it->data());
        fldIt = field.begin();
        if (fldIt->first != "error")
        {
            if (fldIt->first == "#51:")
                currentReaderData.regs[pars.getFilial(fldIt->second)].push_back(fldIt->second);
            else
            if (fldIt->first == "#52:")
                currentReaderData.reregs[pars.getFilial(fldIt->second)].push_back(fldIt->second);                
            else
                currentReaderData.visits[pars.getFilial(fldIt->second)].push_back(fldIt->second);
        }   
        else
            frmParser.lwParsed->addItem(QString::fromStdString(it->data()));
        it++;
    }
    
/*    cout << "regs: " << currentReaderData.regs.size()  
         << "reregs: " << currentReaderData.reregs.size()
         << "visits: " << currentReaderData.visits.size() << endl;*/
    

/* ПереРегистрация */
    itFilial = currentReaderData.reregs.begin();
    while (itFilial != currentReaderData.reregs.end())
    {
        bool filialToDelete = true;
        vector<string>::const_iterator itSecond =  itFilial->second.begin();
        while (itSecond != itFilial->second.end())
        {
            //cout << shiftYear() << pars.getYear(itSecond->data()) << endl;
            if (shiftYear() < boost::lexical_cast<size_t>(pars.getYear(itSecond->data())))
                filialToDelete = false;
            itSecond++;
        }
        if (filialToDelete)
            filialsToDel.push_back(itFilial->first);
        itFilial++;
    }
    
/* Регистрация */
    itFilial = currentReaderData.regs.begin();
    while (itFilial != currentReaderData.regs.end())
    {
        bool filialToDelete = true;        
        vector<string>::const_iterator itSecond =  itFilial->second.begin();
        while (itSecond != itFilial->second.end())
        {
//            cout << itSecond->data() << endl;
            if (shiftYear() < boost::lexical_cast<size_t>(pars.getYear(itSecond->data())))
                filialToDelete = false;
            itSecond++;
        }
        if (filialToDelete)
        {
            if (checkIn(itFilial->first))
            {
                cout << "delete filial: " << itFilial->first << endl;
            }

        }
        
        itFilial++;
    }
    
/* Посещяемость */
    vector<string> visits;
    itFilial = currentReaderData.visits.begin();
    while (itFilial != currentReaderData.visits.end())
    {
        vector<string>::const_iterator itSecond =  itFilial->second.begin();
        while (itSecond != itFilial->second.end())
        {
            if (shiftYear() < boost::lexical_cast<size_t>(pars.getYear(itSecond->data())))
                visits.push_back(itSecond->data());
//            cout << itSecond->data() << endl;
            itSecond++;
        }
        currentReaderData.visits[itFilial->first] = visits;
        itFilial++;
    }
    
    itFilial = currentReaderData.visits.begin();
    while (itFilial != currentReaderData.visits.end())
    {
        vector<string>::const_iterator itSecond =  itFilial->second.begin();
        while (itSecond != itFilial->second.end())
        {
            //cout << itSecond->data() << endl;
            itSecond++;
        }
        itFilial++;
    }
    
    printParsedRecord();
}

bool frmCheckParser::checkIn(string filial) 
{
    vector<string>::const_iterator it = filialsToDel.begin();
    while (it != filialsToDel.end())
    {
        if (filial == it->data())
            return true;
        it++;
    }
    return false;
}

void frmCheckParser::printParsedRecord() 
{
    map<string, vector<string>>::const_iterator it;
    
    it = currentReaderData.regs.begin();
    while (it != currentReaderData.regs.end())
    {
        vector<string>::const_iterator itFilial = it->second.begin();
        while (itFilial != it->second.end())
        {
            bool toDel = false;
            vector<string>::const_iterator flsDelete = filialsToDel.begin();
            while (flsDelete != filialsToDel.end())
            {
                if (it->first == flsDelete->data())
                {
                    toDel = true;
                    break;
                }
                flsDelete++;
            }
            if (!toDel)
                frmParser.lwParsed->addItem("#51: " + QString::fromStdString(itFilial->data()));
            itFilial++;
        }
        it++;
    }
    
    it = currentReaderData.reregs.begin();
    while (it != currentReaderData.reregs.end())
    {
        vector<string>::const_iterator itFilial = it->second.begin();
        while (itFilial != it->second.end())
        {
            bool toDel = false;
            vector<string>::const_iterator flsDelete = filialsToDel.begin();
            while (flsDelete != filialsToDel.end())
            {
                if (it->first == flsDelete->data())
                {
                    toDel = true;
                    break;
                }
                flsDelete++;
            }
            if (!toDel)            
                frmParser.lwParsed->addItem("#52: " + QString::fromStdString(itFilial->data()));
            itFilial++;
        }
        it++;
    }    

    it = currentReaderData.visits.begin();
    while (it != currentReaderData.visits.end())
    {
        vector<string>::const_iterator itFilial = it->second.begin();
        while (itFilial != it->second.end())
        {
            bool toDel = false;
            vector<string>::const_iterator flsDelete = filialsToDel.begin();
            while (flsDelete != filialsToDel.end())
            {
                if (it->first == flsDelete->data())
                {
                    toDel = true;
                    break;
                }
                flsDelete++;
            }
            if (!toDel)            
                frmParser.lwParsed->addItem("#40: " + QString::fromStdString(itFilial->data()));
            itFilial++;
        }
        it++;
    }    
}