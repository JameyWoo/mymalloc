//
// Created by 26220 on 2021/2/21.
//

#ifndef MYMALLOC_BITMAP_H
#define MYMALLOC_BITMAP_H

#include <cstring>
#include "cstdio"

class BitMap {
public:
    BitMap() {
        bitmap = NULL;
        size = 0;
    }

    BitMap(int size) { // contractor, init the bitmap
        bitmap = NULL;
        bitmap = new char[size];
        if (bitmap == NULL) {
            printf("ErroR In BitMap Constractor!\n");
        } else {
            memset(bitmap, 0x0, size * sizeof(char));
            this->size = size;
        }
    }


    /*
     * set the index bit to 1;
     */
    int Set(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            bitmap[addr] |= temp;
            return 1;
        }
    }

    /*
     * return if the index in bitmap is 1;
     */
    bool Get(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            return (bitmap[addr] & temp) > 0 ? 1 : 0;
        }
    }

    /*
     * del the index from 1 to 0
     */
    int Del(int index) {
        if (Get(index) == 0) {
            return 0;
        }
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            bitmap[addr] ^= temp;
            return 1;
        }
    }

private:
    char *bitmap;
    int size;
};

#endif //MYMALLOC_BITMAP_H
