#include "mavproxyint.h"
#include "ui_mavproxyint.h"

MavProxyInt::MavProxyInt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MavProxyInt)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket;
    tcpSocketConnected = false;
}

MavProxyInt::~MavProxyInt()
{
    tcpSocket->disconnect();
    delete ui;
}

void MavProxyInt::connectToMavProxy()
{
    //Following: http://stackoverflow.com/questions/7923485/simplest-qt-tcp-client
    //Following: http://qgroundcontrol.org/dev/mavlink_linux_integration_tutorial

    //Set the ip address of Mavproxy
    QString ipAddress = "127.0.0.1";

    //Set the port number of Mavproxy
    quint16 portNum = 14551;

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    ui->mavProxyOutput->append(tr("Conecting...\n"));
    qDebug() << "Connecting...";
    tcpSocket->connectToHost(ipAddress, portNum);

    if(!tcpSocket->waitForDisconnected(1000))
    {
        ui->mavProxyOutput->append(tr("Error: ") + tcpSocket->errorString());
        qDebug() << "Error: " << tcpSocket->errorString();
    }
    tcpSocketConnected = true;
    //Winsock recv()
        //Check if a read of the socket, output to char *buffer, length, flags
        //try to recieve a packet, and see if it can be decoded


}

void MavProxyInt::connected()
{
    QString status = tr("Connected, we have gotten the connected signal\n");
    //ui->mavProxyOutput->setText(status);
    ui->mavProxyOutput->append(status);
    qDebug() << status;
    tcpSocket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void MavProxyInt::disconnected()
{
    qDebug() << "Disconnected by recieving disconnect signal";
}

void MavProxyInt::bytesWritten(qint64 bytes)
{
    QString status = tr("Bytes Writte: ");
    ui->mavProxyOutput->append(status);
    qDebug() << status<< bytes;
}

void MavProxyInt::readyRead()
{

    QString statusMsg = tr("Reading...\n");
    QByteArray mavData(tcpSocket->readAll());
    //QString mavLinkMsg(tcpSocket->readAll());
    QString mavLinkMsg(mavData);

    ui->mavProxyOutput->append(statusMsg);

    //ui->mavProxyOutput->append(mavLinkMsg + tr("\n"));

    ui->mavProxyOutput->append(mavData + tr("\n"));

    //Parse Mavlink data here

    qDebug() << statusMsg;
    qDebug() << mavLinkMsg;
    qDebug() << "This is the byteArray\n" << mavData;
}

//Source: http://stackoverflow.com/questions/20546750/qtcpsocket-reading-and-writing



void MavProxyInt::on_connectButton_clicked()
{

        QString output = tr("Connecting to Mav Proxy\n");
        connectToMavProxy();
        //ui->mavProxyOutput->setText(output);
        ui->mavProxyOutput->append(output);
        qDebug() << output;
}

void MavProxyInt::on_disconnectButton_clicked()
{
        tcpSocket->disconnect();
        QString output = tr("Disconnecting TCP port\n");
        //ui->mavProxyOutput->setText(output);
        ui->mavProxyOutput->append(output);
        qDebug() << output;
        tcpSocketConnected = false;
}

void MavProxyInt::on_closeButton_clicked()
{
    this->hide();
}
