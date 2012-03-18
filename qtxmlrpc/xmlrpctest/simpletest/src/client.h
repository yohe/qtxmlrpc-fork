#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QVariant>


class Client : QObject
{
      Q_OBJECT

public:
      Client( const QString &address, quint16 port, QObject *parent = 0 );

      void paramTest( const QVariant &param );
      void complexParamTest( const QVariant &param);
      //QVariant operator()(const QVariant &param);
private slots:
      void paramTestResponseReceived( const QVariant &response );
      void complexParamTestResponseReceived( const QVariant &response );

private:
      QString address;
      quint16 port;

      bool ready;
      QVariant res;

};

#endif // CLIENT_H
