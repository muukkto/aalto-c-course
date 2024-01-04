/*
Implement below function **sixBits** which returns only least significant six bits
of the input value **v**. Rest of the two highest significant bits must be reset.
(i.e) If the input value **v** is **11110000**, then **sixBits** function must return
**110000**. One way to accomplish this is to use a bit mask.
*/

// define sixBits function here
#define MASK (0x3F)

unsigned char sixBits(unsigned char v) {
    return (v & MASK);


}