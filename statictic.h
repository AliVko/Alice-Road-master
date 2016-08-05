#ifndef STATICTIC_H_INCLUDED
#define STATICTIC_H_INCLUDED

class Statistic {
private:
    unsigned long long int totalScore;
    double average;
    unsigned int totalGames;
    unsigned long long int lastScore;
    unsigned long long int bestScore;
public:
    Statistic();
    unsigned long long int getTotalScore();
    double getAverage();
    unsigned int getTotalGames();
    unsigned long long int getLastScore();
    unsigned long long int getBestScore();

    void addScore(unsigned long long int score);
    void resetScore();

    void printInfo();
};

#endif // STATICTIC_H_INCLUDED
