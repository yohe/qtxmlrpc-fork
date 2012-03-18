#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QTimer>
#include "server.h"
#include "client.h"
#include <iostream>

int main( int argc, char **argv )
{
    QCoreApplication app( argc, argv );

    QString address = "127.0.0.1";
    quint16 port = 8080;

    TServer s( address, port );
    Client c( address, port  );

    /* NB: Responses are not syncronized */

    c.paramTest( QVariant( "test" ) );
    c.paramTest( QVariant( 10 ) );
    c.paramTest( QVariant( true ) );
    c.paramTest( QVariant( 1.5 ) );

    QVariantMap m;
    QVariantList testList;
    QVariantMap test;
    test["testId"] = "example";
    test["base64Test"] = QByteArray("Params=10, Array in a struct, ");

    testList.push_back(test);
    m.insert("test", "test");
    m.insert("aaa", 1);
    m.insert("bbb", 2);
    m.insert("ccc", 3);
    m.insert("ddd", 4);
    m.insert("eee", 5);
    m.insert("fff", 6);
    m.insert("ggg", 7);
    m.insert("hhh", 8);
    m.insert("iii", 9);
    m.insert("test", testList);

    c.complexParamTest( QVariant( m ) );

    return app.exec();

}

