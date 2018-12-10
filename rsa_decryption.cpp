//
// Created by 李涌铭 on 2018-11-27.
//

#include "rsa_decryption.h"
#include "rsa_encryption.h"
#include "keyset.h"

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int de_modular(int base, int exp, int mod)
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

rsa_decryption::rsa_decryption() {}

rsa_decryption::rsa_decryption(rsa_encryption input_value)
{
    publickey[0] = input_value.publickey[0]; // n
    publickey[1] = input_value.publickey[1]; // e
    size = input_value.get_size();
    receive = input_value.enc_message;
    dec_message = new int [size];
    message = new char [size];

    for (int i=0; i<size; i++) dec_message[i] = de_modular(receive[i], publickey[1], publickey[0]);

    for (int i=0; i<size; i++) message[i] = dec_message[i];

    output = message;

}

void rsa_decryption::display() {
    cout << output <<endl;

}
