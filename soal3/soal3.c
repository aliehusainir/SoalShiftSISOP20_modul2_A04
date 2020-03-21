#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t child_id;
  int status;

  child_id = fork();
  if (child_id == 0) {
    char *argv[] = {"mkdir", "indomie", NULL};
    execv("/bin/mkdir", argv);
  }
  sleep(5);
  child_id = fork();
  if(child_id == 0){
    char *argv[] = {"mkdir", "sedaap", NULL};
    execv("/bin/mkdir", argv);
  }
  child_id = fork();
  if(child_id == 0){
    char *argv[] = {"unzip", "jpg.zip", NULL};
    execv("/usr/bin/unzip", argv);
  }
  while((wait(&status)) > 0);
  child_id = fork();
  if(child_id == 0){
    child_id = fork();
    if(child_id == 0){
      char *argv[] = {"find", "jpg/.", "-type", "f", "-exec", "mv", "{}", "sedaap", "\;", NULL};
      execv("/usr/bin/find", argv);
    }
    while((wait(&status)) > 0);
    char *argv[] = {"find", "jpg/.", "-type", "d", "-exec", "mv", "{}", "indomie", "\;", NULL};
    execv("/usr/bin/find", argv);
  }
  while((wait(&status)) > 0);
  child_id = fork();
  if(child_id == 0){
    char *argv[] = {"find", "indomie/.", "-mindepth", "1", "-type", "d", "-exec", "touch", "{}/coba1.txt", "\;", NULL};
    execv("/usr/bin/find", argv);
  }
  sleep(3);
  while((wait(&status)) > 0);
  char *argv[] = {"find", "indomie/.", "-mindepth", "1", "-type", "d", "-exec", "touch", "{}/coba2.txt", "\;", NULL};
  execv("/usr/bin/find", argv);
}
