cmake_minimum_required(VERSION 3.12)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clion main.cpp keyset.cpp keyset.h rsa_encryption.cpp rsa_encryption.h rsa_decryption.cpp rsa_decryption.h digtial_signature_send.cpp digtial_signature_send.h digtial_signature_receive.cpp digtial_signature_receive.h longlong_rsa.cpp longlong_rsa.h)