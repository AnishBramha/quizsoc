#pragma once

#include <wx/wx.h>

class roundFrame : public wxFrame {

    public:

        roundFrame(const wxString& title);

        virtual ~roundFrame() = default;

    private:

        void switchToHome(wxCommandEvent& evt);
        virtual void switchRound(wxCommandEvent& evt, const wxString& roundName) const = 0;
        void showScores(wxCommandEvent& evt);

        /* ROUND NAMES
         * -----------
         * Pounce/Bounce
         * Buzzer with Challeneges
         * Differential Scoring
        */

        virtual void onSave(wxCommandEvent& evt) const = 0;
        virtual void onSaveAs(wxCommandEvent& evt) const = 0;
        virtual void save(const wxString& filepath) const = 0;
        virtual void saveAs(void) const = 0;
};

class pounceBounceFrame : public roundFrame {

    public:

        pounceBounceFrame(const wxString& title);
};

class buzzerChallenges : public roundFrame {

    public:

        buzzerChallenges(const wxString& title);
};

class differentialScoring : public roundFrame {

    public:

        differentialScoring(const wxString& title);
};








