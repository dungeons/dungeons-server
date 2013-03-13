#ifndef SOCKET_H
#define SOCKET_H

#include "QTcpServer"
#include <QHostAddress>

class socket
{

    public:
        socket(std::string );
        std::string data read( );
        int write(std::string data);
        int accept();
        int close();
    private:
        QHostAddress *addr;
        QTcpServer *QS;
};

#endif // SOCKET_H
