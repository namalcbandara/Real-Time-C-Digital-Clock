#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main() {
    time_t s;
    struct tm* current_time;

    while (1) {
        s = time(NULL);
        current_time = localtime(&s);

        printf("\033[2J\033[H");

        printf("\033[1;36m==========================\n\033[0m");
        printf("\033[1;33m      DIGITAL CLOCK       \n\033[0m");
        printf("\033[1;36m==========================\n\033[0m");
        printf("\033[1;32m         %02d:%02d:%02d\n\033[0m",
               current_time->tm_hour,
               current_time->tm_min,
               current_time->tm_sec);
        printf("\033[1;36m==========================\n\033[0m");

        fflush(stdout);

        #ifdef _WIN32
        Sleep(1000);
        #else
        sleep(1);
        #endif
    }

    return 0;
}
