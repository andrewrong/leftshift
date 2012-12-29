/*
 * Describe:这个方法我觉得其实是最为简单和比较形象的方法，
 * 使用的原理就是矩形转置
 * author:andrewRong
 * */
#include <iostream>
#include <cstring>
#include <assert.h>
#include <malloc.h>

using namespace std;

void Swap(char* left,char* right)
{
    char tmp = *left;
    *left = *right;
    *right = tmp;
}

void Rotate(char* headString, char* rearString)
{
    assert(headString != NULL && rearString != NULL);
    
    while(headString < rearString)
    {
	Swap(headString++,rearString--);
    }
}
void LeftShift(char* str,int strLength,int k)
{
    assert(str != NULL && strLength > 0);

    k = (k % strLength + strLength) % strLength;
    char* middlePtr = str + k;

    Rotate(str,middlePtr - 1);
    Rotate(middlePtr,str + strLength - 1);
    Rotate(str,str + strLength - 1);
}
