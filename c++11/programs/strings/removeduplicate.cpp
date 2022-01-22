
std::string removeDuplicate(std::string  str)
{
	int index = 0, strLen = str.size();
	int uniqueIndex = 0;

	while (index < strLen-1)
	{
		++index;
		if (str[uniqueIndex] != str[index]) 
		{
			++uniqueIndex;
			str[uniqueIndex] = str[index];
		}
	}
}
