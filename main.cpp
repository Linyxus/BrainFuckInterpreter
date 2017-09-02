#include <iostream>
#include "sources/Controller.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc == 1){
        cout<<"You have no input the directory, input the code(Y) or exit the program(N/ANY)?"<<endl<<"NovaBrain>";
        char r;
        cin>>r;
        if(r = 'Y'){
            string data;
            cout<<"inputting code>";
            cin>>data;
            cout<<"NovaBrain>";
            Run(data, 1024);
        }else{
            return 0;
        }
    }else{
        cout<<"NovaBrain>";
        Controller ctrl(argv);
    }
    return 0;
}