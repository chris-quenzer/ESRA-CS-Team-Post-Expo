#ifndef TCPLINK_H
#define TCPLINK_H

#include <QObject>

class TCPLink : public QObject
{
    Q_OBJECT
public:
    explicit TCPLink(QObject *parent = 0);

signals:

public slots:
};

#endif // TCPLINK_H