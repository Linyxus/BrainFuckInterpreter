//
// Created by linyxus on 8/28/17.
//

#ifndef BF_INTERPRETER_PREPROC_H
#define BF_INTERPRETER_PREPROC_H

#include <vector>
#include <string>
using namespace std;

class Parse
{
public:
    vector<int> err_code;
    int value;
    
    int parse_size(string code);
    int parse_int(string str);

    Parse(string data);
    ~Parse();
};

#endif //BF_INTERPRETER_PREPROC_H