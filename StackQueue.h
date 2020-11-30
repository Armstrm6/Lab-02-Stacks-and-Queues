#include <string>

class IStack {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	/// Adds a value to the Stack.  Returns true if able to add, otherwise false
	virtual bool push(int val) = 0;
	/// removes a value from the stack.   Feturns true if able to remove an element, otherwise false
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns top of stack
	virtual int peek() = 0;
	// outputs tthe stacks contents to a string
	virtual std::string toString() = 0;
	
protected:

};



class ArrayBasedStack : public IStack {
public:
	ArrayBasedStack(void);
	virtual ~ArrayBasedStack();
	bool isEmpty() const override;
	bool push(int val) override;
	bool pop() override;
	//If the ADT is empty throw an exception indicating this
	int peek() override;
	int getSizeS();
	std::string toString() override;
private:
	static const int capacity = 4; //left at 4 for the hanoi game, still functions at any other capacities
	int m_array[capacity];
	int top;
};


class IQueue {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	// Adds a value to the Q.  Returns true if able otherwise false
	virtual bool enQueue(std::string val) = 0;
	// remove a value to the Q.  Returns true if able otherwise false
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns the value of the 
	// front of the Q
	virtual std::string peekFront() = 0;
protected:
};



class  ArrayBasedQueue : public IQueue {

public:
	ArrayBasedQueue(void);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const override;
	bool enQueue(std::string val) override;
	bool deQueue() override;
	int getSizeQ();
	//If the ADT is empty throw an exception indicating this
	std::string peekFront() override;
private:
	static const int capacity = 30; //note left at 30 for the use of moves in the hanoi game.
	std::string m_array[capacity];
	int numTerms;
};










