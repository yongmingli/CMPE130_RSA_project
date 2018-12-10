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

#include "longlong_rsa.h"

using namespace std;

void string_to_int(string const& s, long long arr[]){
    for(int i = 0; i < s.length(); i++){
        arr[i] = s[i];
    }
}

long long calculate_d(long long e, long long z, long long n){
    long long sum;

    for(long long i = 1; i < n; i++){
        sum = (i*e - 1);
        if(((sum % z) == 0)){
            return i;
        }
    }
    return 0;
}

longlong_rsa::longlong_rsa() {}

longlong_rsa::longlong_rsa(string message, long long input_p, long long input_q, long long input_e) {
    p = input_p;
    q = input_q;
    e = input_e;
    n = p * q;
    z = (p-1) * (q-1);
    d = calculate_d(e, z, n);
    if (d == 0) cout << "ERROR!" << endl;

    input = message;
    size = (long long) input.length();
    list1 = new long long [size];
    temp = new long long [size];
    for(int i = 0; i < size; i++){
        list1[i] = 0;
        temp[i] = 0;
    }

    enc_message = new long long [size];
    output = new long long [size];

    string_to_int(message, list1);
}

void longlong_rsa::encryption() {

    long long pt, ct, key = e, k;

    for (long long i = 0; i != size; i++)
    {
        pt = list1[i];
        pt = pt - 96;
        k = 1;
        for (long long j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        list1[i] = ct;
        enc_message[i] = ct;
    }

    enc = true;
}

void longlong_rsa::decryption() {
    if (!enc)
    {
        cout << "YOU HAVE TO ENCRYPTION FIRST!"<<endl;
        exit (0);
    }

    long long pt, ct, key = d, k;
    for (long long i = 0; i != size; i++)
    {
        ct = temp[i];
        k = 1;
        for (long long j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        list1[i] = pt;
        output[i] = pt;
    }
    enc = false;
}

string longlong_rsa::get_input() {
    return input;
}

void longlong_rsa::get_output() {
    for (long long i = 0; i < size; i++) printf("%c", output[i]);

}

void longlong_rsa::get_enc_message() {
    for (long long i = 0; i < size; i++) printf("%c", enc_message[i]);
}

void longlong_rsa::get_keys() {
    cout << "In this keyset, q = "<< q <<", p = "<< p <<", e = "<< e <<", d = "<< d <<"."<<endl;
}

void longlong_rsa::build(string message, long long input_p, long long input_q, long long input_e) {
    p = input_p;
    q = input_q;
    e = input_e;
    n = p * q;
    z = (p-1) * (q-1);
    d = calculate_d(e, z, n);
    if (d == 0) cout << "ERROR!" << endl;

    input = message;
    size = (long long) input.length();
    list1 = new long long [size];
    temp = new long long [size];
    for(int i = 0; i < size; i++){
        list1[i] = 0;
        temp[i] = 0;
    }

    enc_message = new long long [size];
    output = new long long [size];

    string_to_int(message, list1);
}
