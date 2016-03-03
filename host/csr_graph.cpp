#include "csr_graph.h"

void APSP::csr_graph::insert(int a,int b,bool direction)
{
	columns.push_back(b);
	rows.push_back(a);

	Edges++;

	if(!direction)
		insert(b,a,true);
}

void APSP::csr_graph::calculateDegreeandRowOffset()
{

	assert(Nodes > 0);
	assert(Edges > 0);

	rowOffsets.resize(Nodes + 1);
	degree.resize(Nodes);

	for(int i=0;i<Nodes;i++)
	{
		rowOffsets[i] = 0;
		degree[i] = 0;
	}

	rowOffsets[Nodes] = 0;

	//Allocate a pair array for rows and columns array
	std::vector<std::pair<unsigned,unsigned> > combined;
	
	//copy the elements from the row and column array
	for(int i=0;i<rows.size();i++)
		combined.push_back(std::make_pair(rows[i],columns[i]));

	//Sort the elements first by row, then by column
	std::sort(combined.begin(),combined.end(),comparator());

	//copy back the elements into row and columns
	for(int i=0;i<rows.size();i++)
	{
		rows[i] = combined[i].first;
		columns[i] = combined[i].second;
	}

	combined.clear();

	//Now calculate the row_offset

	for(int i=0;i<rows.size();i++)
	{
		unsigned curr_row = rows[i];
		
		rowOffsets[curr_row]++;
	}

	int prev = 0,current;

	for(int i=0;i<=Nodes;i++)
	{
		current = rowOffsets[i];
		rowOffsets[i] = prev;
		prev += current;

		if(i != Nodes )
			degree[i] = current - rowOffsets[i];
	}

	assert(rowOffsets[Nodes] == rows.size());
}