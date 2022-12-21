#include <iostream>
#include <algorithm>

#include "training.h"
#include "testing.h"
#include "checking.h"

using namespace std;

int main(int argc, char** argv)
{
    //printing files
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    //accessing the training class through command line
    training train(argv[1]);
    //accessing the testing class through command line
    testing test(argv[2], train.getWords());
    //accessing the checking class through command line
    checking check(argv[3], argv[4], argv[5], test.getGuesses());

    return 0;
}
