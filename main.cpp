#include "main.hpp"
#include "ui.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit() {

    wxInitAllImageHandlers();

    startupFrame* frame = new startupFrame("QuizSoc Startup");
    frame->SetClientSize(500,440);
    frame->Center();
    frame->Show();

    return true;
}


