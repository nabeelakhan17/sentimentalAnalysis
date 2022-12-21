//
// Created by nabee on 9/12/2022.
//

#ifndef ASSIGNMENT2_SENTIMENT_TRAINING_H
#define ASSIGNMENT2_SENTIMENT_TRAINING_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"DSString.h"
#include "DSVector.h"
class training {
private:
    //stores the sentiments and tweets from the training file
    DSVector<pair<DSString, int>> words;
public:
    //trains file
    explicit training(char*);
//reads in
    void FileReader(DSString);
    //parses tweet
    void parsedTweet( bool sentiment, DSString text);

    DSVector<pair<DSString, int>>& getWords();


};


#endif //ASSIGNMENT2_SENTIMENT_SCANNER_H
