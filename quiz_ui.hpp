#pragma once

#include <wx/wx.h>
#include <vector>
#include "files.hpp"
#include "setup_ui.hpp"

class roundFrame : public wxFrame {

    public:

        roundFrame(const wxString& title);

        virtual ~roundFrame() = default;

        /* ROUND NAMES
         * -----------
         * Pounce/Bounce
         * Buzzer with Challeneges
         * Differential Scoring
        */

    protected:

        void switchToHome(wxCommandEvent& evt);
        void showScores(wxCommandEvent& evt);
/*
        virtual void onSave(wxCommandEvent& evt) = 0;
        virtual void onSaveAs(wxCommandEvent& evt) = 0;
        virtual void save(const wxString& filepath) = 0;
        virtual void saveAs(void) = 0;
*/
        int nTeams, nRounds, questions;
        int pplus, pminus, bplus, bminus;
        int buzzplus, buzzminus, challengeplus, challengeminus, wrong;
        int correctplus, correctminus, correctteams, correctpoints;
        int wrongplus, wrongminus, wrongteams, wrongpoints;
        int morewrong;

        std::vector<int> roundType;
        std::vector<std::string> teamName;
};

class pounceBounceFrame : public roundFrame {

    public:

        pounceBounceFrame(const wxString& title);

    private:

        
};

class buzzerChallenges : public roundFrame {

    public:

        buzzerChallenges(const wxString& title);
};

class differentialScoring : public roundFrame {

    public:

        differentialScoring(const wxString& title);
};








