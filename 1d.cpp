
#include"1d.h"

/*
int main() {
    CA_1D automaton = CA_1D(150,30,100,false);
    automaton.set_cell(75,true);
    for(int i=0; i<99; i++)
        automaton.forward_step();

    automaton.display();
    return 0;
}
*/
CA_1D::CA_1D(int l,int r,int a,bool ini_state) { // world length, rule number, age
    rule = r;
    length = l;
    age = a;
    current_step = 0;

    cells = new bool*[age];
    cells[current_step] = new bool[length];
    for(int i=0; i<length; i++)
        cells[current_step][i] = ini_state;

    for(int i =1;i<age; i++) {
        cells[i] = new bool[length];
        for(int j=0; j<length; j++)
            cells[i][j] = false;
    }

}

void CA_1D::forward_step() {
    if(current_step == age-1)
        return;
    current_step++;
    bool* winning_configs;
    winning_configs = resolve_rule();

    for(int c=0; c<length; c++) {
        int hood_num = (cells[current_step-1][(c+1 + length)%(length)] ? 4:0) + (cells[current_step-1][c] ? 2:0) + (cells[current_step-1][(c-1 + length)%(length)] ? 1:0);
        if (winning_configs[hood_num])
            cells[current_step][c] = true;
        else
            cells[current_step][c] = false;
    }
}

bool CA_1D::backward_step() {

}

void CA_1D::set_cell(int cell_no,bool state) {
    if (cell_no<length)
        cells[current_step][cell_no] = state;
}

bool* CA_1D::resolve_rule() {
    bool* winning_configs = new bool[8];
    for(int i=0; i<8; i++)
        winning_configs[i] = (rule>>i & 1 ? true:false);
    return winning_configs;
}

/*void CA_1D::display() {
    for(int i=0; i<age;i++) {
        for(int j=0; j<length; j++)
        std::cout<< (cells[i][j]? '#':' ');
    std::cout<<std::endl;
    }
}*/
//0xf0,219
