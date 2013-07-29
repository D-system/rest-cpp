#ifndef __CLIENT_HANDLER__
#define __CLIENT_HANDLER__

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include "request.hpp"

using boost::asio::ip::tcp;

#define BUFFER_SIZE (8192)

void	get_request_from_socket(tcp::socket &socket, std::string &request);
bool	parse_request_string(const std::string& str, request_t& request);
void	handle_client(tcp::socket& socket);

#endif	// !__CLIENT_HANDLER__
