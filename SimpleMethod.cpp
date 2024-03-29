/*
 * Describe:这是最简单的方法，时间复杂度为O(n*n)
 * author:andrewRong
 * */
#include <iostream>
#include <cstring>
#include <assert.h>
#include <malloc.h>
using namespace std;

void LeftShift(char* str,int strLength,int k)
{
    assert(str != NULL && strLength > 0);

    int shiftNum = (k % strLength + strLength) % strLength;

    while(shiftNum--)
    {
	int tmp = str[0];
	for(int i = 0; i < (strLength - 1); i++)
	{
	    str[i] = str[i+1];
	}

	str[strLength - 1] = tmp;
    }
}
