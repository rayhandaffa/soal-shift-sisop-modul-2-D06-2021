#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void eksekusi(char command[], char *path[]) //command tuh isinya /bin/command
{ 
  int status; 
  pid_t child_id;
  child_id = fork();

  if(child_id == 0)
   {
      execv(command, path);
   }
  else
   {
     ((wait(&status))>0);
     return; 
   } 
}

//a
void makeFolder() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    char *folder[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
    eksekusi("/bin/mkdir", folder);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
  }
}

//b
void download() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    char *dmusik[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/wget", dmusik);

    char *dfilm[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/wget", dfilm);

    char *dfoto[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/wget", dfoto);

  } else {
    // this is parent
    while ((wait(&status)) > 0);
  }
}

//c
void extract() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    sleep(7);  //tunggu sampai file kedownload

    char *exmusik[] = {"unzip", "-q", "Musik_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/unzip", exmusik);

    char *exfilm[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/unzip", exfilm);

    char *exfoto[] = {"unzip", "-q", "Foto_for_Stevany.zip", NULL};
    eksekusi("/usr/bin/unzip", exfoto);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
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
    makeFolder();
//b
    download();
//c
//    sleep(7);  //tunggu sampai file kedownload
    extract();
}
  else {
    // this is parent
    while ((wait(&status)) > 0);
  }

}
