#ifndef __ERRORS__
#define __ERRORS__

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void	response501(tcp::socket& socket);

#endif	// !__ERRORS__
