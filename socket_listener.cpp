
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void	listener(boost::asio::io_service& io)
{
  tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));
  tcp::socket socket(io);
  acceptor.accept(socket);

  std::string message = "Hello World!";

  std::cout << socket.remote_endpoint();

  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

}
