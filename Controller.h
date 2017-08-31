//
// Created by Camel32149 on 8/28/17.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Parse.h"
#include "Run.h"

using namespace std;

class Controller{
public:
    vector<int> err_code;
    vector<int> warning_code;
    list<string> err_info;
    list<string> warning_info;
    //vector<char> code_segment;
    char* code_segment;
    int ArraySize;
    string cs;

    Controller(char* dir[]);
    ~Controller();

    void loadFile(char* dir);
    void Setup();
    void Comeon();
};

#endif