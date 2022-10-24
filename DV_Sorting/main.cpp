#include "orden.h"
#include <ctime>

int main(){
    int tam;
    cout<<"Ingrese tamaño del arreglo ";
    cin>>tam;
    unsigned t0, t1, t2, t3, t4, t5;
    double time;
    int arreglo[tam], arregloDos[tam], arregloTres[tam];
    
    unsigned DT0, DT1, DT2, DT3, DT4, DT5;
    double DTime;
    int DArreglo[tam], DArreglo2[tam], DArreglo3[tam];

    orden* Ordena = nullptr;
    
    cout<<"-----------BubbleSort-----------"<<endl;
    Ordena->generarArreglo(arreglo, tam);
    Ordena->imprimeArreglo(arreglo, tam);
    t0 = clock();
    Ordena->bubbleSort(arreglo, tam);
    Ordena->imprimeArreglo(arreglo, tam);
    t1 = clock();
    time = (double(t1 - t0))/CLOCKS_PER_SEC;
    cout<<"Tiempo del bubble Sort: "<<time<<endl;
    
    cout<<"-----------QuickSort------------"<<endl;
    Ordena->generarArreglo(arregloDos, tam);
    Ordena->imprimeArreglo(arregloDos, tam);
    t2 = clock();
    Ordena->quickSort(arregloDos, 0, tam - 1);
    t3 = clock();
    Ordena->imprimeArreglo(arregloDos, tam);
    time = (double(t3 - t2))/CLOCKS_PER_SEC;
    cout<<"Tiempo del Quick Sort "<<time<<endl;
    
    cout<<"-----------MergeSort------------"<<endl;
    Ordena->generarArreglo(arregloTres, tam);
    Ordena->imprimeArreglo(arregloTres, tam);
    t4 = clock();
    Ordena->mergeSort(arregloTres, 0, tam - 1);
    t5 = clock();
    Ordena->imprimeArreglo(arregloTres, tam);
    time = (double(t5 - t4))/CLOCKS_PER_SEC;
    cout<<"Tiempo del Merge Sort "<<time<<endl;
    
    /*cout<<"-----------Ordenando descendente--------"<<endl;
    Ordena->generarArreglo(DArreglo, tam);
    Ordena->ordenaDescendente(DArreglo, tam);
//    Ordena->imprimeArreglo(DArreglo, tam);
    DT0 = clock();
    Ordena->bubbleSort(DArreglo, tam);
    DT1 = clock();
    Ordena->imprimeArreglo(DArreglo, tam);
    
    DTime = (double(DT1 - DT0))/CLOCKS_PER_SEC;
    cout<<"Tiempo del Bubble Sort "<<DTime<<endl;
    
    Ordena->generarArreglo(DArreglo2, tam);
    Ordena->ordenaDescendente(DArreglo2, tam);
//    Ordena->imprimeArreglo(DArreglo2, tam);
    DT2 = clock();
    Ordena->quickSort(DArreglo2, 0, tam - 1);
    DT3 = clock();
    Ordena->imprimeArreglo(DArreglo2, tam);
    
    DTime = (double(DT3 - DT2))/CLOCKS_PER_SEC;
    cout<<"Tiempo del Quick Sort "<<DTime<<endl;
    
    Ordena->generarArreglo(DArreglo3, tam);
    Ordena->ordenaDescendente(DArreglo3, tam);
//    Ordena->imprimeArreglo(DArreglo3, tam);
    DT4 = clock();
    Ordena->mergeSort(DArreglo3, 0, tam - 1);
    DT5 = clock();
    Ordena->imprimeArreglo(DArreglo3, tam);
    
    DTime = (double(DT5 - DT4))/CLOCKS_PER_SEC;
    cout<<"Tiempo del Merge Sort "<<DTime<<endl;*/
    
    
    
    return 0;
}
