#include <iostream>
#include <string>
#include <string.h>
#include <cassert>
#include <fstream>
using namespace std;

void LeftShift(char* str,int strLength,int shiftNum);

int main()
{
    string filename = "test.txt";
    string originalString;
    string changedString;
    int shiftNum = 0;
    int lineNum = 0;

    ifstream infile(filename.c_str(),ios_base::in);

    if(!infile)
    {
	cerr<<"your file:%s is not exist\n"<<endl;
	return -1;
    }
    
    infile >> lineNum;
    
    cout<<lineNum<<endl;

    char* cOriginalString = NULL;
    char* cChangedString = NULL;

    while(lineNum--)
    {
	infile>>originalString>>shiftNum>>changedString;
	
	cOriginalString = new char[originalString.size() + 1]();
	cChangedString = new char[changedString.size() + 1]();

	assert(cOriginalString != NULL);
	assert(cChangedString != NULL);
	
	originalString.copy(cOriginalString,originalString.size());
	cOriginalString[originalString.size()] = '\0';
	changedString.copy(cChangedString,changedString.size());
	cChangedString[changedString.size()] = '\0';
	
	LeftShift(cOriginalString,originalString.size(),shiftNum);

	if(strcmp(cOriginalString,cChangedString) != 0)
	{
	    cout<<"test error;num is"<<lineNum<<endl;

	    delete[] cOriginalString;
	    delete[] cChangedString;
	    break;
	}

	delete[] cOriginalString;
	delete[] cChangedString;
    }

    return 0;
}
