#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

//function khusus agar dapat memanggil secara cepat
void eksekusi(char command[], char *nyimpenpath[]) //command tuh isinya /bin/command
{ 
  int status; 
  pid_t parentid;
  parentid = fork();

  if(parentid == 0)
   {
      execv(command, nyimpenpath);
   }
  else
   {
     ((wait(&status))>0);
     return; 
   } 
}
//fungsi buat motong eksistensi .jpg(from internet)
char* potongJPG (char* s){
    int n;
    int i;
    char* new;
    //perulangan
    for (i = 0; s[i] != '\0'; i++);
    
    // lenght of the new string
    n = i - 4 + 1;
    if (n < 1)
        return NULL;
    new = (char*) malloc (n * sizeof(char));
    for (i = 0; i < n - 1; i++)
        new[i] = s[i];
    new[i] = '\0';
    return new;
}
//2a
void unzipandRemove()
{
   char tujuan[100]="/home/rayhandapis/modul2/petshop";
   char asal[100]="/home/rayhandapis/Downloads/pets.zip";

   int status;
 
   pid_t parentid;
   parentid = fork();
   
   if(parentid < 0)
    {
      exit(EXIT_FAILURE);
    }

   if(parentid == 0)
    {
      char *folderBaru[]={"mkdir", "-p", tujuan, NULL};
      eksekusi("/bin/mkdir", folderBaru);

      char *extract[]={"unzip", "-q", asal,"-d", tujuan, NULL};//-q buat ngilangin yang di terminal
      eksekusi("/bin/unzip", extract);
    //ngilangin yang ga penting
      DIR *direk;
      direk=opendir(tujuan);
      if(direk!=NULL) 
      {
       struct  dirent *diPetshop;
       while((diPetshop = readdir(direk)) != NULL) 
        {
          if(strcmp(diPetshop->d_name, ".")==0 || strcmp(diPetshop->d_name, "..")==0)
            {
                continue;
            } 
          else if(diPetshop->d_type == DT_DIR)
             {
               char kombinasi[100] = {"tujuan"};
               strcpy(kombinasi, tujuan);
               strcat(kombinasi, "/");
               strcat(kombinasi, diPetshop->d_name);
               char *apus[] = {"rm", "-r", "-f", kombinasi, NULL};
               eksekusi("/bin/rm", apus);
             }
            //  closedir(direk);
        }
      }
    closedir(direk);
    }

    else 
      {
       ((wait(&status))>0);
      }

 }

void makeFiles()
{
   char tujuan[100]="/home/rayhandapis/modul2/petshop";
//    char asal[100]="/home/rayhandapis/Downloads/pets.zip";
   int status;
 
   pid_t parentid;
   parentid = fork();
   
   if(parentid < 0)
    {
      exit(EXIT_FAILURE);
    }

   if(parentid == 0)
   {
       DIR *direk;
       direk=opendir(tujuan);
       if(direk!=NULL)
       {
           struct dirent *diFolder;
           while((diFolder=readdir(direk))!=NULL)
           {
               if(diFolder->d_type == DT_REG)
               {
                   int a; 
                   char *tok, *tok2, *tok3, *tok4;
                   char *filename = diFolder->d_name;
                   char *newName = potongJPG(filename);

                   char hasil1[100], hasil2[100], hasil3[100];
                   char path2[99], path3[99];
                   char jenisHewan[30], namaHewan[30], umurNya[30];

                   for(tok=strtok_r(newName, "_", &tok3); tok!=NULL; tok=strtok_r(NULL, "_", &tok3))
                   {
                       a=0;
                       char path[99]="/home/rayhandapis/modul2/petshop/";
                       strcpy(hasil1, filename);
                       strcpy(path2, path);
                       strcpy(path3, path);
                       strcpy(hasil2, filename);
                       strcpy(hasil3, filename);
                       for(tok2=strtok_r(tok, ";", &tok4); tok2!=NULL; tok2=strtok_r(NULL, ";", &tok4))
                       {
                           if(a==0)strcpy(jenisHewan, tok2);
                           if(a==1)strcpy(namaHewan, tok2);
                           if(a==2)strcpy(umurNya, tok2);
                           a++;
                       }   
                      
                       //2b. buat folder based on jenis hewan
                       strcat(path, jenisHewan);
                       char *buatDirektory[] = {"mkdir", "-p", path, NULL};
                       eksekusi("/bin/mkdir", buatDirektory);
                   }
               
           }
           closedir(direk);
       }
      //  closedir(direk);
    }

   else
   {
       ((wait(&status))>0);
   }
}
void moveFiles()
{
   char tujuan[100]="/home/rayhandapis/modul2/petshop";
//    char asal[100]="/home/rayhandapis/Downloads/pets.zip";
   int status;
 
   pid_t parentid;
   parentid = fork();
   
   if(parentid < 0)
    {
      exit(EXIT_FAILURE);
    }

   if(parentid == 0)
   {
       DIR *direk;
       direk=opendir(tujuan);
       if(direk!=NULL)
       {
           struct dirent *diFolder;
           while((diFolder=readdir(direk))!=NULL)
           {
               if(diFolder->d_type == DT_REG)
               {
                   int a; 
                   char *tok, *tok2, *tok3, *tok4;
                   char *filename = diFolder->d_name;
                   char *newName = potongJPG(filename);

                   char hasil1[100], hasil2[100], hasil3[100];
                   char path2[99], path3[99];
                   char jenisHewan[30], namaHewan[30], umurNya[30];

                   for(tok=strtok_r(newName, "_", &tok3); tok!=NULL; tok=strtok_r(NULL, "_", &tok3))
                   {
                       a=0;
                       char path[99]="/home/rayhandapis/modul2/petshop/";
                       strcpy(hasil1, filename);
                       strcpy(path2, path);
                       strcpy(path3, path);
                       strcpy(hasil2, filename);
                       strcpy(hasil3, filename);
                   }
                    // //2e sementara
                    //    char  lokasitxt[99], pathtxt[99];
                    //    strcpy(lokasitxt, path);
                    //    stpcpy(pathtxt, lokasitxt);

                       char namaditxt[100], value[100];
                       strcpy(namaditxt,namaHewan); //ngekopi namahewan di namaditxt biar yang dipake namaditxt

                       //2c memindahkan to folder
                       strcat(namaHewan, ".jpg");
                       strcat(path2, hasil2);

                       char *kopikeFolder[] = {"cp", "-r", path2, path, NULL};
                       eksekusi("/bin/cp", kopikeFolder);

                       //2c rubah nama 
                       strcpy(path3, path);
                       strcat(path3, "/");
                       strcat(path3, hasil2);
                       strcat(path, "/");
                       strcat(path, namaHewan);
                      //  printf("%s\n", path);
                       char *ubahnama[] = {"ubahnama", path3, path, NULL};
                       eksekusi("/bin/mv", ubahnama);     
                }
             }
           closedir(direk);
        }
      //  closedir(direk);
    }

   else
   {
       ((wait(&status))>0);
   }
}
void keterangantxt()
{
  char tujuan[100]="/home/rayhandapis/modul2/petshop";
//    char asal[100]="/home/rayhandapis/Downloads/pets.zip";
   int status;
 
   pid_t parentid;
   parentid = fork();
   
   if(parentid < 0)
    {
      exit(EXIT_FAILURE);
    }

   if(parentid == 0)
   {
       DIR *direk;
       direk=opendir(tujuan);
       if(direk!=NULL)
       {
           struct dirent *diFolder;
           while((diFolder=readdir(direk))!=NULL)
           {
               if(diFolder->d_type == DT_REG)
               {
                   int a; 
                   char *tok, *tok2, *tok3, *tok4;
                   char *filename = diFolder->d_name;
                   char *newName = potongJPG(filename);

                   char hasil1[100], hasil2[100], hasil3[100];
                   char path2[99], path3[99];
                   char jenisHewan[30], namaHewan[30], umurNya[30];

                   for(tok=strtok_r(newName, "_", &tok3); tok!=NULL; tok=strtok_r(NULL, "_", &tok3))
                   {
                       a=0;
                       char path[99]="/home/rayhandapis/modul2/petshop/";
                       strcpy(hasil1, filename);
                       strcpy(path2, path);
                       strcpy(path3, path);
                       strcpy(hasil2, filename);
                       strcpy(hasil3, filename);
                      //  for(tok2=strtok_r(tok, ";", &tok4); tok2!=NULL; tok2=strtok_r(NULL, ";", &tok4))
                      //  {
                      //      if(a==0)strcpy(jenisHewan, tok2);
                      //      if(a==1)strcpy(namaHewan, tok2);
                      //      if(a==2)strcpy(umurNya, tok2);
                      //      a++;
                      //  }   
                      //2e keterangan.txt
                       char  lokasitxt[99], pathtxt[99];
                       strcpy(lokasitxt, path);
                       stpcpy(pathtxt, lokasitxt);

                       char namaditxt[100], value[100];
                       strcpy(namaditxt,namaHewan); //ngekopi namahewan di namaditxt biar yang dipake namaditxt
                       stpcpy(pathtxt, lokasitxt);

                       strcat(pathtxt, "/keterangan.txt");
                       strcpy(value, "nama : ");
                       strcat(value, namaditxt);
                       strcat(value, "\numur : ");
                       strcat(value, umurNya);
                       strcat(value, "tahun\n\n");
                      //  printf("%s\n", lokasitxt);
                       FILE *asal = fopen(pathtxt, "a");
                       fputs(value, asal);
                       fclose(asal);
                      
                   }
               
           }
           closedir(direk);
       }
      //  closedir(direk);
    }

   else
   {
       ((wait(&status))>0);
   }
}
void ngapusgaguna()
{
   int status;
   
   pid_t parentid;
   parentid = fork();
   
   if(parentid < 0)
    {
      exit(EXIT_FAILURE);
    }

   if(parentid == 0)
   {
       DIR *direk;
       char tujuan[100]="/home/rayhandapis/modul2/petshop";
       direk=opendir(tujuan);
       if(direk!=NULL)
       {
           struct dirent *diFolder;
           while((diFolder=readdir(direk))!=NULL)
           {
               if(diFolder->d_type == DT_REG)
               {
                  char asal[99]="/home/rayhandapis/modul2/petshop/";
                  strcat(asal,diFolder->d_name);
                  char *apusgaguna[]={"rm","-r","-f", asal,NULL};
                  eksekusi("/bin/rm",apusgaguna);
               }
           }
       }
      closedir(direk);
   }
   else 
   {
     ((wait(&status)) > 0);
   }
}
int main()
{
   int status;
   pid_t parentid;
   parentid = fork();

   if(parentid < 0)
   {
      exit(EXIT_FAILURE);
   }

   if(parentid == 0)
   {
      unzipandRemove(); //2a
      makeFiles();//2b
      moveFiles();//2c 2d 
      keterangantxt();//2e
      ngapusgaguna();
   }

   else 
   {
     ((wait(&status)) > 0);
   }

}
