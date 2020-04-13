/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-04-13 22:39:35
 * @LastEditors: youngchany
 * @LastEditTime: 2020-04-13 23:14:09
 */
/*
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Double Pointer
/*
执行用时 :32 ms, 在所有 C++ 提交中击败了6.29%的用户
内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
class Solution {
public:
	vector<char> vowels = {'a', 'o', 'e', 'i', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	string reverseVowels(string s) {
		int i = 0, j = s.size() - 1;

		while(i < j)
		{
			char ci = s.at(i);
			char cj = s.at(j);
			if (find(vowels.begin(), vowels.end(), ci) == vowels.end())
			{
				s[i++] = ci;
			}
			else if (find(vowels.begin(), vowels.end(), cj) == vowels.end())
			{
				s[j--] = cj;
			}
			else
			{
				s[i++] = cj;
				s[j--] = ci;
			}
		}
		return s;
	}
};