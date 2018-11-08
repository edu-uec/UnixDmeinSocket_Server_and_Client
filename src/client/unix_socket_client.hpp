#ifndef UNIX_SOCKET_CLIENT_HPP
#define UNIX_SOCKET_CLIENT_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

namespace asio = boost::asio;
using asio::local::stream_protocol;

class UnixSocketClient
{
  private:
    asio::io_service &io_service_;
    stream_protocol::socket socket_;
    boost::system::error_code error;

  public:
    UnixSocketClient(asio::io_service &io_service)
        : io_service_(io_service),
          socket_(io_service)
    {
    }
    void connect()
    {
        socket_.connect(stream_protocol::endpoint("/tmp/unix_socket_test"));
    }
    void write(std::string msg1)
    {
        const std::string msg = msg1 + "!";
        boost::system::error_code error;
        asio::write(socket_, asio::buffer(msg), error);

        if (error) {
            std::cout << "send failed: " << error.message() << std::endl;
        }
        else {
            std::cout << "send correct!" << std::endl;
        }
    }
};

#endif
