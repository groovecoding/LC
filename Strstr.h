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
		//�����i��ֵ���������
		//����souce �� ATCAAGTTACCAATA   len��15
		//target �� ATA  len ��3
		//��ô���ѭ���͵� 12��ֹͣ��  15-3 +1 =13
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