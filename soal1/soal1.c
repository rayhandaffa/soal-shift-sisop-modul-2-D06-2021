#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>

int main() {
  pid_t id_folder;
  int status;

  id_folder = fork();
  if (id_folder < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_folder == 0) {
    // this is child

    char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
    execv("/bin/mkdir", argv);
  }


//b
  pid_t id_dlmusik, id_dlfilm, id_dlfoto;
  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_dlmusik = fork();
  if (id_dlmusik < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (id_dlmusik == 0){
    // this is parent
    char *dmusik[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", dmusik);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_dlfilm = fork();
  if (id_dlfilm < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
   if (id_dlfilm == 0) {
    // this is parent
    char *dfilm[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", dfilm);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_dlfoto = fork();
  if (id_dlfoto < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_dlfoto == 0) {
    // this is parent
    char *dfoto[] = {"wget", "-bq", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", dfoto);
  }

  sleep(10);

//c
  pid_t id_exmusik, id_exfilm, id_exfoto;
  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_exmusik = fork();
  if (id_exmusik < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_exmusik == 0){
    // this is parent
    char *exmusik[] = {"unzip", "-q", "Musik_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", exmusik);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_exfilm = fork();
  if (id_exfilm < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_exfilm == 0){
    // this is parent
    char *exfilm[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", exfilm);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_exfoto = fork();
  if (id_exfoto < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_exfoto == 0){
    // this is parent
    char *exfoto[] = {"unzip", "-q", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", exfoto);
  }

//d
  pid_t id_mvmusik, id_mvfilm, id_mvfoto;
  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_mvmusik = fork();
  if (id_mvmusik < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (id_mvmusik == 0){
    // this is parent
    char *mmusik[] = {"find", "/home/zulfa/Documents/modul2/shift2/MUSIK/", "-type", "f", "-exec", "/bin/mv", "-t", "/home/zulfa/Documents/modul2/shift2/Musyik", "{}", ";", (char*)NULL};
    execv("/usr/bin/find", mmusik);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_mvfilm = fork();
  if (id_mvfilm < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if(id_mvfilm == 0){
    char *mfilm[] = {"find", "/home/zulfa/Documents/modul2/shift2/FILM/", "-type", "f", "-exec", "/bin/mv", "-t", "/home/zulfa/Documents/modul2/shift2/Fylm", "{}", ";", (char*)NULL};
    execv("/usr/bin/find", mfilm);
  }

  while ((wait(&status)) > 0);//menunggu proses sebelumnya selesai
  id_mvfoto = fork();
  if (id_mvfoto < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if(id_mvfoto == 0){
    char *mfoto[] = {"find", "/home/zulfa/Documents/modul2/shift2/FOTO/", "-type", "f", "-exec", "/bin/mv", "-t", "/home/zulfa/Documents/modul2/shift2/Pyoto", "{}", ";", (char*)NULL};
    execv("/usr/bin/find", mfoto);
  }

  else {
    while ((wait(&status)) > 0); // do nothing
  }
}
