#include "../Include.h"

int main(int argc, char* argv[])
{
    SetConsoleTitleW(L"T R I N I T Y");

    const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(handle, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handle, mode);

    fmt::print(fg(fmt::color::cornsilk) | fmt::emphasis::faint,
               R"(                                   
                                 .--.   _..._   .--.                               
                                  |__| .'     '. |__|      .-.          .-          
                      .|  .-,.--. .--..   .-.   ..--.     .|\ \        / /          
                    .' |_ |  .-. ||  ||  '   '  ||  |   .' |_\ \      / /           
                  .'     || |  | ||  ||  |   |  ||  | .'     |\ \    / /            
                 '--.  .-'| |  | ||  ||  |   |  ||  |'--.  .-' \ \  / /             
                    |  |  | |  '- |  ||  |   |  ||  |   |  |    \ `  /              
                    |  |  | |     |__||  |   |  ||__|   |  |     \  /               
                    |  '.'| |         |  |   |  |       |  '.'   / /                
                    |   / |_|         |  |   |  |       |   /|`-' /                 
                    `'-'              '--'   '--'       `'-'  '..'                  
                    is going to disable & delete Windows Defender from your system.

                    [x] Created by cpz / og
                    [!] https://github.com/cpz/trinity/
                    [!] https://git.tcp.direct/og/trinity  
    )");
    fmt::print(fg(fmt::color::cornsilk) | fmt::emphasis::faint,
               "                [?] Build at {} {}\n",
               __DATE__,
               __TIME__);
    fmt::print("\n");

    if (Remove())
        fmt::print(fg(fmt::color::cornsilk) | fmt::emphasis::faint,
                   "[V] Windows Defender was successfuly removed.\n    [V] We are recommend you to reboot after closing this app.\n");

    fmt::print(fg(fmt::color::dark_cyan) | fmt::emphasis::conceal, "\n\nPress any key to close application.");
    getchar();

    return EXIT_SUCCESS;
}
