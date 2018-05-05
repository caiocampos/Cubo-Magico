#ifndef EXT_H
#define EXT_H

struct coordinate
{
    double x, y, z;

    coordinate()
    {
        x = y = z = 0;
    }

    coordinate(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct rotation
{
    double x, y, z;

    rotation()
    {
        x = y = z = 0;
    }

    rotation(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct color
{
    int r, g, b;

    color()
    {
        r = g = b = 0;
    }

    color(int r, int g, int b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    bool equals(color c)
    {
        return r == c.r && g == c.g && b == c.b;
    }
};

#endif // EXT_H
