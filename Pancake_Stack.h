#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
class Pancake_Stack {
private:
    vector<string> pancakeStack;
    vector<string> randomizedStack;
    int numPancakes;
    
public:
    Pancake_Stack (int);
    void RandomizeStack();
    vector<string> getRandomStack();
    vector<int> getStackInt(vector<string> vec);
   
};
