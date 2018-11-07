#include <string>
#include <vector>
#include <tuple>
#include <sstream> //istringstream
#include <iostream> // cout
#include <fstream> // ifstream
#include <sstream>

using namespace std;
class ScoreBoard {
private:
    vector<tuple<string,double>> data;
    tuple<string,double> turple;
    
    
public:
    
    ScoreBoard (string inputFileName);
    bool sortByScore(tuple<string, double> tupleA, tuple<string, double> tupleB);
    vector<tuple<string,double>> sortVector(vector<tuple<string,double>> data);
    vector<tuple<string,double>> getScore(){
        return data;
    }
};
ScoreBoard::ScoreBoard (string inputFileName){
    
    ifstream inputFile(inputFileName); //Reads input file
    
    while (inputFile) { //reads each line in file
        
        string initials;
        string strscore;
        double score;
        
        getline(inputFile,initials,','); //Takes string before ,
        getline(inputFile,strscore); //Takes string before \n
        
         //If none of the variables are empty a tuple with initials as first element and score (made integer) as second.
        //The tuple is then pushed to the vector
        if(!initials.empty() && !strscore.empty()){
            stringstream (strscore)>>score;
            data.push_back(make_tuple(initials,score));
        }
    }
    if (!inputFile.eof()) {
        cerr << "Could not read file " << inputFileName << "\n";
        __throw_invalid_argument("File not found.");
    }
    
}


