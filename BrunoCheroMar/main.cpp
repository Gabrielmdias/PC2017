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
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>

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
    int nro = 1;
    
                classificacao c;
    string lineX;
    while(getline(X, lineX)){    
        std::stringstream strX(lineX); 
        
        string lineB;
        while(getline(B, lineB)){
            std::stringstream strB(lineB);
            
            string attrB, attrX;            
            while (getline(strX, attrX, ',')){
                   getline(strB, attrB, ',');                

                double  numX = atof(attrX.c_str()),
                        numB = atof(attrB.c_str());
                
                if (numX)
                    c.distancia += pow(numB - numX, 2);
                else
                    c.classe = attrB.c_str();
            }
            
            strX.clear();
            strX.seekg(strX.beg);
        }
        cout << "CLASS."<< nro++ << ": " << c.distancia << "|" << c.classe << "\n";        
        cin.ignore();
        
        B.clear();
        B.seekg(B.beg);
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