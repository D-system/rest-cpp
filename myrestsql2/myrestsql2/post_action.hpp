#ifndef __POST_ACTION__
#define __POST_ACTION__

#include "request.hpp"

using boost::asio::ip::tcp;

void	post_action(request_t& request_st, tcp::socket& socket);

#endif	// !__POST_ACTION__
