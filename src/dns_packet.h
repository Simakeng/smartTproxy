#include <stdint.h>
#include <stdlib.h>

#pragma pack(push, 1)

typedef struct
{
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
} dns_packet_header_t;

typedef struct
{
    void *name;
    uint16_t type;
    uint16_t _class;
} dns_packet_question_t;

typedef struct
{
    uint8_t *name;
    uint16_t type;
    uint16_t _class;
    uint32_t ttl;
    uint16_t rdlength;
    void *rdata;
} dns_packet_answer_t;


typedef struct 
{
    dns_packet_header_t header;
    dns_packet_question_t *questions;
    dns_packet_answer_t *answers;
    dns_packet_answer_t *authorities;
    dns_packet_answer_t *additionals;
} dns_packet_t;


int dns_packet_parse(dns_packet_t *packet, uint8_t *buffer, size_t buffer_size);

int dns_packet_serialize(dns_packet_t *packet, uint8_t *buffer, size_t buffer_size);

int dns_packet_free(dns_packet_t *packet);

#pragma pack(pop)