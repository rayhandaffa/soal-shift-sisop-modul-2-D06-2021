#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>

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
       }
     }
    else 
      {
       ((wait(&status))>0);
      }

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

   else if(parentid == 0)
   {
      unzipandRemove();
   }

   else 
   {
     ((wait(&status)) > 0);
   }

}


