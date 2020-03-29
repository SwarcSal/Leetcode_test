/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-03-26 23:04:16
 * @LastEditors: youngchany
 * @LastEditTime: 2020-03-28 23:31:00
 */
#include <string>
#include <vector>

// 分治法 
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了58.78%的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了10.64%的用户
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }

    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) return strs[l];

        int mid = (l+r)/2;
        string lcpLeft = longestCommonPrefix(strs, l, mid);
        string lcpRight = longestCommonPrefix(strs, mid+1, r);
        return CommonPrefix(lcpLeft, lcpRight);
    }
    
    string CommonPrefix(string left, string right)
    {
        int nMin = left.size() > right.size()? right.size():left.size();
        
        for(int i = 0; i < nMin; i ++) {
            if (left[i] != right[i])
                return left.substr(0, i);
        }
        return left.substr(0, nMin);
    }
};


// 二分法