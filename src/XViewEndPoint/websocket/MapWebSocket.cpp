#include "MapWebSocket.h"
#include <QDebug>

MapWebSocket::MapWebSocket(const QString &baseUrl)
    : m_baseUrl(baseUrl)
{

}

void MapWebSocket::init()
{
    connect(&m_ws, &QWebSocket::connected, this, [](){
        qDebug() << "map websocket connected";
    });

    connect(&m_ws, &QWebSocket::disconnected, this, [](){
        qDebug() << "map websocket disconnected";
    });

    connect(&m_ws, &QWebSocket::textMessageReceived, this, [](const QString &msg){
        qDebug() << "recieve text msg: " << msg;
    });

    connect(&m_ws, &QWebSocket::binaryMessageReceived, this, [](const QString &msg){
       qDebug() << "receive binary msg";
    });

    m_ws.open(m_baseUrl + "/map");
}

void MapWebSocket::requestMapData()
{

}
