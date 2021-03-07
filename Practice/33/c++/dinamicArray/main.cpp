#include <iostream>

using namespace std;

int*  create (int lengthA, int firstT = 0, int stepP = 0);
void sort (int *array, int lengthA);
int* print (int *array, int lengthA);

int main()
{
    int lengthA, firstT, stepP;
    cin >> lengthA >> firstT >> stepP;
    int *q = create(lengthA, firstT, stepP);
    sort(q, lengthA);
    q = print (q, lengthA);
    delete []q;
    return 0;
}

int*  create (int lengthA, int firstT, int stepP){
    int *q = new int [lengthA];
    for (int i = 0; i < lengthA; i++){
        q[i] = firstT;
        firstT += stepP;
    }
    return q;
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
