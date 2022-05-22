cmake_minimum_required(VERSION 3.14)

project(XViewEndPoint)

set(SOURCES
    XViewEndPoint.h
    XViewEndPoint.cpp
    websocket/MapWebSocket.h
    websocket/MapWebSocket.cpp
    websocket/RealtimeWebSocket.h
    websocket/RealtimeWebSocket.cpp
)

add_library(${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::WebSockets
)


add_executable(${PROJECT_NAME}_test
    test/main.cpp
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME}_test PRIVATE
    Qt5::Core
    Qt5::WebSockets
)
