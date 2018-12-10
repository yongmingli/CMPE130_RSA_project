#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <chrono>
#include <cstdint>
#include <cmath>


#include "longlong_rsa.h"
#include "keyset.h"
#include "rsa_encryption.h"
#include "rsa_decryption.h"
#include "digtial_signature_send.h"
#include "digtial_signature_receive.h"

using namespace std;

class CurrentTime {
    std::chrono::high_resolution_clock m_clock;

public:
    uint64_t milliseconds();
    uint64_t microseconds();
    uint64_t nanoseconds();
};

uint64_t CurrentTime::milliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
            (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::microseconds()
{
    return std::chrono::duration_cast<std::chrono::microseconds>
            (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::nanoseconds()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>
            (m_clock.now().time_since_epoch()).count();
}

int main() {

    //Demo for RSA

//    string input_rsa = "Hello, World!!!!!!!!!";
//    cout << endl
//    << "This is simple RSA DEMO"<<"\n"
//    << "{" << endl
//    << "The input message is: " << "\n"
//    << input_rsa <<"\n"<<endl;
//
//
//    rsa_encryption test_en (input_rsa);
//    test_en.keydisplay();
//    test_en.process_display();
//
//    int size_rsa = test_en.get_size();
//    char *enc_message_in_char = new char [size_rsa];
//    for (int i = 0; i< size_rsa; i++) enc_message_in_char[i] = test_en.enc_message[i];
//    string enc_message = enc_message_in_char;
//
//    cout << "The encrypted message is: " << "\n"
//    << enc_message<<endl;
//
//    rsa_decryption test_de (test_en);
//
//    cout << "\n"<< "The output message is: " << "\n";
//    test_de.display();
//    cout << "}" << "\n";

//    keyset x;
//    x.generate();
//    x.display();

    string message = "Hello class, we are Group #2, and we are presenting RSA and Digital Signature~~~";
    longlong_rsa key[10];
    key[0].build (message, 11, 13, 17);
    key[1].build (message, 227, 41, 167);
    key[2].build (message, 257,3919,2549);
    key[3].build (message, 317,1151,349);
    key[4].build (message, 811,3121,227);
    key[5].build (message, 881,41,4877);
    key[6].build (message, 1283,1117,1277);
    key[7].build (message, 1307,2207,127);
    key[8].build (message, 2039,2251,227);
    key[9].build (message, 4549,613,2657);

    cout <<"\n"<< "This is simple RSA DEMO"<<"\n"
    << "{" << endl << "\n"
    << "The input message is: " << "\n"
            << "          "
    << message <<"\n"<<endl;

    key[0].get_keys();

    key[0].encryption();
    cout << "\nThe encrypted message is: " << "\n" << "          ";
    key[0].get_enc_message();
    cout <<endl;

    key[0].decryption();
    cout << "\n"<< "The output message is: " << "\n" << "          ";
    key[0].get_output();
    cout << "\n" <<endl;

    // For Runtime now
    cout << "\n"<< "NOW, IT IS RUN TIME TEST:" << "\n" <<endl;
    CurrentTime current_time; // use for runtime
    uint64_t start1;
    uint64_t start2;
    uint64_t start3;

    uint64_t end1;
    uint64_t end2;
    uint64_t end3;

    // Runtime for key
    for (int i = 0; i<10; i++)
    {
        cout << "Keyset"<<i<<":" << "\n";
        key[i].get_keys();

        start1 = current_time.milliseconds();
        start2 = current_time.microseconds();
        start3 = current_time.nanoseconds();

        key[i].encryption(); //key[i] encryption

        end1 = current_time.milliseconds();
        end2 = current_time.microseconds();
        end3 = current_time.nanoseconds();

        cout << "The runtime of encryption for keyset"<<i<<" is:" << "\n"
             << "Milliseconds: "   << (end1 - start1)
             << ", microseconds: " << (end2 - start2)
             << ", nanoseconds: "  << (end3 - start3)
             << ".\n";

        start1 = current_time.milliseconds();
        start2 = current_time.microseconds();
        start3 = current_time.nanoseconds();

        key[i].decryption(); //key[i] decryption

        end1 = current_time.milliseconds();
        end2 = current_time.microseconds();
        end3 = current_time.nanoseconds();

        cout << "The runtime of decryption for keyset"<<i<<" is:" << "\n"
             << "Milliseconds: "   << (end1 - start1)
             << ", microseconds: " << (end2 - start2)
             << ", nanoseconds: "  << (end3 - start3)
             << ".\n"<<endl;

    }
    cout  << "}" << "\n";



    //Demo for Digital signature

    keyset sender(53,67,7);

    keyset receiver(181,107,89);

    keyset test_ds; // test subject for digital signature
    test_ds.generate();

    int sender_publickey[2];
    sender_publickey[0] = sender.publickey[0];
    sender_publickey[1] = sender.publickey[1];

    int receiver_publickey[2];
    receiver_publickey[0] = receiver.publickey[0];
    receiver_publickey[1] = receiver.publickey[1];

    string input_ds = "The password is 1234567890)(*&^%$#@!.";
    string test_input_ds  = "The password is 212^&*(%$#@3218986~~";


    cout << endl << endl
    << "This is digital signature DEMO"<<"\n"
    << "{" << "\n"<< endl
    << "The input message is: " << "\n"
            << "          "
    << input_ds <<"\n"<<endl;

    digital_signature_send ds_en_object (input_ds, sender, receiver_publickey);

    digital_signature_send ds_test_en_object (test_input_ds, test_ds, receiver_publickey);

    digtial_signature_receive ds_de_object (ds_en_object, receiver, sender_publickey);

    digtial_signature_receive ds_test_de_object (ds_test_en_object, receiver, sender_publickey);

    ds_de_object.verify_message();

    cout << endl
         << "NOW, IT IS FROM THE DIFFERENT SENDER: " << "\n" << endl;

    ds_test_de_object.verify_message();

    cout << "}" << "\n";
}