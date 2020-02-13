#include "stackundo.h"

StackUndo::StackUndo()
{

}

void StackUndo::record(int position,int prev)
{
	container.push({position,prev});
}

StackUndo::DataSudoku StackUndo::undo()
{
	if(container.empty())
		return {-1,0};
	StackUndo::DataSudoku val = container.top();
	container.pop();
	return  val;
}
