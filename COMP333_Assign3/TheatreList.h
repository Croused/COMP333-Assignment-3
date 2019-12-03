#pragma once


#include <iostream>
#include <string>


using namespace std;

struct SeatNode {
	string patronName;
	int seatNo;
	SeatNode * link;
};

class TheatreList {

	private:
		SeatNode * firstPtr;
		string concertTitle;
		int numSeatsSold;
		int maxSeats;

	public:
		TheatreList(int /*Max Seats*/,
					string /*Concert Title*/);
		~TheatreList();
		void showReservations(ostream& /*Output Destination*/) const;
		void reserveSeat(string /*Patron Name*/,
					    int /*Seat Number*/);
		void removeSeat(int /*Seat Number*/);
		int getNoSeat() const { return numSeatsSold; }
		string getConcertTitle() const { return concertTitle; }



};