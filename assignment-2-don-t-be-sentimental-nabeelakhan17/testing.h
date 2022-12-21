//
// Created by nabee on 9/13/2022.
//

#ifndef ASSIGNMENT2_SENTIMENT_TESTING_H
#define ASSIGNMENT2_SENTIMENT_TESTING_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"DSString.h"
#include "DSVector.h"

class testing {

    private:
    // stores the tweets and sentiments from the training words file
        DSVector<pair<DSString, int>> trainWords;
    //stores the guesses
        DSVector<pair<DSString, bool>> guesses;
    public:
    //all the methods
        testing(char*arg, DSVector<pair<DSString, int>>& t);
        void scanner(DSString filename);
        void parsed(DSString id, DSString text);
        DSVector<pair<DSString, bool>>& getGuesses();
};


#endif //ASSIGNMENT2_SENTIMENT_TESTING_H
