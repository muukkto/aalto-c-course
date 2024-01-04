#ifndef AALTO_TCPHEADER_H
#define AALTO_TCPHEADER_H

#include <stdint.h>

int validateHeader(uint32_t header);
int getFrameId(uint32_t header);
int getFrameType(uint32_t header);
int getSourceAddress(uint32_t header);

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid);
uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type);

#endif
