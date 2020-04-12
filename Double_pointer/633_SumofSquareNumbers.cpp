/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-04-12 13:58:04
 * @LastEditors: youngchany
 * @LastEditTime: 2020-04-12 22:47:01
 */
/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
 

示例2:

输入: 3
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// sqrt()
// 注意越界

// Double Pointer
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了78.89%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
#include <cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
		if (c < 0)
			return false;
		int l = 0, r = sqrt(c);
        while (l <= r) {
            if (l * l > c - r * r) {
                r --;
            }
            else if (l * l < c - r * r) {
                l ++;
            }
            else if (l * l == c - r * r) {
                return true;
            }
        }
        return false;
    }
};