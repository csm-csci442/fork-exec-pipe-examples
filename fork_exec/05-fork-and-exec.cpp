/**
 * Simple program demonstrating the fork() system call for spawning new
 * processes.
 *
 * man 2 fork
 * man 3 exec
 * man 2 wait
 * man perror
 */

#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

using namespace std;

int main() {
  int pid; // process ID

  // Attempt to fork off a new process.
  if ((pid = fork()) == -1) {
    perror("fork failed");
    return 1;
  }

  cout << "The child is started." << endl << endl;

  // fork() will return two different values on success, depending on whether
  // the current process is the parent or the child.

  // fork() returns 0 in the child process
  if (pid == 0) {
    cout << endl << "I’m the child and my pid is " << getpid() << endl;
    cout << "I’m waiting for the execute sacrifice." << endl << endl;

    // Execute the given command.
    execl("/bin/ls", "ls", "-l", (char *)0);   /* execute a process */

    // Because exec replaces the current process image with the new program,
    // this line will only ever be reached if exec fails for whatever reason.
    // Output the error information.
    perror("exec failed");
    return 2;

  // fork() returns the child process' process ID (PID) in the parent process.
  } else {
    cout << endl << "I’m the parent. I’ll wait on my child." << endl;

    // Wait for the child process to finish executing.
    waitpid(pid, NULL, 0);

    cout << endl << "The child with pid = " << pid << " is done." << endl;
  }

  return EXIT_SUCCESS;
}
