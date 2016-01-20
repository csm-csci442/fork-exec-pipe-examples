/**
 * Another fork example; this one shows both the parent process ID and the child
 * process ID.
 *
 * man 2 fork
 * man 2 getpid
 */

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  // Only one process executes this line, since it's before the fork() statement
  cout << "My pid is: " << getpid() << endl;

  // Fork a new child process.
  pid_t pid = fork();

  // Two processes will execute this line; the parent will output the child
  // process' PID, while the child will output 0 (indicating it's the child).
  cout << "My pid is: " << pid << endl;

  return 0;
}
