#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string cmdBuff;
  pid_t pid;

  do
  {
    cout << " cmd> ";
    cin >> cmdBuff;

    if (cmdBuff != "exit") { 
      pid = fork();


      if (pid < 0) {
        cerr << "Error: Unable to create child process\n";
        return 1;
      }

      if (pid == 0) {

        int exec = execlp(cmdBuff.c_str(), cmdBuff.c_str(), NULL);
        if(exec < 0)
          {
            cerr << "Error: Invalid Command\n";
            return 1;
          }

      } else {
        wait(NULL);
      }
    }



  } while (cmdBuff != "exit");
  

  return 0;
}