//
// Created by nabee on 9/13/2022.
//

#include "testing.h"
//constructor for testing
testing::testing(char *arg, DSVector<pair<DSString, int>>& t) {
    trainWords = t;
    scanner(arg);
}
//reads in the testing file
void testing::scanner(DSString fileName) {
    ifstream inFile;
    inFile.open(fileName.c_str());
    //checks if file is open or not
    if(inFile.is_open())
    {
        cout<<"File is open"<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    char temp[1000];
    inFile.getline(temp, 1000);
    while(!inFile.eof())
    {
       //stores the ID
        inFile.getline(temp, 1000, ',');
        DSString id(temp);
        //discards the unecessary text
        for (int i = 0; i < 3; i++) {
            inFile.getline(temp, 1000, ',');
        }
        inFile.getline(temp, 1000, '\r');
        //tweet DSString object created
        DSString tweet(temp);
        tweet.toLower();
        //tweet sent to the method parsed
        parsed(id, tweet);
        inFile.getline(temp, 1000);
    }

}

void testing::parsed(DSString id, DSString text) {
    //tokenizes the tweet from the testing file into a DSString vector
    DSVector<DSString> list = text.tokenize();
    int count = 0;
    //iterating the list vector
    for(int i = 0; i<list.size(); i++)
    {
        for(int j = 0; j< trainWords.size(); j++)
        {
            //checks to see if the new tweet and the words from the trained tweet data set are the same
            if(list[i] == trainWords[j].first) {
                //if the train words have a positive sentiment, count is incremented
                if (trainWords[j].second > 0) {
                    count++;
                }//if the train words appear in a negative sentiment, count is decremented
                else if (trainWords[j].second < 0) {
                    count--;
                }
                break;
            }
        }
    }
    //creates a new pair construct of the tweet and makes it true if it has more positive sentiment words than negative sentiments
    pair<DSString, bool> temp;
    temp.first = id;
    temp.second = count > 0;
    //the word and the sentiment is added to the guesses vector
    guesses.push_back(temp);
}
//returns guesses
DSVector<pair<DSString, bool>>& testing::getGuesses() {
    return guesses;
}

