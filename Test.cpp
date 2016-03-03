#include "host/csr_graph.h"

int main()
{
	APSP::csr_graph host_graph(15);
	
	for(int i=0; i<10; i++)
	{
		host_graph.insert(i,i+1,true);
	}
}