#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Newspaper newspaper("Newspaper A");
    Reader reader;
    void (Newspaper::*newPaperNameDate)(const QString &,const QDate &)=&Newspaper::newPaper;
    QObject::connect(&newspaper, newPaperNameDate,
                     &reader,    &Reader::receiveNewspaper);
//    QObject::connect(&newspaper,
//                     static_cast<void (Newspaper:: *)(const QString &, const QDate &)>(&Newspaper::newPaper),
//                     &reader,
//                     &Reader::receiveNewspaper);
    newspaper.send();

    return app.exec();
}
