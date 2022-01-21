
/*

const char* ptr - a pointer to a constant character. it means data is constant. not pointer. so we can change the value of ptr but not the data in the address pointer to ptr. 

char* const ptr - constant pointer to a character. it means ptr can assign only once with one address, we can't change the address it points too, however we can change the value in that address.

const char* const ptr - constant pointer to a constant character
	char const * const ptr is same as const char *const ptr.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a='A', b='B';
	const char* ptr = &a; //here we can assign different values to ptr

	char* const ptr2 = &a;	// we can't reassign a value to ptr2 again

	ptr = &b; //is valid 
	
//	ptr2 = &b //is invalid

	//*ptr = 'c' ; //is invalid
	*ptr2 = 'c' ; 

	return 0;
}
