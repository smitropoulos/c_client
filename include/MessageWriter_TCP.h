//
// Created by Stefanos Mitropoulos on 2019-05-20.
//

#ifndef TCP_CLIENT_MESSAGEWRITER_TCP_H
#define TCP_CLIENT_MESSAGEWRITER_TCP_H

#include <TCP_ConnectionHandler.h>
#include <poll.h>
#include <iostream>
#include <string>

class MessageWriter_TCP {
private:
    std::string mMessage{};
    int mSocket{};
public:
    MessageWriter_TCP():mSocket{TCP_ConnectionHandler::getInstance().getSocket()} {}
    void sendMessage(int sockfd = 0) const;
};


#endif //TCP_CLIENT_MESSAGEWRITER_TCP_H
