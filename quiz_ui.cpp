#include "quiz_ui.hpp"


roundFrame::roundFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    loadScoring(this->pplus, this->pminus, this->bplus, this->bminus, this->buzzplus, this->buzzminus, this->challengeplus, this->challengeminus, this->wrong, this->correctplus, this->correctminus, this->correctteams, this->correctpoints, this->wrongplus, this->wrongminus, this->wrongteams, this->wrongpoints, this->morewrong);

    loadTeamsAndRounds(this->nTeams, this->nRounds, this->questions, this->roundType, this->teamName);
}

void roundFrame::switchToHome(wxCommandEvent& evt) {

    int opt = wxMessageBox("Are you sure you want to exit?", "Exit quiz", wxOK | wxCANCEL | wxICON_WARNING);

    if (opt == wxID_OK) {

        startupFrame* frame = new startupFrame("QuizSoc Home");

        frame->SetClientSize(500, 440);
        frame->Center();
        frame->Show();

        this->Close();
    }

    return;
}



pounceBounceFrame::pounceBounceFrame(const wxString& title) : roundFrame(title) {

    
}




