#include <iostream>
#include <thread>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include "unix_socket_server.hpp"

class ExampleUI {
private:
    std::string exampleLabel;
public:
    void onCommandArrive(std::string command){
        exampleLabel = command;
        std::cout << exampleLabel << std::endl;
    }
};

int main(){
    asio::io_service io_service;
    unlink("/tmp/unix_socket_test");
    UnixSocketServer unixSocketServer1(io_service);
    unixSocketServer1.accept();
    ExampleUI exampleUI;
    unixSocketServer1.commandArriveEvent.connect(boost::bind(&ExampleUI::onCommandArrive, &exampleUI, _1));
    std::thread threadServer([&unixSocketServer1]{
        while (true){
            unixSocketServer1.read();
        }
    });
    threadServer.join();
}
