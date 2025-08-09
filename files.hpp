#pragma once

#include <iostream>
#include <fstream>
#include <string>

/*
 * ROUND TYPE CODE
 * ---------------
 *  Pounce/Bounce - 0
 *  Buzzer with Challenges - 1
 *  Differential Scoring - 2
 */

void saveScoring(int pounceBounce[4], int buzzerWithChallenges[5], int differentialScoring[9]);

void saveTeamsAndRounds(int nTeams, int nRounds, int nQuestions, int roundType[], std::string teamName[]);



