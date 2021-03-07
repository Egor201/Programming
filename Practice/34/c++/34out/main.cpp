#include <iostream>

using namespace std;

void  create (int *&q, int lengthA, int firstT = 0, int stepP = 0);
void sort (int *array, int lengthA);
int* print (int *array, int lengthA);
void destroy (int *&q);

int main()
{
    int lengthA, firstT, stepP;
    cin >> lengthA >> firstT >> stepP;
    int *q = new int [0];
    create(q, lengthA, firstT, stepP);
    sort(q, lengthA);
    q = print (q, lengthA);
    destroy(q);
}

void destroy (int *&q){
    if (q != nullptr){
        delete []q;
        q = nullptr;
    }
}

void  create (int *&q, int lengthA, int firstT, int stepP){
    q = new int [lengthA];
    for (int i = 0; i < lengthA; i++){
        q[i] = firstT;
        firstT += stepP;
    }
}

void sort (int *array, int lengthA){
    int z, i, j;
    for (i = 1; i < lengthA; i++){
        z = array[i];
        for (j = i - 1; j >= 0 && array[j] > z; j--)
            array[j+1] = array[j];
        array[j+1] = z;
    }
}

int* print (int *array, int lengthA){
    for (int i = 0; i < lengthA; i++){
        std::cout << array[i] << " ";
    }
    return array;
}

