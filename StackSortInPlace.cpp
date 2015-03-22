// Program to sort a stack without using any external space. Basically sort a stack in place. 

#include <iostream>
#include <stack>

class SortStackInPlace
{
    public:
        void print_stack(const std::stack<int> &_stack)
        {
                std::stack<int> temp_stack(_stack);
                for(;temp_stack.size()>0;)
                {
                        std::cout<<"data: "<<temp_stack.top()<<std::endl;
                        temp_stack.pop();
                }
        }

	void swap(int &_first, int &_second)
	{
		std::cout<<_first<<"::"<<_second<<std::endl;
		_first = _first+_second;
		_second = _first - _second;
		_first = _first - _second;
		std::cout<<_first<<"::"<<_second<<std::endl;
	}
	
	void sort_stack_rec(int nTop, std::stack<int> &_stack)
	{
		std::cout<<"in sort: "<<nTop<<std::endl;
		if(_stack.size() == 0)
		{
			_stack.push(nTop);
			return;
		}	
		int top = _stack.top();
		std::cout<<"top: "<<top<<std::endl;
		if(top < nTop)
		{
			swap(top, nTop);
		}
		_stack.pop();
		sort_stack_rec(top, _stack);
		std::cout<<"push: "<<nTop<<std::endl;
		_stack.push(nTop);
		print_stack(_stack);
	}

	void sort_stack(std::stack<int> &_stack)
	{
		for(int i = 1; i < _stack.size(); i++)
		{
			int top = _stack.top();
			_stack.pop();
			sort_stack_rec(top, _stack);
		}
	}
        
};

int main()
{
    SortStackInPlace obj;

    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(9);
    myStack.push(5);
    std::cout<<"first"<<std::endl;
    obj.print_stack(myStack);
    obj.sort_stack(myStack);
    std::cout<<"final"<<std::endl;
    obj.print_stack(myStack);

    return 0;
}
