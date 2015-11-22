#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;
int status;
int main()
{
	fstream myfile;
 	myfile.open("example1.txt", ios::in | ios::out);
	if(fork())
	{
		wait(&status);
 		string output;
 		if (myfile.is_open()) {
 			while (getline(myfile, output)) {
				cout<<"parent: "<<output;
	 		}
			cout << endl;
		}
	}
	else
	{
		cout << "Enter the text to be written into the file:\n";
		string text;
		getline(cin, text);
		myfile << text;
	}
	return 0;
}
