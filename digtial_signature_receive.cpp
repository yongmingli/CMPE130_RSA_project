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
#include "digtial_signature_receive.h"

using namespace std;

int ds_de_modular(int base, int exp, int mod)
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

digtial_signature_receive::digtial_signature_receive() {}

digtial_signature_receive::digtial_signature_receive
(digital_signature_send input_value, keyset receiver_keyset, int sender_publickey[2]) {

    receiver = receiver_keyset;
    publickey[0] = sender_publickey[0];
    publickey[1] = sender_publickey[1];

    size = input_value.get_size();
    de_message = new int [size];
    de_message_in_char = new char [size];

    de_dsmessage = new int [size];
    ds_message = new int [size];
    ds_message_in_char = new char [size];


    for (int i = 0; i < size; i++) de_message[i] =
            ds_de_modular(input_value.enc_message[i],
                    receiver.get_d(), receiver.get_n());
    // decrypt the message using receiver's private keys
    for (int i=0; i<size; i++) de_message_in_char[i] = de_message[i];
    de_output = de_message_in_char;

    for (int i = 0; i < size; i++) de_dsmessage[i] =
            ds_de_modular(input_value.send_digital_signature[i],
                    receiver.get_d(), receiver.get_n());
    // decrypt the digital signature using receiver's private keys

    for (int i = 0; i < size; i++) ds_message[i] =
            ds_de_modular(de_dsmessage[i],
                    publickey[1], publickey[0]);
    // second decrypt the digital signature using sender's public keys
    for (int i=0; i<size; i++) ds_message_in_char[i] = ds_message[i];
    ds_output = ds_message_in_char;

    if (de_output == ds_output) {authentic = true;}
    else authentic = false;
}

void digtial_signature_receive::verify_message()
{
    if (authentic)
    {
        cout<< "Good: The message has been verified and confirmed that "
               "it is sent by the party you received public keys "
               "as well as digital signature from. " << endl
               << endl
                << "The message you received is: "<<endl
                << "          "
                << de_output << endl;
    }
    else
    {
        cout<< "ERROR: The message you received does not match with the message "
               "from the digital signature you received."<< endl
            << endl
            << "The message you received is: "<<endl
                << "          "
            << de_output <<endl << "\n"
            << "The message from the digital signature is: "<<endl
                << "          "
            << ds_output <<endl;
    }
}