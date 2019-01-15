#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> indices;
		map<int, int> valueIndices;

		for (int i = 0; i < nums.size(); i++) {
			if (valueIndices.find(target - nums[i]) != valueIndices.end()) {
				indices.push_back(i);
				indices.push_back(valueIndices[target - nums[i]]);
				return indices;
			}
			valueIndices[nums[i]] = i;
		}
		return indices;
	}
};

int main(int argc, char* argv[])
{
	vector<int> ilist = {1, 2, 5, 6, 10, 9, 3, 4, 8};
	copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	Solution test;
	int target = -1;
	cin >> target;
	
	vector<int> dlist = test.twoSum(ilist, target);
	copy(dlist.begin(), dlist.end(), ostream_iterator<int>(cout, "\n"));
	
	return 0;
}

