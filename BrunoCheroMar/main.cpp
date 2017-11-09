/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabriel
 *
 * Created on 31 de Outubro de 2017, 20:34
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;



string Classificar(ifstream& B, ifstream& X, int k){
    string strB, strX;
    double numB, numX, dif;

    do {
        do {
            getline(B, strB, ',');
            getline(X, strX, ',');
            numB = atof(strB.c_str());
            numX = atof(strX.c_str());
        } while (numX > 0);
    } while

    //Obter as classes das k menores distâncias
    return "a classe que mais apareceu dentre as k classes obtidas";
    }
/*
 * 
 */
int main(int argc, char** argv) {
    string nomeArqB = "train_59.data",
           nomeArqX = "test_59.data";
    ifstream B, X;
    
    B.open(nomeArqB.c_str());
    X.open(nomeArqX.c_str());
    
    if(!B.is_open() || !X.is_open())
        return 0;
    
    Classificar(B, X, 1);
    
    B.close();
    X.close();
    
    return 0;
}