//
// Created by misha on 16/12/2020.
//

#include "Parser.h"
#include "BST.h"
#include "SingleRotor.h"
#include "MultiRotor.h"
#include "FixedWing.h"
#include "Hybrid.h"
/*A class handles IO
 * fields - file names and destination vector*/


/*Opens a file for reading.
 * fstream object is passed by reference and
 * initialized in function body.
 * return value - number of lines red*/
int Parser::file_open(fstream &fs, const char *file) {
    fs.open(file);
    string line;
    if (!fs) {
        return 0;
    }
    string buff;
    int counter = 0;
    //count lines
    while (getline(fs, buff)) {
        counter++;
    }
    //return to the beginning of file
    fs.clear();
    fs.seekg(0);
    return counter;
}


/*returns a maximal number of iterations
 */
int Parser::parse_IterationsLimit(fstream &init_data) {

    string iter_num;
    getline(init_data, iter_num);
    stringstream ss(iter_num);
    string temp;
    int counter = 0;
    /*reading a line and
     * counting number of words.
     * if it's 1 and number is legal
     * positive integer (is_float
     * with flag true, checks it)
     * converts an input to a int*/
    while (ss >> temp) counter++;
    if (counter != 1) return -1;
    if (!is_float(temp, true)) return -1;
    int i;
    stringstream ss1(iter_num);
    ss1 >> i;
    return i;


}


/*Checks if a string is legal float number
 * If flag 'iter' is true, checks if a string
 * is a positive integer -- used for maximal number of iterations parsing*/
bool Parser::is_float(const string &str, bool iter) {

    bool dec_point = false;
    for (int i = 0; i < (int) str.length(); ++i) {
        if (!iter && str[0] == '-')
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


/*Gets an int reference and updates it
 * to be the iteration limit, red from file.
 * calls to parse aim for destination vector parsing
 * and to parse_IterationsLimit for maximal number of iterations parsing*/
bool Parser::parse_init(int &iteration_limit) {

    string line;
    fstream init_data;
    if (file_open(init_data, init_file_name) != 3) {
        cout << INV_INPUT << endl;
        return false;
    }
    if(!parse_limits(init_data)) return false;
    aim = parse_aim(init_data);
    if (aim.get_x() == -99) {
        cout << INV_INPUT << endl;
        return false;
    }
    iteration_limit = parse_IterationsLimit(init_data);
    if (iteration_limit == -1) return false;

    return true;


}

/*reads files of initial drones locations
 * checks if coordinates are legal with
 * is_legal_float
 * initializes Drone instances with coordinates
 * and adds them to a List.*/
bool Parser::parse_drones(Tree<Drone> *dl) {
    {
        fstream aim;
        file_open(aim, init_file_name);
        parse_aim(aim);

        fstream fs;
        int n = file_open(fs, drones_file_name);
        if (n == 2) {
            cerr << INV_INPUT << endl;
            return false;
        }

        string line;
        getline(fs, line);
        if (!is_float(line, true)) {
            cout << INV_INPUT << endl;
            return false;
        }
        while (getline(fs, line)) {
            if (!legal_drone_data(line)) {
                cerr << INV_INPUT << endl;
                return false;
            }
            string temp;
            stringstream ss(line);
            double place_x;
            double place_y;
            double speed_x;
            double speed_y;
            char type;
            ss >> type;
            ss >> place_x;
            ss >> place_y;
            ss >> speed_x;
            ss >> speed_y;
            Vector place(place_x, place_y);
            Vector speed(speed_x, speed_y);
            Drone * drone;
            switch (type) {
                case 'S':
                    drone = new SingleRotor(place, speed, this->aim, x_max, y_max, x_min, y_min);
                    break;
                case 'M':
                    drone = new MultiRotor(place, speed, this->aim, x_max, y_max, x_min, y_min);
                    break;
                case 'W':
                    drone = new FixedWing(place, speed, this->aim, x_max, y_max, x_min, y_min);
                    break;
                case 'H':
                    drone = new Hybrid(place, speed, this->aim, x_max, y_max, x_min, y_min);
                    break;
                default:
                    drone = new Drone(place, speed, this->aim, x_max, y_max, x_min, y_min);
                    break;
            }
            dl->insert(drone);
            delete drone;
        }

        return true;

    }
}


/*Function detects if drone's initial position data
 * is valid -- legal nubers, 4 numbers in a row,
 * delimited by space*/
bool Parser::legal_drone_data(const string &line) {
    {
        int counter = 0;
        stringstream ss(line);
        string temp;
        while (ss >> temp) counter++;
        if (counter != 5) {
            cerr << INV_INPUT << endl;
            return false;
        }
        char type;
        stringstream ss1(line);
        if((ss1 >> type).fail()) return false;
        while (ss1 >> temp) {
            if (!is_float(temp, false)) {
                cerr << INV_INPUT << endl;
                return false;
            }
        }
        return true;
    }
}


/*Checks if destanation vector is legal --
 and initializes a data member*/
Vector Parser::parse_aim(fstream &init_data) {
    {
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
            if (!is_float(temp, false))
                return Vector(-99, -99);
        }
        stringstream ss3(line);
        ss3 >> x;
        ss3 >> y;
        aim = Vector(x, y);
        return Vector(x, y);

    }
}

bool Parser::parse_limits(fstream &fs) {
    string line;
    getline(fs, line);
    stringstream ss(line);
    int counter = 0;
    string temp;
    while (ss >> temp) counter++;
    if (counter != 4) return false;
    stringstream ss1(line);
    if ((ss1 >> x_min).fail()) return false;
    if ((ss1 >> y_min).fail()) return false;
    if ((ss1 >> x_max).fail()) return false;
    if ((ss1 >> y_max).fail()) return false;
    if (y_min > y_max || x_min > x_max) return false;
    if (aim.get_x() < x_min || aim.get_x() > x_max || aim.get_y() < y_min || aim.get_y() > y_max) return false; //checking if destination point is in right bounds
    return true;
}

Parser::Parser(const Parser &other) {
    this->aim = other.aim;
    this->drones_file_name = other.drones_file_name;
    this->init_file_name = other.init_file_name;
}

Parser::~Parser() {

}

