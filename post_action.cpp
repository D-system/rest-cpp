
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include "post_action.hpp"
#include "responses.hpp"

#define	FILE_NAME_LENGTH 64

char*	gen_random(char *s, const int len) {
  static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
  int	pid = (int)::getpid();

  for (int i = 0; i < len; ++i) {
    s[i] = alphanum[( rand() + pid ) % (sizeof(alphanum) - 1)];
  }
  s[len - 1] = 0;
  return s;
}

void		post_action(request_t& request_st, tcp::socket& socket) {
  char		file_name[FILE_NAME_LENGTH];
  std::string	path;

  if (request_st.uri_args.size() != 1) {
    response400(socket);
    return ;
  }
  path += request_st.uri_args[0];
  gen_random(file_name, FILE_NAME_LENGTH);
  path += file_name;

  std::ofstream	file( path.c_str() );

  if ( ! file.is_open() ) {
    response500(socket);
    return ;
  }
  file << request_st.content;
  file.close();
  request_st.uri += "/";
  request_st.uri += file_name;
  response201(socket, request_st.uri);
}
