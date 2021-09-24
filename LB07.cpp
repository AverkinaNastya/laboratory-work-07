#include <iostream>
#include <cstdlib>

using namespace std;

class List
{
public:

    List(int n);
    ~List();
    void element(int g);

private:
    int size;
    int* p = NULL;
};
 
List::List(int n)
{
    try {
        if (n < 1) throw(n);
        size = n;
        p = new int[n];
        if (p == 0) throw("FREE STORE EXHAUSTED");
        cout << "Элементы списка: ";
        for (int i = 0; i < size; i++) {
            p[i] = rand() % 21;
            cout <<" " << p[i];
        }
        cout << endl;
    }
    catch (int n) {
        cout << "Неверно задана размерность списка" << endl;
    }
    catch (char* error) {
        cout << "Превышение свободной памяти" << endl;
    }
}

List::~List()
{
    delete[] p; 
}

void List::element(int g) {
    try
    {
        if ((g-1 < size) && (g-1 >= 0)) {
            cout << p[g-1] << endl;
        }
        else {
            throw(g-1);
        }
    }
    catch (int g)
    {
        cout << "Выход за границы списка" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");                      
    int g, n;                                          
    cout << "введите размерность списка -> ";          
    cin >> n;
    List* mylist = new List(n);
    cout << "обратиться к элементу по номеру -> ";
    cin >> g;
    mylist->element(g);
    mylist->~List();
    system("PAUSE");
    return 0;
}