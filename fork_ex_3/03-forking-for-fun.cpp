/**
 * An example with two fork() statements, which results in a total of four
 * processes. Try running this program multiple times, and see if the output
 * changes. The PIDs should always change, and the order of outputs can change,
 * too.
 *
 * man 2 fork
 * man 2 getpid
 */

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  // One process is executing at this point.
  cout << "My pid is: " << getpid() << endl;

  // Spawn a child process.
  pid_t pid_1 = fork();

  // There are now two processes executing this line: the original (parent)
  // process and the newly spawned child process.
  //
  // After this line, there will be four processes executing.
  pid_t pid_2 = fork();

  cout << "pid_1 is: " << pid_1 << endl;
  cout << "pid_2 is: " << pid_2 << endl;

  return 0;
}
