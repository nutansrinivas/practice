#include <iostream>

//forgeeksskeegfor

int validatePalindrom(std::string & str, int & midLeft, int & midRight, int strLen, int & paLen)
{
	while (midLeft >= 0 && midRight < strLen)
	{
			if (str[midLeft] != str[midRight]) break;
			--midLeft;
			++midRight;
			paLen+=2;
	}
	return paLen;	
}

int main()
{
	
	std::cout << "Enter the input string : " << std::endl ;
	std::string inputStr;

	getline(std::cin, inputStr);
	int inputStrLen = inputStr.size(); 
	int maxPalindromeLen = 1;
	int palindromeStartIndex = 0;

	for (int i=1; i < inputStrLen; ++i)
	{
		int paLen = 0;
		int midLeft = i-1, midRight = (i-1);

		if ((++midRight < inputStrLen) && (inputStr[midLeft] == inputStr[midRight])) 
			validatePalindrom(inputStr, midLeft, midRight, inputStrLen, paLen);
		
		if (paLen > maxPalindromeLen)
		{
			palindromeStartIndex = midLeft+1;
			maxPalindromeLen = paLen;
		}

		if ((++midRight < inputStrLen) && (inputStr[midLeft] == inputStr[midRight])) 
			validatePalindrom(inputStr, midLeft, midRight, inputStrLen, ++paLen);

		if (paLen > maxPalindromeLen)
		{
			palindromeStartIndex = midLeft+1;
			maxPalindromeLen = paLen;
		}
	}

	std::cout << "Givent Input : " << inputStr << std::endl;
	std::cout << "MaxPalindrom Len : " << maxPalindromeLen << ", and start index : " << palindromeStartIndex << std::endl;
	std::cout << "MaxPalindrom : " << inputStr.substr(palindromeStartIndex, maxPalindromeLen) << std::endl;
}


