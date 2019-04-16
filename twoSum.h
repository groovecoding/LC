#pragma once
#include<vector>
#include<map>
// LC608
//TwoSum using Hash


std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::map<int, int> temp;
	std::vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		if (temp.find(target-nums[i]) != temp.end())
		{
			res.push_back(temp[target - nums[i]]); //��Ϊtemp��������±��С�����������ǰ��
			res.push_back(i + 1); //�±��1��ʼ��������Ҫ��1
		}
		temp[nums[i]] = i + 1;  //�±��1��ʼ��������Ҫ��1
	}
}



