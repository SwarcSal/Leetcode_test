// SelectionSort : O(n^2)
#include <iostream>
#include <vector>
using namespace std;

void selectsort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int minindex = i;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] < nums[minindex])
                minindex = j;
        }
        if (minindex > i)
            swap(nums[i], nums[minindex]);
    }
}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    vector<int> nums = {10, 3, 6, 3, 2, 6, 8};
//    selectsort(nums);
//    for(int i = 0; i < nums.size(); ++i) {
//        cout << nums[i] << ' ';
//    }
//    cout << endl;
//    return 0;
//}
