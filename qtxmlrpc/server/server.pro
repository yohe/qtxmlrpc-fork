#
# Qxmlrpc Server
#
TEMPLATE = lib
CONFIG += staticlib
#sheardlib
QT = core network xml
DESTDIR = ./lib

INCLUDEPATH += ../utils/src
LIBS += -L../utils/lib
#  -lxmlrpcutilsd

CONFIG(debug, debug|release) {
OBJECTS_DIR = build/debug
MOC_DIR = build/debug
TARGET = xmlrpcserverd
}
else {
OBJECTS_DIR = build/release
MOC_DIR = build/release
TARGET = xmlrpcserver
}

include(server.pri)


