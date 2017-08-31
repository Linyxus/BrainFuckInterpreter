#include <c++/cstring>
#include "Run.h"

Run::Run(char* cs, int size){
	Parser(cs, size);
}

Run::~Run(){

}

void Run::Parser(char* cs, int size){
	printf("the container size :%d\n\n", size);
	data = new int[size];
	memset(&data, 0, size);


	int counter = {};
	int flag;
//	while(counter < sizeof(cs)){
//		printf("%c\n", cs[counter]);
//        counter++;
//	}
	 while(counter < sizeof(cs)){
	 	switch(cs[counter]){
	 		case '+':
	 			data[ptr]++;
	 			break;

	 		case '-':
	 			data[ptr]--;
	 			break;

	 		case '>':
	 			ptr++;
	 			if(ptr >= size){
	 				ptr = 0;
	 			}
	 			break;

	 		case '<':
	 			ptr--;
	 			if(ptr < 0){
	 				ptr = size;
	 			}
	 			break;

	 		case ',':
	 			data[ptr] = getchar();
	 			break;

	 		case '.':
	 			putchar(data[ptr]);
	 			break;

	 		case '[':
	 			if(!data[ptr]){
	 				while(cs[counter] != ']'){
	 					counter++;
	 				}
	 			}else{
	 				flag = counter;
	 			}
	 			break;

	 		case ']':
	 			if(data[ptr]){
	 				counter = flag;
	 			}
	 			break;
	 	}
	 	counter++;
	 }
}