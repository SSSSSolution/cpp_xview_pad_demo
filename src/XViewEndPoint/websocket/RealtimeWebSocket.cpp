#include "RealtimeWebSocket.h"
#include <rapidjson/document.h>
//#include <rapidjson/
RealtimeWebSocket::RealtimeWebSocket(const QString &baseUrl)
    : m_baseUrl(baseUrl)
{

}

void RealtimeWebSocket::init()
{
    connect(&m_ws, &QWebSocket::connected, this, [=](){
        qDebug() << "realtime websocket connected";
        requestSimulationWorld();
    });

    connect(&m_ws, &QWebSocket::disconnected, this, [](){
        qDebug() << "realtime websocket disconnected";
    });

    connect(&m_ws, &QWebSocket::textMessageReceived, this, [](const QString &msg){
//        qDebug() << "realtime ws recieve text msg: " << msg;
        rapidjson::Document doc;
        doc.Parse(msg.toStdString().c_str());
        if (doc.HasParseError())
        {
            qDebug() << "parse error";
        }

        if (doc.HasMember("type") && doc["type"].IsString())
        {
            qDebug() << "msg type: " << doc["type"].GetString();
        }




    });

    connect(&m_ws, &QWebSocket::binaryMessageReceived, this, [](const QString &msg){
       qDebug() << "realtime ws receive binary msg";
    });

    m_ws.open(m_baseUrl + "/websocket");
    qDebug() << "open: " + m_baseUrl + "/websocket";
}

void RealtimeWebSocket::requestSimulationWorld()
{
    QString request = "{ \
                        \"type\": \"RequestSimulationWorld\", \
                        \"planning\": \"\"\
                      }";
    m_ws.sendTextMessage(request);
}
