//
//  main.cpp
//  CodeClinic_Weather
//
//  Created by Egor Wexler on 07/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <map>
#include <ostream>


using namespace std;
namespace fs = std::__fs::filesystem;

time_t convertDateTime(string date, string time = "00:00:00")
{
    // parse values from date string
    int yyyy, mon, dd = 0;
        if (sscanf(date.c_str(), "%d_%d_%d", &yyyy, &mon, &dd) != 3)
    {
        cerr << "ERROR: Failed to parse date string " << date << endl;
        return -1;
    }

    // parse values from time string
    int hh, mm, ss = 0;
    if (sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss) != 3)
    {
        cerr << "ERROR: Failed to parse time string " << date << endl;
        return -2;
    }
    
    struct tm dateTime = {};
    dateTime.tm_year = yyyy - 1900; // years since 1900
    dateTime.tm_mon = mon - 1;      // months since January
    dateTime.tm_mday = dd;          // day of the month
    dateTime.tm_hour = hh;          // hours since midnight
    dateTime.tm_min = mm;           // minutes after the hour
    dateTime.tm_sec = ss;           // seconds after the minute

    // return a time_t value representing seconds since 1970
    return mktime(&dateTime);
}


int main(int argc, const char * argv[]) {
    fs::path resources = (argc > 1 ? argv[1] : "./resources");
   
    if(!is_directory(resources)) {
        cout << "Wrong resource directory" << endl;
        return 1;
    }
    map<time_t, double> dataSet;
    for_each(fs::directory_iterator(resources), fs::directory_iterator(),
             [&](auto f) {
        if(!is_directory(f.path())) {
            fstream file;
            file.open(f.path().string());
            string line;
            getline(file, line);
            
            while (getline(file, line)) {
                string date, time;
                double temp, pressure;
                istringstream buf(line);
                buf >> date >> time >> temp >> pressure;
//                cout << convertDateTime(date, time) << " " << pressure << endl;
                dataSet.insert({convertDateTime(date, time), pressure});
                
            }
        };
    });
    
    string dateIn, timeIn;
    cout << "Enter Start date as yyyy_mm_dd: ";
    cin >> dateIn;
    cout << "Enter Start time as hh:mm:ss: ";
    cin >> timeIn;

    time_t startTime = convertDateTime(dateIn, timeIn);
    
    cout << "Enter end date as yyyy_mm_dd: ";
    cin >> dateIn;
    cout << "Enter end time as hh:mm:ss: ";
    cin >> timeIn;
    
    time_t endTime = convertDateTime(dateIn, timeIn);
    
    map<time_t, double>::iterator it1 = dataSet.lower_bound(startTime);
    map<time_t, double>::iterator it2 = dataSet.lower_bound(endTime);
        
    double koef;
    
    double difP = it2->second - it1->second;
    double difT = it2->first - it1->first;
    
    koef = difP/difT * 24 * 60 * 60;
    cout << "Pressure coefficient: " << koef << endl;
    
    
//    for_each(it1, it2, [](pair<time_t, double>p){cout << p.first << " " << p.second << endl;});
    
    
    
}
