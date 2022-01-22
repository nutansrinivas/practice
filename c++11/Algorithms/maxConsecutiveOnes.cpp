

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int activeCnt = 0;
        for (auto i : nums)
        {
            if (i == 1) ++activeCnt;
            }
            else
            {
                if (maxCnt < activeCnt) maxCnt = activeCnt;
                activeCnt = 0;
            }
        }
        if (maxCnt < activeCnt) maxCnt = activeCnt;
       return maxCnt;
    }
};
