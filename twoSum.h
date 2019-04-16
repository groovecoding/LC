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



std::vector<int> twoSum_TwoPointer(std::vector<int>& nums, int target)
{
	// write your code here
	//use two pointer
	std::vector<int> res;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		if (nums[left] + nums[right] > target && left <= right)
			right--;
		if (nums[left] + nums[right] < target && left <= right)
			left++;
		if (nums[left] + nums[right] == target)
		{
			res.push_back(left + 1);
			res.push_back(right + 1);
			return res;
		}
		//����ֻ��һ���𰸣������ҵ��Ϳ���return

	}
}