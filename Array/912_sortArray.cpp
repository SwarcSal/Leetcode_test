/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-03-31 22:51:43
 * @LastEditors: youngchany
 * @LastEditTime: 2020-03-31 23:07:11
 */
#include <iostream>
#include <vector>

// 快速排序
class Solution {
	int partition(vector<int>& nums, int l, int r) {
		int pivot = nums[r];
		int i = l - 1;
		for (int j = l; j < r; ++j) {
			if (nums[j] < pivot) {
				i += 1;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i+1], nums[r]);
		return i + 1;
	}

    int randomized_partition(vector<int>& nums, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(nums[i], nums[r]);
		return partition(nums, l, r);
	}

    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
