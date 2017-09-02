//
// Created by Camel32149 on 8/28/17.
//

#include "sources/Controller.h"

Controller::Controller(char *dir[]){
	loadFile(dir[1]);
	Setup();
	Comeon();
}

Controller::~Controller(){
	//output the error information:
	cout<<endl;
	if(err_code.size() == 0){
		cout<<"The program has been executed!"<<endl;
	}else{
		for(int i = 0; i < err_code.size(); i++){
			switch(err_code[i]){
				case 199:
					cout<<"It is a wrong format, check your code."<<endl;
					break;
				case 404:
					cout<<"Can't open the filename.Check your directory is vaild."<<endl;
					break;
				case 198:
					cout<<"Expected a '}', did you forget?"<<endl;
					break;
				case 197:
					cout<<"invaild value in the '#size{...}'. "<<endl;
					break;
			}
		}
	}
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

		code_segment = string(buffer);
        delete buffer;
	}
}

void Controller::Setup(){
	Parse parser(code_segment);
	ArraySize = parser.value;
	//error code container union
	err_code.insert(err_code.end(), parser.err_code.begin(), parser.err_code.end());
}

void Controller::Comeon(){
	Run runner(code_segment, ArraySize);
	//error code container union: none
}