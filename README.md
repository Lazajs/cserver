# C Server from scratch

## Description

This is a simple socket server written in C for windows, using the winsock2 library.
It will create a connection with google (IP is taken from ip.c), send a HTTP request and print the response.

## Usage

Compile the program with `gcc main.c -o main.exe -lws2_32` and run it with `main.exe`.

## Errors

If you get an error like `undefined reference to 'WSAStartup@8'` you need to link the winsock2 library. You can do this by adding `-lws2_32` to the compile command.

If for any reason the connection always fails, you can try running `ip.exe` to get a new IP address. This will only work on windows .