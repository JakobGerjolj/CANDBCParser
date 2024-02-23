#include "canstartandprocess.h"

CANstartAndProcess::CANstartAndProcess() {
    startCAN();
    startParser();
    readAndProcessCANpodatke();
}

void CANstartAndProcess::startCAN()
{
    const QString pluginName = "socketcan";

    canDevice = QCanBus::instance()->createDevice(pluginName, "vcan0");
    if (canDevice && canDevice->connectDevice()) {
        qDebug() << "Connected to CAN bus";
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CANstartAndProcess::readAndProcessCANpodatke);
    } else {
        qDebug() << "Failed to connect to CAN bus";
    }
}

void CANstartAndProcess::readAndProcessCANpodatke()
{
    while (canDevice->framesAvailable()) {
        const QCanBusFrame frame = canDevice->readFrame();
        qDebug() << "FRAME ID";
        qDebug() << frame.frameId();
        qDebug() << "FRAME ID_OVER";
        QCanFrameProcessor::ParseResult resultFrame1 = frameProcessor.parseFrame(frame);
        qDebug() << "Signal value";
        qDebug() << resultFrame1.signalValues;
        qDebug() << "";
    }
}

void CANstartAndProcess::startParser()
{
    QString filePath = "/home/jakob/Documents/canDBC/mojDBC.dbc";
    const bool result = fileParser.parse(filePath);
    if(result){
        qDebug() << "GOOD DBC";
    } else  qDebug() << "Error:" << fileParser.errorString();
    frameProcessor.setUniqueIdDescription(QCanDbcFileParser::uniqueIdDescription());
    frameProcessor.setMessageDescriptions(fileParser.messageDescriptions());
}
