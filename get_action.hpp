#ifndef __GET_ACTION__
#define __GET_ACTION__

#include "request.hpp"

using boost::asio::ip::tcp;

void	get_action(request_t& request_st, tcp::socket& socket);

#endif	// !__GET_ACTION__
