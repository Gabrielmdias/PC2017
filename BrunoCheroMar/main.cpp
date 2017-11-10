/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Author: BrunoCheroMariana
 *
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

struct classificacao{
    int distancia;
    string classe;
};



void insertionSort(classificacao maisVotadas[], classificacao c, int k){
    int i;
    
    for(int j = 1; j < k; j){        
        classificacao key = maisVotadas[j];
        for(i = j-1; (i > -1) && (maisVotadas[i].distancia < key.distancia); i--){
            maisVotadas[i+1] = maisVotadas[i];
        }
        maisVotadas[i+1] = key;
    }
}

string classificar(ifstream& B, ifstream& X, int k){
    string strB, strX;
    double numB, numX, dif;
    int posB = B.tellg(),
        posX = X.tellg();
    //classificacao maisVotadas[k];
    std::vector<classificacao> maisVotadas;
    maisVotadas.resize(k);
    
    do {
        classificacao c;
        
        B.seekg(posB);        
        do {
            getline(B, strB, ',');
            getline(X, strX, ',');
            if (!(numB = atof(strB.c_str())))
                c.classe = strB;
            numX = atof(strX.c_str());                

            c.distancia += pow(numB - numX, 2);            
        } while (numX > 0);
        
        maisVotadas.insert(0, c);
        
            
    } while (numX > 0);

    //Obter as classes das k menores distâncias
    return "oooi";
}

int main(int argc, char** argv) {
    string nomeArqB = "train_59.data",
           nomeArqX = "test_59.data";
    ifstream B, X;
    
    B.open(nomeArqB.c_str());
    X.open(nomeArqX.c_str());
    
    if(!B.is_open() || !X.is_open())
        return 0;
    
    cout << classificar(B, X, 10);
    
    B.close();
    X.close();
    
    return 0;
}