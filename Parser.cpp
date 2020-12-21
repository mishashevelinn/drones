//
// Created by misha on 16/12/2020.
//

#include "Parser.h"
/*A class handles IO
 * fields - file names and destination vector*/


/*Opens a file for reading.
 * fstream object is passed by reference and
 * initialized in function body.
 * return value - number of lines red*/
int Parser:: file_open(fstream &fs, const char *file) {
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
        if (!is_float(temp,true)) return -1;
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
        for (int i = 0; i < (int)str.length(); ++i) {
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
        if (file_open(init_data,init_file_name) != 2) {
            cout << INV_INPUT << endl;
            return false;
        }

        aim = parse_aim(init_data);
        if (aim.get_x() == -99) {
            cout << INV_INPUT << endl;
            return false; }
        iteration_limit = parse_IterationsLimit(init_data);

        return true;


}

/*reads files of initial drones locations
 * checks if coordinates are legal with
 * is_legal_float
 * initializes Drone instances with coordinates
 * and adds them to a List.*/
bool Parser::parse_drones(DroneList &dl) {
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
        if(!is_float(line, true))
        {
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
}



/*Function detects if drone's initial position data
 * is valid -- legal nubers, 4 numbers in a row,
 * delimited by space*/
bool Parser::legal_drone_data(const string &line) {
    {
        int counter = 0;
        stringstream ss(line);
        string temp;
        while(ss >> temp) counter++;
        if(counter != 4) {
            cerr << INV_INPUT << endl;
            return false;
        }
        stringstream ss1(line);
        while (ss1 >> temp)
        {
            if(!is_float(temp, false))
            {
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
                if (!is_float(temp,false))
                    return Vector(-99, -99);
            }
            stringstream ss3(line);
            ss3 >> x;
            ss3 >> y;
            aim = Vector(x, y);
            return Vector(x, y);

    }
}

Parser::Parser(const Parser & other) {
    this->aim = other.aim;
    this->drones_file_name = other.drones_file_name;
    this->init_file_name = other.init_file_name;
}

Parser::~Parser() {

}

