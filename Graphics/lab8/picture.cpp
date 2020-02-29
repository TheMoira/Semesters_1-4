///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "picture.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* window;
	window = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* image;
	image = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,533 ), wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );
	
	image->Add( m_panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	window->Add( image, 1, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	wxBoxSizer* options;
	options = new wxBoxSizer( wxVERTICAL );
	
	options->SetMinSize( wxSize( 200,-1 ) ); 
	ReadFromFile_Button = new wxButton( this, wxID_ANY, wxT("Wczytaj obrazek"), wxDefaultPosition, wxDefaultSize, 0 );
	options->Add( ReadFromFile_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	cenzure_button = new wxButton( this, wxID_ANY, wxT("Cenzura"), wxDefaultPosition, wxDefaultSize, 0 );
	options->Add( cenzure_button, 0, wxALIGN_CENTER|wxALL, 5 );
	
	Erode_Button = new wxButton( this, wxID_ANY, wxT("Erode"), wxDefaultPosition, wxDefaultSize, 0 );
	options->Add( Erode_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	Animation_Button = new wxCheckBox( this, wxID_ANY, wxT("Animacja"), wxDefaultPosition, wxDefaultSize, 0 );
	Animation_Button->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	options->Add( Animation_Button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	text_panel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,1000 ), 0 );
	options->Add( text_panel, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	window->Add( options, 0, wxALIGN_LEFT, 5 );
	
	
	this->SetSizer( window );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MyFrame::~MyFrame()
{
}


void MyFrame::Read_From_File(wxCommandEvent& event)
{
    wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("JPG file (*.jpg)|*.jpg"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
     




}
