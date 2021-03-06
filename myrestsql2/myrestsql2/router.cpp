
#include <boost/algorithm/string.hpp>
#include <string>
#include "router.hpp"
#include "get_action.hpp"
#include "post_action.hpp"
#include "delete_action.hpp"
#include "put_action.hpp"
#include "responses.hpp"

route_t gl_routes[] = {
  { (char*)"DELETE", delete_action },
  { (char*)"POST", post_action },
  { (char*)"GET", get_action },
  { (char*)"PUT",  put_action },
  { (char*)"PATCH", not_implemented },
  { NULL, NULL }
};

void	not_implemented(request_t& request_st, tcp::socket& socket) {
  response501( socket );
}

void	routing(request_t& request_st, tcp::socket& socket) {
  route_t*	routes = gl_routes;
  std::string	method = boost::to_upper_copy(request_st.method);

  for (int i = 0; routes[i].str != NULL; ++i ) {
    if (routes[i].str == method) {
      (routes[i].ptr)(request_st, socket);
      return ;
    }
  }
  response405( socket );
}
