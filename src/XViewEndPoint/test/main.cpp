#include "../websocket/RealtimeWebSocket.h"
#include "../websocket/MapWebSocket.h"
#include <QCoreApplication>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    RealtimeWebSocket realtimeWS("ws://127.0.0.1:8888");
    realtimeWS.init();

//    MapWebSocket mapWS("ws://127.0.0.1:8888");
//    mapWS.init();

    return app.exec();
}
