#include <iostream>
#define pr std::cout <<
#define prnewln << std::endl;
#define prpoint << point.x << ' ' << point.y
class Point
{
public:
    Point(int x_ = 0, int y_ = 0)
    {
        x = x_;
        y = y_;
    }
    int x;
    int y;
};

class GameObject
{
public:
    GameObject()
    {
    }

    ~GameObject()
    {
    }
    virtual void Display() = 0;

protected:
    Point point;
    int type;
};

class Hero : public GameObject
{
public:
    Hero(Point T)
    {
        point = T;
    }

    void Display(){
        pr "Hero at: " prpoint prnewln}

protected:
    Point T;
};

class Enemy : public GameObject
{
public:
    Enemy(Point T, int _type)
    {
        point = T;
        type = _type;
    }

    void Display(){
        pr "Enemy of type: " << type << "at: " prpoint prnewln
    }

protected:
    Point T;
};

/* Expected Output:
 * 
 * Hero at: 0 0
 * Enemy of type: 1 at: 10 10
 * Enemy of type: 2 at: 10 20
 * Enemy of type: 1 at: 5 25
 */

int main(void)
{
    GameObject *objects[4];
    objects[0] = new Hero(Point(0, 0));
    objects[1] = new Enemy(Point(10, 10), 1);
    objects[2] = new Enemy(Point(10, 20), 2);
    objects[3] = new Enemy(Point(5, 25), 1);

    for (int i = 0; i < 4; ++i)
    {
        objects[i]->Display();
        delete objects[i];
    }

    return 0;
}
