#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define BUFFERSIZE 256

int main(int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    ssize_t numread, numwritten;

    if (argc != 3) {
	cerr << "usage:  tfile <infilename> <outfilename>\n";
	exit(EXIT_FAILURE);
    }

    // open files to make sure reading and writing is possible before doing any
    int infd = open(argv[1], O_RDONLY);
    if (infd < 0) {
	perror("open 1");
	exit(EXIT_FAILURE);
    }
    cout << "Input FD is " << infd << endl;

    int outfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
    if (outfd < 0) {
	perror("open 1");
	exit(EXIT_FAILURE);
    }
    cout << "Output FD is " << outfd << endl;
    
    // read from file
    numread = read(infd, buffer, BUFFERSIZE-1);
    if (numread < 0) {
	perror("read");
	exit(EXIT_FAILURE);
    }
    cout << "Read " << numread << " characters\n";
    buffer[numread] = '\0';

    cout << "Input file contents::buffer:: <" << buffer << ">\n";

    // write file
    numwritten = write(outfd, buffer, numread);
    if (numwritten < 0) {
	perror("write");
	exit(EXIT_FAILURE);
    }
    cout << "Wrote " << numwritten << " characters\n";

    // close the files
    if (close(infd) < 0) {
	perror("close in");
	exit(EXIT_FAILURE);
    }
    
    if (close(outfd) < 0) {
	perror("close out");
	exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
