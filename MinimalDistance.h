#pragma once
#include<vector>
#include<iostream>
#include<algorithm>


//���ö��֡������� ��TLE
std::vector<int>  minimalDistance(std::vector<int>& a, std::vector<int>& b)
{
	std::vector<int> res;
	for (size_t i = 0; i < b.size(); i++)
	{
		int temp = INT_MAX;
		int Last_J = 0;
		for (size_t j = 0; j < a.size(); j++)
		{
			int diff = abs(b[i] - a[j]);
			if (diff < temp)
			{
				temp = diff;
				Last_J = j;
			}
			if (diff == temp && a[j] < a[Last_J])
				Last_J = j;
		}
		res.push_back(a[Last_J]);
	}
	return res;
}



std::vector<int> minimalDistance_logN(std::vector<int>& a, std::vector<int>& b)
{

	std::vector<int> res;
	//��a����
	std::sort(a.begin(), a.end());
	//��b�е�ÿ��Ԫ����a�н����۰����
	for (size_t i = 0; i < b.size(); i++)
	{
		int single_res = 0;
		int start = 0;
		int end = a.size();
		int mid = start + (end - start) / 2;
		while (start +1 < end)
		{
			if (b[i]<= a[mid] && start + 1 < end)
				end = mid;
			if (b[i] >= a[mid] && start + 1 < end)
				start = mid;
		}
		//
		if(abs(b[i] - a[start]) <= abs(b[i] - a[end]) && a[start] <=a[end])
		{
			single_res = a[start];
		}
		else
		{
			single_res = a[end];
		}
		res.push_back(single_res);
	}

}