#include "router.hpp"
#include "get_action.hpp"
#include "errors.hpp"

route_t gl_routes[] = {
  { (char*)"GET", get_action },
  { NULL, NULL }
};

void	routing(request_t& request_st) {
  route_t*	routes = gl_routes;

  for (int i = 0; routes[i].str != NULL; ++i ) {
    if (routes[i].str == request_st.method) {
      (routes[i].ptr)(request_st);
      return ;
    }
  }
  error501( *(request_st.socket) );
}
