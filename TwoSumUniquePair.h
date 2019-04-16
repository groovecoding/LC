#pragma once
//LC 587 twoSumUniquePair
#include<vector>
//Input nums= [1,1,2,45,46,46] target = 47
//output: 2
//Array has been sorted
//two pointers
//
int twoSum6(std::vector<int> &nums, int target)
{
	//可以先对原数组去重
	int validateIndex = removeDuplicate(nums);
	int ans = 0;
	int left = 0;
	int right = validateIndex;  // index
	while (left <= right)
	{
		if (nums[left] + nums[right] < target && left <= right)
			left++;
		if (nums[left] + nums[right] > target && left <= right)
			right--;

		//只有相等的情况才会影响最终的结果，只在相等的情况下处理重复的情况
		if (nums[left] + nums[right] == target)
		{
			//一进来就ans++用的是最右边的值
			ans++;
			while (left < right && nums[right] == nums[right-1])
			{
				right--;
			}
			left++;
			right--;
		}
	}
	return ans;
}


int removeDuplicate(std::vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	
	int j = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i-1])
		{
			j++;
			nums[j] = nums[i];
		}
	}
	return j + 1;
}