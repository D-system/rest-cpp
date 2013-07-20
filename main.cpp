
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "socket_listener.hpp"

int	main(int argc, char** argv)
{
  try {
    boost::asio::io_service io;
    listener(io);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return (0);
}
