#pragma once

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>

class startupFrame : public wxFrame {

    public:

        startupFrame(const wxString& title);

    private:

        void showAbout(wxCommandEvent& evt);
        void switchToMain(wxCommandEvent& evt);
        void quit(wxCommandEvent& evt);
};

class mainFrame : public wxFrame {

    public:

        mainFrame(const wxString& title);

    private:

        void switchToHome(wxCommandEvent& evt);
        void showTeams(wxCommandEvent& evt);
        void scoreChooser(wxWindow* parent, wxSizer* sizer, const wxString& label);
};

class teamFrame : public wxFrame {

    public:

        teamFrame(const wxString& title);

    private:
        
        void showTeamChooser(wxCommandEvent& evt);
        void switchToHome(wxCommandEvent& evt);

        wxSpinCtrl* teams;
        wxSpinCtrl* rounds;
        wxSpinCtrl* questions;
       
        wxBoxSizer* mainSizer;
        wxBoxSizer* controlSizer;

        wxScrolled<wxPanel>* scrollable;
};

class aboutFrame : public wxFrame {

    public:

        aboutFrame(const wxString& title);
};

class roundFrame : public wxFrame {

    public:

        roundFrame(const wxString& title);

        virtual ~roundFrame() = default;

    private:

        void switchToHome(wxCommandEvent& evt);
        virtual void switchRound(wxCommandEvent& evt, const wxString& roundName) const = 0;

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





