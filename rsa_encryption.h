//
// Created by 李涌铭 on 2018-11-27.
//
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include "keyset.h"

#ifndef CLION_RSA_ENCRYPTION_H
#define CLION_RSA_ENCRYPTION_H

using namespace std;

class rsa_encryption {

protected:

    keyset key;
    string input;
    int size;
    int *input_asc; //input string to asc

public:
    int *enc_message; // encryption message
    int publickey[2];  // (n,e)

    rsa_encryption(); //Default constructor
    explicit rsa_encryption (string input_string);

    int get_size();
    void keydisplay();
    void process_display();
};


#endif //CLION_RSA_ENCRYPTION_H
