#include "my_server.h"
void dispatch(pCLIENT phead, char* msg)
{
	while(phead)
	{
		write(phead->m_send, msg, strlen(msg));
		phead = phead->m_next;
	}
}