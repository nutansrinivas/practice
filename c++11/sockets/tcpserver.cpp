#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


/* STRUCTURES - SOCKET 

	struct sockaddr 
	{
		unsigned short sa_family;
		char sa_data[14];
	};	

	struct in_addr { unsigned long s_addr; }  //32-bit ip addres in n/w byte order 

	struct sockaddr_in 
	{
		short int sa_family;
		unsigned short int sin_port;
		struct in_addr sin_addr;
		unsigned char sin_zero[8];
	}

	struct hostent
	{
		char *h_name;
		char **h_aliases;
		int 	h_addrtype;
		int 	h_length;
		char	**h_addr_list; -> struct :q

	}
*/

class TCPClient 
{
	public : 
		TCPClient();
		connect(std::string & hostName, unsigned int port, bool isHostIP=true);
}
