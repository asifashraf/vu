// Assignment01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Assignment01.h"

template <typename Elem>
class List
{

private:

	//protect assignment
	void operator = (const List&) {}

	//protect copy constructor
	List(const List&) {}

public:

	// default constructor
	List() {}

	//base destructor
	virtual ~List() {}

	//Reinit
	virtual void clear() = 0;
	virtual bool insert(const Elem&) = 0;
	virtual bool append(const Elem&) = 0;
	virtual Elem remove() = 0;
	virtual void moveToStart() = 0;
	virtual void moveToEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int leftLength() const = 0;
	virtual int rightLength() const = 0;
	virtual void movetoPos(int pos) = 0;
	virtual const Elem& getValue() const = 0;
};


int main()
{
	//lets assume we can initialize list even if abstract
	//since question asks us NOT to implement the list
	List<int> L1;

	//=================================================================
	// ANSWER # 1 of a)
	// Assume a list has the following configuration : < | 2, 23, 15, 5, 9 >.
	//Write only Method calls(Name of function) 
	//using the List ADT of Figure 1(a)to delete the element with value 15.
	//=================================================================
		
	// ANSWER
	//if we don't know 15's position then
	int toFindAndDelete = 15;	
	while (true)
	{
		L1.next();
		if (L1.getValue() == toFindAndDelete) 
		{
			L1.remove();
			break;
		}
	}
	//Configurations during the answer
	//< | 2, 23, 15, 5, 9 > 
	//< 2, | 23, 15, 5, 9 >
	//< 2, 23, | 15, 5, 9 >
	//Remove function called
	//< 2, 23, | 5, 9 >


	//=================================================================
	// ANSWER # 2 of a)
	// Assume a list has the following configuration : < | 2, 23, 15, 5, 9 >.
	//Write only Method calls(Name of function) 
	//using the List ADT of Figure 1(a)to delete the element with value 15.
	//=================================================================

	// ANSWER
	// if we know 15's position then 
	int knownPosition = 2; // Known position, just written for simplicity
	L1.movetoPos(knownPosition);
	L1.remove();
	//Configurations during the answer
	//< 2, 23, | 15, 5, 9 >
	//Remove function called
	//< 2, 23, | 5, 9 >

	
	//=================================================================
	// ANSWER # 1 of b)	
	//b)  Show the list configuration resulting from each series of list operations using the List ADT of Figure 1(a) 
    // Assume that list L1 is empty at the beginning of each series. Show where the fence is in the list.
	//L1.append(10);
	//L1.append(20); 
	//L1.append(15);
	//=================================================================

	//Lets make sure list has no elements and fence is at zero index
	L1.clear(); //< | >

	L1.append(10);
	L1.append(20); 
	L1.append(15);
	
	//Since this is just an abstract class and doesn't show the
	//code of append/insert functions, we can assume we can 
	//implement insert/append functions in two ways.

	//Way # 1
	//Configuration if coded to move fense after inserted/appended element
	//< | >
	//< 10 | >
	//< 10, 20 | >
	//< 10, 20, 15 | >

	//Way # 2
	//Configuration if coded to move fense before inserted/appended element
	//< | >
	//< | 10 >
	//< 10, | 20 >
	//< 10, 20, | 15 >

	return 0;
}

