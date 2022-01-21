#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <unordered_set>

//possible substring of a string is : n * (n+1) / 2
//
void printAllSubstringsOf(std::string & istr, int len)
{
	for (int pos = 0; pos < len; ++pos)
	for (int i = pos; i < len; ++i) std::cout << istr.substr(pos, i-pos+1) << std::endl ;
	
	return ;
}

//assuming all are small characters
bool hasDistinctChars(std::string & str)
{
	char alphabets[26] = {0,};

	for (int i=0; i<str.length(); ++i) 
		if (alphabets[str[i]] == 0) ++alphabets[str[i]] ;
		else return false;
	return true;
}

//get list of strings which has k distrinct characters, and length of string >= k
std::vector<std::string> getAllSubStringsWithDC(std::string & istr, int len, int dcCnt)
{
	std::vector<std::string> dcSubStr;
	std::unordered_set<std::string> uniqueSubStrOfDC;

	char alphabets[26] ;

	for (int pos = 0; pos < len; ++pos)
	{
		memset(alphabets, 0, sizeof(alphabets));
		int dcCntLocal = 0;

		for (int i = pos; i < len; ++i)
		{
			if (alphabets[istr[i] - 'a'] == 0) ++dcCntLocal ; 
			else break; //else is needed only non repetative chars | str length k with k distinct chars

			++alphabets[istr[i] - 'a'] ;

			if (dcCntLocal == dcCnt) 
			{
				std::string dcStr = istr.substr(pos, i-pos+1);
				std::cout << dcStr << std::endl;
				dcSubStr.push_back(dcStr);
				uniqueSubStrOfDC.insert(dcStr);   //to print unique substrings
			}

			if (dcCntLocal >= dcCnt) break;
		}
	}	
	return dcSubStr;
}



//abcd
int getCountOfAllSubStringsWithDC(std::string istr)
{
	int alphabets[26] = {0,};
	int i = 0, j = 0, ans = 0, n = istr.length();
	
	for (i = 0; i < n;)
	{
		if (j < n && alphabets[istr[j] - 'a'] == 0)
		{
			alphabets[istr[j]]++;
			ans += j - i + 1;   //list of substrings end with position j , start position j to i
			++j;
		}
		else
		{
			alphabets[istr[j] - 'a']--;
			++i;
		}
	}
	return ans;
}

//default call is getAllSubSequence("abcd", "");
void getAllSubSequence(std::string istr, std::string ostr)
{
	if (istr.empty()) 
	{
		std::cout << " - " << ostr ;
		return;
	}

	getAllSubSequence(istr.substr(1), ostr+istr[0]);
	getAllSubSequence(istr.substr(1), ostr);
}



int main()
{
	std::string inputStr;

	std::cout << std::endl << "enter the string : ";
	std::cin >> inputStr;
	std::cout << std::endl ;

	//printAllSubstringsOf(inputStr, inputStr.length());
	//std::vector<std::string>  usubstr = getAllSubStringsWithDC(inputStr, inputStr.length(), 3);
	getAllSubSequence(inputStr, "");
	return 0;
}
