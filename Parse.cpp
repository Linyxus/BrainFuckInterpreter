//
// Created by linyxus on 8/28/17.
//
#define DEFAULT 1024
#include "sources/Parse.h"

Parse::Parse(string data){
	parse_size(data);
}

Parse::~Parse(){

}

int Parse::parse_size(string code){
	size_t p1 = code.find('#', 0);
	if(p1 == string::npos){
		value = DEFAULT;
		return 0;
	}

	if(code.substr(p1+1, 5) != "size{") {
        err_code.push_back(199);
        value = DEFAULT;
        return 0;
    }

    size_t p2 = code.find('}', p1);
    if (p2 == string::npos) {
    	err_code.push_back(198);
    	value = DEFAULT;
    	return 0;
    }

    int i = parse_int(code.substr(p1+6, p2-(p1+6)));
    if (i == -1) {
    	err_code.push_back(197);
    	value = DEFAULT;
    	return 0;
    }

    value = i;
}

int Parse::parse_int(string str){
	int _ret = 0;
	for(char ch : str){
		if(!isdigit(ch)){
			return -1;
		}
		_ret = _ret * 10 + ch - '0';
	}
	return _ret;
}