///< @file cell.h

/**
 @author Yaroslav, Roma, Anna

 Cell - ����� ������ ����;
*/

class Cell{
private:
    /// ����� ������� ������
    int side;
    /// ��� ������, 1 - ������ ������, 0 - ����� ������
    int type;
    /// �������� ������
    bool focus;
    /// ������� ������� ������
    int side_bold = 5;
    /// ������ �� x
    int margin_x = 260;
    /// ������ �� y
    int margin_y = 60;
    /// ��������� �� ������
    BaseFigure* figure = nullptr;
public:
    /// �����������
    Cell(int type0, int side0);

    void draw(int i_cell, int j_cell);
    void set_focus(bool focus0);
    int get_type();
    void set_figure(BaseFigure* figure0);
    BaseFigure* get_figure();
};

Cell::Cell(int type0, int side0){
    type = type0;
    side = side0;
    focus = false;
}
/**
 ������� ��������� ������;
 \param i_cell  - ����� ������ �� ������
 \param j_cell  - ����� ������ �� �������
*/
void Cell::draw(int i_cell, int j_cell){
    if(type == 0){
        txSetColor(TX_WHITE,10);
        txSetFillColor(TX_WHITE);
    }

    else{
        txSetColor(TX_BLACK,10);
        txSetFillColor(TX_BLACK);
    }

    if(focus){
        txSetColor(TX_GREEN,12);
    }
    txRectangle(margin_x+j_cell*(side)+side_bold, margin_y+i_cell*(side)+side_bold, margin_x+(j_cell+1)*(side)-side_bold, margin_y+(i_cell+1)*(side)-side_bold);
}
/**
 ������� ������������ ������;
 \param focus0  - �������� ������
*/
void Cell::set_focus(bool focus0){
    focus = focus0;
}
/**
 �������, ������� ���������� ��� ������;
*/
int Cell::get_type(){
    return type;
}
/**
 �������, ������� ����������� ������ ������;
 \param figure0  - ��������� �� ������
*/
void Cell::set_figure(BaseFigure* figure0){
    figure = figure0;
}
/**
  ���������� ��������� �� ������;
*/
BaseFigure* Cell::get_figure(){
    return figure;
}