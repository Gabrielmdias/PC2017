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
#include <sstream>

using namespace std;

struct classificacao{
    double distancia;
    string classe;
};



void insertionSort(classificacao maisVotadas[], classificacao c, int k){
    int i;
    
    //if (c.distancia < maisVotadas[k].distancia)
      //  swap(c, maisVotadas[k]);    
    
    for(int j = 1; j < k; j){        
        classificacao key = maisVotadas[j];
        for(i = j-1; (i > -1) && (maisVotadas[i].distancia < key.distancia); i--){
            maisVotadas[i+1] = maisVotadas[i];
        }
        maisVotadas[i+1] = key;
    }
}

string classificar(ifstream& B, ifstream& X, int k){
    string lineB, lineX;    
        
    while(getline(X, lineX)){
        std::stringstream strX(lineX);
        int i = strX.tellg();
        
        while(getline(B, lineB)){
            std::stringstream strB(lineB);

            strX.seekg(i);
            
            string attrB, attrX;
            getline(strB, attrB, ',');
            getline(strX, attrX, ',');

            classificacao c;
            double numB, numX, dif;
            if (!(numB = atof(attrB.c_str()))){
                c.classe = attrB;
                cout<<"Classe :"<<attrB;
            }
            numX = atof(attrX.c_str());                

            c.distancia += pow(numB - numX, 2);            
            
           // cout << numB << " - " << numX  << "\n";
        }
    
    }
    return "\n";
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