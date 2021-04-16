#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    time_t rawtime;
    struct tm * timeinfo;
    char timestamp[50] = { 0 };

    while (1)
    {
        // Get timestamped name
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(timestamp, 50, "%Y-%m-%d_%X", timeinfo);
        printf("%s\n", timestamp);
        // END

        // Create a directory with a timestamped name
        int check = mkdir(timestamp, 0777);
        // END

        // Every 40 seconds
        sleep(40);
        // END
    }

    return 0;
}
