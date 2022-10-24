//  Created by Alan Alfredo Onofre Chavez on 09/10/22.
#ifndef orden_h
#define orden_h
#include <iostream>
using namespace std;

class orden{
    public:
        void bubbleSort(int [], int );
        void quickSort(int [], int , int );
        void mergeSort(int [], int, int);
        void imprimeArreglo(int [], int);
        void ordenaDescendente(int [], int);
        void generarArreglo(int [], int);
    private:
        void swap(int* , int*);
        void merge(int [], int, int, int);
        int particion(int [], int, int);
};

#endif /* orden_h */
