//
// Created by Stefanos Mitropoulos on 2019-05-20.
//

#ifndef TCP_CLIENT_TCP_CONNECTIONHANDLER_H
#define TCP_CLIENT_TCP_CONNECTIONHANDLER_H

#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <strings.h>
#include <spdlog/spdlog.h>


class TCP_ConnectionHandler {
private:
    TCP_ConnectionHandler() = default;
    int mSocket{};
    int mPort{8080};
    std::string mHost{};
    bool init{};
public:
    static TCP_ConnectionHandler& getInstance() {
        static TCP_ConnectionHandler xInstance;
        return xInstance;
    }

    void setup(const std::string &host, unsigned int port) {
        this->mPort = port;
        this->mHost = host;
        init = true;
    }

    void Connect();

    int getSocket() const {
        return mSocket;
    }

};


#endif //TCP_CLIENT_TCP_CONNECTIONHANDLER_H
