//
// Created by 李涌铭 on 2018-11-27.
//
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include "keyset.h"
#include "rsa_encryption.h"

#ifndef CLION_RSA_DECRYPTION_H
#define CLION_RSA_DECRYPTION_H

using namespace std;

class rsa_decryption {

protected:

    int publickey[2];  // (n,e)
    int size;
    int *receive;
    int *dec_message; // decryption message
    char *message;
    string output;

public:
    rsa_decryption(); //Default constructor
    explicit rsa_decryption (rsa_encryption input_value);
    void display();
};


#endif //CLION_RSA_DECRYPTION_H
