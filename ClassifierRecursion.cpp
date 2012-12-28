#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void LeftTurnString(char* cString,int k)
{
    if(strlen(cString) > k && k > 0)
    {
	if(k <= (strlen(cString) - k))
    	{
    	    int i = 0; 
    	    for(i = 0; i < k; i++)
    	    {
    	        int tmp = cString[i];
    	        cString[i] = cString[i + k];
    	        cString[i + k] = tmp;
    	    }
    	    LeftTurnString(&cString[k],k);
    	}
    	else
    	{
	    int i = 0; 
	    int dist = strlen(cString) - k;
	    for(i = 0; i < dist; i++)
	    {
		int tmp = cString[i];
		cString[i] = cString[i + k];
		cString[i + k] = tmp;
	    }
	    LeftTurnString(&cString[dist],k - dist);
    	}
    }
}

int main(int argc,char** argv)
{
    char* cstring = (char*)malloc(256 * sizeof(char));
    char cstr[6] = "hello";
    int k = 0;
    if(argc == 1)
    {
	LeftTurnString(cstr,3);
	printf("result:%s\n",cstr);
    }
    else
    {
	memcpy(cstring,argv[1],strlen(argv[1]) + 1);
	k = argv[2][0] - '0';
	printf("str:%s,k :%d\n",argv[1],k);
	LeftTurnString(cstring,k);
	printf("result:%s\n",cstring);
	free(cstring);
    }
    return 0;
}

