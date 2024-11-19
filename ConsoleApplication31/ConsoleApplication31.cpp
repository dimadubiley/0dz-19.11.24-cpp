#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class Array
{
    T* mas = nullptr;
    int size;
public:
    Array();
    void Output();
    ~Array();
    T operator[](int index);
    int GetSize() const
    {
        return size;
    }
    T* GetPtr() const
    {
        return mas;
    }
    void SetSize(int s)
    {
        size = s;
    }
    void SetPtr(T* ptr)
    {
        mas = ptr;
    }
};

template <class T>
Array<T>::Array()
{
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % 100 * 1.2;
    }
}

template <class T>
void Array<T>::Output()
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}

template <class T>
Array<T>::~Array()
{
    if (mas != nullptr)
    {
        delete[] mas;
    }
}

template <class T>
T Array<T>::operator[](int index)
{
    return mas[index];
}

class Point
{
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator[](int index)
    {
        if (index == 0)
            return Point(x, 0);
        else
            return Point(0, y);
    }

    friend ostream& operator<<(ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    Point& operator=(const Point& p)
    {
        if (this != &p)
        {
            x = p.x;
            y = p.y;
        }
        return *this;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

int main()
{
    srand(time(0));

    Array<int> obj1;
    obj1.Output();

    Array<char> obj2;
    obj2.Output();

    Array<double> obj3;
    obj3.Output();

    Array<Point> obj4;
    obj4.Output();

    system("pause");
}
