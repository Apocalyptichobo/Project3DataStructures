#pragma once
#define WIDTH 358
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class GraphS {
private:
    class GFlight
    {
    public:
        int date;
        string carrier; //company VF DL
        string flight_number;

        int crs_dept_time;
        int dept_time;
        int dep_delay; //delay time

        int taxi_out;
        int wheels_off;

        int wheels_on;
        int taxi_in;

        int crs_arr_time;
        int arr_time;
        int arr_delay; //second delay time

        int cancelled;
        string cancel_code;

        int diverted;

        int crs_elapsed_time;
        int actual_elapsed_time;

        int air_time;
        int distance;
        //delays
        int carrier_delay; //time delayed
        int weather_delay; //time delayed
        int nas_delay;	   //time delayed
        int security_delay; //time delayed
        int late_aircraft_delay; //time delayed

        GFlight()
        {

            date = -1;
            carrier = "";
            flight_number = "";

            crs_dept_time = -1;
            dept_time = -1;
            dep_delay = -1;

            taxi_out = -1;
            wheels_off = -1;

            wheels_on = -1;
            taxi_in = -1;

            crs_arr_time = -1;
            arr_time = -1;
            arr_delay = -1;

            cancelled = -1;
            cancel_code = "";

            diverted = -1;

            crs_elapsed_time = -1;
            actual_elapsed_time = -1;

            air_time = -1;
            distance = -1;

            carrier_delay = -1;
            weather_delay = -1;
            nas_delay = -1;
            security_delay = -1;
            late_aircraft_delay = -1;

        }
        GFlight operator=(const GFlight& obj) {

            GFlight g;

            g.date = obj.date;
            g.carrier = obj.carrier;
            g.flight_number = obj.flight_number;

            g.crs_dept_time = obj.crs_dept_time;
            g.dept_time = obj.dept_time;
            g.dep_delay = obj.dep_delay;

            g.taxi_out = obj.taxi_out;
            g.wheels_off = obj.wheels_off;

            g.wheels_on = obj.wheels_on;
            g.taxi_in = obj.taxi_in;

            g.crs_arr_time = obj.crs_arr_time;
            g.arr_time = obj.arr_time;
            g.arr_delay = obj.arr_delay;

            g.cancelled = obj.cancelled;
            g.cancel_code = obj.cancel_code;

            g.diverted = obj.diverted;

            g.crs_elapsed_time = obj.crs_elapsed_time;
            g.actual_elapsed_time = obj.actual_elapsed_time;

            g.air_time = obj.air_time;
            g.distance = obj.distance;

            //delays
            g.carrier_delay = obj.carrier_delay;
            g.weather_delay = obj.weather_delay;
            g.nas_delay = obj.nas_delay;
            g.security_delay = obj.security_delay;
            g.late_aircraft_delay = obj.late_aircraft_delay;

            return g;
        }
    };
    vector<GFlight> data[WIDTH][WIDTH];
    map<string, int> airports;
public:
    GraphS(); //DONE
    void readData(int year); //DONE

    //Option 3
    float avgDelayTime(string& corp); //DONE
    string commonDelay(string& corp); //DONE
    string commonAirline(string& corp); //DONE
    float airPercentDelayed(string& corp); //DONE
    int fromX(string& corp); // DONE
    int toX(string& corp); //DONE

    //Option 2
    float avgDelayTimeXY(string& corp1, string& corp2); //DONE
    string commonDelayXY(string& corp1, string& corp2); //DONE
    float airPercentDelayedXY(string& corp1, string& corp2); //DONE
    float avgTaxiOutTime(string& corp); //DONE
    int noPlanesFlown(string& corp1, string& corp2); //DONE
    int noPlanesDelayed(string& corp1, string& corp2); //DONE



    int noPlanesDelayed(string& corp); //DONE
    float avgDelayTimeCorp(string& corp); //DONE
    string commonDelayCorp(string& corp); // DONE
    float airPercentDelayedCorp(string& corp); //DONE
    float avgTravelTime(string& corp); //DONE
    int noPlanesFlownCorp(string& corp); //DONE
    int noPlanesDelayedCorp(string& corp); //DONE


	//Option 4 - delays
	// CARRIER
	// WEATHER
	// NAS
	// SECURITY
	// LATE_AIRCRAFT

	/*
	cout << "Average delay time for X: " << endl;
	cout << "Top five airports with the highest delay time for X: " << endl;
	cout << "Bottom five airports with the lowest delay time for X: " << endl;
	cout << "Average travel time for X delay type: " << endl;
	cout << "The best airport to go to during this year to avoid delay type X is: " << endl;
	*/

    float avgDelayTimeWhenDelayed(string& delayType);
    vector<string> topFiveForDelays(string& delayType);
    vector<string> bottomFiveForDelays(string& delayType);
    float avgTravelTimeWhenDelayed(string& delayType);
    string bestForThisDelay(string& delayType);


};