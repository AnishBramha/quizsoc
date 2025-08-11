#include "files.hpp"

void saveScoring(int pounceBounce[4], int buzzerWithChallenges[5], int differentialScoring[9]) {

    std::fstream fout;
    fout.open(".scoring", std::ios::out);

    for (int i = 0; i < 3; i++)
        fout << pounceBounce[i] << " ";
    fout << pounceBounce[3] << "\n";

    for (int i = 0; i < 4; i++)
        fout << buzzerWithChallenges[i] << " ";
    fout << buzzerWithChallenges[4] << "\n";

    for (int i = 0; i < 8; i++)
        fout << differentialScoring[i] << " ";
    fout << differentialScoring[8] << "\n";

    fout.close();
    return;
}

void loadScoring(int &pplus, int &pminus, int &bplus, int &bminus, int &buzzplus, int &buzzminus, int &challengeplus, int &challengeminus, int &wrong, int &correctplus, int &correctminus, int &correctteams, int &correctpoints, int &wrongplus, int &wrongminus, int &wrongteams, int& wrongpoints, int &morewrong) {

    std::fstream fin;
    fin.open(".scoring", std::ios::in);

    fin >> pplus >> pminus >> bplus >> bminus;
    fin >> buzzplus >> buzzminus >> challengeplus >> challengeminus >> wrong;
    fin >> correctplus >> correctminus >> correctteams >> correctpoints >> wrongplus >> wrongminus >> wrongteams >> wrongpoints >> morewrong;

    fin.close();
    return;
}

void saveTeamsAndRounds(int nTeams, int nRounds, int nQuestions, int roundType[], std::string teamName[]) {

    std::fstream fout;
    fout.open(".settings", std::ios::out);

    fout << nTeams << " " << nRounds << " " << nQuestions << "\n";

    for (int i = 0; i < nRounds - 1; i++)
        fout << roundType[i] << " ";
    fout << roundType[nRounds - 1] << "\n";

    for (int i = 0; i < nTeams; i++)
        fout << teamName[i] << "\n";

    fout.close();
    return;
}

void loadTeamsAndRounds(int &nTeams, int &nRounds, int &questions, std::vector<int> &roundType, std::vector<std::string> &teamName) {

    std::fstream fin;
    fin.open(".settings", std::ios::in);

    fin >> nTeams >> nRounds >> questions;

    for (int i = 0; i < nRounds; i++) {

        int type;
        fin >> type;

        roundType.push_back(type);
    }

    for (int i = 0; i < nTeams; i++) {

        std::string name;
        std::getline(fin >> std::ws, name);

        teamName.push_back(name);
    }

    fin.close();
    return;
}


