#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile qFile_Ptr("E:\\map\\office_map.yaml");
    if(!qFile_Ptr.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Open failed.");
        return -1;
    }

    QTextStream txtInput(&qFile_Ptr);
    QString lineStr;

    double dResolution;
    double dOriginX,dOriginY;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        qDebug(lineStr.toStdString().data());
        if(lineStr.contains("resolution"))
        {
            QStringList listLineStr = lineStr.split(':');

            dResolution = listLineStr.at(1).toDouble();
            qDebug(QString::number(dResolution).toStdString().data());
        }
        if(lineStr.contains("origin"))
        {
            QStringList listLineStr = lineStr.split(':');

            QStringList listOriginStr = listLineStr.at(1).split(',');
            QStringList listXStr = listOriginStr.at(0).split('[');
            dOriginX = listXStr.at(1).toDouble();
            qDebug(QString::number(dOriginX).toStdString().data());
            dOriginY = listOriginStr.at(1).toDouble();
            qDebug(QString::number(dOriginY).toStdString().data());
        }
    }


    qFile_Ptr.close();

    return a.exec();
    return 0;
}

