#
# Qxmlrpc Client
#
TEMPLATE = lib
CONFIG += staticlib
#sharedlib
QT = core network xml
DESTDIR = ./lib

#DEFINES += QT_NO_OPENSSL
INCLUDEPATH += ../utils/src
LIBS += -L../utils/lib
# -lxmlrpcutilsd

CONFIG(debug, debug|release) {
OBJECTS_DIR = build/debug
MOC_DIR = build/debug
TARGET = xmlrpcclientd
}
else {
OBJECTS_DIR = build/release
MOC_DIR = build/release
TARGET = xmlrpcclient
}


include(client.pri)



