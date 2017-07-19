#ifndef CUBE_H
#define CUBE_H


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
    void F(int i){rot(i, 0);}
    void B(int i){rot(i, 1);}
    void R(int i){rot(i, 3);}
    void L(int i){rot(i, 2);}
    void U(int i){rot(i, 4);}
    void D(int i){rot(i, 5);}
    void MR(int i){rotM(i, 0);}
    void MF(int i){rotM(i, 1);}
    void MU(int i){rotM(i, 2);}

    MainCube(int input[6][9]);
    void downCross();
    void downCornerRestore();
    void centreEdgeRestore();
    void upCross();
    void upSurfaceCornerRestore();
    void upCornerRestore();
    void upEdgeRestore();
    void printCube();
    void printBuf();
private:
    void rot(int i, int dirc);
    void rotM(int i, int dirc);
    Cube c;
};

#endif // CUBE_H
