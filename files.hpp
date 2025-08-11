#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * ROUND TYPE CODE
 * ---------------
 *  Pounce/Bounce - 0
 *  Buzzer with Challenges - 1
 *  Differential Scoring - 2
 */

void saveScoring(int pounceBounce[4], int buzzerWithChallenges[5], int differentialScoring[9]);

void saveTeamsAndRounds(int nTeams, int nRounds, int nQuestions, int roundType[], std::string teamName[]);

void loadScoring(int& pplus, int& pminus, int& bplus, int& bminus, int& buzzplus, int& buzzminus, int& challengeplus, int& challengeminus, int& wrong, int& correctplus, int& correctminus, int& correctteams, int& correctpoints, int& wrongplus, int& wrongminus, int& wrongteams, int& wrongpoints, int& morewrong);

void loadTeamsAndRounds(int& nTeams, int& nRounds, int& questions, std::vector<int>& roundType, std::vector<std::string>& teamName);

