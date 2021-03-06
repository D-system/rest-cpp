#ifndef __ERRORS__
#define __ERRORS__

#include <fstream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void	response200(tcp::socket& socket, std::ifstream& file);
void	response201(tcp::socket& socket, std::string& location);
void	response204(tcp::socket& socket);
void	response400(tcp::socket& socket);
void	response404(tcp::socket& socket);
void	response405(tcp::socket& socket);
void	response500(tcp::socket& socket);
void	response501(tcp::socket& socket);

#endif	// !__ERRORS__
