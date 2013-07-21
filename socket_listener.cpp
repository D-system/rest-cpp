
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include "client_handler.hpp"

using boost::asio::ip::tcp;

void	listener(boost::asio::io_service& io)
{
  tcp::acceptor	acceptor(io, tcp::endpoint(tcp::v4(), 8080));
  tcp::socket	socket(io);

  while (1) {
    acceptor.accept(socket);
    handle_client(socket);
  }
}
