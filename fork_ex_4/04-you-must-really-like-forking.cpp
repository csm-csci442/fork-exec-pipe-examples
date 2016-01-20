/**
 * An example with multiple fork() statements. Try running the program, then
 * try drawing the corresponding process tree and associating each output to a
 * process.
 *
 * man 2 fork
 * man 2 getpid
 */

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  // Fork in a loop. Try drawing the resulting process tree. How many times does
  // fork() get called?
  for (size_t i = 0; i < 3; i++) {
    int pid = fork();

    if (pid == 0) {
      // a + 0 => a, a + 1 => b, and so forth
      cout << char('a' + i) << endl;
    } else if (pid > 0) {
      // z - 0 => z, z - 1 => y, and so forth
      cout << char('z' - i) << endl;
    } else {
      perror("fork failed");
      return 1;
    }
  }

  return EXIT_SUCCESS;
}
