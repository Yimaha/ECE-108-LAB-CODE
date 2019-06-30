//
// Created by cai24 on 6/26/2019.
//
#include <iostream>
#include <fstream>


#ifndef ECE108LAB2_ECE_108_LAB2_H
#define ECE108LAB2_ECE_108_LAB2_H
int** InputReading(std::ifstream & input_file_stream, int numClauses, int numVars);
bool LogicEvaluation(int** evaluation, int num_logic, int num_variables, std::string first_input);
void CleanUp(int** evaluation, int numClauses);

#endif //ECE108LAB2_ECE_108_LAB2_H
