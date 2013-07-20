
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>

using boost::asio::ip::tcp;

#define BUFFER_SIZE (8192)

void	get_request(tcp::socket &socket, std::string &request) {
  boost::array<char, BUFFER_SIZE> buffer;
  int size;

  size = socket.read_some(boost::asio::buffer(buffer));
  std::copy(buffer.begin(), buffer.begin() + size, std::back_inserter(request));
}

bool	parse_request_string(const std::string& str, request_t& request) {
  boost::regex pattern_method_uri("^([A-Za-z]+)[ \t]+([\\S]+)");
  boost::regex pattern_content("^([^\r\n]+\r\n)*\r\n(.*)$");
  boost::smatch result;

  if ( ! boost::regex_search(str, result, pattern_method_uri) )
    return (false);
  request.method = result[1];
  request.uri = result[2];

  if ( boost::regex_search(str, result, pattern_content) )
    request.content = result[ result.size() - 1 ];
  return (true);
}


    // for (unsigned int i=0; i < result.size(); i++) {
    //   std::cout << "RESULT " << i << " >>" << result[i] << "<<" << std::endl;
    // }

void	listener(boost::asio::io_service& io)
{
  std::string	request;
  tcp::acceptor	acceptor(io, tcp::endpoint(tcp::v4(), 8080));
  tcp::socket	socket(io);
  request_t	request_st;

  acceptor.accept(socket);
  get_request(socket, request);
  parse_request_string(request, request_st);

  // std::cout << request;
  // std::cout << socket.remote_endpoint();

  std::string message = "Hello World!";
  boost::system::error_code ignored_error;
  boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

}
