// ***********************************************************************//
// Name: Dana Davidson and Michelle Yoon
// Homework #1:  Simply File Copy
// In this assignment, we are implementing a program that copies
// content from one file to anonther file.
// ***********************************************************************//
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
using namespace std;

int main (int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Error: Expecting 3 arguments on the command line" << endl;
    exit(1);
  }

   // writes copied data to this file
   ofstream copyFile(argv[2]);

   // reads data from this file
   ifstream originalFile;

   // to store the file data into
   string fileData[100];
   string line;
   int numLine = 0;

   // opening the original file
   originalFile.open(argv[1]);

   if (!originalFile)
   {
     cout << "Error: Unable to open the file: " << endl;
   }

   // reading every line of strings in the file and storing
   // it to the fileData array
   while (!originalFile.eof())
   {
     getline (originalFile, line);

     fileData[numLine] = line;

     numLine++;
   }

   // writing the file data to the copy file
   for (int i = 0; i < numLine -1; i++)
   {
     copyFile << fileData[i] << endl;
   }

   // closing the orginal file
   originalFile.close();

   cout << "Copied finished." << endl;

   return 0;
}

