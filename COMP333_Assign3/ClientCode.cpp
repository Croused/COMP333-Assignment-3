//Darrell Crouse
//COMP333 Assignment 3
//A quick program to manage a concerts using link lists.

#include <iostream>
#include <string>
#include <cassert>
#include "TheatreList.h"

using namespace std;

int main() {

	TheatreList *newList = new TheatreList(5, "Concert 1");
	assert(newList);

	newList->reserveSeat("Darrell", 2);
	newList->reserveSeat("Hailey", 4);
	newList->reserveSeat("Aiden", 3);
	newList->reserveSeat("Jen", 5);
	newList->reserveSeat("Joe", 1);
	newList->reserveSeat("Jane", 6);
	
	newList->showReservations(cout);

	newList->removeSeat(1);
	newList->removeSeat(6);
	newList->removeSeat(3);
	newList->removeSeat(1);
	newList->showReservations(cout);

	cout << newList;

	delete newList;
	cout << "\n\nEnd Of Program\n";
	system("pause");
}

ostream & operator << (ostream& output, const TheatreList *inputList) {
	output << inputList->concertTitle << " has "
		<< inputList->numSeatsSold << " seats reserved." << endl;
	return output;
}
