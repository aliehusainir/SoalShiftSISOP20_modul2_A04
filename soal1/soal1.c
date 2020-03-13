#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int arr1[5];
  char bintang[] = "*";
  char addres[60];
  int sama;

  if(argc != 5){
    printf("Jumlah argumen tidak sesuai\n");
    return 0;
  }
  for(int i=1; i<=3; i++){
      sama = strcmp(argv[i], bintang);
      if(sama == 0)
        arr1[i] = 0;
      else arr1[i] = atoi(argv[i]);
  }
  
  if (arr1[1] < 0 || arr1[1] > 59){
        printf("Argumen detik harus angka 0-59\n");
        return 0;
      }
     
  if (arr1[2] < 0 || arr1[2] > 59){
        printf("Argumen menit harus angka 0-59\n");
        return 0;
      }
  if (arr1[3] < 0 || arr1[3] > 23){
        printf("Argumen jam harus angka 0-23\n");
        return 0;
      }
  
  strcpy(addres, argv[4]);
 
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
           execl("/bin/bash", "bash", addres, NULL);
        else 
            while ((wait(&status)) > 0);
       }
    sleep(1);
  }
}

