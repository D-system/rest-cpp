#ifndef __PUT_ACTION__
#define __PUT_ACTION__

#include "request.hpp"

using boost::asio::ip::tcp;

void	put_action(request_t& request_st, tcp::socket& socket);

#endif	// !__PUT_ACTION__
