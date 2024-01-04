#include "header.c"
#include <stdio.h>

int main()
{
    /* Feel free to modify this function to test different things */

    uint32_t ackHeader = createAckHeader(12, 3, 4, 1);
    uint32_t nackHeader = createAckHeader(12, 3, 5, 0);
    uint32_t frameHeader = createHeader(15, 22, 8, 2);


    //printf("%d", validateHeader(526985525));

    printf("%d", createAckHeader(30, 113, 29, 0));

    //printf("Ack Header: valid %d, source %d frame id %d type %d \n", validateHeader(ackHeader), getSourceAddress(ackHeader), getFrameId(ackHeader), getFrameType(ackHeader));
    //printf("Nack Header: valid %d, source %d frame id %d type %d \n", validateHeader(nackHeader), getSourceAddress(nackHeader), getFrameId(nackHeader), getFrameType(nackHeader));
    printf("Frame Header: valid %d, source %d frame id %d type %d \n", validateHeader(frameHeader), getSourceAddress(frameHeader), getFrameId(frameHeader), getFrameType(frameHeader));

    return 0;
}
