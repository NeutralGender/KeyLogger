#include "../../Include/Error_Logger/Error_Logger.h"

error_log::error_log( const std::string& filepath )
                    : ofstream{ filepath, std::ios_base::app }, 
                      buffer{ std::cout.rdbuf( ofstream.rdbuf() ) }
{ log_time = std::chrono::system_clock::now(); }

error_log::error_log() : ofstream{}, 
                         buffer{ std::cout.rdbuf( ofstream.rdbuf() ) }
{ log_time = std::chrono::system_clock::now(); }

error_log::~error_log()
{ std::cout.rdbuf( buffer ); }

char* error_log::to_time_t()
{
  std::time_t end_time = std::chrono::system_clock::to_time_t(log_time);
  return ( std::ctime(&end_time) );
}