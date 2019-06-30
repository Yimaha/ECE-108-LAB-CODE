#include <iostream>
#include <fstream>
#include "ECE.108_Lab2.h"

int main(int argc, char* argv[]) {
    std::ifstream inputFileStream;
    int numVars;
    int numClauses;
    std::string fileName = argv[1];

    //reading start
    inputFileStream.open(fileName);
    //unable to read file
    if(!inputFileStream){
        std::cerr << "File don't exsit, or unable to open" << std::endl;
        exit(1);
    }
    //1st and 2nd string are parsed directly into int and stored as numVars and numClauses;
    inputFileStream >> numVars >> numClauses;
    // now logic should be complete, start reading the input
    int ** evaluation = InputReading(inputFileStream, numClauses, numVars);
    //holder for the first input
    std::string first_input;
    while(std::cin >> first_input) {
        //if the logic is true, output true
        if (LogicEvaluation(evaluation, numClauses, numVars, first_input))
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
    //delete all the pointers
    CleanUp(evaluation, numClauses);
    return 0;
}

/**
 * Reading rules for logic evaluation
 * Author: Justin, Ashish
 * @param reference to a ifstream, number of clauses, and number of variables
 * @return a pointer of a pointer that contains all clauses in order
 */
int** InputReading(std::ifstream & input_file_stream, int numClauses, int numVars){
    int** evaluation;
    evaluation = new int* [numClauses];
    for(int i = 0; i< numClauses; i++){
        evaluation[i] = new int [numVars];
    }
    int counter = 0;
    int subCounter = 0;
    std::string currentChar;
    //fill the array with 0s (a.k.a don't cares)
    while(input_file_stream >> currentChar)
    {
        if(currentChar == "0") {
            subCounter = 0;
            counter++;
        } else {
            try{
                evaluation[counter][subCounter] = std::stoi(currentChar);
            }catch (std::invalid_argument e){}
            subCounter++;
        }
    }
    return evaluation;
}

/**
 * Evaluating logic for a particular set of logic
 * Author: Justin, Ashish
 * @param evaluation logic, number of logic, number of variable, and the first logic of the set (1 or -1)
 * @return a boolean logic that either represent passing the evalution or not
 */
bool LogicEvaluation(int** evaluation, int num_logic, int num_variables, std::string first_input){
    // evaluation is the logic you receive, you evaluate based on the input
    std::string current_string;
    int current_variables[num_variables];
    current_variables[0] = std::stoi(first_input);
    for(int i = 1; i <= num_variables; i++){
        std::cin >> current_string;
        if(current_string != "0")
            try{
                current_variables[i] = std::stoi(current_string);
            }catch(std::invalid_argument e){}
    }
    // current logic gathered, now evaluate.
    for(int i = 0; i < num_logic; i++){
        bool logic_pass = false;
        for(int j = 0; j < num_variables; j++){
            //if it reaches 0, then rest are 0 too, which is pointless to evaluate
            if(evaluation[i][j] == 0)
               break;
            //if variable matches, "or" statement is true, therefore we can move on to the next clause
            if(evaluation[i][j] == current_variables[abs(evaluation[i][j]) - 1]){
                logic_pass = true;
                break;
            }
        }
        //if none of the variable matches, then the statement is false since it is "and"
        if(!logic_pass)
            return false;
    }
    return true;
}

/**
 * Clean up all pointer used
 * Author: Justin, Ashish
 * @param the pointer to cleanup and the number of elements
 * @return no return
 */
void CleanUp(int** evaluation, int numClauses){
    for(int i = 0; i < numClauses; i++){
        delete[] evaluation[i];
    }
    delete[] evaluation;
}

