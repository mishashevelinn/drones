//
// Created by misha on 16/12/2020.
//
#define INV_INPUT "Error; invalid input"
#ifndef DRONES_PARSER_H
#define DRONES_PARSER_H
#include "BST.h"
#include <ostream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "BST.h"
#include "Vector.h"
#include "Drone.h"

using namespace std;


class Parser {
public:
    int x_min, y_min, x_max, y_max;
    Parser( const Parser & other);
    Parser & operator =(const Parser & rhs){
        this->aim = rhs.aim;
        this->drones_file_name = rhs.drones_file_name;
        this->init_file_name = rhs.init_file_name;
return *this;
    }
    Parser(const char *init_file_name, const char *drones_file_name) : init_file_name(init_file_name),
    drones_file_name(drones_file_name), aim() {}

    const char *init_file_name;
    const char *drones_file_name;


    virtual ~Parser();

    Vector aim;

    int file_open(fstream &fs, const char *file) ;


    int parse_IterationsLimit(fstream &init_data);

    Vector parse_aim(fstream &init_data);


    bool is_float(const string &str, bool iter);

    bool parse_init(int &iteration_limit);

    bool parse_drones(Tree<Drone> * dl);


    bool legal_drone_data(const string & line);

    bool parse_limits(fstream &fs);
};


#endif //DRONES_PARSER_H
