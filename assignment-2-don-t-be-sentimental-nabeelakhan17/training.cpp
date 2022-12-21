
#include "training.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;
//method reading into the file
void training:: FileReader(DSString filename)
{
    ifstream inFile;
    inFile.open(filename.c_str());
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

    //parsing till the end of the file
    while(!inFile.eof())
    {
        //getting the sentiment value and setting the sentiment to true if it equals 4
        inFile.getline(temp, 1000, ',');
        bool sentiment = temp[0] == '4';
        for (int i = 0; i < 4; i++) {
            inFile.getline(temp, 1000, ',');
        }
        //getting the tweet
        inFile.getline(temp, 1000, '\r');
        DSString tweet(temp);
        tweet.toLower();
        //parsing through the tweet and giving each worde a positive or negative sentiment
        parsedTweet(sentiment, tweet);
        inFile.getline(temp, 1000);
    }
    inFile.close();
}

void training::parsedTweet(bool sentiment, DSString text) {
    //parsing the tweet taken from the above method into tokens
    DSVector<DSString> list = text.tokenize();
    //looping through the tweet
    for(int i = 0; i<list.size(); i++)
    {
        bool found = false;
        //looping through the words found in the tweet
        for(int j = 0; j< words.size(); j++)
        {
            //if the words in the new tweet match the old tweet it goes in
            if(list[i] == words[j].first) {
                //if the sentiment is true the words counter is incremented
                if (sentiment) {
                    words[j].second++;
                } //if the sentiment is false, the words counter is decremented
                else {
                    words[j].second--;
                }
                found = true;
                break;
            }
        }
        //if the word of the new tweet is not found in the prevoius tweets a new pair is created and a number for sentiment is assigned
        if (!found) {
            pair<DSString, int> temp;
            temp.first = list[i];
            if (sentiment) {
                temp.second = 1;
            } else {
                temp.second = -1;
            }
            words.push_back(temp);
        }

    }
}

training::training(char *arg) {
    FileReader(arg);
}
//returns getWords
DSVector<pair<DSString, int>> &training::getWords() {
    return words;
}
