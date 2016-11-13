template <class T>
class Stack
{

public:

	Stack();

	int empty(void); // 1=true, 0=false

	int push(T &); // 1=successful,0=stack overflow

	T pop(void);

	T peek(void);

	~Stack();

private:
	
	int top;
	
	T* nodes;

};