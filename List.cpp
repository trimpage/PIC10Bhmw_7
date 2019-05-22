//List.cpp

#include "List.h"

//FREE FUNCTION DEFINITIONS
//operator << overload
std::ostream& operator<<(std::ostream& outStream, const pic10b::LinkedList& list) {
	//size of list variable
	size_t listSize = list.size();

	//for each int in the link
	for (int i : list) {
		//output int
		outStream << i << ' ';
	}

	//spacing
	outStream << '\n';

	return outStream;
}

//swap
void pic10b::swap(LinkedList& firstList, LinkedList& secondList) {
	//swap nodes
	std::swap(firstList.first, secondList.first);
	std::swap(firstList.last, secondList.last);

	//swap sizes
	std::swap(firstList.listSize, secondList.listSize);
}

//search function
bool pic10b::seqSearch(const_iterator firstIt, const_iterator secondIt, int value) {
	//decrement secondIt to exclude that value
	--secondIt;

	//for the range between the iterators
	for (firstIt; firstIt != secondIt; ++firstIt) {
		//if the value matches
		if (*firstIt == value) {
			return true;
		}
		//else continue
		else {
			continue;
		}
	}
	//if loop is over and haven't returned true, must be false
	return false;
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
pic10b::LinkedList::LinkedList() noexcept : first(nullptr), last(nullptr), listSize(0) {}

//initializer list constructor
pic10b::LinkedList::LinkedList(std::initializer_list<int> intList) : first(nullptr), last(nullptr), listSize(0) {
	//for each int in the list
	for (int i : intList) {
		//push back value
		push_back(i);
	}
}

//copy constructor
pic10b::LinkedList::LinkedList(const LinkedList& _list) : first(nullptr), last(nullptr), listSize(0) {
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

//assignment operator
pic10b::LinkedList& pic10b::LinkedList::operator=(LinkedList list) & {
	//if lists are not equal
	if (this != &list) {
		//swap lists
		swap(*this, list);
	}
	return *this;
}

//push back function
void pic10b::LinkedList::push_back(int value) {
	//create new node
	node* newNode = new node(value);

	//if last node is not null
	if (last) {
		//last next is new node
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
	
	//increment size
	++listSize;
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

		//decrement size
		--listSize;
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

		//decrement size
		--listSize;
	}
}

//push front function
void pic10b::LinkedList::push_front(int value) {
	//if list is empty, just push back
	if (!last) {
		push_back(value);
	}
	//else list is not empty
	else {
		//create new node
		node* newNode = new node(value);

		//set next iterator to first
		newNode->next = first;

		//set previous of first node to new node
		first->previous = newNode;

		//set new node to first
		first = newNode;

		//increment size
		++listSize;
	}
}

//pop front function
void pic10b::LinkedList::pop_front() {
	//if list is empty throw error
	if (!last) {
		throw std::logic_error("Cannot pop front on empty list!");
	}
	//else if just one element
	else if (first == last) {
		//free memory
		delete first;

		//make null
		first = last = nullptr;

		//decrement size
		--listSize;
	}
	//else more than one element
	else {
		//create new first node
		node* newFirst = first->next;

		//free heap memory
		delete first;

		//set new node to first
		first = newFirst;

		//decrement size
		--listSize;
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
		
		//increment size
		++listSize;
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

		//decrement size
		--listSize;
	}
}

//sort function
void pic10b::LinkedList::sort() const {
	iterator end = iterator(last, this);

	for (end; end.current != first->next; --end) {
		//create left and right iterators
		iterator left = iterator(first, this);
		iterator right = iterator(first->next, this);
		
		//while iterator right is not at the end
		while (right.current != nullptr) {
			//if value of left is greater than right
			if (left.current->value > right.current->value) {
				//swap nodes
				std::swap(left.current->value, right.current->value);
			}
			++left;
			++right;
		}
	}
}

//iterator begin function
pic10b::iterator pic10b::LinkedList::begin() {
	return iterator(first, this);
}

//iterator end function
pic10b::iterator pic10b::LinkedList::end() {
	return iterator(nullptr, this);
}

//const iterator begin function
pic10b::const_iterator pic10b::LinkedList::begin() const {
	return const_iterator(first, this);
}

//const iterator end function
pic10b::const_iterator pic10b::LinkedList::end() const {
	return const_iterator(nullptr, this);
}

//get size function
size_t pic10b::LinkedList::size() const {
	return listSize;
}

//NODE CLASS DEFINITIONS
//constructor
pic10b::node::node(int _value) : value(_value), previous(nullptr), next(nullptr) {}

//CONST_ITERATOR CLASS DEFINITIONS
//constructor
pic10b::const_iterator::const_iterator(node* _node, const LinkedList* _list) : current(_node), container(_list) {}

//prefix ++ operator
pic10b::const_iterator& pic10b::const_iterator::operator++() {
	//if iterator is at nullptr, can't go forwards
	if (current == nullptr) {
		throw std::logic_error("Invalid address!");
	}
	//else if iterator is at last, set to nullptr
	else if (current == container->last) {
		current = nullptr;
	}
	//else at beginning or middle
	else {
		//reference next node
		current = current->next;
	}
	return *this;
}

//postfix ++ operator
pic10b::const_iterator pic10b::const_iterator::operator++(int value) {
	//copy iterator
	const_iterator copyIt = *this;

	//increment
	++copyIt;

	return copyIt;
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
	//copy iterator 
	const_iterator copyIt = *this;

	//decrement
	--copyIt;

	return copyIt;
}

//dereference operator
const int& pic10b::const_iterator::operator*() const {
	//return const reference to stored int
	return current->value;
}

//ITERATOR CLASS DEFINITIONS
//constructor
pic10b::iterator::iterator(node* _node, const LinkedList* _list) : current(_node), container(_list) {}

//prefix ++ operator
pic10b::iterator& pic10b::iterator::operator++() {
	//if iterator is at nullptr, can't go forwards
	if (current == nullptr) {
		throw std::logic_error("Invalid address!");
	}
	//else if iterator is at last, set to nullptr
	else if (current == container->last) {
		current = nullptr;
	}
	//else at beginning or middle
	else {
		//reference next node
		current = current->next;
	}
	return *this;
}

//postfix ++ operator
pic10b::iterator pic10b::iterator::operator++(int value) {
	//copy iterator
	iterator copyIt = *this;

	//increment
	++copyIt;

	return copyIt;
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
	//copy iterator 
	iterator copyIt = *this;

	//decrement
	--copyIt;

	return copyIt;
}

//dereference operator
int& pic10b::iterator::operator*() const {
	//return reference to stored int
	return current->value;
}

