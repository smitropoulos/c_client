#include "TCP_ConnectionHandler.h"
#include "MessageWriter_TCP.h"

int main(){
    TCP_ConnectionHandler::getInstance().setup("localhost", 8081);
    TCP_ConnectionHandler::getInstance().Connect();
    MessageWriter_TCP msg;
    msg.sendMessage();
}

