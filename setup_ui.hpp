#pragma once

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <vector>
#include "quiz_ui.hpp"
#include "files.hpp"

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
        wxSpinCtrl* scoreChooser(wxWindow* parent, wxSizer* sizer, const wxString& label);

        wxSpinCtrl* pplus;
        wxSpinCtrl* pminus;
        wxSpinCtrl* bplus;
        wxSpinCtrl* bminus;

        wxSpinCtrl* buzzplus;
        wxSpinCtrl* buzzminus;
        wxSpinCtrl* challengeplus;
        wxSpinCtrl* challengeminus;
        wxSpinCtrl* challengeWrong;

        wxSpinCtrl* plusCorrect;
        wxSpinCtrl* plusWrong;
        wxSpinCtrl* plusTeams;
        wxSpinCtrl* plusPoints;
        wxSpinCtrl* minusCorrect;
        wxSpinCtrl* minusWrong;
        wxSpinCtrl* minusTeams;
        wxSpinCtrl* minusPoints;
        wxSpinCtrl* moreWrong;
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

        std::vector<wxChoice*> roundType;
        std::vector<wxTextCtrl*> teamName;
};

class aboutFrame : public wxFrame {

    public:

        aboutFrame(const wxString& title);
};



