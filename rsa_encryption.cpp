//
// Created by 李涌铭 on 2018-11-27.
//

#include "rsa_encryption.h"
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include "keyset.h"

using namespace std;

int en_modular(int base, int exp, int mod)
{
    int x = 1;
    int i;
    int power = base % mod;
    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }
    return x;
}

rsa_encryption::rsa_encryption() {}

rsa_encryption::rsa_encryption(string input_string) {
    input = input_string;
    size = input_string.length();
    input_asc = new int[size];
    enc_message = new int[size];
    key.generate();

    publickey[0] = key.publickey[0];
    publickey[1] = key.publickey[1];

    for (int i = 0; i < size; i++) input_asc[i] = input[i];
    for (int i = 0; i < size; i++) enc_message[i] = en_modular(input_asc[i], key.get_d(), key.get_n());
}

int rsa_encryption::get_size() {
    return size;
}

void rsa_encryption::keydisplay() {key.display();}

void rsa_encryption::process_display() {
    cout<<"The ASCII array of the input message is: " << endl;
    for (int i = 0; i < size; i++)
        cout<< input_asc[i] << " , ";
    cout<<"\n"<<endl
    <<"The encrypted array of the input message is: " << endl;
    for (int i = 0; i < size; i++)
        cout<< enc_message[i] << " , ";
    cout<<"\n"<<endl;
}
