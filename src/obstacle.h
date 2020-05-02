#ifndef OBSATCLE_H
#define OBSATCLE_H

class obstacle
{
private:
    /* data */
    int posX;
    int posY;

public:
    obstacle(/* args */);
    obstacle(int positionX, int positionY);
    ~obstacle();
};

#endif