#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main(int argc, char* argv[]){
    //first identify type of boolean
    std::string input = argv[1];
    //if And Gate
    if(input[1] == '.'){
        //number of input
        int n = std::count(input.begin(), input.end(), '.') + 1;
        //array of all the input
        std::string inputArray[n];
        int pos = input.find('.');
        for(int i = 0; i < n; i++){
            inputArray[i] = input.substr(0, pos);
            input.erase(0, pos + 1);
            pos = input.find('.');
        }

        for(int i = 0; i< n; i++){
            std::cout << inputArray[i] << " ";
        }
        std::cout << argv[1] << std::endl;

        int end = pow(2, n);
    for(int i=0; i< end; i++){
        char output[n];
        std::fill(output, output + n, 'F');
        int current = i;
        for(int j = n-1; j > -1; j--){
            if(current >= pow(2, j)){
            current = current - pow(2,j);
            output[j] = 'T';
            }
        }
        for(int j = 0; j < n; j++){
            std::cout << output[j] << " ";
        }
        if(i == end -1)
        std::cout << "T" << std::endl;
        else
        std::cout << "F" << std::endl;
        }
    } else {
        //number of input
        int n = std::count(input.begin(), input.end(), '+') + 1;
        //array of all the input
        std::string inputArray[n];
        //
        int pos = input.find("+");
        for(int i = 0; i < n; i++){
            inputArray[i] = input.substr(0, pos);
            input.erase(0, pos + 1);
            pos = input.find("+");
        }

        for(int i = 0; i< n; i++){
            std::cout << inputArray[i] << " ";
        }
        std::cout << argv[1] << std::endl;

        int end = pow(2, n);

        for(int i=0; i< end; i++){
            char output[n];
            std::fill(output, output + n, 'F');
            int current = i;
            for(int j = n-1; j > -1; j--){
                if(current >= pow(2, j)){
                current = current - pow(2,j);
                output[j] = 'T';
                }
            }
            for(int j = 0; j < n; j++){
                std::cout << output[j] << " ";
            }
            if(i == 0)
            std::cout << "F" << std::endl;
            else
            std::cout << "T" << std::endl;

        }
    }
}