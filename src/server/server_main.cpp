#include <iostream>
#include "unix_socket_server.hpp"

void on

int main(){
    asio::io_service io_service;
    unlink("/tmp/unix_socket_test");
    UnixSocketServer unixSocketServer1(io_service);
    unixSocketServer1.accept();
    while (true){
        std::string result = unixSocketServer1.read();
        std::cout << result << std::endl;
    }
}
