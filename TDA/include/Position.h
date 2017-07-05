#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position();
        virtual ~Position();
        //wspolrzedne
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setXYZ(float x, float y, float z);
        float getX();
        float getY();
        float getZ();
        float* getXYZ();
         //wspolrzedne na co ma patrzec
        void setRX(float rx);
        void setRY(float ry);
        void setRZ(float rz);
        void setRXYZ(float rx, float ry, float rz);
        float getRX();
        float getRY();
        float getRZ();
        float* getRXYZ();
    protected:
        float x,y,z;
        float rx,ry,rz;//rotation x,y,z in degree
    private:
};

#endif // POSITION_H
