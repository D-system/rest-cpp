
#ifndef __REQUEST__
#define __REQUEST__

#include <vector>


typedef struct	request_s {
  std::string			method;
  std::string			uri;
  std::string			content;
  std::vector<std::string>	uri_args;
}		request_t;


#endif	// !__REQUEST__
