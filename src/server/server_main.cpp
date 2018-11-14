#include <iostream>
#include <thread>
#include "unix_socket_server.hpp"

int main(){
    asio::io_service io_service;
    unlink("/tmp/unix_socket_test");
    UnixSocketServer unixSocketServer1(io_service);
    unixSocketServer1.accept();
    std::thread threadServer([&unixSocketServer1]{
        while (true){
            unixSocketServer1.read();
        }
    });
    threadServer.join();
}
