/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-03-29 21:17:38
 * @LastEditors: youngchany
 * @LastEditTime: 2020-03-29 21:32:24
 */


// normal
// timeout
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        for (int i = 0; i < height.size() - 1; ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int nHMin = min(height[i], height[j]);
                int nDiff = j - i;
                ans = max(ans, nHMin * nDiff);
            }
        }
        return ans;
    }
};



/*
    Double Pointer
    执行用时 :16 ms, 在所有 C++ 提交中击败了87.67%的用户
    内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
class Solution {
public: 
    int maxArea(vector<int>& height) {
        int pLeft = 0;
        int pRight = height.size() - 1;

        int ans = -1;
        

        while(pLeft < pRight) {
            int high = min(height[pLeft], height[pRight]);
            ans = max(ans, (pRight - pLeft) * high);
            if (height[pLeft] > height[pRight]) {
                --pRight;
            }
            else {
                ++pLeft;
            }
        }
        return ans;
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
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}