#ifndef _APSP_CSR_GRAPH
#define _APSP_CSR_GRAPH 

#include <utility>
#include <algorithm>

#include <vector>
#include <string>

#include <assert.h>

namespace APSP
{

class csr_graph
{
	struct comparator
	{
		bool operator()(const std::pair<unsigned,unsigned> &a,const std::pair<unsigned,unsigned> &b) const
		{
			if(a.first < b.first)
				return true;
			else if(a.first > b.first)
				return false;
			else
				return (a.second < b.second);
		}
	};;

public:

	int Nodes,Edges;

	std::vector<unsigned> rowOffsets;
	std::vector<unsigned> columns;
	std::vector<unsigned> rows;

	std::vector<unsigned> degree;

	csr_graph(int nodes)
	{
		Nodes = nodes;
		Edges = 0;
	}

	~csr_graph()
	{
		rowOffsets.clear();
		columns.clear();
		rows.clear();
		degree.clear();
	}

	void insert(int a,int b,bool direction);

	void calculateDegreeandRowOffset();

};

}

#endif