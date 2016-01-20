/**
 * Simple program demonstrating fork(), a system call that spawns a new process.
 *
 * man fork
 */

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  // Fork a new child process. After this system call, there will be two
  // processes executing.
  pid_t pid = fork();

  cout << "My pid is: " << pid << endl;

  // In practice, you should always check for errors when using system calls!

  return 0;
}
