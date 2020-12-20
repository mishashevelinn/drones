//
// Created by misha on 16/12/2020.
//
#define INV_INPUT "Error; invalid input"
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

    int file_open(fstream &fs, const char *file) ;


    int parse_IterationsLimit(fstream &init_data);

    Vector parse_aim(fstream &init_data);


    bool is_float(const string &str, bool iter);

    bool parse_init(int &iteration_limit);

    bool parse_drones(DroneList & dl);


    bool legal_drone_data(const string & line);

};


#endif //DRONES_PARSER_H
