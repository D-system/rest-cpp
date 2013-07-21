#include "router.hpp"
#include "get_action.hpp"
#include "responses.hpp"

route_t gl_routes[] = {
  { (char*)"GET", get_action },
  { NULL, NULL }
};

void	routing(request_t& request_st, tcp::socket& socket) {
  route_t*	routes = gl_routes;

  for (int i = 0; routes[i].str != NULL; ++i ) {
    if (routes[i].str == request_st.method) {
      (routes[i].ptr)(request_st, socket);
      return ;
    }
  }
  response501( socket );
}