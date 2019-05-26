//
// Created by Stefanos Mitropoulos on 2019-05-20.
//

#include <iostream>
#include "TCP_ConnectionHandler.h"

void TCP_ConnectionHandler::Connect() {
    {
        struct hostent *he;
        struct sockaddr_in their_addr{}; /* connector's address information */

        if ((he=gethostbyname(mHost.c_str())) == nullptr) {  /* get the host info */
            spdlog::error("gethostbyname");
        }

        if ((mSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            spdlog::error("socket");
            exit(1);
        }

        their_addr.sin_family = AF_INET;      /* host byte order */
        their_addr.sin_port = htons(mPort);    /* short, network byte order */ //NOLINT
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        bzero(&(their_addr.sin_zero), 8);     /* zero the rest of the struct */

        if (connect(mSocket, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
            spdlog::error("connect");
            exit(1);
        }
}

}


