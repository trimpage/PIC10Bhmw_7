//List.cpp

#include "List.h"

//FREE FUNCTION DEFINITIONS
//swap
void pic10b::swap(LinkedList& firstList, LinkedList& secondList) {
	//swap nodes
	std::swap(firstList.first, secondList.first);
	std::swap(firstList.last, secondList.last);
}

//iterator == operator
bool pic10b::operator==(const iterator& first, const iterator& second) {
	//return bool of whether pointers are equal or not
	return ((first.current == second.current) && (first.container == second.container));
}

//iterator != operator
bool pic10b::operator!=(const iterator& first, const iterator& second) {
	//return opposite of ==
	return !(first == second);
}

//const iterator == operator
bool pic10b::operator==(const const_iterator& first, const const_iterator& second) {
	//return bool of whether pointers are equal or not
	return ((first.current == second.current) && (first.container == second.container));
}

//const iterator != operator
bool pic10b::operator!=(const const_iterator & first, const const_iterator & second) {
	//return opposite of ==
	return !(first == second);
}

//LINKEDLIST CLASS DEFINITIONS
//default constructor
pic10b::LinkedList::LinkedList() noexcept : first(nullptr), last(nullptr) {}

//initializer list constructor
pic10b::LinkedList::LinkedList(std::initializer_list<int> intList) {}

//copy constructor
pic10b::LinkedList::LinkedList(const LinkedList& _list) : first(nullptr), last(nullptr) {
	//for each int in the old list
	for (int i : _list) {
		//push value back
		push_back(i);
	}
}

//move constructor
pic10b::LinkedList::LinkedList(LinkedList&& _list) noexcept : LinkedList() {
	//use swap to swap
	swap(*this, _list);
}

//destructor
pic10b::LinkedList::~LinkedList() {
	//start at first node
	node* newNode = first;

	//while not past the end aka nullptr
	while (newNode != nullptr) {
		//temporarily store next position
		node* temp = newNode->next;

		//delete node on heap
		delete newNode;

		//move newNode to right
		newNode = temp;
	}
}




//push back function
void pic10b::LinkedList::push_back(int value) {
	//create new node
	node* newNode = new node(value);

	//if last node is not null
	if (last) {
		//last points to next
		last->next = newNode;

		//newNode has last as the one before
		newNode->previous = last;

		//update last position
		last = newNode;
	}
	//else last node is null so list is empty
	else {
		first = last = newNode;
	}
}

//pop back function
void pic10b::LinkedList::pop_back() {
	//if list is empty
	if (!last) {
		throw std::logic_error("Cannot pop back on empty list!");
	}
	//else if just one element
	else if (first == last) {
		//free heap memory
		delete first;

		//make pointers null because they are empty
		first = last = nullptr;
	}
	//else there are multiple elements
	else {
		//create new last node
		node* newLast = last->previous;

		//set next pointer to null
		newLast->next = nullptr;

		//free memory
		delete last;

		//update last value
		last = newLast;
	}
}

//insert function
void pic10b::LinkedList::insert(iterator it, int value) {
	//if iterator is null, insert at end
	if (it.current == nullptr) {
		push_back(value);
	}
	//else if first, insert at beginning
	else if (it.current == first) {
		push_front(value);
	}
	//else inserting in the middle
	else {
		//create new node
		node* newNode = new node(value);

		//set next iterator
		newNode->next = it.current;

		//set previous iterator
		newNode->previous = it.current->previous;

		//make previous' next node newNode
		it.current->previous->next = newNode;

		//make current previous node newNode
		it.current->previous = newNode;
	}
}

//erase function 
void pic10b::LinkedList::erase(iterator it) {
	//if removing first value
	if (it.current == first) {
		//pop front value
		pop_front();
	}
	//else if removing last
	else if (it.current == last) {
		//pop back value
		pop_back();
	}
	//else in the middle
	else {
		//reroute next of previous
		it.current->previous->next = it.current->next;

		//reroute previous of next
		it.current->next->previous = it.current->previous;

		//free heap memory
		delete it.current;
	}
}









//NODE CLASS DEFINITIONS
//constructor
pic10b::node::node(int _value) : value(_value), previous(nullptr), next(nullptr) {}








//ITERATOR CLASS DEFINITIONS
//constructor
pic10b::iterator::iterator(node* _node, const LinkedList* _list) : current(_node), container(_list) {}

//prefix ++ operator
pic10b::iterator& pic10b::iterator::operator++() {

}

//postfix ++ operator
pic10b::iterator pic10b::iterator::operator++(int value) {

}

//prefix -- operator
pic10b::iterator& pic10b::iterator::operator--() {
	//if iterator is at first element, can't go backwards
	if (current == container->first) {
		throw std::logic_error("Invalid address!");
	}
	//else if iterator is nullptr, go to last element
	if (current == nullptr) {
		current = container->last;
	}
	//else in the middle
	else {
		//reference previous node
		current = current->previous;
	}
	return *this;
}

//postfix -- operator
pic10b::iterator pic10b::iterator::operator--(int value) {

}

//dereference operator
int& pic10b::iterator::operator*() const {
	//return reference to stored int
	return current->value;
}


//CONST_ITERATOR CLASS DEFINITIONS
//constructor
pic10b::const_iterator::const_iterator(node* _node, const LinkedList* _list) : current(_node), container(_list) {}

//prefix ++ operator
pic10b::const_iterator& pic10b::const_iterator::operator++() {

}

//postfix ++ operator
pic10b::const_iterator pic10b::const_iterator::operator++(int value) {

}

//prefix -- operator
pic10b::const_iterator& pic10b::const_iterator::operator--() {
	//if iterator is at first element, can't go backwards
	if (current == container->first) {
		throw std::logic_error("Invalid address!");
	}
	//else if iterator is nullptr, go to last element
	if (current == nullptr) {
		current = container->last;
	}
	//else in the middle
	else {
		//reference previous node
		current = current->previous;
	}
	return *this;
}

//postfix -- operator
pic10b::const_iterator pic10b::const_iterator::operator--(int value) {

}
//dereference operator
const int& pic10b::const_iterator::operator*() const {
	//return const reference to stored int
	return current->value;
}