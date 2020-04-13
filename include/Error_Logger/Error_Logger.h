#pragma once

/**
 * Standart headers: c++/os
 */
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

/**
 * @class RAII Class for logging errors to audit file
 * overwriting stdout to std::ofstream, restore stdout in destructor
 */
class error_log
{
private:
    /**
     * Set up pointer to stringstream for buffer
     */
    using buftype = decltype( std::cout.rdbuf() );

    /**
     * Define type of ::system_clock::now
     */
    using time_now = decltype( std::chrono::system_clock::now() );

    /**
     * offsteram object for file write
     */
    std::ofstream ofstream;

    /**
     * buffer for restore std::cout stringstream from std::cout.rdbuf();
     */
    buftype buffer;

    /**
     * Data-member for time logging of error
     */
    time_now log_time;

public:
    /**
     * @brief Parametrized class Constructor
     * @param filepath File for error logs
     */
    explicit error_log( const std::string& filepath );
    
    /**
     * @brief Default Constructor
     */
    error_log();

    /**
     * @brief Destructor
     */
    ~error_log();

    /**
     * @brief Setup log time
     * @return time in ctime format
     */
    char* to_time_t();

};
