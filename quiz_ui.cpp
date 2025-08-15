#include "quiz_ui.hpp"


roundFrame::roundFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title),

nTeams(0), nRounds(0), questions(0),
pplus(0), pminus(0), bplus(0), bminus(0),
buzzplus(0), buzzminus(0), challengeplus(0), challengeminus(0), wrong(0),
correctplus(0), correctminus(0), correctteams(0), correctpoints(0),
wrongplus(0), wrongminus(0), wrongteams(0), wrongpoints(0),
morewrong(0) {

    loadScoring(this->pplus, this->pminus, this->bplus, this->bminus, this->buzzplus, this->buzzminus, this->challengeplus, this->challengeminus, this->wrong, this->correctplus, this->correctminus, this->correctteams, this->correctpoints, this->wrongplus, this->wrongminus, this->wrongteams, this->wrongpoints, this->morewrong);

    loadTeamsAndRounds(this->nTeams, this->nRounds, this->questions, this->roundType, this->teamName);
}

void roundFrame::switchToHome(wxCommandEvent& evt) {

    wxMessageDialog* warn = new wxMessageDialog(this, "Are you sure you want to exit?", "Exit quiz", wxYES_NO | wxICON_WARNING);

    if (warn->ShowModal() == wxID_YES) {

        startupFrame* frame = new startupFrame("QuizSoc Home");

        frame->SetClientSize(500, 440);
        frame->Center();
        frame->Show();

        this->Close();
    }

    return;
}


pounceBounceFrame::pounceBounceFrame(const wxString& title) : roundFrame(title) {

    wxScrolled<wxPanel>* scrollable = new wxScrolled<wxPanel>(this);

    wxBoxSizer* masterSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* switchSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* teamSizer1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* teamSizer2 = new wxBoxSizer(wxHORIZONTAL);

    
    wxPanel* switchPanel = new wxPanel(this, wxID_ANY);
    wxPanel* mainPanel = new wxPanel(scrollable, wxID_ANY);
    wxPanel* controlPanel = new wxPanel(this, wxID_ANY);

    wxStaticText* qLabel = new wxStaticText(switchPanel, wxID_ANY, "Question");

    wxChoice* qNumber = new wxChoice(switchPanel, wxID_ANY);

    for (int i = 1; i <= this->questions; i++)
        qNumber->Append(wxString::Format("%d", i));
    qNumber->SetSelection(0);

    wxButton* qChange = new wxButton(switchPanel, wxID_ANY, "Change question");

    switchSizer->AddStretchSpacer(1);
    switchSizer->Add(qLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
    switchSizer->Add(qNumber, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
    switchSizer->Add(qChange, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
    switchSizer->AddStretchSpacer(1);

    switchPanel->SetSizerAndFit(switchSizer);

    wxButton* round = new wxButton(controlPanel, wxID_ANY, "Change round");
    wxButton* scoreboard = new wxButton(controlPanel, wxID_ANY, "Show scoreboard");
    wxButton* mark = new wxButton(controlPanel, wxID_ANY, "Mark");
    wxButton* quit = new wxButton(controlPanel, wxID_ANY, "Quit");


    wxFont bold = GetFont().MakeBold();

    
    wxArrayString teamNames;

    for (const auto& name : this->teamName)
        teamNames.Add(name);

    wxCheckListBox* teamspp = new wxCheckListBox(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, teamNames);
    teamspp->SetMinSize(wxSize(200, 150));
    wxStaticText* pplabel = new wxStaticText(mainPanel, wxID_ANY, "Pounce (Correct)");
    pplabel->SetFont(bold);

    wxCheckListBox* teamspm = new wxCheckListBox(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, teamNames);
    teamspm->SetMinSize(wxSize(200, 150));
    wxStaticText* pmlabel = new wxStaticText(mainPanel, wxID_ANY, "Pounce (Wrong)");
    pmlabel->SetFont(bold);

    wxCheckListBox* teamsbp = new wxCheckListBox(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, teamNames);
    teamsbp->SetMinSize(wxSize(200, 150));
    wxStaticText* bplabel = new wxStaticText(mainPanel, wxID_ANY, "Bounce (Correct)");
    bplabel->SetFont(bold);

    wxCheckListBox* teamsbm = new wxCheckListBox(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, teamNames);
    teamsbm->SetMinSize(wxSize(200, 150));
    wxStaticText* bmlabel = new wxStaticText(mainPanel, wxID_ANY, "Bounce (Wrong)");
    bmlabel->SetFont(bold);

    wxBoxSizer* teamppSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* teampmSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* teambpSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* teambmSizer = new wxBoxSizer(wxVERTICAL);

    teamppSizer->Add(pplabel, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
    teamppSizer->Add(teamspp, 1, wxALIGN_CENTER_HORIZONTAL);

    teampmSizer->Add(pmlabel, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
    teampmSizer->Add(teamspm, 1, wxALIGN_CENTER_HORIZONTAL);

    teambpSizer->Add(bplabel, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
    teambpSizer->Add(teamsbp, 1, wxALIGN_CENTER_HORIZONTAL);

    teambmSizer->Add(bmlabel, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);
    teambmSizer->Add(teamsbm, 1, wxALIGN_CENTER_HORIZONTAL);

    teamSizer1->Add(teamppSizer, 1, wxEXPAND | wxALL, 5);
    teamSizer1->Add(teampmSizer, 1, wxEXPAND | wxALL, 5);
    teamSizer2->Add(teambpSizer, 1, wxEXPAND | wxALL, 5);
    teamSizer2->Add(teambmSizer, 1, wxEXPAND | wxALL, 5);

    mainSizer->AddStretchSpacer(1);
    mainSizer->Add(teamSizer1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 20);
    mainSizer->Add(teamSizer2, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 20);
    mainSizer->AddStretchSpacer(1);
    mainPanel->SetSizer(mainSizer);

    controlSizer->Add(round, 0, wxALL, 10);
    controlSizer->Add(scoreboard, 0, wxALL, 10);
    controlSizer->AddStretchSpacer(1);
    controlSizer->Add(mark, 0, wxALL, 10);
    controlSizer->Add(quit, 0, wxALL, 10);

    controlPanel->SetSizerAndFit(controlSizer);
    
    masterSizer->Add(switchPanel, 0, wxEXPAND | wxALL, 5);
    masterSizer->Add(scrollable, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND | wxALL);
    masterSizer->Add(controlPanel, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* scrollSizer = new wxBoxSizer(wxVERTICAL);
    scrollSizer->Add(mainPanel, 1, wxEXPAND);
    scrollable->SetSizerAndFit(scrollSizer);

    scrollable->FitInside();
    scrollable->SetScrollRate(5,5);

    quit->Bind(wxEVT_BUTTON, &roundFrame::switchToHome, this);

    this->SetSizerAndFit(masterSizer);
    this->Layout();
}




