#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    time_t rawtime;
    struct tm *timeinfo;
    char timestamp[50] = {0};
    pid_t child_id;

    child_id = fork();

    if (child_id < 0)
    {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id == 0)
    {

    }
    else
    {
        // this is parent

        while (1)
        {
            // Get timestamped name
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(timestamp, 50, "%Y-%m-%d_%X", timeinfo);
            // printf("%s\n", timestamp);

            // Create a directory with a timestamped name
            int check = mkdir(timestamp, 0777);

            // Every 40 seconds
            sleep(40);
        }
    }    

    return 0;
}
