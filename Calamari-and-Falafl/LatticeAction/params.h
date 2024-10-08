#ifndef PARAMS_H
#define PARAMS_H

#include "config.h"

#define SEEDBYTES 32
#define CRHBYTES 48
#define N 256
#define Q 8380417
#define QBITS 23
#define ROOT_OF_UNITY 1753
#define D 20 // 14
#define GAMMA1 ((Q - 1)/4/16)
#define GAMMA1MASK 0x3FFFF
#define GAMMA2 (GAMMA1/2)
#define ALPHA (2*GAMMA2)

// MODE 是 2

#if MODE == 1
#define K 3
#define L 2
#define ETA 7
#define SETABITS 4
#define BETA 375
#define OMEGA 64

#elif MODE == 2
#define K 4
#define L 3
#define ETA 6
#define SETABITS 4
#define BETA 325
#define OMEGA 80

#elif MODE == 3
#define K 5
#define L 4
#define ETA 5
#define SETABITS 4
#define BETA 275
#define OMEGA 96

#elif MODE == 4
#define K 6
#define L 5
#define ETA 3
#define SETABITS 3
#define BETA 175
#define OMEGA 120

#endif

#define POLT1_SIZE_PACKED ((N*(QBITS - D))/8)
#define POLT0_SIZE_PACKED ((N*D)/8)
#define POLETA_SIZE_PACKED ((N*SETABITS)/8)
#define POLZ_SIZE_PACKED ((N*(QBITS - 5))/8)
#define POLW1_SIZE_PACKED ((N*4)/8)

#define CRYPTO_PUBLICKEYBYTES (SEEDBYTES + K*POLT1_SIZE_PACKED)
#define CRYPTO_SECRETKEYBYTES (2*SEEDBYTES + (L + K)*POLETA_SIZE_PACKED + CRHBYTES + K*POLT0_SIZE_PACKED)
#define CRYPTO_BYTES (L*POLZ_SIZE_PACKED + (OMEGA + K) + (N/8 + 8))

#endif
