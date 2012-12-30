/*
 * Describe:使用循环链的方法来解决这个问题
 * anuthor: andrewRong
 * */
#include <assert.h>
#include <iostream>

using namespace std;

int Gcd(int left,int right)
{
    assert(left != 0 && right != 0);

    int max = left > right ? left : right; 
    int min = left > right ? right : left; 
    
    left = max;
    right = min;

    int reminder = left % right;

    while(reminder != 0)
    {
	left = right;
	right = reminder;

	reminder = left % right;
    }

    return right;
}

void LeftShift(char* str,int strLength,int shiftNum)
{
    assert(str != NULL && strLength > 0);

    shiftNum = (shiftNum % strLength + strLength) % strLength;

    if(shiftNum != 0)
    {
	int groupNum = Gcd(strLength,shiftNum); 
    	int chainOfNum = strLength / groupNum;

    	cout<<groupNum<<" "<<shiftNum<<endl;

    	for(int i = 0; i < groupNum; i++)
    	{
    	    int tmp = str[i];
    	    int j = 0;

    	    for(j = 0; j < (chainOfNum - 1); j++)
    	    {
    	        str[(i + j * shiftNum) % strLength] = str[(i + (j + 1) * shiftNum) % strLength];   
    	    }

    	    str[(i + j * shiftNum) % strLength] = tmp;
    	}
    }
}
