
#include <stdio.h>
#include <vector>
#include <iostream>

class Solution {
public:
    
    //[1,0,2,3,0,4,5,0]
    //1, 0,0,2,3,0,4,5  
    //[1,2,3,4,5,6,7,8,9,a]
    //[0,1,9,2,6,0,0,4,1,0]
    //[0, ,1,9,2,6,0,0,4,1]
    void duplicateZeros(vector<int>& arr) {
        
        int cnt=0, len=arr.size();
        int i = 0;
        for (; (i < len-1-cnt) && (len-i-1 > cnt); i++) if (arr[i]==0) ++cnt;
        if (cnt==0) return;
        
        if (((len-1-cnt) == i) && (0 == arr[i]))
        {                    
            arr[len-1] = 0;
            len--;
        }
        
        for (i = len-1-cnt; i>=0; i--)
        {
            if (cnt == 0) return;
            arr[i+cnt] = arr[i];
            
            if (arr[i]==0)
            {    
                arr[i+cnt-1] = 0;
                cnt--;
            }
        }
        
        /*
        for(int i=0; i < arr.size() - 1; ++i)
        {
            if (arr[i] == 0)
            { 
                for(int j = arr.size()-1 ; j > i+1 ; --j) arr[j] = arr[j-1];
                arr[i+1] = 0;
                i++;
            }
        }
        */
    }
};

int main()
{
	//std::vector<int> vt = {9,9,9,4,8,0,0,3,7,2,0,0,0,0,9,1,0,0,1,1,0,5,6,3,1,6,0,0,2,3,4,7,0,3,9,3,6,5,8,9,1,1,3,2,0,0,7,3,3,0,5,7,0,8,1,9,6,3,0,8,8,8,8,0,0,5,0,0,0,3,7,7,7,7,5,1,0,0,8,0,0};
	//std::vector<int> vt = {1,1,0,0,1};
	//std::vector<int> vt = {1,1,0,0};
	//std::vector<int> vt = {1,2,4,0};
	std::vector<int> vt = {1,2,3,0,0,0,7};
	//std::vector<int> vt = {1,2,3,0,0,6};

	Solution sol;

	std::cout << "[" ;
	for (auto i : vt) std::cout << "," << i ;
	std::cout << "]" << std::endl;

	sol.duplicateZeros(vt);

	std::cout << "[" ;
	for (auto i : vt) std::cout << "," << i ;
	std::cout << "]" << std::endl;
}
#if 0
class Solution {
	public:
		//std::vector<int> vt = {1,2,3,0,0,6};
		//i=0,1,2,3,4,  cnt=0,0,0,0,1 r=5,5,5,5,4


		void duplicateZeros(std::vector<int>& arr) {

			if (arr.size() < 2) return ;

			if ((arr.size() == 2) && (arr[0] == 0))
			{
				arr[1] = 0;
				return;
			}

			int i=0, cnt = 0, len = arr.size();

			for (; i < (len-1 - cnt); i++)
			{
				if (arr[i] == 0) cnt++;
			}

			if (cnt == 0) return ;

			if (arr[len-1-cnt] == 0)
			{

			}

			for (i=len-1-cnt; cnt > 0 ; i--)
			{
				arr[len-1] = arr[i];
				std::cout << "shifting from arr[" << i << "] : " << arr[i] << "to arr[" << len-1 << "] : " << arr[len-1] << std::endl;

				if (arr[i] == 0) 
				{
					arr[-2+len--] = 0;
					cnt--;
					std::cout << "duplicate zero arr[" << i << "] : " << arr[i] << "to arr[" << len-1 << "] : " << arr[len-1] << std::endl;
				}
				len--;
			}
		}

};




#endif
