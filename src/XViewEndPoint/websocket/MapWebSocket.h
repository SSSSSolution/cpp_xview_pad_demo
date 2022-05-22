#ifndef MAP_WEBSOCKET_H
#define MAP_WEBSOCKET_H

#include <QObject>
#include <QWebSocket>
#include <QString>

class MapWebSocket : public QObject
{
    Q_OBJECT
public:
    MapWebSocket(const QString &baseUrl);
    void init();

    void requestMapData();

private:
    QWebSocket m_ws;
    QString m_baseUrl;
};

#endif
