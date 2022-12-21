//
// Created by nabee on 9/20/2022.
//

#include "checking.h"
#include <iomanip>

//reads in file
void checking::readingIn(DSString filename) {
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
    char temp [1000];
    inFile.getline(temp, 1000);
    while(!inFile.eof())
    {
        inFile.getline(temp, 1000, ',');
        //reads in and stores the sentiment
        bool sentiment = temp[0] == '4';
        //stores the tweet
        inFile.getline(temp, 1000, '\r');
        //creates a pair construct with tweet and sentiment
        pair<DSString, bool> t;
        t.first = temp;
        t.second = sentiment;
//pushes back the tweet and sentiment to correct sentiments
        correctSentiments.push_back(t);

        inFile.getline(temp, 1000);


    }
    inFile.close();

}
//constructor for checking file
checking::checking(char *c, char *d, char *v, DSVector<pair<DSString, bool>>& g) {
    guesses = g;
    readingIn(c);
    crossComparasin();
    ids(d);
    accuracy(v);
}

void checking::crossComparasin() {
//loops through the guesses vector
    for( int i = 0; i< guesses.size(); i++)
    {
        for (int j = 0; j < correctSentiments.size(); j++)
        {
            //checks to see if the guesses and sentiments words are the same
            if(guesses[i].first == correctSentiments[j].first )
            {
                //checks to see if the sentiments of guesses and correct sentiments are not equal
                if(guesses[i].second != correctSentiments[j].second)
                {
                    //if wrond, pushes back it in the vector
                    pair<DSString, bool> t;
                    t.first = guesses[i].first;
                    t.second = guesses[i].second;
                    wrongGuesses.push_back(t);
                    break;
                }
            }
        }
    }
//calculates accuracy
    acc = (double)(guesses.size() - wrongGuesses.size()) / guesses.size();


}

void checking::ids(char *c) {
    ofstream myfile;
    myfile.open(c);
    //writes the ids and sentiments of the guesses in the file
    for (int i = 0; i < guesses.size(); i++) {
        if (guesses[i].second) {
            myfile << "4,";
        } else {
            myfile << "0,";
        }
        myfile << guesses[i].first << endl;
    }
    myfile.close();
}



void checking::accuracy(char *c) {
    ofstream myfile;
    myfile.open(c);
    //prints accuracy
    myfile << setprecision(3) << acc << endl;
    //prints the wrong guesses and the correct answer
    for (int i = 0; i < wrongGuesses.size(); i++) {
        if (wrongGuesses[i].second) {
            myfile << "4,0,";
        } else {
            myfile << "0,4,";
        }
        myfile << wrongGuesses[i].first << endl;
    }
    myfile.close();
}

