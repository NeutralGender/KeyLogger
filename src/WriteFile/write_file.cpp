#include "../../include/WriteFile/write_file.h"

write_file::write_file() : out ( "log/keylogger_default.txt", 
                                 std::ios_base::out | 
                                 std::ios_base::app | 
                                 std::ios_base::binary )
{}

write_file::write_file( const std::string& filename )
                      : out ( filename, std::ios_base::out | 
                                        std::ios_base::app | 
                                        std::ios_base::binary )
{}

write_file::~write_file()
{ out.close(); }

void write_file::write( const std::wstring& str_to_file )
{
    std::string s{ &str_to_file[0], &str_to_file[ wcslen( str_to_file.data() ) ] };
    out << s;
} 