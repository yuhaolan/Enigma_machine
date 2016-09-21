#include <string>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "rotor.cc"
#include "permutation.cc"
#include <vector>
#include <stdio.h>
using namespace std;

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
	FILE *fp;
	char firstchar,lastchar;
	int c;
	char buffer[BUFFERSIZE];
	int f = 2;//the vaild characters between A and Z
	int ii = 0;// all the characters read
   	if (argc != 2) 
	{
		cerr << "usage:  drive <infilename>\n";
		exit(EXIT_FAILURE);
    	}
	//read the file
    	fp = fopen(argv[1],"r");
	//check the file is empty or not
	if (fp == NULL)
	{
		cerr << "Can not open the input file\n";
	}
	while((c = fgetc(fp)) != EOF)
	{
		
		if (ii == 0) firstchar =  c;
		if (ii == 1) lastchar =  c;			
		if (ii >= 2)
		{
			if (c >= firstchar && c <= lastchar)
			{
				buffer[f] = (char) c;
				++f;		
			}

		}
	ii++;
	}
	buffer[0] = firstchar;
	buffer[1] = lastchar;
	int length,i,i1;
	i1=0;
	int line = 0;//the number of lines
	length = lastchar - firstchar + 1;
	unsigned char str[length];
	vector <Rotor *> rotorset;// set the vector,each element in vector is about Rotor
	for (i = 2; i <= f; i++)//i is used to seach all the index in the buffer
	{
					// i1 is used to seach the string
			str[i1] = buffer[i];
			i1++;
		if (i1 == length)// construct the Rotor
		{
			i1 = 0;
			if (line == 0)
			{
				puts("0");
				printf("REFLECTOR::%c %c %s\n",firstchar,lastchar,str);
				rotorset.push_back(new Rotor (firstchar, lastchar, str));
			}
			else
			{
				printf("R %d ::%c %c %s\n",line,firstchar,lastchar,str);
				rotorset.push_back(new Rotor (firstchar, lastchar, str));
				rotorset[line]->setPosition(buffer[i+1]);
				printf("R %d ::set position::%c\n",line,buffer[i+1]);
				i++;//to ignore the 'A'(the character that is used to set position)
			}
			line++;	
		}
		
	}
	puts("\nInput a message");

	char message;
	while((message = getchar()) != '\n')
	{
		for (i = line - 1;i > 0; i--)
		{
			rotorset[i]->rotate();
		}
		for (i = line -1;i >= 0; i--)
		{
			message = rotorset[i]->forward(message);
		}
		for (i = 1; i < line ;i++)
		{
			message = rotorset[i]->reverse(message);
		}
		printf("%c",message);
	
	}


printf("\n");


exit(EXIT_SUCCESS);
}

			

	
	
/*
AZ
YRUHQSLDPXNGOKMIEBFZCWVJAT      buffer[3]..buffer[28]
EKMFLGDQVZNTOWYHXUSPAIBRCJ A
AJDKSIRUXBLHWTMCQGZNPYFVOE A
BDFHJLCPRTXVZNYEIWGAKMUSQO A
*/

