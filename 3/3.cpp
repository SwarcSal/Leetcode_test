// Runtime: 20 ms, faster than 98.18% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string dst, sTmp;
        int nSize = s.size();
        int tmp = 0;
        while(tmp < nSize) {
            int nr = sTmp.rfind(s.at(tmp), sTmp.size());
            if (nr != string::npos) {
                if (dst.size() < sTmp.size()) {
                    dst.assign(sTmp);
                }
                sTmp.erase(0, nr + 1);
            }

            sTmp.append(1, s.at(tmp));   

            tmp ++;
        }
        return dst.size() > sTmp.size()?dst.size():sTmp.size();
    }
};
