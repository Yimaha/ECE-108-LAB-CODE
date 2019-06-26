#include <iostream>
#include <fstream>
#include "ECE.108_Lab2.h"

int main(int argc, char* argv[]) {
    //declaring local variables
    std::ifstream inputFileStream;
    int numVars;
    int numClauses;
    std::string currentChar;
    std::string fileName = argv[1];

    //reading start
    inputFileStream.open(fileName);
    if(!inputFileStream){
        std::cerr << "File don't exsit, or unable to open" << std::endl;
        exit(1);
    }
    //1st and 2nd string are parsed directly into int and stored as numVars and numClauses;
    inputFileStream >> numVars >> numClauses;
    int evaluation[numClauses][numVars];
    int counter = 0;
    int subCounter = 0;
    //fill the array with 0s (a.k.a don't cares)
    for(int i = 0; i < numClauses; i++){
        for(int j = 0; j < numClauses; j++){
            evaluation[i][j] = 0;
        }
    }
    while(inputFileStream >> currentChar)
    {
        if(currentChar == "0") {
            subCounter == 0;
            counter++;
        } else {
            evaluation[counter][subCounter] = std::stoi(currentChar);
            subCounter++;
        }
    }
    // now logic should be complete, start reading the input

//    int evaluation[6][5] = {
//            {1,-2,-3,-4,-5},
//            {1,2,3,4,5},
//            {1,2,3,4,5},
//            {1,2,3,4,5},
//            {1,2,3,4,5},
//            {1,2,3,4,5}
//    };
    int rows = sizeof(evaluation)/sizeof(evaluation[0]);
    int cols = sizeof(evaluation[0])/sizeof(evaluation[0][0]);

    std::cout << rows << " " << cols << std::endl;

    bool valid[rows] = {false};
    bool logic = true;

    for (int i =0; i < rows; i++){

        for( int j =0; j< cols; j++){

            if( evaluation[i][j] > 0){
                valid[i] =true;
            }

        }


    }

    for(int i= 0; i<rows; i++){
        if(valid [i] == false){
            logic = false;
        }

    }

    if(logic == true){

        std::cout<<"True"<<std::endl;

    }else{

        std::cout <<"False" <<std::endl;

    }

    return  0;
}