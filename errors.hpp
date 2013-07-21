#ifndef __ERRORS__
#define __ERRORS__

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void	error501(tcp::socket& socket);

#endif	// !__ERRORS__
