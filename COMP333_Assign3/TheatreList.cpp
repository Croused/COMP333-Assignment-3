//Darrell Crouse
//COMP333 Assignment 3
//A quick program to manage a concerts using link lists.

#include "TheatreList.h"
#include <cassert>
#include <iomanip>

TheatreList::TheatreList(int newMaxSeats, string newConcertTitle) {
	firstPtr = NULL;
	concertTitle = newConcertTitle.empty() ? "No Concert Title" : newConcertTitle;
	maxSeats = newMaxSeats < 0 ? 0 : newMaxSeats;
}

TheatreList::~TheatreList() {
	SeatNode * walker = firstPtr;
	while (walker != NULL) {
		walker = walker->link;
		delete firstPtr;
		firstPtr = walker;
	}
}

void TheatreList::showReservations(ostream & output) const {
	SeatNode *walker = firstPtr;

	output << "Concert Title: " << concertTitle << endl;
	output << left << setw(25) << "Name" << setw(25)
		<< "Seat" << endl << endl;

	while (walker != NULL) {
		output << left << setw(25) << walker->patronName
			<< setw(25) << walker->seatNo << endl;
		walker = walker->link;
	}

	output << endl << "There are " << numSeatsSold
		<< " seats reserved." << endl;
}

void TheatreList::reserveSeat(string patronName, int seatNum) {
	SeatNode * walker = firstPtr;
	SeatNode * stalker = NULL;

	patronName = patronName.empty() ? "No Name Provided" : patronName;
	seatNum = seatNum < 0 ? 0 : seatNum;

	while (walker != NULL) {
		if (walker->seatNo >= seatNum)
			break;

		stalker = walker;
		walker = walker->link;
	}

	if ((walker != NULL && walker->seatNo == seatNum) || numSeatsSold >= maxSeats) {
		cout << "Unable to add seat" << endl;
	}
	else {
		SeatNode * newSeat = new SeatNode;
		assert(newSeat);

		newSeat->patronName = patronName;
		newSeat->seatNo = seatNum;
		newSeat->link = walker;
		numSeatsSold++;
		if (stalker == NULL) {
			firstPtr = newSeat;
		}
		else {
			stalker->link = newSeat;
		}
	}
}

void TheatreList::removeSeat(int seatNum) {
	SeatNode * walker = firstPtr;
	SeatNode * stalker = NULL;

	while (walker != NULL) {
		if (walker->seatNo == seatNum)
			break;

		stalker = walker;
		walker = walker->link;
	}

	if (walker != NULL) {
		if (firstPtr == walker) {
			firstPtr = walker->link;
		}
		else {
			stalker->link = walker->link;
		}
		delete walker;
		numSeatsSold--;
	}
	else {
		cout << "Seat Not Found" << endl;
	}
}