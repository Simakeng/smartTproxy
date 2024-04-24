#include <stdint.h>
#include <stdio.h>
/*
❯ sudo ./test.server 53
server address: 0.0.0.0
server received datagram from 10.45.233.182
server received 0/44 bytes: 
00 01 01 00 00 01 00 00 00 00 00 00 03 32 31 32 
03 32 33 33 02 34 35 02 31 30 07 69 6E 2D 61 64 
64 72 04 61 72 70 61 00 00 0C 00 01 
 === end of stream. ===
server received datagram from 10.45.233.182
server received 0/31 bytes: 
00 02 01 00 00 01 00 00 00 00 00 00 03 77 77 77 
05 62 61 69 64 75 03 63 6F 6D 00 00 01 00 01 
 === end of stream. ===
server received datagram from 10.45.233.182
server received 0/31 bytes: 
00 03 01 00 00 01 00 00 00 00 00 00 03 77 77 77 
05 62 61 69 64 75 03 63 6F 6D 00 00 1C 00 01 
 === end of stream. ===
 */

static const uint8_t dns_ptr_query[] = {
    0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x32, 0x31, 0x32, //
    0x03, 0x32, 0x33, 0x33, 0x02, 0x34, 0x35, 0x02, 0x31, 0x30, 0x07, 0x69, 0x6E, 0x2D, 0x61, 0x64, //
    0x64, 0x72, 0x04, 0x61, 0x72, 0x70, 0x61, 0x00, 0x00, 0x0C, 0x00, 0x01,                         //
};


int main()
{
    printf("test\n");
    return 0;
}