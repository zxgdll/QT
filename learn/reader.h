#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}

    void receiveNewspaper(const QString & name,const QDate &date=QDate::currentDate())
    {
        qDebug() << "Receives Newspaper: " << name<<date;
    }
};
