#include "setup_ui.hpp"

/*
* *************
* HOME FRAME
* *************
*/

startupFrame::startupFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxImage image;
    image.LoadFile("QuizSoc_Logo.png", wxBITMAP_TYPE_PNG);
    wxBitmap bmp(image);
    wxStaticBitmap* logo = new wxStaticBitmap(panel, wxID_ANY, bmp);

    wxButton* create = new wxButton(panel, wxID_ANY, "Create Quiz");
    wxButton* about = new wxButton(panel, wxID_ANY, "About");
    wxButton* quit = new wxButton(panel, wxID_ANY, "Quit");

    wxStaticLine* hSep = new wxStaticLine(panel);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);

    controlSizer->Add(create, 0, wxALL, 5);
    controlSizer->Add(about, 0, wxALL, 5);
    controlSizer->Add(quit, 0, wxALL, 5);
   
    mainSizer->Add(logo, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 20);
    mainSizer->Add(hSep, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);
    mainSizer->Add(controlSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    panel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    create->Bind(wxEVT_BUTTON, &startupFrame::switchToMain, this);
    about->Bind(wxEVT_BUTTON, &startupFrame::showAbout, this);
    quit->Bind(wxEVT_BUTTON, &startupFrame::quit, this);
}


void startupFrame::showAbout(wxCommandEvent& evt) {

    aboutFrame* frame = new aboutFrame("About");
    frame->SetClientSize(300,165);
    frame->Center();
    frame->Show();
}

void startupFrame::quit(wxCommandEvent& evt) {

    this->Close();
}

void startupFrame::switchToMain(wxCommandEvent& evt) {

    mainFrame* frame = new mainFrame("Set the scoring system");
    frame->SetClientSize(825, 450);
    frame->Center();
    frame->Show();

    this->Close();
}

/*
* ***********
* ABOUT FRAME
* ***********
*/

aboutFrame::aboutFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX & ~wxMINIMIZE_BOX) {

    wxBoxSizer* boxSizer = new wxBoxSizer(wxALL);

    wxStaticText* info = new wxStaticText(this, wxID_ANY, "\t Free and Open Source Quiz Manager\n\n Licensed under the GNU Public License (3.0)\n\n\t\t\tVersion 1.0.0 (beta)\n\n\t\t~ Anish Teja Bramhajosyula\n\n\t\thttps://www.github.com/AnishBramha/quizsoc");

    boxSizer->Add(info, 0, wxALL | wxALIGN_CENTER, 10);

    this->SetSizerAndFit(boxSizer);
    this->Layout();
}


/*
 * ********************
 * SCORE SELECTOR FRAME
 * ********************
*/


mainFrame::mainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE) {

    wxScrolled<wxPanel>* scrollable = new wxScrolled<wxPanel>(this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxFont bold = GetFont().MakeBold();

    wxStaticText* headingPounceBounce = new wxStaticText(scrollable, wxID_ANY, "Pounce/Bounce");
    headingPounceBounce->SetFont(bold);
    mainSizer->Add(headingPounceBounce, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    wxBoxSizer* pounceBounceSizer1 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, pounceBounceSizer1, "(+)Pounce");
    scoreChooser(scrollable, pounceBounceSizer1, "(-)Pounce");
    mainSizer->Add(pounceBounceSizer1, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    mainSizer->AddSpacer(10);

    wxBoxSizer* pounceBounceSizer2 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, pounceBounceSizer2, "(+)Bounce");
    scoreChooser(scrollable, pounceBounceSizer2, "(-)Bounce");
    mainSizer->Add(pounceBounceSizer2, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);

    
    mainSizer->Add(new wxStaticLine(scrollable), 0, wxEXPAND | wxALL, 20);

    wxStaticText* headingBuzzerChallenges = new wxStaticText(scrollable, wxID_ANY, "Buzzer with Challenges");
    headingBuzzerChallenges->SetFont(bold);
    mainSizer->Add(headingBuzzerChallenges, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    wxBoxSizer* buzzerChallengesSizer1 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, buzzerChallengesSizer1, "(+)Buzz");
    scoreChooser(scrollable, buzzerChallengesSizer1, "(-)Buzz");
    mainSizer->Add(buzzerChallengesSizer1, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    mainSizer->AddSpacer(20);

    wxBoxSizer* buzzerChallengesSizer2 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, buzzerChallengesSizer2, "(+)Challenge");
    scoreChooser(scrollable, buzzerChallengesSizer2, "(-)Challenge");
    scoreChooser(scrollable, buzzerChallengesSizer2, "(-)Agreeing with wrong challenge");
    mainSizer->Add(buzzerChallengesSizer2, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    

    mainSizer->Add(new wxStaticLine(scrollable), 0, wxEXPAND | wxALL, 20);

    wxStaticText* headingDifferentialScoring = new wxStaticText(scrollable, wxID_ANY, "Differential Scoring");
    headingDifferentialScoring->SetFont(bold);
    mainSizer->Add(headingDifferentialScoring, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    wxBoxSizer* differentialScoringSizer1 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, differentialScoringSizer1, "(+) = (Correct Answers ×");
    scoreChooser(scrollable, differentialScoringSizer1, "+ Wrong Answers ×");
    scoreChooser(scrollable, differentialScoringSizer1, "+ Number of Teams ×");
    scoreChooser(scrollable, differentialScoringSizer1, ") × Points:");
    mainSizer->Add(differentialScoringSizer1, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    mainSizer->AddSpacer(10);

    wxBoxSizer* differentialScoringSizer2 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, differentialScoringSizer2, "(-) = (Correct Answers ×");
    scoreChooser(scrollable, differentialScoringSizer2, "+ Wrong Answers ×");
    scoreChooser(scrollable, differentialScoringSizer2, "+ Number of Teams ×");
    scoreChooser(scrollable, differentialScoringSizer2, ") × Points:");
    mainSizer->Add(differentialScoringSizer2, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    mainSizer->AddSpacer(10);

    wxBoxSizer* differentialScoringSizer3 = new wxBoxSizer(wxHORIZONTAL);
    scoreChooser(scrollable, differentialScoringSizer3, "If more wrong answers: (-)");
    mainSizer->Add(differentialScoringSizer3, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);
    mainSizer->AddSpacer(10);


    scrollable->SetSizerAndFit(mainSizer);
    scrollable->FitInside();
    scrollable->SetScrollRate(5,5);

    
    wxButton* cancel = new wxButton(this, wxID_ANY, "Cancel");
    wxButton* next = new wxButton(this, wxID_ANY, "Next");
    
    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);
    controlSizer->Add(cancel, 0, wxALL, 10);
    controlSizer->AddStretchSpacer(1);
    controlSizer->Add(next, 0, wxALL, 10);

    wxBoxSizer* scrollableSizer = new wxBoxSizer(wxVERTICAL);
    scrollableSizer->Add(scrollable, 1, wxEXPAND);
    scrollableSizer->Add(controlSizer, 0, wxEXPAND);

    this->SetSizerAndFit(scrollableSizer);
    this->Layout();

    cancel->Bind(wxEVT_BUTTON, &mainFrame::switchToHome, this);
    next->Bind(wxEVT_BUTTON, &mainFrame::showTeams, this);
}


void mainFrame::showTeams(wxCommandEvent& evt) {

    teamFrame* frame = new teamFrame("Configure teams and rounds");
    frame->SetClientSize(800,600);
    frame->Center();
    frame->Show();
    
    this->Close();
}


void mainFrame::scoreChooser(wxWindow* parent, wxSizer* sizer, const wxString& label) {

    sizer->Add(new wxStaticText(parent, wxID_ANY, label), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);

    wxSpinCtrl* score = new wxSpinCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(45, -1), wxSP_ARROW_KEYS | wxSP_WRAP, -100, 100, 0);

    sizer->Add(score, 0, wxRIGHT, 15);
}

void mainFrame::switchToHome(wxCommandEvent& evt) {

    startupFrame* frame = new startupFrame("QuizSoc Home");
    frame->SetClientSize(500, 440);
    frame->Center();
    frame->Show();

    this->Close();
}


/*
 * ***************************
 * TEAM & ROUND SELECTOR FRAME
 * ***************************
*/

teamFrame::teamFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    this->scrollable = new wxScrolled<wxPanel>(this);

    wxBoxSizer* masterSizer = new wxBoxSizer(wxVERTICAL);
    this->mainSizer = new wxBoxSizer(wxVERTICAL);
    this->controlSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* exitSizer = new wxBoxSizer(wxHORIZONTAL);

    wxPanel* controlPanel = new wxPanel(this->scrollable, wxID_ANY);
    wxPanel* exitPanel = new wxPanel(this, wxID_ANY);

    wxStaticText* teamPrompt = new wxStaticText(controlPanel, wxID_ANY, "Number of teams");
    this->teams = new wxSpinCtrl(controlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(45, -1), wxSP_ARROW_KEYS | wxSP_WRAP, 1, 50, 1);

    wxStaticText* roundPrompt = new wxStaticText(controlPanel, wxID_ANY, "Number of rounds");
    this->rounds = new wxSpinCtrl(controlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(45, -1), wxSP_ARROW_KEYS | wxSP_WRAP, 1, 50, 1);
    
    wxStaticText* questionsPrompt = new wxStaticText(controlPanel, wxID_ANY, "Questions per round");
    this->questions = new wxSpinCtrl(controlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(45, -1), wxSP_ARROW_KEYS | wxSP_WRAP, 1, 50, 1);

    wxButton* customize = new wxButton(controlPanel, wxID_ANY, "Customize");

    this->controlSizer->Add(teamPrompt, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    this->controlSizer->Add(this->teams, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    this->controlSizer->Add(roundPrompt, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    this->controlSizer->Add(this->rounds, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    this->controlSizer->Add(questionsPrompt, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    this->controlSizer->Add(this->questions, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    this->controlSizer->Add(customize, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    controlPanel->SetSizerAndFit(this->controlSizer);
    this->mainSizer->Add(controlPanel, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 20);

    
    customize->Bind(wxEVT_BUTTON, &teamFrame::showTeamChooser, this);


    this->scrollable->SetSizer(this->mainSizer);
    this->scrollable->FitInside();
    this->scrollable->SetScrollRate(5,5);


    wxButton* cancel = new wxButton(exitPanel, wxID_ANY, "Cancel");
    wxButton* start = new wxButton(exitPanel, wxID_ANY, "Start");

    exitSizer->Add(cancel, 0, wxEXPAND | wxALL, 10);
    exitSizer->AddStretchSpacer(1);
    exitSizer->Add(start, 0, wxEXPAND | wxALL, 10);

    exitPanel->SetSizerAndFit(exitSizer);

    wxBoxSizer* scrollableSizer = new wxBoxSizer(wxVERTICAL);
    scrollableSizer->Add(scrollable, 1, wxEXPAND);
    scrollableSizer->Add(exitSizer, 0, wxEXPAND);

    masterSizer->Add(this->scrollable, 1, wxEXPAND | wxALL, 10);
    masterSizer->Add(exitPanel, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);

    this->SetSizerAndFit(masterSizer);
    this->Layout();

    cancel->Bind(wxEVT_BUTTON, &teamFrame::switchToHome, this);

}



void teamFrame::showTeamChooser(wxCommandEvent& evt) {

    wxButton* button = wxDynamicCast(evt.GetEventObject(), wxButton);

    if (button->GetLabel() == "Customize") {

        long nTeams = this->teams->GetValue();
        long nRounds = this->rounds->GetValue();

        this->rounds->Disable();
        this->teams->Disable();
        this->questions->Disable();

        if (button)
            button->SetLabel("Reset");

        this->mainSizer->Add(new wxStaticLine(this->scrollable), 0, wxEXPAND | wxALL, 20);

        wxFont bold = GetFont().MakeBold();

        wxStaticText* headingRounds = new wxStaticText(this->scrollable, wxID_ANY, "Select round type");
        headingRounds->SetFont(bold);
        this->mainSizer->Add(headingRounds, 0, wxALL, 5);

        for (int r = 1; r <= nRounds; r++) {

            wxBoxSizer* roundSizer = new wxBoxSizer(wxHORIZONTAL);

            wxStaticText* nRound = new wxStaticText(this->scrollable, wxID_ANY, wxString::Format("Round %d", r), wxDefaultPosition, wxSize(60, -1));

            wxChoice* roundType = new wxChoice(this->scrollable, wxID_ANY);
            roundType->Append("Pounce/Bounce");
            roundType->Append("Buzzer with Challenges");
            roundType->Append("Differential Scoring");

            roundSizer->Add(nRound, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
            roundSizer->Add(roundType, 0, wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

            this->mainSizer->Add(roundSizer, 0, wxEXPAND | wxALL, 5);
        }

        this->mainSizer->Add(new wxStaticLine(this->scrollable), 0, wxEXPAND | wxALL, 20);

        wxStaticText* headingTeams = new wxStaticText(this->scrollable, wxID_ANY, "Name your teams");
        headingTeams->SetFont(bold);
        this->mainSizer->Add(headingTeams, 0, wxALL, 5);

        for (int t = 1; t <= nTeams; t++) {

            wxBoxSizer* teamSizer = new wxBoxSizer(wxHORIZONTAL);

            wxStaticText* nTeam = new wxStaticText(this->scrollable, wxID_ANY, wxString::Format("Team %d", t), wxDefaultPosition, wxSize(60, -1));

            wxTextCtrl* teamName = new wxTextCtrl(this->scrollable, wxID_ANY, "");

            teamSizer->Add(nTeam, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
            teamSizer->Add(teamName, 1, wxEXPAND | wxALIGN_CENTER_VERTICAL | wxLEFT, 5);

            this->mainSizer->Add(teamSizer, 0, wxEXPAND | wxALL, 5);
        }

        this->scrollable->Layout();
        this->scrollable->FitInside();
        this->mainSizer->Layout();
    
    } else {

        teamFrame* frame = new teamFrame("Configure teams and rounds");
        frame->SetClientSize(this->GetClientSize());
        frame->Center();
        frame->Show();

        this->Close();
    }
}


void teamFrame::switchToHome(wxCommandEvent& evt) {

    startupFrame* frame = new startupFrame("QuizSoc Home");
    frame->SetClientSize(500,440);
    frame->Center();
    frame->Show();

    this->Close();
}



