//
// Created by misha on 16/12/2020.
//
#define INVINP "ERROR; invalid input"
#ifndef DRONES_PARSER_H
#define DRONES_PARSER_H

#include <ostream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "DroneList.h"
using namespace std;


class Parser {
public:
    Parser(const char *init_file_name, const char *drones_file_name) : init_file_name(init_file_name),
                                                                       drones_file_name(drones_file_name), aim() {}

    const char *init_file_name;
    const char *drones_file_name;
    Vector aim;

    int file_open(fstream &fs, bool drones, const char *file) {
        fs.open(file);
        string line;
        if (!fs) {
            return 0;
        }
        string buff;
        int counter = 0;
        while (getline(fs, buff)) {
            counter++;
        }
        if (counter != 2 && !drones) {
            cerr << INVINP << endl;
            return 0;
        }
        fs.clear();
        fs.seekg(0);
        return counter;
    }


    int parse_IterationsLimit(fstream &init_data) {
        string iter_num;
        getline(init_data, iter_num);
        stringstream ss(iter_num);
        string temp;
        int counter = 0;
        while (ss >> temp) counter++;
        if (counter != 1) return -1;
        if (!is_float(temp, false, true)) return -1;
        int i;
        stringstream ss1(iter_num);
        ss1 >> i;
        return i;

    }


    Vector parse_aim(fstream &init_data) {
        string line;
        getline(init_data, line);
        stringstream ss(line);
        string temp;
        int counter = 0;
        while (ss >> temp) counter++;
        if (counter != 2) return Vector(-99, -99); //represents invalid vector
        stringstream ss2(line);
        double x;
        double y;
        while (ss2 >> temp) {
            if (!is_float(temp, true, false))
                return Vector(-99, -99);
        }
        stringstream ss3(line);
        ss3 >> x;
        ss3 >> y;
        aim = Vector(x, y);
        return Vector(x, y);

    }


    bool is_float(const string &str, bool square, bool iter) {
        bool dec_point = false;
        for (int i = 0; i < str.length(); ++i) {
            if (!square && !iter && str[0] == '-')
                continue;
            if (!dec_point && !iter && str[i] == '.') {
                dec_point = true;
                continue;
            }
            if (!isdigit(str[i]))
                return false;
        }
        return true;
    }

    bool parse_init(int &iteration_limit) {
        string line;
        fstream init_data;
        if (!file_open(init_data, false, init_file_name)) {
            cout << INVINP;
            return false;
        };

        aim = parse_aim(init_data);
        if (aim.x == -99) return false;
        iteration_limit = parse_IterationsLimit(init_data);

    }

    bool parse_drones(DroneList & dl) {
        fstream aim;
        file_open(aim, false, init_file_name);
        parse_aim(aim);

        fstream fs;
        int n = file_open(fs, true, drones_file_name);
        if (n < 1) {
            cerr << INVINP << endl;
            return false;
        }

        string line;
        getline(fs, line);
        if(!is_float(line, false, true))
        {
            cout << INVINP << endl;
            return false;
        }
        while (getline(fs, line)) {
            if (!legal_drone_data(line)) {
                cerr << INVINP << endl;
                return false;
            }
            string temp;
            stringstream ss(line);
            double place_x;
            double place_y;
            double speed_x;
            double speed_y;
            ss >> place_x;
            ss >> place_y;
            ss >> speed_x;
            ss >> speed_y;
            Vector place(place_x, place_y);
            Vector speed(speed_x, speed_y);
            Drone drone(place, speed, this->aim);
            dl.insert(drone);
        }

        return true;

    }


    bool legal_drone_data(const string & line)
    {
        int counter = 0;
        stringstream ss(line);
        string temp;
        while(ss >> temp) counter++;
        if(counter != 4) {
            cerr << INVINP << endl;
            return false;
        }
        stringstream ss1(line);
        while (ss1 >> temp)
        {
            if(!is_float(temp, false, false))
            {
                cerr << INVINP << endl;
                return false;
            }
        }
        return true;
    }
};


#endif //DRONES_PARSER_H
