/***************************************************************
 * Name:      CA_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ahmed (ahmed.a.bashir@gmail.com)
 * Created:   2014-01-17
 * Copyright: Ahmed ()
 * License:
 **************************************************************/


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include<wx/dcbuffer.h>
#include<wx/event.h>
#include "1d.h"
enum {DIALG=1,B_PLAY,B_FORWD};

class Dialg : public wxDialog {
    CA_1D autom;
    public:
        Dialg(const wxString& title,const wxPoint& pos,const wxSize& size) : wxDialog(NULL,DIALG,title,pos,size), autom(150,30,100,false){
            this->SetBackgroundStyle(wxBG_STYLE_CUSTOM);
            //this->SetBackgroundColour(wxColour(wxString::FromAscii("Black")));

            autom.set_cell(75,true);

            wxButton* b1 = new wxButton(this,B_PLAY,wxString::FromAscii("Play !"),wxPoint(10,10));
            wxButton* b2 = new wxButton(this,B_FORWD,wxString::FromAscii("Step"),wxPoint(10,50));
           // b1->Connect(wxID_ANY,wxEVT_MOUSEWHEEL,wxMouseEventHandler(Dialg::xy_click));
            //wxGrid* grid = new wxGrid( this,-1,wxPoint( 0, 0 ),wxSize( 400, 300 ) );
            //wxBufferedPaintDC a;

        }

        void xy_click(wxMouseEvent& event) {
            //event.Skip();
            long x,y;
          //  x = event.GetX();
          //  y = event.GetY();
            //std::string strg = (char)0x30+x + " " + (char)(0x30+y);
            wxMessageDialog* msg = new wxMessageDialog(this,wxString::FromAscii("hello"),wxString::FromAscii(":'("),wxOK);

        }

        void play(wxCommandEvent &event) {
            for(int i=0; i<autom.age-1; i++) {
                autom.forward_step();
                Refresh();
            }
        }

        void forward_step(wxCommandEvent &event) {
            autom.forward_step();
            Refresh();
        }

        /*void draw_grid(wxPaintDC& paintdc,int x,int y,int horiz,int vert,int space) {
            for(int i=0; i<horiz+1; i++)
                paintdc.DrawLine(x+i*space,y,x+i*space,y+vert*space);
            for(int i=0; i<vert+1; i++)
                paintdc.DrawLine(x,y+i*space,x+horiz*space,y+i*space);
        }*/

        void draw_grid2(wxPaintDC& paintdc,int x,int y,int horiz,int vert,int space) {
            for(int i=0; i<horiz; i++)
                for(int j=0; j<vert; j++) {
                    if(autom.cells[j][i])
                        paintdc.SetBrush(wxBrush(wxString::FromAscii("Black"),1));
                    else
                        paintdc.SetBrush(wxBrush(wxString::FromAscii("White"),1));
                    paintdc.DrawRectangle(x+i*space,y+j*space,space,space);
                }
        }

        void draw_row(wxPaintDC& paintdc,int x,int y,int cells,int space) {
            for(int i=0; i<cells; i++)
                    paintdc.DrawRectangle(x+i*space,y,space,space);
        }

        void paint(wxPaintEvent& event) {
            wxPaintDC paintdc(this);
            //paintdc.DrawRectangle(0,0,100,100);
            draw_grid2(paintdc,110,110,autom.length,autom.age,5);
           // draw_row(paintdc,110,110+autom.current_step*5,autom.length,5);
        }


        void on_close(wxCloseEvent &event) {
            //wxMessageDialog* msg = new wxMessageDialog(this,wxString::FromAscii("BYE !!"),wxString::FromAscii(":'("),wxOK);
            //msg->ShowModal();
            this->Destroy();
        }
    DECLARE_EVENT_TABLE();
};



class CA_App:public wxApp {
    virtual bool OnInit();
};

IMPLEMENT_APP(CA_App);

bool CA_App::OnInit() {
    Dialg* start = new Dialg(wxString::FromAscii("CA"),wxPoint(50,25),wxSize(1000,800));

    start->Show(true);
    return true;
}

BEGIN_EVENT_TABLE(Dialg, wxDialog)
    EVT_PAINT(Dialg::paint)
    EVT_BUTTON(B_FORWD,Dialg::forward_step)
    EVT_BUTTON(B_PLAY,Dialg::play)
    EVT_MOUSE_EVENTS(Dialg::xy_click)
    EVT_CLOSE(Dialg::on_close)
END_EVENT_TABLE();
/*wxButton(wxWindow* parent, wxWindowID id, const wxString& label = wxEmptyString,
          const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
          long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = "button")*/



