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
Pada codingan diata digunakan `unzip` untuk mengekstrak file yang dipilih, lalu digunakan `-q` agar hasil lognya tidak tertulis di terminal.<br>
- **Penjelasan dan Penyelesaian Soal 1d**<br>
- **Penjelasan dan Penyelesaian Soal 1e**<br>
- **Penjelasan dan Penyelesaian Soal 1f**<br>

## Kendala yang dialami selama mengerjakan soal no.1

## Penjelasan dan Penyelesaian soal no.2
- **Penjelasan dan Penyelesaian Soal 2a**<br>
Pada soal no 2 ini kita diminta untuk mengextract zip yang telah di download kemudian hasil extract-an di simpan ke dalam folder "/home/rayhandapis/modul2/petshop". Setelah di extract kemudia soal meminta kita membuat program dapat membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folde-folder yang dibutuhkan sesuai dengan isi zip. Untuk mengextract zip dapat menggunakan sebuah `/bin/unzip` dan hasil extract-annya disimpan di folder `petshop` 
```
 if(parentid == 0)
    {
      char *folderBaru[]={"mkdir", "-p", tujuan, NULL};
      eksekusi("/bin/mkdir", folderBaru);

      char *extract[]={"unzip", "-q", asal,"-d", tujuan, NULL};//-q buat ngilangin yang di terminal
      eksekusi("/bin/unzip", extract);
    }
```
Pada potongan codingan di atas dapat dilihat dengan menggunakan *mkdir* digunakan untuk membuat sebuah folder petshop pada directory`/home/rayhandapis/modul2/"` dan untuk mengextractnya sendiri menggunakan `unzip` dengan sytax *unzip, -q, file source, -d, file destination, NULL*. -q disini digunakan agar ketika melakukan extract tidak ditampilkan pada terminal.
```
 if(parentid == 0)
 {
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
```
Selanjutnya, untuk menghapus folder yang tidak dibutuhkan kami menggunakan sebuah directory listing dengan library `dirent.h` untuk mengetahui isi folder yang telah di unzip. Dikarenakan pada soal ini hanya membutuhkan sebuah file-file yang berisi sebuah foto dengan format `.jpg`, maka file yang berupa DIRECTORY `DT_DIR` akan di remove. 
- **Penjelasan dan Penyelesaian Soal 2b**<br>
Pada soal meminta kita untuk dapat meng-zip kan kembali berdasarkan jenis peliharaan, sebelumnya kita dapat menghilangkan 4 indeks terakhir dari sebuah string guna untuk mempermudah program dalam mencari jenis hewan. 
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
Fungsi diatas digunakan untuk setiap file foto agar string nama file tersebut dapat digunakan kembali untuk membuat folder based on jenis hewan or jenis peliharaan dan nama file foto peliharaan. Untuk pemanggilan fungsi dapat di tulis berikut ini : 
`char *newName = potongJPG(filename);` kemudian kita diminta untuk membuat folder sesuai kategori jenis peliharaan yang ada dengan cara: 
```
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
`strtok_r` ini digunakan untuk memotong kata dalam string. Terdapat dua kali penggunaan for. For yang pertama digunakan untuk 
- **Penjelasan dan Penyelesaian Soal 2c**<br>
- **Penjelasan dan Penyelesaian Soal 2d**<br>
- **Penjelasan dan Penyelesaian Soal 2e**<br>
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








- **Penjelasan dan Penyelesaian Soal 3b**<br>
- **Penjelasan dan Penyelesaian Soal 3c**<br>
- **Penjelasan dan Penyelesaian Soal 3d**<br>
- **Penjelasan dan Penyelesaian Soal 3e**<br>
## Kendala yang dialami selama mengerjakan soal no.3 
