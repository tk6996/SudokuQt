#ifndef STACKUNDO_H
#define STACKUNDO_H

#include <stack>
class StackUndo
{
	public:
		struct DataSudoku
		{
			int position;
			int prev;
		};
		StackUndo();
		void record(int position,int prev);
		DataSudoku undo();
	private:
		std::stack<DataSudoku> container;
};

#endif // STACKUNDO_H
