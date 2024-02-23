#ifndef CANSTARTANDPROCESS_H
#define CANSTARTANDPROCESS_H
#include <QDebug>
#include <QtEndian>
#include <QCanDbcFileParser>
#include <QCanFrameProcessor>
#include <QCanUniqueIdDescription>
#include <QCanMessageDescription>
#include <QCanMessageDescription>
#include <QObject>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QStringListModel>
#include <QCanDbcFileParser>
#include <QCanBusDevice>



class CANstartAndProcess : public QObject
{
    Q_OBJECT
public:
    CANstartAndProcess();
    QCanDbcFileParser fileParser;
    QCanFrameProcessor frameProcessor;
private:
    QCanBusDevice *canDevice;
    void startCAN();
    void readAndProcessCANpodatke();
    void startParser();
};

#endif // CANSTARTANDPROCESS_H
