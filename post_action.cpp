
#include "post_action.hpp"
#include "responses.hpp"

void	post_action(request_t& request_st, tcp::socket& socket) {
  std::cout << ">>> post_action <<<" << std::endl;
  response501(socket);
}
