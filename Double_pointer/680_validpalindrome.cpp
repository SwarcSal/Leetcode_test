/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-04-13 23:14:35
 * @LastEditors: youngchany
 * @LastEditTime: 2020-04-13 23:37:57
 */
/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Double Pointer
/*
执行用时 :84 ms, 在所有 C++ 提交中击败了64.51%的用户
内存消耗 :23.8 MB, 在所有 C++ 提交中击败了41.67%的用户
*/
class Solution {
public:
    bool validPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;

		for(; i < j; i++, j--)
        {
			if (s.at(i) != s.at(j))
			{
				return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
			}
		}
		return true;
	}

	bool isPalindrome(string s, int i, int j)
	{
		while (i < j)
		{
			if (s.at(i++) != s.at(j--))
				return false;
		}
		return true;
	}
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().validPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}