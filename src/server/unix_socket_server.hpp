#ifndef UNIX_SOCKET_SERVER_HPP
#define UNIX_SOCKET_SERVER_HPP

#include <boost/asio.hpp>
#include <iostream>

namespace asio = boost::asio;
using asio::local::stream_protocol;

class UnixSocketServer
{
  private:
    asio::io_service &io_service_;
    stream_protocol::socket socket_;
    stream_protocol::acceptor acceptor_;
    asio::streambuf receive_buff_;
    boost::system::error_code error;

  public:
    UnixSocketServer(asio::io_service &io_service)
        : io_service_(io_service),
          socket_(io_service),
          acceptor_(io_service, stream_protocol::endpoint("/tmp/unix_socket_test"))
    {
    }
    void accept()
    {
        acceptor_.accept(socket_);
    }
    void read()
    {
        if (asio::read_until(socket_, receive_buff_, '!', error))
        {

            if (error && error != asio::error::eof)
            {
                std::cout << "receive failed: " << error.message() << std::endl;
            }
            else
            {
                const char *data = asio::buffer_cast<const char *>(receive_buff_.data());
                std::cout << data << std::endl;
            }
            receive_buff_.consume(receive_buff_.size());
        }
    }
};

#endif