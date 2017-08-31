//
// Created by Camel32149 on 8/28/17.
//

#include "Controller.h"

Controller::Controller(char *dir[]){
	loadFile(dir[1]);
	Setup();
	Comeon();
}

Controller::~Controller(){
	//output the error information:
	//cout<<ArraySize;
}

void Controller::loadFile(char *dir){
	ifstream in;
	in.open(dir);
	if(!in){
		err_code.push_back(404);
	}else{
		in.seekg(0, ios::end);
		int length = in.tellg();
		in.seekg(0, ios::beg);
		char* buffer = new char[length];
		in.read(buffer, length);
		in.close();

		// for(int i = 0; i < length; i++){
		// 	code_segment.push_back(buffer[i]);
		// }
		// 
		code_segment = new char[length];
		code_segment = buffer;

		cs = string(buffer);
	}
}

void Controller::Setup(){
	Parse parser(cs);
	ArraySize = parser.value;
	//error code container union
}

void Controller::Comeon(){
	Run runner(code_segment, ArraySize);
	//error code container union: none
}