#ifndef RUN_H
#define RUN_H

#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

class Run
{
public:
	//cs: code_segment
	//int ds_size; //data_segment size

	int ptr = {};
	int *data;

	Run(char* cs, int size);
	~Run();
	void Parser(char* cs, int size);
};

#endif // RUN_H
