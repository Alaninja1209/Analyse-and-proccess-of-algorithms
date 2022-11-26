//  Created by Alan Alfredo Onofre Chavez on 14/11/22.
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

int LCS(string DNA, string DNA_new, long int m, long int n){
    int L[m + 1][n + 1];
    
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(DNA[i - 1] == DNA_new[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else{
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    return L[m][n];
}

string leerArchivo(string direccion){
    string texto;
    ifstream archivo;
    archivo.open(direccion, ios::in); //Abriendo archivo en modo lectura
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    while(!archivo.eof()){
        getline(archivo, texto);
        //cout<<texto<<endl;
    }
    
    return texto;
}

int main() {
    string DNAnew = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_new.txt";
    string Pikachu = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_Pikachu.txt";
    string SpongeBob = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_SpongeBob.txt";
    string PatrickStar = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_PatrickStar.txt";
    string Spiderman = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_Spiderman.txt";
    string RickSapiens = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_RickSapiens.txt";
    string Perry = "/Users/alanonofre/Documents/AES/Algorithms/LCS/LCS/LCS/DNA_PerryThePlatypus.txt";
        
    string DNA = leerArchivo(DNAnew);
        
    string DNAPikachu = leerArchivo(Pikachu);
    string DNASpongeBob = leerArchivo(SpongeBob);
    string DNAPatrick = leerArchivo(PatrickStar);
    string DNASpiderman = leerArchivo(Spiderman);
    string DNARickSapiens = leerArchivo(RickSapiens);
    string DNAPerry = leerArchivo(Perry);
    
    int x  = LCS(DNA, DNAPikachu, DNA.size(), DNAPikachu.size());
    int x2 = LCS(DNA, DNASpongeBob, DNA.size(), DNASpongeBob.size());
    int x3 = LCS(DNA, DNASpiderman, DNA.size(), DNASpiderman.size());
    int x4 = LCS(DNA, DNAPatrick, DNA.size(), DNAPatrick.size());
    int x5 = LCS(DNA, DNARickSapiens, DNA.size(), DNARickSapiens.size());
    int x6 = LCS(DNA, DNAPerry, DNA.size(), DNAPerry.size());
    
    int matrixLCS[6] = {x, x2, x3, x4, x5, x6};
    
    float big = 0;
    string afiliacion;
    
    for(int i = 0; i < size(matrixLCS); i++){
        if(matrixLCS[i] > big){
            big = matrixLCS[i];
        }
    }
    
    float parentezco = (big / DNA.size()) * 100;
    
    cout<<"Longitud de la especie: "<<big<<endl;
    cout<<"Porcentaje de parentezco: "<<parentezco<<endl;
    cout<<"NUEVA ESPECIE: DEWOTT"<<endl;
    
    return 0;
}
