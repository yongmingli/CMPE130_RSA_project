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

#ifndef CLION_DIGTIAL_SIGNATURE_RECEIVE_H
#define CLION_DIGTIAL_SIGNATURE_RECEIVE_H

using namespace std;

class digtial_signature_receive {

protected:
    keyset receiver;   // receiver's keyset
    int publickey[2];  // (n,e) [This is from the sender]
    int size;

    int *de_message;
    char *de_message_in_char;
    string de_output;

    int *de_dsmessage;
    int *ds_message;
    char *ds_message_in_char;
    string ds_output;

    bool authentic;

public:
    digtial_signature_receive();
    explicit digtial_signature_receive
    (digital_signature_send input_value, keyset receiver_keyset, int sender_publickey[2]);
    void verify_message(); // to verfy message and output the result.
};


#endif //CLION_DIGTIAL_SIGNATURE_RECEIVE_H
