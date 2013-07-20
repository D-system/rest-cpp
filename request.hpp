
#ifndef __REQUEST__
#define __REQUEST__


typedef struct	request_s {
  std::string	method;
  std::string	uri;
  std::string	content;
}		request_t;


#endif	// !__REQUEST__
