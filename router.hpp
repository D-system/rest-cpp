#ifndef __ROUTER__
#define __ROUTER__

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include "request.hpp"

void		routing(request_t& request_st);

typedef	struct	route_s {
  char*		str;
  void		(*ptr)(request_t& request_st);
}		route_t;

#endif	// !__ROUTER__
