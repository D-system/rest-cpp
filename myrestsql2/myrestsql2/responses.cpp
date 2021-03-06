
#include "responses.hpp"

void	response200(tcp::socket& socket, std::ifstream& file) {
  std::string message = "HTTP1/1 200 Ok\r\n\r\n";
  std::string file_string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  message += file_string;
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response201(tcp::socket& socket, std::string& location) {
  std::string message = "HTTP1/1 201 Created\r\nLocation ";
  message += location;
  message += "\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response204(tcp::socket& socket) {
  std::string message = "HTTP1/1 204 No Content\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response400(tcp::socket& socket) {
  std::string message = "HTTP1/1 400 Bad Request\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response404(tcp::socket& socket) {
  std::string message = "HTTP1/1 404 Not Found\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response405(tcp::socket& socket) {
  std::string message = "HTTP1/1 405 Method Not Allowed\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response500(tcp::socket& socket) {
  std::string message = "HTTP1/1 500 Internal Server Error\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

void	response501(tcp::socket& socket) {
  std::string message = "HTTP1/1 501 Not Implemented\r\n\r\n";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
}

