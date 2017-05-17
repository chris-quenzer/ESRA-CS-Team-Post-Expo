#ifndef MAVPROXYINT_H
#define MAVPROXYINT_H

#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QObject>
#include <QDebug>
#include "mavlinkIncludes/common/mavlink.h"

namespace Ui {
class MavProxyInt;
}

class MavProxyInt : public QWidget
{
    Q_OBJECT

public:
    explicit MavProxyInt(QWidget *parent = 0);
    ~MavProxyInt();

    //Mavproxyport
    quint16 mavProxyPort = 14551;
    QString mavProxyAddress = "172.0.0.1";
    quint8 sysID = 255;
    quint8 compID = 1;

    bool silent = true;
    bool verbose = false;
    bool debug = false;
    int linkID;
    bool tcpSocketConnected;
    void connectToMavProxy();

    QTcpSocket *tcpSocket;

signals:

public slots:


    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private slots:

    void on_connectButton_clicked();
    void on_disconnectButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::MavProxyInt *ui;
    //QTcpSocket *tcpSocket;
};

#endif // MAVPROXYINT_H
