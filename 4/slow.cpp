// O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0)
        {
            int size = nums2.size();
            return size%2==1?nums2[size/2]:(float)(nums2[size/2]+nums2[size/2-1])/2;
        }
        if (nums2.size() == 0)
        {
            int size = nums1.size();
            return size%2==1?nums1[size/2]:(float)(nums1[size/2]+nums1[size/2-1])/2;
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len3 = len1 + len2;
        int left = -1, right = -1;
        if (len3 % 2 == 1)
        {
            right = len3 / 2;
            left = right;
        }
        else
        {
            right = len3 / 2;
            left = right - 1;
        }
        cout << "left: " << left << " right: " << right << endl;
        int i1 = 0, i2 = 0;
        int sum = 0, tmp;
        for (int i = 0; i <= right; i++)
        {
            if (i2 >= len2 || (i1 < len1 && i2 < len2 && nums1[i1] <= nums2[i2]))
            {
                tmp = nums1[i1];
                i1 ++;
            }
            else if (i1 >= len1 || (i1 < len1 && i2 < len2 && nums1[i1] > nums2[i2]))
            {
                tmp = nums2[i2];
                i2 ++;
            }

            cout << tmp << endl;
            if (i == left || i == right)
            {
                sum += tmp;
            }
        }
        return right==left?sum:(float)sum/2;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
