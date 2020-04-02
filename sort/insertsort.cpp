//
// Created by ycy37 on 2020/4/2.
// InsertSort : O(n^2)
//
#include <iostream>
#include <vector>
using namespace std;
void insertsort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int tmp = nums[i];
        int j = i;
//        for (; j > 0 && nums[j] < nums[j-1]; --j) {
//            swap(nums[j], nums[j-1]);
//        }
        for (; j > 0 && nums[j-1] > tmp; --j) {
            nums[j] = nums[j-1];
        }
        nums[j] = tmp;
    }

}

int main() {
    std::cout << "insertsort!" << std::endl;
    vector<int> nums = {10, 3, 6, 3, 2, 6, 8};
    insertsort(nums);
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
