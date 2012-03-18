

#include "client.h"
#include "xmlrpcclient.h"

#include <QVariantList>
#include <iostream>

Client::Client( const QString &address, quint16 port, QObject *parent )
            : QObject( parent ), address( address ), port( port )
{

}


void Client::paramTest( const QVariant &param )
{
      ready = false;
      XmlRpcClient *client = new XmlRpcClient( address, port );
      connect( client, SIGNAL( dataReady(QVariant) ), this, SLOT( paramTestResponseReceived(QVariant) ) );
      client->execute( "example.onParamTest", QVariantList() << param );

}

void Client::complexParamTest(const QVariant &param )
{
      ready = false;
      XmlRpcClient *client = new XmlRpcClient( address, port );
      connect( client, SIGNAL( dataReady(QVariant) ), this, SLOT( complexParamTestResponseReceived(QVariant) ) );
      client->execute( "example.complexParamTest", QVariantList() << param );

}

void Client::paramTestResponseReceived( const QVariant &response )
{
    std::cout << "--------example.onParamTest ResponseReceived start-----------" << std::endl;
    QMap<QString, QVariant> responseMap = response.toMap();
    QMapIterator<QString, QVariant> ite(responseMap);
    while(ite.hasNext()) {
        ite.next();
        std::cout << ite.key().toStdString() << " : " << ite.value().toString().toStdString() << std::endl;
    }
    //qDebug() << response;
    std::cout << "--------example.onParamTest ResponseReceived End-----------" << std::endl;

}

void Client::complexParamTestResponseReceived( const QVariant &response )
{
    std::cout << "--------example.complexParamTest ResponseReceived start-----------" << std::endl;
    QMap<QString, QVariant> responseMap = response.toMap();
    QMapIterator<QString, QVariant> ite(responseMap);
    while(ite.hasNext()) {
        ite.next();
        std::cout << ite.key().toStdString() << " : " << ite.value().toString().toStdString() << std::endl;
    }
    //qDebug() << response;
    std::cout << "--------example.complexParamTest ResponseReceived End-----------" << std::endl;
}


