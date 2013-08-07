#ifndef __DELETE_ACTION__
#define __DELETE_ACTION__

#include "request.hpp"

using boost::asio::ip::tcp;

void	delete_action(request_t& request_st, tcp::socket& socket);

#endif	// !__DELETE_ACTION__
