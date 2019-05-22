//List.h

#ifndef LIST
#define LIST
#include <iostream>
#include <stdexcept>

namespace pic10b {
	//declare node and iterator classes
	class node;
	class iterator;
	class const_iterator;

	//LinkedList class
	class LinkedList {
		//declare friends
		friend iterator;
		friend const_iterator;

		//declare swap as friend so it can access list nodes
		friend void swap(LinkedList& firstList, LinkedList& secondList);

	public:
		//default constructor
		LinkedList() noexcept;

		//initializer list constructor
		LinkedList(std::initializer_list<int> intList);

		//copy constructor
		LinkedList(const LinkedList& _list);

		//move constructor
		LinkedList(LinkedList&& _list) noexcept;

		//destructor
		~LinkedList();

		//assignment operator
		LinkedList& operator=(LinkedList list) &;

		/*
		push back function to add given value at end of list
		@param value: int to push back
		*/
		void push_back(int);

		/*
		pop back function to remove value from end of list
		*/
		void pop_back();

		/*
		push front function to add value to beginning
		@param value: value to be added
		*/
		void push_front(int value);

		/*
		pop front function to remove value from beginning
		*/
		void pop_front();

		/*
		function to insert value before given position
		@param it: position to insert at
		@param value: int to insert
		*/
		void insert(iterator it, int value);

		/*
		function to erase value at position
		@param it: position to erase value at
		*/
		void erase(iterator it);

		/*
		function to sort list elements in ascending order
		*/
		void sort();

		/*
		function to obtain beginning iterator
		@return: beginning iterator
		*/
		iterator begin();

		/*
		function to obtain end iterator
		@return: end iterator
		*/
		iterator end();

		/*
		function to obtain const beginning iterator
		@return: const beginning iterator
		*/
		const_iterator begin() const;

		/*
		function to obtain const end iterator
		@return: const end iterator
		*/
		const_iterator end() const;

		/*
		function to get size of list
		@return: size variable of list
		*/
		size_t size() const;

	private:
		//pointers to first and last nodes
		node* first;
		node* last;

		//size variable for list size
		size_t listSize;

	};

	//node class
	class node {
		//declare friends
		friend LinkedList;
		friend iterator;
		friend const_iterator;

	private:
		//data for ints
		int value;

		//previous and next nodes
		node* previous;
		node* next;

		//constructor for new node
		node(int _value);
	};

	// const iterator class
	class const_iterator {
		//declare friends
		friend LinkedList;
		friend iterator;

	public:
		//prefix ++ operator
		const_iterator& operator++();

		//postfix ++ operator
		const_iterator operator++(int value);

		//prefix -- operator
		const_iterator& operator--();

		//postfix -- operator
		const_iterator operator--(int value);

		//dereference operator
		const int& operator*() const;

		//comparison operator
		friend bool operator==(const const_iterator& first, const const_iterator& second);

	private:
		//node currently being managed
		node* current;

		//LinkedList being managed
		const LinkedList* container;

		//constructor accepting node and list to point to
		const_iterator(node* node, const LinkedList* list);
	};

	//iterator class
	class iterator {
		//declare friends
		friend LinkedList;

	public:
		//prefix ++ operator
		iterator& operator++();

		//postfix ++ operator
		iterator operator++(int value);

		//prefix -- operator
		iterator& operator--();

		//postfix -- operator
		iterator operator--(int value);

		//dereference operator
		int& operator*() const;

		//conversion operator from iterator to const iterator
		operator const_iterator() const {
			return const_iterator(current, container);
		}

		//comparison operator
		friend bool operator==(const iterator& first, const iterator& second);

	private:
		//node currently being managed
		node* current;

		//LinkedList being managed
		const LinkedList* container;

		//constructor accepting node and list to point to
		iterator(node* node, const LinkedList* list);
	};

	/*
	swap declaration for fully qualified lookup, swaps pointers of linked lists
	@param first: first list to be swapped
	@param second: second list to be swapped
	*/
	void swap(LinkedList& firstList, LinkedList& secondList);

	/*
	search function to return whether or not given value is found in the given range of the list
	@param firstIt: start iterator
	@param secondIt: end iterator
	@param value: value to search for
	*/
	bool seqSearch(const_iterator firstIt, const_iterator secondIt, int value);

	//operator declarations for fully qualified lookup
	bool operator==(const iterator& first, const iterator& second);
	bool operator!=(const iterator& first, const iterator& second);

	bool operator==(const const_iterator& first, const const_iterator& second);
	bool operator!=(const const_iterator& first, const const_iterator& second);
}

//operator << overload declaration
std::ostream& operator<<(std::ostream& outStream, const pic10b::LinkedList& list);

#endif	
