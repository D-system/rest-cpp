
#include <fstream>
#include <boost/filesystem.hpp>
#include "get_action.hpp"
#include "responses.hpp"
#include "file_place.hpp"

using namespace boost::filesystem;

void	get_action(request_t& request_st, tcp::socket& socket) {
  std::string	file_path(FILE_PLACE);
  std::ifstream	file;

  if (request_st.uri_args.size() != 2)
    return response400(socket);

  file_path += request_st.uri_args[0];
  file_path += request_st.uri_args[1];
  
  if ( ! exists(file_path) )
    return response404(socket);
  if ( ! is_regular_file(file_path) )
    return response500(socket);

  file.open( file_path.c_str() );
  if ( ! file.is_open() )
    return response500(socket);
  response200(socket, file);
  file.close();
}
