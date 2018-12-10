//
// Created by 李涌铭 on 2018-12-05.
//
#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <streambuf>
#include <sstream>

#ifndef CLION_LONGLONG_RSA_H
#define CLION_LONGLONG_RSA_H

using namespace std;

class longlong_rsa {
protected:

    long long p;
    long long q; // prime number 2
    long long n; // n = p*q
    long long z; // z = (p-1)*(q-1)
    long long e; // choose e from the prime array above
    long long d; // ed % z = 1

    long long size;
    long long *list1; // input message in long long
    long long *temp; // hold the cp text

    string input;
    long long *enc_message;
    long long *output;

    bool enc;

public:
    longlong_rsa();
    explicit longlong_rsa (string message, long long input_p, long long input_q, long long input_e);
    void build (string message, long long input_p, long long input_q, long long input_e);
    void encryption();
    void decryption();

    string get_input();
    void get_output();
    void get_enc_message();
    void get_keys();

};


#endif //CLION_LONGLONG_RSA_H
