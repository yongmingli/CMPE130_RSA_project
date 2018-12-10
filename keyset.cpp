//
// Created by 李涌铭 on 2018-11-27.
//

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>       /* time */

#include "keyset.h"

using namespace std;

int calculate_d(int e, int z, int n){
    int sum;
    for(int i = 1; i < n; i++){
        sum = (i*e - 1);
        if(((sum % z) == 0)){
            return i;
        }
    }
    return 0;
}

keyset::keyset() {

    p = 0;
    n = 0;
    q = 0; // prime number 2
    z = 0; // z = (p-1)*(q-1)
    e = 0; // choose e from the prime array above
    d = 0; // ed % z = 1


    //privatekey[2]: (n,d)
    privatekey[0] = 0;
    privatekey[1] = 0;

    //publickey[2]:  (n,e)
    publickey[0] = 0;
    publickey[1] = 0;
}

keyset::keyset(int p1, int q1, int e1) {
    p = p1;
    q = q1;
    n = p * q;
    z = (p - 1) * (q - 1);
    e = e1;
    d = calculate_d(e, z, n);
    //privatekey[2]: (n,d)
    privatekey[0] = n;
    privatekey[1] = d;

    //publickey[2]:  (n,e)
    publickey[0] = n;
    publickey[1] = e;
}



void keyset::generate() {
    srand (time(NULL));

    do {
        p = prime[rand() % 50];

        do {
            do { q = prime[rand() % 50]; }
            while (q == p);

            n = p * q;
        } while (n < 128);

        z = (p - 1) * (q - 1);

        do { e = prime[rand() % 50]; }
        while (e > z);

        d = calculate_d(e, z, n);
        if (e*d % z == 1) {}
        else d = 0;
    }
    while (d == 0);

    //privatekey[2]: (n,d)
    privatekey[0] = n;
    privatekey[1] = d;

    //publickey[2]:  (n,e)
    publickey[0] = n;
    publickey[1] = e;
}

int keyset::get_d() {return d;}

int keyset::get_n() {return n;}

void keyset::display() {
    cout << "In this keyset:"<<endl
    <<"p = " << p <<endl
    <<"q = " << q <<endl
    <<"n = " << n <<endl
    <<"z = " << z <<endl
    <<"e = " << e <<endl
    <<"d = " << d <<endl
    <<"The private key (n,d) = (" << privatekey[0] <<","<< privatekey[1] <<")"<<endl
    <<"The public key (n,e) = (" << publickey[0] <<","<< publickey[1] <<")"<<"\n"<<endl;
}

