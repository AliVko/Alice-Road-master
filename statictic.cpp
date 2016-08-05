#include "statictic.h"

#include <iomanip>
#include <iostream>

using namespace std;

Statistic::Statistic() {
    this->totalScore = 0;
    this->average = 0;
    this->totalGames = 0;
    this->lastScore = 0;
    this->bestScore = 0;
}

unsigned long long int Statistic::getTotalScore() {
    return this->totalScore;
}

double Statistic::getAverage() {
    return this->average;
}

unsigned int Statistic::getTotalGames() {
    return this->totalGames;
}

unsigned long long int Statistic::getLastScore() {
    return this->lastScore;
}

unsigned long long int Statistic::getBestScore() {
    return this->bestScore;
}

void Statistic::addScore(unsigned long long int score) {
    totalScore += score;
    lastScore = score;
    if ( score > bestScore ) bestScore = score;
    average = (average*totalGames++) + score;
    average /= totalGames;

}

void Statistic::resetScore() {
    this->totalScore = 0;
    this->average = 0;
    this->totalGames = 0;
    this->lastScore = 0;
    this->bestScore = 0;
}

void Statistic::printInfo() {
    cout << endl << "Total score: " << totalScore;
    cout << endl << "Total games: " << totalGames;
    cout << endl << "Last score: " << lastScore;
    cout << endl << "Best score: " << bestScore;
    cout << endl << "Average: " << setw(8) << setprecision(2) << average << endl;
}
