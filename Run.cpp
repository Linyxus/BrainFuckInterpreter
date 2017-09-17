#include <cstring>
#include <stack>
#include "sources/Run.h"

Run::Run(string cs, int size){
	Parser(cs, size);
}

Run::~Run(){

}

void Run::Parser(string cs, int size){
    stack<int> flagStack = stack<int>();
    printf("the container size :%d\n\n", size);
    data = new int[size];
	memset(data, 0, size);

    ptr = 0;
	size_t counter = 0;
//	while(counter < sizeof(cs)){
//		printf("%c\n", cs[counter]);
//        counter++;
//	}
    size_t len = cs.length();
    while(counter < len){
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
                    int need = 1;
	 				while(need > 0){
	 					counter++;
	 					if (cs[counter] == ']') need--;
	 					else if (cs[counter] == '[') need++;
	 				}
	 			}else{
	 				flagStack.push(counter);
	 			}
	 			break;

	 		case ']':
	 			if(data[ptr]){
                    counter = flagStack.top() - 1;
	 			}
                flagStack.pop();
	 			break;
	 	}
	 	counter++;
	 }
}
