//
// Created by nabee on 9/20/2022.
//

#ifndef ASSIGNMENT2_SENTIMENT_CHECKING_H
#define ASSIGNMENT2_SENTIMENT_CHECKING_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"DSString.h"
#include "DSVector.h"

class checking {
private:
    DSVector<pair<DSString, bool>> guesses;
    DSVector<pair<DSString, bool>> wrongGuesses;
    DSVector<pair<DSString, bool>> correctSentiments;
    double acc;
public:
    //constructor
     checking(char* c, char* d, char* v, DSVector<pair<DSString, bool>>&);
    void readingIn(DSString filename);
    void crossComparasin();
    void ids(char* c);
    void accuracy(char *c);


};


#endif //ASSIGNMENT2_SENTIMENT_CHECKING_H
