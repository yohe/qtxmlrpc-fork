
#include <iostream>
#include <xmlrpcserver.h>
#include <QHostAddress>

#include "server.h"

TServer::TServer( const QString &address, quint16 port, QObject *parent )
      : QObject( parent )
{
      XmlRpcServer *srv = new XmlRpcServer;
      if ( srv->listen( QHostAddress( address ), port ) ) {
          srv->registerSlot( this, SLOT( paramTestRequestReceived(QVariant) ), "example.onParamTest" );
          srv->registerSlot(this, SLOT(complexParamTestRequestReceived(QVariant)), "example.complexParamTest");
      }
}


QVariant TServer::paramTestRequestReceived( const QVariant &param )
{
    std::cout << "Server::paramTestRequestReceived start" << std::endl;
    std::cout << param.toString().toStdString() << std::endl;
    std::cout << "Server::paramTestRequestReceived end" << std::endl;
    return param;
}

QVariant TServer::complexParamTestRequestReceived(const QVariant &param) {

    std::cout << "Server::complexParamTestRequestReceived start" << std::endl;
    std::cout << "Server::complexParamTestRequestReceived end" << std::endl;
    return param;
}


TServer::~TServer()
{
    std::cout<<"Delete XML-RPC server..."<<std::endl;
}

