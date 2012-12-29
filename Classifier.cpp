/*
 * Describe:使用分组方法去进行旋转任务,以迭代的形式
 * author:andrewRong
 * */
#include <iostream>
#include <assert.h>

using namespace std;

void Swap(char* left,char* right)
{
    char tmp = *left;
    *left = *right;
    *right = tmp;
}

void LeftShift(char* str,int strLength,int shiftNum)
{
    assert(str != NULL && strLength > 0);

    char* p1 = NULL;
    char* p2 = NULL;
    char* middleptr = NULL;

    shiftNum = (shiftNum % strLength + strLength) % strLength;

    int loopNum = 0;
    
    if(shiftNum != 0)
    {
	loopNum = strLength / shiftNum;

    	p1 = str;
    	p2 = str + shiftNum;

    	cout<<str<<" "<<loopNum<<" "<<shiftNum<<endl;

    	for(int i = 0; i < (loopNum - 1);i++)
    	{
    	    for(int j = 0; j < shiftNum; j++)	
    	    {
    	        Swap(p1++,p2++);
    	    }
    	}

    	middleptr = p2;

    	while(p2 != str + strLength)
    	{
    	    Swap(p1++,p2++);

    	    if(p1 == middleptr)
    	    {
    	        middleptr = p2;
    	    }
    	    else if(p2 == str + strLength)
    	    {
    	        p2 = middleptr;
    	    }
    	}
    }
}
