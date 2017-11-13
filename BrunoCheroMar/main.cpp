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

int show (classificacao v[], int k){
    cout << "topK [";
    for (int i = 0; i < k; i++)
        std::printf(" %.1f ", v[i].distancia);
    cout << "]\n";
}

void insortion(classificacao v[], classificacao c, int k){
    cout << c.distancia << ", " << c.classe << endl;
    if (c.distancia > v[k].distancia)
        v[k].classe = "aehoo";//linha com problema
    
    show(v, k);
}

string classificar(ifstream& B, ifstream& X, int k){
    int repfB = 0,
        replX = 0,
        replB = 0;
    
    classificacao c, topK[k];
    c.distancia = 0.0f;
    c.classe = "classe";
    for (int i = 0; i < k; i++){
        topK[i] = c;
    }
    
    string lineX;
    while(getline(X, lineX)){    
        replX++;
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

            insortion(topK, c, k);
            cout << "LX: " << replX << "   FB: " << repfB << "   LB " << replB++ << endl;
        }

        B.clear();
        B.seekg(B.beg);
        repfB++;
        cin.ignore();
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