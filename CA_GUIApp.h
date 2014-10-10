/***************************************************************
 * Name:      CA_GUIApp.h
 * Purpose:   Defines Application Class
 * Author:    Ahmed (ahmed.a.bashir@gmail.com)
 * Created:   2014-01-17
 * Copyright: Ahmed ()
 * License:
 **************************************************************/

#ifndef CA_GUIAPP_H
#define CA_GUIAPP_H

#include <wx/app.h>

class CA_GUIApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CA_GUIAPP_H
