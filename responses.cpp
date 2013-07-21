
#include "responses.hpp"

void	response501(tcp::socket& socket) {
  std::string message = "HTTP1/1 501 Not Implemented\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}
