
#ifndef __REQUEST__
#define __REQUEST__

#include <vector>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

typedef struct			request_s {
  std::string			method;
  std::string			uri;
  std::string			content;
  std::vector<std::string>	uri_args;
}				request_t;


#endif	// !__REQUEST__
