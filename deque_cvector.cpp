#include <iostream>
using namespace std;

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();

    void push_back(int x);
    void push_front(int x);
    int& operator[](int i);

    int** map;
    int size_map, size_vec;
    int size;

private:
    int head_map, head_pos;
    int tail_map, tail_pos;

    void expand();
};

// ---------------- CONSTRUCTOR ----------------
XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    size = 0;

    map = new int*[size_map];

    for (int i = 0; i < size_map; i++)
        map[i] = nullptr;

    head_map = tail_map = size_map / 2;
    head_pos = tail_pos = size_vec / 2;
}

// ---------------- DESTRUCTOR ----------------
XVector::~XVector()
{
    for (int i = 0; i < size_map; i++)
        if (map[i] != nullptr)
            delete[] map[i];

    delete[] map;
}

// ---------------- EXPAND ----------------
void XVector::expand()
{
    int new_size = size_map * 2;
    int** new_map = new int*[new_size];

    for (int i = 0; i < new_size; i++)
        new_map[i] = nullptr;

    int offset = (new_size - size_map) / 2;

    for (int i = 0; i < size_map; i++)
        new_map[i + offset] = map[i];

    delete[] map;
    map = new_map;

    head_map += offset;
    tail_map += offset;

    size_map = new_size;
}

// ---------------- PUSH_BACK ----------------
void XVector::push_back(int x)
{
    if (map[tail_map] == nullptr)
        map[tail_map] = new int[size_vec];

    map[tail_map][tail_pos] = x;

    if (size == 0)
    {
        head_map = tail_map;
        head_pos = tail_pos;
    }

    size++;

    if (tail_pos < size_vec - 1)
    {
        tail_pos++;
    }
    else
    {
        tail_pos = 0;
        tail_map++;

        if (tail_map == size_map)
            expand();

        if (map[tail_map] == nullptr)
            map[tail_map] = new int[size_vec];
    }
}

// ---------------- PUSH_FRONT ----------------
void XVector::push_front(int x)
{
    if (map[head_map] == nullptr)
        map[head_map] = new int[size_vec];

    map[head_map][head_pos] = x;

    if (size == 0)
    {
        tail_map = head_map;
        tail_pos = head_pos;
    }

    size++;

    if (head_pos > 0)
    {
        head_pos--;
    }
    else
    {
        head_pos = size_vec - 1;
        head_map--;

        if (head_map < 0)
            expand();

        if (map[head_map] == nullptr)
            map[head_map] = new int[size_vec];
    }
}

// ---------------- OPERATOR [] ----------------
int& XVector::operator[](int i)
{
    if (i < 0 || i >= size)
        exit(1);

    int m = head_map;
    int p = head_pos;

    for (int k = 0; k < i; k++)
    {
        p++;
        if (p == size_vec)
        {
            p = 0;
            m++;
        }
    }

    return map[m][p];
}

// ---------------- PRINT (NO SE MODIFICA) ----------------
void print(XVector* p)
{
    for (int i = 0; i < p->size; i++)
        cout << (*p)[i] << " ";
    cout << "\n";
}
