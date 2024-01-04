#include "header.h"
#include <stdio.h>

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */

#define SYNC_MASK (0x3F)
#define ACK_MASK (1 << 6)
#define V_MASK (1 << 7)
#define TYPE_MASK (7 << 8)
#define FRAME_ID_MASK (0x1F << 11)
#define SOURCE_MASK (0xFF << 16)
#define DESTINATION_MASK (0xFF << 24)


void op_print_byte(uint32_t b) {
  int i;
  for (i = 0; i < 8; i++) {
    printf("%d", !!((b << i) & 0x80));
  }

}

int validateHeader(uint32_t header)
{
    int sync_value = header & SYNC_MASK;
    int ack_value = (header & ACK_MASK) >> 6;
    int v_value = (header & V_MASK) >> 7;
    int type_value = (header & TYPE_MASK) >> 8;
    int source_value = (header & SOURCE_MASK) >> 16;
    int destination_value = (header & DESTINATION_MASK) >> 24;

    if (sync_value == 0x2a) {
        if ((source_value != 0) && (destination_value != 0) && (destination_value != source_value)) {
            if (ack_value == 1) {
                if (v_value == 1) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (type_value != 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
int getFrameId(uint32_t header)
{
    if (validateHeader(header) == 1) {
        int frame_id_value = (header & FRAME_ID_MASK) >> 11;

        return frame_id_value;
    } else {
        return -1;
    }  
}
int getFrameType(uint32_t header)
{
    if (validateHeader(header) == 1) {
        int ack_value = (header & ACK_MASK) >> 6;
        if (ack_value == 1) {
            return 0;
        } else {
            int type_value = (header & TYPE_MASK) >> 8;

            return type_value;
        }
    } else {
        return -1;
    }
}
int getSourceAddress(uint32_t header)
{
    if (validateHeader(header) == 1) {
        int source_value = (header & SOURCE_MASK) >> 16;

        return source_value;
    } else {
        return -1;
    } 
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid)
{
    int sync_bits = 0x2a;
    int ack_bits = 1 << 6;
    int type_bits = 0 << 8;
    int frame_id_bits = frameId << 11;
    int source_bits = sourceAddress << 16;
    int destination_bits = destAddress << 24;
    int v_bits;

    if (valid == 0) {
        v_bits = 0 << 7;
    } else {
        v_bits = 1 << 7;
    }

    return sync_bits | ack_bits | type_bits | frame_id_bits | source_bits | destination_bits | v_bits;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    int sync_bits = 0x2a;
    int ack_bits = 0 << 6;
    int v_bits = 0 << 7;
    int type_bits = type << 8;
    int frame_id_bits = frameId << 11;
    int source_bits = sourceAddress << 16;
    int destination_bits = destAddress << 24;
    
    return sync_bits | ack_bits | type_bits | frame_id_bits | source_bits | destination_bits | v_bits;
}
