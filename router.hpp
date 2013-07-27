#ifndef __ROUTER__
#define __ROUTER__

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include "request.hpp"

using boost::asio::ip::tcp;

void		not_implemented(request_t& request_st, tcp::socket& socket);
void		routing(request_t& request_st, tcp::socket& socket);

typedef	struct	route_s {
  char*		str;
  void		(*ptr)(request_t& request_st, tcp::socket& socket);
}		route_t;

#endif	// !__ROUTER__
