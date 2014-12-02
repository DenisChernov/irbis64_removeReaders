/* 
 * File:   msgs.h
 * Author: demiin
 *
 * Created on November 30, 2013, 10:42 PM
 */

#ifndef ERRORS_H
#define	ERRORS_H

#include "colors.h"
#include <string>
#include <iostream>

using namespace std;

enum errorTypes {EFATAL    = -1,
                 ENONFATAL = -2,
                 EOK       =  0,
                 EINFO     =  1,
                };

class msgs {
public:
    msgs();
    virtual ~msgs();
    
    /*
     *  Вывод сообщения, раскрашенный вручную =)
     */
    void print(errorTypes err, string msg);
    
private:

};

#endif	/* ERRORS_H */

