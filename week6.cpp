// week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
// get the bowling scores
void GetBowlingData(string names[10], int scores[10][5]) {
    int i = 0;
    ifstream fs;
    fs.open("BowlingScores.txt");
    while (!fs.eof()) {
        // storing the string in name in index 0, then the next four numbers because there are 4 numbers recorded for each player then when i is 1 it does it does for the second line ect
        fs >> names[i] >> scores[i][0] >> scores[i][1] >> scores[i][2] >> scores[i][3] >> scores[i][4];

        i++;
    }
    

}
// to get the average we have to nest the loop to be able to loop each number
void GetAverageScore(int scores[10][5], double averageScores[10]) {

    for (int i = 0; i < 10; i++) {

        averageScores[i] = 0;
        for (int j = 0; j < 5; j++) {
        // for index 0 it will calculate the whole first line then keep going down until the tenth line which is the 9th element
              averageScores[i] += scores[i][j];

        }

        averageScores[i] /= 5.00;

    }
    

}
void PrettyPrintResults(string names[10], int scores[10][5], double averageScores[10]) {

   
    // this is the same loop as the getaveragescore function it is a nested loop. the names will all be on the left column then each score will be displayed with space between them
    for (int i = 0; i < 10; i++) {

        cout << left << setw(10) << names[i] ;

        for (int j = 0; j < 5; j++)

            cout << scores[i][j] << "\t";
        // after the average score it end the line and go back to printing the name
            cout << averageScores[i] << endl;

    }

}
int main() {
    // declaring all of the variables and calling the functions with their arguments.
    string names[10];

    int scores[10][5];

    double averageScores[10];

    int i = 0;

    GetBowlingData(names, scores);

    GetAverageScore(scores, averageScores);

    PrettyPrintResults(names, scores, averageScores);

}
