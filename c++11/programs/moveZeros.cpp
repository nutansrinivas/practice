class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos=0;
        //[0,1,0,3,12]
        for (int i=1; i<nums.size(); i++) 
        {
            if ((0==nums[i-1])) && (0 != nums[i]) nums[pos++] = nums[i];
        }
        
        for (; pos < nums.size()-1;pos++) nums[pos]=0;    
    }
};


for(int j = 0; j < A.size();){
            if(A[j] %2 == 0){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j++;
            }else{
                j++;
            }
        }



				for (int i=0; i < A.size(); i++)
            if (A[i]%2!=0)
            {
                if (epos < 0) epos = i;
            }
            else if ((epos >= 0) && (epos != i))
            {
                int temp = A[epos];
                A[epos++] = A[i];
                A[i] = temp;
            }
            else epos++;
        return A;
    }
