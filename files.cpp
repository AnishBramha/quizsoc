#include "files.hpp"

void saveScoring(int pounceBounce[4], int buzzerWithChallenges[5], int differentialScoring[9]) {

    std::fstream fout;
    fout.open(".scoring", std::ios::out);

    for (int i = 0; i < 3; i++)
        fout << pounceBounce[i] << "%";
    fout << buzzerWithChallenges[3] << "\n";

    for (int i = 0; i < 4; i++)
        fout << buzzerWithChallenges[i] << "%";
    fout << buzzerWithChallenges[4] << "\n";

    for (int i = 0; i < 7; i++)
        fout << differentialScoring[i] << "%";
    fout << differentialScoring[8] << "\n";

    fout.close();
    return;
}

void saveTeamsAndRounds(int nTeams, int nRounds, int nQuestions, int roundType[], std::string teamName[]) {

    std::fstream fout;
    fout.open(".settings", std::ios::out);

    fout << nTeams << "%" << nRounds << "%" << nQuestions << "\n";

    for (int i = 0; i < nRounds - 1; i++)
        fout << roundType[i] << "%";
    fout << roundType[nRounds - 1] << "\n";

    for (int i = 0; i < nTeams; i++)
        fout << teamName[i] << "\n";

    fout.close();
    return;
}


