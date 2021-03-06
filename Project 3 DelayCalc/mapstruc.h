#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

class MapS {
private:
	struct Flight
	{
		string carrier; //company VF DL

		string origin; //airport ATL,
		string destination; //airport

		int crs_dept_time; //scheduled departure time, ####
		int dept_time; //actual departure time, ####
		int dep_delay; //delay time

		int taxi_out; //need
		int taxi_in; //need

		int arr_delay; //second delay time

		int cancelled; 

		int crs_elapsed_time; //keep just in case
		int actual_elapsed_time; //keep just in case

		int air_time; //time in the air
		int distance; //keep just in case
		//delays
		int carrier_delay; //time delayed
		int weather_delay; //time delayed
		int nas_delay;	   //time delayed	
		int security_delay; //time delayed
		int late_aircraft_delay; //time delayed
	};

public:
	map<string, Flight> data; //key first line, value is the flight data
	map<string, string> carrier;
	map<string, string> airports;
	vector<string> delays{"CARRIER", "WEATHER", "NAS", "SECURITY", "LATE_AIRCRAFT"};
	MapS();
	MapS(string d);
	void Option1(string input);//done
	void Option2(string& input, string& input2);//done
	void Option3(string& input);//done
	void Option4(string& input);//done
	void Option5(string& input);//done
	bool exist(string& o, string& d);
	//company option 1 (DONE)
	int comAvgDelay(string search); //average delay time for company (done)
	string comDelayType(string search); //most common delay type for company (done)
	float comPerDelayed(string search); //percentage of flights delayed for company (done)
	int comAvgTravelTime(string search); //average travel time for company (done)
	int comNumLaunched(string search); //number of planes launched for company (done)
	int comNumDelayed(string search); //number of planes delayed for company (done)

	//arrival/departure option 2 (DONE)
	int ADAvgDelay(string& o, string& d); //average delay time for A/D (done)
	string ADDelayType(string& o, string& d); //average delay type for company A/D (done)
	float ADPerDelayed(string& o, string& d); //percentage of flights delayed for A/D (done)
	pair<int,int> avgTaxiTime(string& o, string& d); //gets taxi in and out time for A/D, first position is in, second is out (done)
	int ADNumLaunched(string& o, string& d); //number of planes launched (done)
	int ADNumDelayed(string& o, string& d); //number of planes delayed (done)

	//airport option 3 (DONE) 
	int airAvgDelay(string& search); //average X's at airport.
	string airDelayType(string& search); //find the most common type of delay for given airport 
	float airPercentDelayed(string& search); //percentage delayed at given airport 
	string airCarrier(string& search); //most common airline flown from given airport
	int airAvgTravelTime(string& search); //average travel time at given airport 
	pair<int, int> airNumFlown(string& search); //flights to and from, in that order returned
	int airNumDelayed(string& search); //number of planes delayed at given airport 

	//type of delay option 4
	int avgDelay(string& search); //average delay time for given delay
	//pair<vector<string>, vector<string>> airportHighLow(string search);
	int avgTravelTime(string& search); //average travel time for given delay
	//string bestAirport(string search); //best airport to travel with given delay
	//Option 4 - delays
	// CARRIER
	// WEATHER
	// NAS
	// SECURITY
	// LATE_AIRCRAFT
	//departure time option 5 (DONE)
	int timeAvgDelay(string& time); //average delay time for given time (done)
	string timeDelayType(string& time); //find the most common type of delay for given time (done)
	pair<vector<string>, vector<string>> airportDelayTimes(string& time); //finds the airports with the best and worst delay time for the given time, first is best second is worst (done)
	float timePercentDelayed(string& time); //percentage delayed at given time (done)
};

