/* 
 * File:   fOper.h
 * Author: demiin
 *
 * Created on November 19, 2013, 10:34 PM
 */

#ifndef FOPER_H
#define	FOPER_H

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include "msgs.h"

using namespace std;

class fOper {
public:
    fOper();
    virtual ~fOper();
    
    /*
     *  Закрытие файла
     */
    void fClose();
    
    /*
     *  Открыть файл на чтение.
     *  Возвращает true в случае успеха
     */
    bool fROpen(string filename);
    
    /*
     *  Открыть на запись
     * 
     */
    bool fWOpen(string filename);
    
    /*
     *  Читает строку и помещает ее по указателю в line.
     *  ВОзвращает количество прочтенных символов
     */
    size_t readline(string *line);

    /*
     *  Записывает строку.
     *  Возвращает количество записанных символов
     */
    size_t writeLine(string *line);
    
    /*
     *  Конец файла?
     */
    bool atEnd();
    
private:
    int _frID;
    int _fwID;
    msgs msg;
    ofstream wFile;
    ifstream rFile;
};

#endif	/* FOPER_H */

