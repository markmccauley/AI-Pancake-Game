//
//  Pancake_Stack.cpp
//  
//
//  Created by Lasse Starklit on 24/10/2018.
//
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Pancake_Stack.h"
#include <algorithm>
#include <cstdlib>
// shuffle algorithm example
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

//Constructor that creates stack of pancakes ordered
Pancake_Stack::Pancake_Stack (int pancakes){
    
    
    numPancakes=pancakes;  //Defines number of pancakes.
    
    
    for (int i=1; i<=pancakes;i++){
        string temp="";
        //First row
        for (int j=1; j<=3;j++){
            //Second row
            if (j%2==0){
                temp+=string(pancakes-i, ' ');
                temp+="|";
                temp+=string(i-1, ' ');
                temp+=to_string(i);
                temp+=string(i-1, ' ');
                temp+="|";
                temp+="\n";
            }else{
                //first and third row of pancake
                temp+=string(pancakes-i, ' ');
                temp+="+";
                temp+=string(i-1, '-');
                temp+="-";
                temp+=string(i-1, '-');
                temp+="+";
                temp+="\n";
            }
        }
        
        
        pancakeStack.push_back(temp);
    }
}


//Adds a stack 
void Pancake_Stack::RandomizeStack(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    randomizedStack=pancakeStack;
    //Not sure this is random
    shuffle ( randomizedStack.begin(), randomizedStack.end(), default_random_engine(seed));
    
}
vector<string> Pancake_Stack::getRandomStack(){
    return randomizedStack;
    
}


//Returns a vector of pancake sizes in integer
vector<int> Pancake_Stack::getStackInt(vector<string> vec){
    vector<int> pancakedStack;
    for (auto i: randomizedStack){
        for (int j=1; j<=9;j++){
            if (i.find(to_string(j)) != string::npos){
                pancakedStack.push_back(j);
            }
    
        }
    }
    
    return pancakedStack;
}
