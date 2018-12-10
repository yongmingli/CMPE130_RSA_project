//
// Created by 李涌铭 on 2018-11-27.
//
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include "keyset.h"
#include "rsa_encryption.h"
#include "rsa_decryption.h"
#include "digtial_signature_send.h"

using namespace std;

int ds_en_modular(int base, int exp, int mod)
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

digital_signature_send::digital_signature_send() {}



int digital_signature_send::get_size() {
    return size;
}

digital_signature_send::digital_signature_send(string input_string, keyset sender_keyset, int receiver_publickey[2]) {

    sender = sender_keyset;
    publickey[0] = receiver_publickey[0]; // n
    publickey[1] = receiver_publickey[1]; // e

    input = input_string;
    size = input_string.length();
    input_asc = new int[size];
    digital_signature = new int [size];

    enc_message = new int [size];
    send_digital_signature = new int [size];

    for (int i = 0; i < size; i++) input_asc[i] = input[i];
    for (int i = 0; i < size; i++) digital_signature[i] =
            ds_en_modular(input_asc[i], sender.get_d(), sender.get_n());
    // make digital signature with sender's private key


    for (int i = 0; i < size; i++) enc_message[i] =
            ds_en_modular(input_asc[i], publickey[1], publickey[0]);
    // encrypt the message with receiver's public key
    for (int i = 0; i < size; i++) send_digital_signature[i] =
            ds_en_modular(digital_signature[i], publickey[1], publickey[0]);
    // encrypt the digital signature with receiver's public key
}
