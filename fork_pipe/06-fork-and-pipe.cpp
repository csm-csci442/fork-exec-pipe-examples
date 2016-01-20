/**
 * Simple program demonstrating using pipe() for inter-process communication.
 *
 * man 3 fork
 * man 2 pipe
 * man 2 read
 * man 2 write
 * man perror
 */

#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

 #define DATA "There are 10 types of people ... "

using namespace std;

int main() {
  // Array of file descriptors (in and out).
  // Data written to the_pipe[1] can be read from the_pipe[0].
  int the_pipe[2];

  // Attempts to create a pipe. the_pipe must be available to both processes.
  if (pipe(the_pipe) < 0) {
    perror("opening pipe");
    return 1;
  }

  // fork() a new process.
  int pid = fork();

  // You should ALWAYS check system calls for errors.
  if (pid == -1) {
    perror("fork");
    return 2;
  }

  // If this is the child process...
  if (pid == 0) {
    // The child will write a message to its parent on the_pipe[1], which the
    // parent can read on the_pipe[0]. So, the child closes the read-end of the
    // pipe.
    close(the_pipe[0]);

    cout << "I'm the child; I have something important to say." << endl << endl;

    // Write the message (and check for error).
    if (write(the_pipe[1], DATA, sizeof(DATA)) < 0) {
      perror("writing message");
    }

    // We're done with the file, close it so parent can finish reading.
    close(the_pipe[1]);

  // Otherwise, this is the parent process.
  } else {
    // Create a character buffer that we'll use to read the child's message.
    char buf[1024];

    // The parent will read (using the_pipe[0] the message the child writes to
    // the_pipe[1]. So, the parent closes the write-end of the pipe.
    close(the_pipe[1]);

    cout << "I'm the parent; I should listen to my child." << endl << endl;

    // Attempt to read from the pipe (and check for error).
    if (read(the_pipe[0], buf, 1024) < 0) {
      perror("reading message");
    }

    cout << "My child says: " << buf << endl;

    // We're done with the file, so close it (best practice).
    close(the_pipe[0]);
  }

  return EXIT_SUCCESS;
}
