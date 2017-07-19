#include <iostream>
using namespace std;

class Cube{
public:
    Surface s[6];
    // 0: zheng
    // 1: fan
    // 2: zuo
    // 3: you
    // 4: shang
    // 5: xia
};

class Surface{
public:
    enum color{
        c1, c2, c3, c4, c5, c6
    };
    color c[3][3];
};

class MainCube{
public:
    void F();
    void B();
    void R();
    void L();
    void U();
    void D();
    void MR();
    void MF();
    void MU();
private:
    // dirc 0: F
    // dirc 1: B
    // dirc 2: L
    // dirc 3: R
    // dirc 4: U
    // dirc 5: D
    void rot(int i, int dirc){
        int allDirc[6][6] = {
            {0, 1, 2, 3, 4, 5},
            {1, 0, 2, 3, 4, 5},
            {2, 3, 1, 0, 4, 5},
            {3, 2, 0, 1, 4, 5},
            {4, 5, 2, 3, 1, 0},
            {5, 4, 3, 2, 1, 0}
        };
        for(int j = 0; j < i; ++j){
            Surface::color tmp1 = c.s[allDirc[dirc][2]].c[0][2];
            Surface::color tmp2 = c.s[allDirc[dirc][2]].c[1][2];
            Surface::color tmp3 = c.s[allDirc[dirc][2]].c[2][2];

            // zuobian
            c.s[allDirc[dirc][2]].c[0][2] = c.s[allDirc[dirc][5]].c[2][0];
            c.s[allDirc[dirc][2]].c[1][2] = c.s[allDirc[dirc][5]].c[2][1];
            c.s[allDirc[dirc][2]].c[2][2] = c.s[allDirc[dirc][5]].c[2][2];
            // xiabian
            c.s[allDirc[dirc][5]].c[2][0] = c.s[allDirc[dirc][3]].c[0][0];
            c.s[allDirc[dirc][5]].c[2][1] = c.s[allDirc[dirc][3]].c[1][0];
            c.s[allDirc[dirc][5]].c[2][2] = c.s[allDirc[dirc][3]].c[2][0];
            // youbian
            c.s[allDirc[dirc][3]].c[0][0] = c.s[allDirc[dirc][4]].c[2][0];
            c.s[allDirc[dirc][3]].c[1][0] = c.s[allDirc[dirc][4]].c[2][1];
            c.s[allDirc[dirc][3]].c[2][0] = c.s[allDirc[dirc][4]].c[2][2];
            // shangbian
            c.s[allDirc[dirc][4]].c[2][0] = tmp1;
            c.s[allDirc[dirc][4]].c[2][1] = tmp2;
            c.s[allDirc[dirc][4]].c[2][2] = tmp3;
        }
    }

    // dirc 0: MR
    // dirc 1: MF
    // dirc 2: MU
    void rotM(int i, int dirc){
        int allDirc[3][6] = {
            {0, 1, 2, 3, 4, 5},
            {2, 3, 1, 0, 4, 5},
            {0, 1, 4, 5, 3, 2}
        };

        Surface::color tmp1 = c.s[allDirc[dirc][0]].c[0][1];
        Surface::color tmp2 = c.s[allDirc[dirc][0]].c[1][1];
        Surface::color tmp3 = c.s[allDirc[dirc][0]].c[2][1];
        // zheng
        c.s[allDirc[dirc][0]].c[0][1] = c.s[allDirc[dirc][5]].c[0][1];
        c.s[allDirc[dirc][0]].c[1][1] = c.s[allDirc[dirc][5]].c[1][1];
        c.s[allDirc[dirc][0]].c[2][1] = c.s[allDirc[dirc][5]].c[2][1];
        // xia
        c.s[allDirc[dirc][5]].c[0][1] = c.s[allDirc[dirc][1]].c[0][1];
        c.s[allDirc[dirc][5]].c[1][1] = c.s[allDirc[dirc][1]].c[1][1];
        c.s[allDirc[dirc][5]].c[2][1] = c.s[allDirc[dirc][1]].c[2][1];
        // fan
        c.s[allDirc[dirc][1]].c[0][1] = c.s[allDirc[dirc][4]].c[0][1];
        c.s[allDirc[dirc][1]].c[1][1] = c.s[allDirc[dirc][4]].c[1][1];
        c.s[allDirc[dirc][1]].c[2][1] = c.s[allDirc[dirc][4]].c[2][1];
        // shang
        c.s[allDirc[dirc][4]].c[0][1] = c.s[allDirc[dirc][0]].c[0][1];
        c.s[allDirc[dirc][4]].c[1][1] = c.s[allDirc[dirc][0]].c[1][1];
        c.s[allDirc[dirc][4]].c[2][1] = c.s[allDirc[dirc][0]].c[2][1];
    }
    Cube c;
};

// dirc 0: F
// dirc 1: B
// dirc 2: L
// dirc 3: R
// dirc 4: U
// dirc 5: D
void rot(Cube c, int i, int dirc){
    int allDirc[6][6] = {
        {0, 1, 2, 3, 4, 5},
        {1, 0, 2, 3, 4, 5},
        {2, 3, 1, 0, 4, 5},
        {3, 2, 0, 1, 4, 5},
        {4, 5, 2, 3, 1, 0},
        {5, 4, 3, 2, 1, 0}
    };
    for(int j = 0; j < i; ++j){
        Surface::color tmp1 = c.s[allDirc[dirc][2]].c[0][2];
        Surface::color tmp2 = c.s[allDirc[dirc][2]].c[1][2];
        Surface::color tmp3 = c.s[allDirc[dirc][2]].c[2][2];

        // zuobian
        c.s[allDirc[dirc][2]].c[0][2] = c.s[allDirc[dirc][5]].c[2][0];
        c.s[allDirc[dirc][2]].c[1][2] = c.s[allDirc[dirc][5]].c[2][1];
        c.s[allDirc[dirc][2]].c[2][2] = c.s[allDirc[dirc][5]].c[2][2];
        // xiabian
        c.s[allDirc[dirc][5]].c[2][0] = c.s[allDirc[dirc][3]].c[0][0];
        c.s[allDirc[dirc][5]].c[2][1] = c.s[allDirc[dirc][3]].c[1][0];
        c.s[allDirc[dirc][5]].c[2][2] = c.s[allDirc[dirc][3]].c[2][0];
        // youbian
        c.s[allDirc[dirc][3]].c[0][0] = c.s[allDirc[dirc][4]].c[2][0];
        c.s[allDirc[dirc][3]].c[1][0] = c.s[allDirc[dirc][4]].c[2][1];
        c.s[allDirc[dirc][3]].c[2][0] = c.s[allDirc[dirc][4]].c[2][2];
        // shangbian
        c.s[allDirc[dirc][4]].c[2][0] = tmp1;
        c.s[allDirc[dirc][4]].c[2][1] = tmp2;
        c.s[allDirc[dirc][4]].c[2][2] = tmp3;
    }
}

// dirc 0: MR
// dirc 1: MF
// dirc 2: MU
void rotM(Cube c, int i, int dirc){
    int allDirc[3][6] = {
        {0, 1, 2, 3, 4, 5},
        {2, 3, 1, 0, 4, 5},
        {0, 1, 4, 5, 3, 2}
    };

    Surface::color tmp1 = c.s[allDirc[dirc][0]].c[0][1];
    Surface::color tmp2 = c.s[allDirc[dirc][0]].c[1][1];
    Surface::color tmp3 = c.s[allDirc[dirc][0]].c[2][1];
    // zheng
    c.s[allDirc[dirc][0]].c[0][1] = c.s[allDirc[dirc][5]].c[0][1];
    c.s[allDirc[dirc][0]].c[1][1] = c.s[allDirc[dirc][5]].c[1][1];
    c.s[allDirc[dirc][0]].c[2][1] = c.s[allDirc[dirc][5]].c[2][1];
    // xia
    c.s[allDirc[dirc][5]].c[0][1] = c.s[allDirc[dirc][1]].c[0][1];
    c.s[allDirc[dirc][5]].c[1][1] = c.s[allDirc[dirc][1]].c[1][1];
    c.s[allDirc[dirc][5]].c[2][1] = c.s[allDirc[dirc][1]].c[2][1];
    // fan
    c.s[allDirc[dirc][1]].c[0][1] = c.s[allDirc[dirc][4]].c[0][1];
    c.s[allDirc[dirc][1]].c[1][1] = c.s[allDirc[dirc][4]].c[1][1];
    c.s[allDirc[dirc][1]].c[2][1] = c.s[allDirc[dirc][4]].c[2][1];
    // shang
    c.s[allDirc[dirc][4]].c[0][1] = c.s[allDirc[dirc][0]].c[0][1];
    c.s[allDirc[dirc][4]].c[1][1] = c.s[allDirc[dirc][0]].c[1][1];
    c.s[allDirc[dirc][4]].c[2][1] = c.s[allDirc[dirc][0]].c[2][1];
}

