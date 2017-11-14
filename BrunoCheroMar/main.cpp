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
    
    bool operator<(const classificacao& c) const {
        return distancia < c.distancia;
    }
};

int version = 0;

int show (vector<classificacao> v){
    cout << version++ << " topK [";
    for(vector<classificacao>::iterator it = v.begin(); it < v.end(); it++)
        cout << ' ' << it.base()->distancia << ' ';
    cout << "]\n";
}

vector<classificacao> insortion(vector<classificacao> v, classificacao c){    
    if (c.distancia < v.back().distancia){
        swap(c, v.back());
        sort(v.begin(), v.end());
    }
    
    return v;
}

string classificar(ifstream& B, ifstream& X, int k){
    classificacao c;
    c.distancia = 999.0f;   c.classe = "classe";
    
    vector<classificacao> topK;
    while (topK.size() < k)
        topK.push_back(c);
    
    string  lineX, lineB,
            attrX, attrB;
    while(getline(X, lineX)){
        std::stringstream strX(lineX);
        
        classificacao c;    
        c.distancia = 0;    c.classe = "classe";
        
        while(getline(B, lineB)){
            std::stringstream strB(lineB);
            
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

            topK = insortion(topK, c);
        }

        B.clear();
        B.seekg(B.beg);
    }
    
    show(topK);
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