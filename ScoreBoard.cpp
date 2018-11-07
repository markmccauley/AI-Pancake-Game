//
//  ScoreBoard.cpp
//  
//
//  Created by Lasse Starklit on 22/10/2018.
//
#include "ScoreBoard.h"
#include <string>
#include <vector>
#include <tuple>
#include <sstream> //istringstream
#include <iostream> // cout
#include <fstream> // ifstream
#include <sstream>

using namespace std;

//Returns true if value of second element in tuple is greater than the first. eg. if the score is greater
bool sortByScore(tuple<string, double> tupleA, tuple<string, double>tupleB){
    return (get<1>(tupleA) > get<1>(tupleB));
}

//Returns a vector sorted by the second element greatest to lowest. eg. the greatest score first and lowest last
vector<tuple<string,double>> sortVector(vector<tuple<string,double>> data) {
    sort(data.begin(), data.end(), sortByScore);
    return data;
}

