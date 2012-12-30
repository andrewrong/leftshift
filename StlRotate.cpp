/*
 * Describe:使用stl的rotate函数来解决这个问题
 * author: andrewRong
 * */
#include <iostream>
#include <algorithm>
#include <cassert>

void LeftShift(char* str,int strLength,int shiftNum)
{
    assert(str != NULL && strLength > 0);

    shiftNum = (shiftNum % strLength + strLength) % strLength;
    
    if(shiftNum != 0)
    {
	std::rotate(str,str + shiftNum, str + strLength);
    }
}
