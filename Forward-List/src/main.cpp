#include "fList.hpp"

int main() {
	
	FList<int> list;
	FList<int> list2;
	FList<int> list3;
	FList<int> list4;
	list4.insert(1,0);
	list4.insert(2,1);
	list4.split();
	list.insert(1,0);
	list.insert(2,1);
	list2.insert(4,0);

	merge(list, list2);
	list.print();
	swap(list, list2);
	list2.erase(4);
	list2.print();
}