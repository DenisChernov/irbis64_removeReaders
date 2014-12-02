/*
 * File:   main.cpp
 * Author: demiin
 *
 * Created on November 29, 2014, 12:21 PM
 */

#include <QApplication>
#include <QtWidgets/qwidget.h>
#include "frmCheckParser.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    frmCheckParser *formParser = new frmCheckParser();
    formParser->show();

    return app.exec();
}
