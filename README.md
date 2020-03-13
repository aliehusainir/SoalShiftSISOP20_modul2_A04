# SoalShiftSISOP20_modul2_A04
Praktikum Modul 2 Sisop 2020<br/>
05111840000051 Juwita Kartika Rani<br/>
05111840000097 Alie Husaini R.<br/>
# Soal 1
# Soal 2
## 2a. Membuat sebuah program C yang membuat sebuah folder dengan nama sesuai tanggal dan jam setiap 30 detik
![Screenshot from 2020-03-13 16-26-19](https://user-images.githubusercontent.com/57984390/76608269-ebb7dc00-6547-11ea-8979-ede7eb7b0660.png)<br/>
Pertama, digunakan header `time.h` untuk mendapatkan waktu saat program berjalan.<br/>
Kemudian, digunakan fungsi `strftime` untuk menyimpan tanggal dan jam dalam string `timestr`.<br/>
Lalu, program melakukan perulangan terus menerus untuk membuat directory dan memanggil `fork()`.<br/>
Jika program adalah parent, maka sleep selama 30 detik. Jika bukan, maka keluar dari loop.<br/>
## 2b. Mengisi tiap folder dengan gambar setiap 5 detik
![Screenshot from 2020-03-13 16-26-38](https://user-images.githubusercontent.com/57984390/76608271-ece90900-6547-11ea-85ac-94ef3ad3a3e5.png)<br/>
Program melakukan looping sebanyak 20 kali dan melakukan `fork()` untuk setiap iterasi.<br/>
Kemudian dibuat string baru yang mengandung waktu untuk nama gambar.<br/>
Selain itu juga dibuat string untuk menyimpan link yang mau diunduh, dimodifikasi sesuai detik Epoch Unix.<br/>
Child kemudian menjalankan fungsi `execv()`, sedangkan parent melakukan `sleep()` selama 5 detik.<br/>
## 2c. Memasukkan folder ke dalam zip dan menghapus folder semula
![Screenshot from 2020-03-13 16-26-57](https://user-images.githubusercontent.com/57984390/76608272-ed819f80-6547-11ea-8ef5-677fadf993e3.png)<br/>
Setelah looping untuk download sebanyak 20 kali selesai, dibuat string yang berisi `timestr`.zip.<br/>
Program kemudian menjalankan `execv()` untuk memasukkan folder `timestr` ke dalam `timestr`.zip.<br/>
Digunakan option `-m` agar tidak menyisakan folder semula dan `-r` untuk melakukan zip secara rekursif.<br/>
