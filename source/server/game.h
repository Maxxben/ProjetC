#include "../common/cfg.h"
#ifndef JEU_H
#define JEU_H

typedef struct  {
    jeuClient rc1;
    jeuClient rc2;
}Result_Round;
#endif /* JEU_H */

 Result_Round RoundProcess(jeuClient c1, jeuClient c2);
