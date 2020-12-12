/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.h
 * Author: Onasis Reyes
 *
 * Created on 11 de diciembre de 2020, 01:09 PM
 */

#ifndef CSV_H
#define CSV_H

#include <iostream>
using std::endl;
using std::cout;

#include <iomanip>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::fstream;
        
using namespace std;

class csv {
public:
    csv();
    csv(const csv& orig);
    virtual ~csv();
    
    csv(string);
    csv(string, bool);

    vector<vector<string>> sort(int, bool);
    vector<string> get_column(int);
    vector<string> get_row(int);
    vector<string> get_max(int);
    vector<string> get_min(int);

    void print_data();
    void truncate_row(int);
    void truncate_column(int);
    void write_file();
    void load_file(bool);

    csv concat(csv, string);
    
private:
    string file_name;
    vector<string>headers;
    vector<vector<string>> data;
    int data_count;
};

#endif /* CSV_H */

