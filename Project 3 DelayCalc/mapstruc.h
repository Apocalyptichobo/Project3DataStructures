#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>
#include <map>a
#include <sstream>
using namespace std;

class MapS {
private:
	struct Flight
	{
		int date;
		string carrier;
		string flight_number;

		string origin;
		string destination;

		int crs_dept_time;
		int dept_time;
		int dep_delay;

		int taxi_out;
		int wheels_off;

		int wheels_on;
		int taxi_in;

		int crs_arr_time;
		int arr_time;
		int arr_delay;

		int cancelled;

		string cancel_code;

		int diverted;

		int crs_elapsed_time;
		int actual_elapsed_time;

		int air_time;
		int distance;

		int carrier_delay;
		int weather_delay;

		int nas_delay;
		int security_delay;
		int late_aircraft_delay;
	};

public:
	map<int, Flight> data; //key first line, value is the flight data
	MapS();
	MapS(int year);
	int total(string key); //total X's at airport. 
	float average(string key); //average X's at airport.


};