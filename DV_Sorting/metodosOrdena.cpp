//  Created by Alan Alfredo Onofre Chavez on 09/10/22.
#include "orden.h"
#include <ctime>

void orden::generarArreglo(int arreglo[], int tam){
    srand((unsigned)time(0)); //Inicializar la semilla para generar numeros aleatorios
    for(int i = 0; i < tam; i++){
        arreglo[i] = rand()%100;
    }
}

void orden::ordenaDescendente(int arreglo[], int n){
    bool flag = true;
    int auxiliar;
    
    for(int i = 0; i < n && flag; i++){
        flag = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arreglo[j + 1] > arreglo[j]){
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
                flag = true;
            }
        }
    }
}

void orden::bubbleSort(int arreglo[], int n){
    bool flag = true;
    int auxiliar;
    
    for(int i = 0; i < n && flag; i++){
        flag = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arreglo[j + 1] < arreglo[j]){
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
                flag = true;
            }
        }
    }
}

void orden::quickSort(int arreglo[], int inicio, int fin){
    if(inicio >= fin){
        return;
    }

    int part = particion(arreglo, inicio, fin);
    quickSort(arreglo, inicio, part - 1);
    quickSort(arreglo, part + 1, fin);
}

int orden::particion(int arreglo[], int inicio, int fin){
    int pivote = arreglo[inicio];
    int contador = 0;
    for(int i = inicio + 1; i <= fin;i++){
        if (arreglo[i] <= pivote){
            contador++;
        }
    }
    int indicePivote = inicio + contador;
    swap(&arreglo[indicePivote], &arreglo[inicio]);
    int i = inicio, j = fin;

    while(i < indicePivote && j > indicePivote){
        while(arreglo[i] <= pivote){
            i++;
        }
        while(arreglo[j] > pivote){
            j--;
        }
        if(i < indicePivote && j > indicePivote){
            swap(&arreglo[i++], &arreglo[j--]);
        }
    }
    return indicePivote;
}

void orden::swap(int* val1, int* val2){
    int temporal = *val1;
    *val1 = *val2;
    *val2 = temporal;
}

void orden::mergeSort(int arreglo[], int inicio, int fin){

    if(inicio < fin){
        int medio = inicio + (fin - inicio)/2;
        mergeSort(arreglo, inicio, medio);
        mergeSort(arreglo, medio + 1, fin);
        merge(arreglo, inicio, medio, fin);
    }
}

void orden::merge(int arreglo[], int inicio, int medio, int final){
    int i,j,k;
    int elementosIzq = medio - inicio + 1;
    int elementosDer = final - medio;

    int izq[elementosIzq];
    int der[elementosDer];

    for(int i = 0; i < elementosIzq; i++){
        izq[i] = arreglo[inicio + i];
    }
    for(int j = 0; j < elementosDer; j++){
        der[j] = arreglo[medio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    while(i < elementosIzq && j < elementosDer){
        if(izq[i] <= der[j]){
            arreglo[k] = izq[i];
            i++;
        }else{
            arreglo[k] = der[j];
            j++;
        }
        k++;
    }
    while(j < elementosDer){
        arreglo[k] = der[j];
        j++;
        k++;
    }
    while(i < elementosIzq){
        arreglo[k] = izq[i];
        i++;
        k++;
    }
}

void orden::imprimeArreglo(int arreglo[], int tam){
    for(int i = 0; i < tam; i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

