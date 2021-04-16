#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void download2() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }

  if (child_id == 0) {
//film
   char *argv[] = {"wget", "-bq", "--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", argv);
} else {
//    while ((wait(&status)) > 0);
//foto
    char *argv[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", argv);
  }
}

void download1() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
//musik
   char *argv[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", argv);
} else {
    // this is parent
    download2();
  }
}


int main() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
//a
    char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
    execv("/bin/mkdir", argv);
} else {
    // this is parent
    while ((wait(&status)) > 0);
//b
    download1();
  }

  return 0;
}
