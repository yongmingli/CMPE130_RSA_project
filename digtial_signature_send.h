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

#ifndef CLION_DIGTIAL_SIGNATURE_SEND_H
#define CLION_DIGTIAL_SIGNATURE_SEND_H

using namespace std;

class digital_signature_send {

protected:
    keyset sender;
    int publickey[2];  // (n,e) [This is from the receiver]
    string input;
    int size;

    int *input_asc; //input string to asc
    int *digital_signature;

public:
    int *enc_message; // encryption message with receiver's public key
    int *send_digital_signature; // encrypted digital signature with receiver's public key


    digital_signature_send(); //Default constructor
    explicit digital_signature_send (string input_string, keyset sender_keyset,int receiver_publickey[2]);

    int get_size();

};

#endif //CLION_DIGTIAL_SIGNATURE_SEND_H
