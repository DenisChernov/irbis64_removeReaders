/* 
 * File:   msgs.cpp
 * Author: demiin
 * 
 * Created on November 30, 2013, 10:42 PM
 */

#include "msgs.h"

msgs::msgs() {
}

msgs::~msgs() {
}

void msgs::print(errorTypes err, string msg)
{
    switch (err)
    {
        case EOK:
        {
            cout << txt_white;
            break;
        }
        case EFATAL:
        {
            cout << txt_red;
            break;
        }
        case EINFO:
        {
            cout << txt_b_green;
            break;
        }
        case ENONFATAL:
        {
            cout << txt_b_yellow;
            break;
        }
    }
    cout << msg << txt_end << endl;
    
}