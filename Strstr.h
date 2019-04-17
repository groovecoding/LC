#pragma once
//LC 13 string search
//naive search(brute force)
#include<string>
using std::string;

int strStr(string& source, string& target)
{
	int sourceLen = source.size();
	int targetLen = target.size();
	int j;
	for (int i = 0; i < sourceLen- targetLen + 1; i++)
		//这里的i的值是这样算的
		//假设souce 是 ATCAAGTTACCAATA   len是15
		//target 是 ATA  len 是3
		//那么外层循环就到 12就停止了  15-3 +1 =13
	{
		for (j = 0; j < targetLen; j++)
		{
			if (target[j] != source[i + j])
				break;
		}
		if (j == targetLen)
			return i;
	}

	return -1;
}