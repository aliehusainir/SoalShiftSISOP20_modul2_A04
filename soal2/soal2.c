#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main() {
  pid_t child_id = 1;
  int status, s, i, h, d, m, y;
  time_t rawtime;
  struct tm *info;
  char timestr[50];

  while(child_id != 0){
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(timestr, 50, "%Y-%m-%d_%H:%M:%S", info);
    mkdir(timestr, 0777);
    child_id = fork();
    if(child_id != 0)sleep(30);
  }
  int c = 20;
  while(c--){
    child_id = fork();
    if(child_id == 0){
      chdir(timestr);
      time(&rawtime);
      info = localtime(&rawtime);
      char timestr2[50];
      char size[20];
      char site[] = "https://picsum.photos/";
      int t = (int) time(NULL) % 1000 + 100;
      sprintf(size, "%d", t);
      strftime(timestr2, 50, "%Y-%m-%d_%H:%M:%S", info);
      strcat(site, size);
      char *argv[] = {"wget", "-O", timestr2, site, NULL};
      execv("/usr/bin/wget", argv);
    }
    sleep(5);
  }
  while(wait(&status)>0);
  char zip[100];
  sprintf(zip, "%s.zip", timestr);
  char *argv[] = {"zip", "-mr", zip , timestr, NULL};
  execv("/usr/bin/zip", argv);
}
