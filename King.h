///< @file King.h

/**
 @author Roma, Timofey, Yaroslav

 King - ����� ������ ������;

 ������� ������ BaseFigure.
*/
class King:public BaseFigure{
    /// ���������� �������� ���� ������;
    int step = 0;
    /// ���������� �������� ���������;
    bool castling = false;
    /// ��������������� ������ ������ ��� ���������;
    vector <int*> castling_cells;
public:
    /// �����������
    King(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}
    virtual void draw(int type0, int x_cell0, int y_cell0) override;                    // ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;        // ������� ����������� �����
    virtual void change() override{}
    int get_step();
    void set_step(int step0);
    bool get_castling();
    void set_castling(bool castling0);
    vector <int*> get_castling_cells();
    void set_castling_cells(vector <int*> castling_cells0);
};
/**
 ������� ��������� ������;
 \param x  - ���������� ������ �� ��� x;
 \param y  - ���������� ������ �� ��� y;
 \param r  - ������ ������.
 */
void King::draw(int x, int y, int r){
    txSetColor(side_color,2);
    txSetFillColor (RGB (255, 215, 0)); // ������ ��� ������

    POINT headtop[25] = {{(6*r)+x, (0*r)+y}, {(7*r)+x, (6*r)+y}, {(8*r)+x, (0*r)+y},
                     {(9*r)+x, (6*r)+y}, {(10*r)+x, (0*r)+y}, {(11*r)+x, (6*r)+y},
                     {(12*r)+x, (0*r)+y}, {(13*r)+x, (6*r)+y}, {(14*r)+x, (0*r)+y},
                     {(15*r)+x, (6*r)+y}, {(16*r)+x, (0*r)+y}, {(16*r)+x, (8*r)+y},
                     {(14*r)+x, (8*r)+y}, {(12*r)+x, (18*r)+y}, {(13*r)+x, (18*r)+y},
                     {(13*r)+x, (19*r)+y}, {(14*r)+x, (19*r)+y}, {(14*r)+x, (20*r)+y},
                     {(8*r)+x, (20*r)+y}, {(8*r)+x, (19*r)+y}, {(9*r)+x, (19*r)+y},
                     {(9*r)+x, (18*r)+y}, {(10*r)+x, (18*r)+y}, {(8*r)+x, (8*r)+y}, {(6*r)+x, (8*r)+y}}; //"������", �������� � ����������� �� ������
    txPolygon (headtop, 25);

    /*POINT headnottop[26] = {{(2*r)+x, (0*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (0*r)+y},
                           {(4*r)+x, (4*r)+y}, {(4*r)+x, (0*r)+y}, {(5*r)+x, (4*r)+y},
                           {(6*r)+x, (4*r)+y}, {(7*r)+x, (0*r)+y}, {(7*r)+x, (4*r)+y},
                           {(8*r)+x, (0*r)+y}, {(8*r)+x, (4*r)+y}, {(9*r)+x, (0*r)+y},
                           {(9*r)+x, (5*r)+y}, {(7*r)+x, (5*r)+y}, {(6*r)+x, (9*r)+y},
                           {(7*r)+x, (9*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (10*r)+y},
                           {(8*r)+x, (11*r)+y}, {(3*r)+x, (11*r)+y}, {(3*r)+x, (10*r)+y},
                           {(4*r)+x, (10*r)+y}, {(4*r)+x, (9*r)+y}, {(5*r)+x, (9*r)+y},
                           {(4*r)+x, (5*r)+y}, {(2*r)+x, (5*r)+y}}; //"������", �������� � ����������� �� ������
    txPolygon (headnottop, 26);*/

    txSetFillColor (main_color); // �������� ���� (�����)
    //txSetFillColor (RGB (255, 255, 255)); ///< �������� ���� (������)

    POINT body[4] = {{(10*r)+x, (20*r)+y}, {(12*r)+x, (20*r)+y}, {(16*r)+x, (40*r)+y}, {(6*r)+x, (40*r)+y}}; // ������������ ����
    txPolygon (body, 4);

    POINT stand1[4] = {{(4*r)+x, (40*r)+y}, {(18*r)+x, (40*r)+y}, {(18*r)+x, (42*r)+y}, {(4*r)+x, (42*r)+y}}; // ������ ��������� ��� ����, � � ����� ������ ���
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(2*r)+x, (42*r)+y}, {(20*r)+x, (42*r)+y}, {(20*r)+x, (44*r)+y}, {(2*r)+x, (44*r)+y}}; // ������ ��������� ��� �������(�����,����,����) � ������
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (44*r)+y}, {(22*r)+x, (44*r)+y}, {(22*r)+x, (46*r)+y}, {(0*r)+x, (46*r)+y}};// ������ ��������� ��� ������(������, �������)
    txPolygon (stand3, 4);
}
/**
 ������� �������� ����������� ����;

 \param figures  - ������ �����.

 ������ ����� � ��� �� ��� ������� �� ���� ������;

*/
void King :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    castling_cells.clear();
    if((x_cell+1) < 8 && (y_cell-1) >= 0)
    {                                           // ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                  // out = true;
                   break;
            }
        }
    }
    if((x_cell -1) >= 0 && (y_cell-1) >= 0)
    {                                           // ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                 //  out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8 && (y_cell+1) < 8)
    {                                           // ���� ������
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                 //  out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0 && (y_cell+1) < 8)
    {                                           // ���� �����
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                  // out = true;
                   break;
            }
        }
    }
    if((y_cell-1) >= 0)
    {                                           // �����
        int* cell = new int[2];
        cell[0] = y_cell - 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((y_cell+1) < 8)
    {                                           // ����
        int* cell = new int[2];
        cell[0] = y_cell + 1;
        cell[1] = x_cell;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + 1)) && (figura->get_x_cell() == (x_cell))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((x_cell+1) < 8)
    {                                           // ������
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell + 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((x_cell-1) >= 0) {                       // �����
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = x_cell - 1;
        move_ability_cells.push_back(cell);
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 1))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   //out = true;
                   break;
            }
        }
    }
    if((y_cell == 7) && (x_cell == 4)){         // ��������� ��� �����
        Rook* rook;
        int prov = 1;
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 1)) ||
              ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 2)) )) {
                prov = 2;
                break;
            }
        }
        if(prov == 1) {
            for(auto figura : figures) {
                rook = dynamic_cast<Rook*>(figura);
                if((figura->get_y_cell() == 7) && (figura->get_x_cell() == 7) && (rook) && (step == 0) && (rook->get_step() == 0)) {
                    int* cell = new int[2];
                    cell[0] = y_cell;
                    cell[1] = x_cell + 3;
                    castling_cells.push_back(cell);
                    break;
                }
            }
        }
        prov = 1;
        for(auto figura : figures) {
            if (((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 1))) ||
               ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 2))) ||
               ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 3)))) {
                prov = 2;
                break;
            }
        }
        if(prov == 1) {
            for(auto figura : figures) {
                rook = dynamic_cast<Rook*>(figura);
                if((figura->get_y_cell() == 7) && (figura->get_x_cell() == 0) && (rook) && (step == 0) && (rook->get_step() == 0)) {
                    int* cell = new int[2];
                    cell[0] = y_cell;
                    cell[1] = x_cell - 4;
                    castling_cells.push_back(cell);
                    break;
                }
            }
        }

    }
    if((y_cell == 0) && (x_cell == 4)){          // ��������� ��� ������
        Rook* rook;
        int prov = 1;
        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 1)) ||
              ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell + 2)) )) {
                prov = 2;
                break;
            }
        }
        if(prov == 1) {
            for(auto figura : figures) {
                rook = dynamic_cast<Rook*>(figura);
                if((figura->get_y_cell() == 0) && (figura->get_x_cell() == 7) && (rook) && (step == 0) && (rook->get_step() == 0)) {
                    int* cell = new int[2];
                    cell[0] = y_cell;
                    cell[1] = x_cell + 3;
                    castling_cells.push_back(cell);
                    break;
                }
            }
        }
        prov = 1;
        for(auto figura : figures) {
            if (((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 1))) ||
               ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 2))) ||
               ((figura->get_y_cell() == (y_cell)) && (figura->get_x_cell() == (x_cell - 3)))) {
                prov = 2;
                break;
            }
        }
        if(prov == 1) {
            for(auto figura : figures) {
                rook = dynamic_cast<Rook*>(figura);
                if((figura->get_y_cell() == 0) && (figura->get_x_cell() == 0) && (rook) && (step == 0) && (rook->get_step() == 0)) {
                    int* cell = new int[2];
                    cell[0] = y_cell;
                    cell[1] = x_cell - 4;
                    castling_cells.push_back(cell);
                    break;
                }
            }
        }

    }
   // if((y_cell == 7) && (x_cell == 6))
}
/**
 �������, ������� ��������� ���������� step;
*/
int King::get_step() {
    return step;
}
/**
 �������, ������� ����������� ��� (step) ������;
 \param step0  - �������� ���� ������;
*/
void King::set_step(int step0) {
    step = step0;
}
/**
 �������, ����������� ��������� ���������;
*/
bool King::get_castling() {
    return castling;
}
/**
 �������, ������� ����������� ��������� ��������� (castling);
 \param castling0  - �������� ���������;
*/
void King::set_castling(bool castling0) {
    castling = castling0;
}
/**
 �������, ����������� ������ ����������� ���������;
*/
vector <int*> King::get_castling_cells() {
    return castling_cells;
}
/**
 �������, ������� ����������� �������� ������� ��� ����������� ��������� (castling_cells);
 \param castling_cells0  - ��������������� ������ ������ ��� ���������;
*/
void King::set_castling_cells(vector <int*> castling_cells0) {
    castling_cells = castling_cells0;
}
