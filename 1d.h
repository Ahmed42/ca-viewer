//#ifndef 1D_H_INCLUDED
//#define 1D_H_INCLUDED

class CA_1D {
    public:
        bool** cells;
        bool* resolve_rule(); // produces the hood configurations that will make the cell 'live' to the next step (true = life,false = death)
        int rule,length,age;
        int current_step;
        CA_1D(int,int,int,bool);
        void forward_step();
        bool backward_step();
        void set_cell(int,bool);
        void display();
        // add destructor
};

//#endif // 1D_H_INCLUDED
