# Sistem Operasi D-06 (2021)
Praktikum Sistem Operasi Modul 2 - Daemon dan Proses
Kelompok : 
1. Ramadhan Arif - 05111940000162
2. Zulfayanti Sofia Solichin - 05111940000189
3. Rayhan Daffa Alhafish - 05111940000227

## Penjelasan dan Penyelesaian soal no.1
- **Penjelasan dan Penyelesaian Soal 1a**<br>
Pada soal ini kita diminta untuk membuat 3 folder bernama "Fylm", "Musyik", dan "Pyoto".<br>
  ```
   char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
   execv("/bin/mkdir", argv);
  ```
  Pada potongan codingan di atas digunakan `mkdir` untuk membuat folder baru diikuti dengan nama-nama folder yang ingin dibuat.<br>
- **Penjelasan dan Penyelesaian Soal 1b**<br>
Pada soal ini kita diminta untuk mendownload .zip file yang terdapat di soal dengan menggunakan `wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext`<br>
  ```
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
  ```
  pada codingan di atas digunakan `-bq` agar proses mendownload berjalan di background dan hasil log tidak akan ditulis di terminal.<br>
- **Penjelasan dan Penyelesaian Soal 1c**<br>
Pada soal ini kita dinimta untuk mengekstrak zip file yang sudah kita download sebelumnya<br>
  ```
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
  ```
  Pada codingan diata digunakan `unzip` untuk mengekstrak file yang dipilih, lalu digunakan `-q` agar hasil lognya tidak tertulis di terminal. Proses ini dilakukan setelah jeda waktu 10 detik dari proses sebelumnya dengan fungsi `sleep(10)` untuk memastikan semua file sudah terdownload terlebih dahulu.<br>
- **Penjelasan dan Penyelesaian Soal 1d**<br>
Pada soal ini kita diminta untuk memindahkan semua file dari folder yang sudah di ekstrak ke forlder Myusik, Fylm, Pyoto yang sudah dibuat diawal.<br>
```
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
```
Pada proses ini, kita menggunakan find dengan `-type f` yaitu untuk menemukan semua data dengan tipe file, dan melakukan `-exec /bin/mv` untuk menggunakan perintah move yaitu memindahkan semua file yang telah di find sebelumnya kedalam folder Musyik, Fylm, Pyoto yang telah dibuat sebelumnya.<br>

- **Penjelasan dan Penyelesaian Soal 1e**<br>
- **Penjelasan dan Penyelesaian Soal 1f**<br>

## Kendala yang dialami selama mengerjakan soal no.1
1. Pada saat ingin melakukan proses download file, file tidak terdownload karena fungsi execv kurang menggunakan `usr` untuk lokasi mengeksekusi.<br>
2. pada sat mengerjakan soal 1e dan 1f tidak terdapat error saat memanggil proses namun proses tidak dapat berjalan.<br>

## Penjelasan dan Penyelesaian soal no.2
Untuk penjelasan dan penyelesaian soal no 2 dibagi menjadi beberapa sub-nomer, yaitu:
- **Penjelasan dan Penyelesaian Soal 2a**<br>
  Pada soal nomer 2a ini kita diminta membuat program agar bisa meng-*extract* zip yang diberikan ke dalamfolder yang memiliki alamat `/home/rayhandapis/modul2/petshop`. Karena bos Loba teledor, maka soal 2a meminta kita membuat sebuah rencana agar program dapat membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder - folder yang tidak dibutuhkan. Oleh karena itu, kami membuat sebuah fungsi `unzipandRemove()` yang dimana sudah sesuai dengan penjelasan soal nomer 2a ini. 
  ```
      /2a
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
  ```
  Berdasarkan fungsi di atas untuk meng-*extract* zip kami pertama2 membuat sebuah folder dengan menggunakan `mkdir` pada directory `/home/rayhandapis/modul2/`. Kemudian, meng-*extract* menggunakan `unzip` dengan syntax `unzip, "-q", file asal, "-d", file tujuan` . Kami menggunakan `-q` digunakan agar log ketika melakukan *extract* tidak ditampilkan pada terminal. Selanjutnya, kita dapat menghapus folder yang tidak dibutuhkan. Disini kami menggunakan directory listing dengan library `dirent.h` untuk mengetahui isi folder yang telah di `unzip`. Karena file yang dibutuhkan hanya foto-foto dengan format `.jpg`, maka file yang berupa directory `DT_DIR` akan di hapus atau di remove.
- **Penjelasan dan Penyelesaian Soal 2b**<br>
  Pada nomer 2b ini kita diminta membuat folder berdasarkan jenis peliharaan. Karena kita tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip namun, sebelum itu kami menggunakan sebuah fungsi untuk menghilangkan 4 indeks terakhir dari sebuah string. 
  ```
       //fungsi buat motong eksistensi .jpg
       char* potongJPG (char* sistem)
        {
            int n;
            int i;
            char* baru;

            //perulangan
            for (i = 0; sistem[i] != '\0'; i++);
    
    
            n = i - 4 + 1;//panjang dari new stringnya
           if (n < 1)
            {
                return NULL;
            }

           baru = (char*) malloc (n * sizeof(char));
           for (i = 0; i < n - 1; i++)
            {
               baru[i] = sistem[i];
            }
    
           baru[i] = '\0';
           return baru;
       }
  ```
  Menggunakan fungsi `potongJPG` untuk setiap file foto agar string nama file tersebut dapat digunakan untuk membuat folder untuk setiap jenis peliharaan dan nama file foto peliharaan. Selanjutnya kita memanggil fungsi tersebut menggunakan syntax `char *newName = potongJPG(filename);`. Kemudian, kami dapat membuat folder sesuai kategori jenis pelihaaran yang dengan menggunakan sebuah fungsi `kategoriFiles()`.
  ```
    
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
  ```
  `strtok_r` digunakan untuk memotong kata dalam string. Pada kesempatan kali ini kami menggunakan dua perulangan, perulangan perta digunakan untuk mengecek untuk foto yang terdiri dari dua hewan peliharaan sehingga dipisahkan dengan `_`, kemudian memotong string. Setelah itu, membuat sebuah `char` untuk menyimpan kategori hewan peliharaan, nama hewan peliharaan, dan umur. Selanjutnya pada perulangan kedua, memotong string nama file yang dipisahkan dengan `;` dan ketika i=0 berarti program sedang mengecek potongan pertama pada string sehingga mendapatkan kategori hewan peliharaan. Kemudian, menggunakan `mkdir` untuk membuat folder sesuai kategori peliharaan.
- **Penjelasan dan Penyelesaian Soal 2c dan 2d**<br>
  Pada soal 2c ini kita diminta memindahkan foto ke folder dengan kategori yang sesuai 
  ```
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
  ```
    Bagian atas ini untuk merename dan mengkopi file-file pada setiap folder. Dikarenakan sebelumnya sudah menemukan nilai untuk variabel name, variabel tersebut ditambah dengan ekstensi jpg dijadikan sebagai path baru dimana file sebelumnya akan dipindah. Untuk merename sendiri bisa menggunakan `/bin/mv` dan untuk mengkopi kami menggunakan `/bin/cp`. nomor 2c dan 2d dilakukan secara bersamaan pada dua fungsi ini Untuk meremove file-file di luar folder-folder kategori (bekas copy untuk soal 2c), kami menggunakan `/bin/rm` untuk menghapus file-file tersebut, apabila ternyata file dalam path Petshop berupa file reguler biasa dan bukan direktori (karena apabila file di folder Petshop berupa direktori artinya file tersebut merupakan folder kategori yang telah dibuat). Kami masih menggunakan directory listing atas, akan tetapi untuk meremove sudah di luar looping pemisahan string. Untuk pengapusan file-file yang tidak digunakan kami membuat sebuah fungsi bernama `ngapusgaguna()`.

- **Penjelasan dan Penyelesaian Soal 2e**<br>
  Pada soal 2e ini diminta untuk membuat sebuah `keterangan.txt` yang dimana sebelumnya di atas sudah mengcopy nilai beberapa variabel ke dalam variabel baru untuk digunakan di bawah, yaitu
  ```
                       //2e keterangan.txt
                       char  lokasitxt[99], pathtxt[99];
                       strcpy(lokasitxt, path);
                       stpcpy(pathtxt, lokasitxt);

                       char namaditxt[100], value[100];
                       strcpy(namaditxt,namaHewan); //ngekopi namahewan di namaditxt biar yang dipake namaditxt
                       stpcpy(pathtxt, lokasitxt);
  ```
  Kemudian, untuk memasukkan file txt sendiri dengan cara membuat path baru berisi "keterangan.txt", dan kemudian memasukkan nilai dalam variabel name, dan age pada file dengan format yang telah ditentukan. Setelah file selesai diappend, file akan ditutup kembali. Untuk memasukkan file juga masih di dalam looping pemisahan string yang awal.
  ```
                      //2e keterangan.txt
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
  ```
## Kendala yang dialami selama mengerjakan soal no.2 
Beberapa kendala yang kami alami selama mengerjakan soal no.2 antara lain : <br>
1. Pada mengerjakan soal2 ini kami mengalami error ketika menjalankan program yang telah kami buat dan muncul seperti ini: <br> 
   ![soal2](https://github.com/rayhandaffa/soal-shift-sisop-modul-2-D06-2021/blob/main/soal2/error2a.jpg)<br> 
   Ketika menjalankan sebuah program, kami lupa untuk mendeclare fungsi yang telah kami buat di main sehingga muncul seperti itu. 
 2. Ketika mengerjakan soal2e, yang membuat keterangan.txt kami mengalami error muncul seperti ini: <br> 
   ![soal2](https://github.com/rayhandaffa/soal-shift-sisop-modul-2-D06-2021/blob/main/soal2/hasil%20salah%20letak%20untuk%202e.jpg)<br> 
   Hal ini disebabkan karena kami salah meletakan posisi, ketika foto sudah di potong eksistensinya oleh karena itu hanya folder frog saja yang muncul.
 3. Untuk Program yang dimaksudkan pada poin no.2 dapat dilihat di bawah ini : <br> 
   ![soal2](https://github.com/rayhandaffa/soal-shift-sisop-modul-2-D06-2021/blob/main/soal2/kodingan%20salah%20letak%20untuk%202e.jpg)<br> 
   Potongan kodingan di atas menjelaskan bahwa hasil `pathtxt` merupakan hasil dari yang sudah di potong ketika menjalankan soal no 2b yang dimana dipisahkan secara `;` dan diminta untuk memotong eksistensi `.jpg`.
 4. Dan ketika mengerjakan soal no.2b yang diminta untuk memotong eksistensi `.jpg` kami mengalami kesulitan sehingga, kami mencari pada link ini: 
     https://stackoverflow.com/questions/27414696/remove-last-four-characters-from-a-string-in-c
    
## Penjelasan dan Penyelesaian soal no.3
- **Penjelasan dan Penyelesaian Soal 3a**<br>

Pada soal 3a ini, diminta untuk membuat program C yang setiap mana setiap 40 detik membuat sebuah direktori dengan nama timestamp waktu saat ini dengan format [YYYY-mm-dd_HH:ii:ss].

Pertama, perlu dideklarasikan variabel-variabel yang dibutuhkan, seperti `rawtime`, `timeinfo`, dan array char `timestamp` untuk keperluan pembuatan timestamp.
```
time_t rawtime;
struct tm *timeinfo;
char timestamp[50] = {0};
```
Lalu, deklarasikan `child_id` dan lakukan fork pada `child_id` untuk membuat proses baru. Lakukan pengecekan untuk mengecek apakah proses baru berhasil dibuat. Apabila hasil `child_id` != 0 maka akan menuju ke parent process.
```
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

}
```
Pada bagian parent process, dilakukan infinite while loop. Fungsi `time` berfungsi untuk mengembalikan waktu saat ini dan menaruhnya di variabel `rawtime`. Fungsi `localtime` berfungsi untuk mengembalikan representasi struct tm dari `rawtime` pada zona waktu lokal. Fungsi `strftime` berfungsi untuk memformat `timeinfo` menjadi `timestamp` sesuai format yang diinginkan, yakni `%Y-%m-%d_%X`.
```
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
```

Lalu, dibuat sebuah direktori dengan nama berupa `timestamp`.
```
int check = mkdir(timestamp, 0777);
```
Dan beri jeda proses iterasi dengan fungsi `sleep`. Atur menjadi 40 detik.
```
sleep(40);
```

Berikut ini adalah screenshot hasil output dari program 3a diatas.

![soal3](https://github.com/rayhandaffa/soal-shift-sisop-modul-2-D06-2021/blob/main/soal3/soal3.png)<br> 

- **Penjelasan dan Penyelesaian Soal 3b**<br>
- **Penjelasan dan Penyelesaian Soal 3c**<br>
- **Penjelasan dan Penyelesaian Soal 3d**<br>
- **Penjelasan dan Penyelesaian Soal 3e**<br>
## Kendala yang dialami selama mengerjakan soal no.3 

1. Terkendala saat ingin melakukan download gambar dari URL. Direktori terbuat tetapi gambar tidak terunduh.
```
char *argv1[] = {"wget", imageURL, "-O", timestampImg, "-o", "/dev/null", NULL};
execv("/usr/bin/wget", argv1);
```
