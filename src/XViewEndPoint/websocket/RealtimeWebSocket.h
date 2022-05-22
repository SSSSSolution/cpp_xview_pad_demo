#ifndef REALTIME_WEBSOCKET_H
#define REALTIME_WEBSOCKET_H

#include <QObject>
#include <QWebSocket>

class RealtimeWebSocket : public QObject
{
    Q_OBJECT
public:
    RealtimeWebSocket(const QString &baseUrl);
    void init();

    void requestSimulationWorld();

private:
    QWebSocket m_ws;
    QString m_baseUrl;
};

#endif
