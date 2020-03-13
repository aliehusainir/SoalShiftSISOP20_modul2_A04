# SoalShiftSISOP20_modul2_A04
Praktikum Modul 2 Sisop 2020<br/>
05111840000051 Juwita Kartika Rani<br/>
05111840000097 Alie Husaini R.<br/>
# Soal 1
## 1a.Program menerima 4 argumen berupa: Detik: 0-59 atau * (any value), Menit: 0-59 atau * (any value), Jam: 0-23 atau * (any value), Path file .sh
  Input berupa argumen, dapat dilakukan dengan menambahkan argumen int argc, char *argv[]. argc digunakan untuk menyimpan jumlah argumen yang telah diinput dan argv[] digunakan untuk menyimpan setiap argumen yang dipisahkan oleh spasi dan \.
## 1b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai
  Jumlah argumen tidak boleh sama dengan 5. argc != 5. Sehingga akan mengeluarkan pesan error "Jumlah argumen tidak sesuai".

  ![1b](https://user-images.githubusercontent.com/56763570/76609224-4152a100-64d4-11ea-981f-8eb18ccfa3eb.jpg)
  
  Jika ada string * maka sehingga di set nilai = 0. Nilai detik, menit, jam disimpan pada array
  
  ![bintang](https://user-images.githubusercontent.com/56763570/76609441-a27a7480-64d4-11ea-8f0e-cdbda0a9018c.jpg)
  
  khusus untuk path file isi argumen ke 4 di copy ke sebuah array string yang bernama addres
  
  ![add](https://user-images.githubusercontent.com/56763570/76610407-15d0b600-64d6-11ea-90c0-2e759ab6e65a.jpeg)
  
  Jika menginputkan nilai detik, menit tidak pada interval 0-59 dan jam tidak pada interval 0-23 maka akan mengeluarkan pesan error.
## 1c. Program hanya menerima 1 config cron
## 1d. Program berjalan di background (daemon)
  Program berjalan poda backround daemon sehingga mengambil tempate sama seperti pada modul 2.
  
  pid_t pid, sid;      

  pid = fork();     

  
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {    
    //Deklarasi variabel untuk mengambil waktu sekarang
    time_t rawtime;
    struct tm *time_m;
    
    rawtime = time(NULL);
    time_m = localtime(&rawtime);
    
    if((time_m->tm_sec == arr1[1] || arr1[1] == 0) &&
       (time_m->tm_min == arr1[2] || arr1[2] == 0) && 
       (time_m->tm_hour == arr1[3] || arr1[3] == 0))
       {
        int status;
        if(fork() == 0) 
        //array addres diinputkan
           execl("/bin/bash", "bash", addres, NULL);
        else 
            while ((wait(&status)) > 0);
       }
    sleep(1);
  }
}

![WhatsApp Image 2020-03-13 at 02 26 22 (1)](https://user-images.githubusercontent.com/56763570/76610942-e9696980-64d6-11ea-9e01-432ca127165b.jpeg)
![hasil](https://user-images.githubusercontent.com/56763570/76611117-3baa8a80-64d7-11ea-86c3-faefada514ee.jpg)
# Soal 2
## 2a. Membuat sebuah program C yang membuat sebuah folder dengan nama sesuai tanggal dan jam setiap 30 detik
Pertama, digunakan header `time.h` untuk mendapatkan waktu saat program berjalan.<br/>
Kemudian, digunakan fungsi `strftime` untuk menyimpan tanggal dan jam dalam string `timestr`.<br/>
Lalu, program melakukan perulangan terus menerus untuk membuat directory dan memanggil `fork()`.<br/>
Jika program adalah parent, maka sleep selama 30 detik. Jika bukan, maka keluar dari loop.<br/>
## 2b. Mengisi tiap folder dengan gambar setiap 5 detik
Program melakukan looping sebanyak 20 kali dan melakukan `fork()` untuk setiap iterasi.<br/>
Kemudian dibuat string baru yang mengandung waktu untuk nama gambar.<br/>
Selain itu juga dibuat string untuk menyimpan link yang mau diunduh, dimodifikasi sesuai detik Epoch Unix.<br/>
Child kemudian menjalankan fungsi `execv()`, sedangkan parent melakukan `sleep()` selama 5 detik.<br/>
## 2c. Memasukkan folder ke dalam zip dan menghapus folder semula
Setelah looping untuk download sebanyak 20 kali selesai, dibuat string yang berisi `timestr`.zip.<br/>
Program kemudian menjalankan `execv()` untuk memasukkan folder `timestr` ke dalam `timestr`.zip.
## 2d. Membuat program killer
Fungsi `fopen` digunakan untuk membuat file `kill.sh`, yaitu script yang berisi `kill -9 (PID) rm "$0"`.<br/>
Script ini akan membunuh parent process beserta anak-anaknya, kemudian menghapus dirinya.<br/>
## 2e. Mode -a dan -b
