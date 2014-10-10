/***************************************************************
 * Name:      CA_GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ahmed (ahmed.a.bashir@gmail.com)
 * Created:   2014-01-17
 * Copyright: Ahmed ()
 * License:
 **************************************************************/

#ifndef CA_GUIMAIN_H
#define CA_GUIMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "CA_GUIApp.h"


#include <wx/button.h>
#include <wx/statline.h>
class CA_GUIDialog: public wxDialog
{
    public:
        CA_GUIDialog(wxDialog *dlg, const wxString& title);
        ~CA_GUIDialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // CA_GUIMAIN_H
