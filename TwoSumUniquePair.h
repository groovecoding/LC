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
	//�����ȶ�ԭ����ȥ��
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

		//ֻ����ȵ�����Ż�Ӱ�����յĽ����ֻ����ȵ�����´����ظ������
		if (nums[left] + nums[right] == target)
		{
			//һ������ans++�õ������ұߵ�ֵ
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