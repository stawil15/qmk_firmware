
#include "quantum.h"

enum unicode_names {
    E_100, //💯
    E_BBB, //🅱
    E_CLAP, //👏
    E_EYES, //👀
    E_GRIM, //😬
    E_THNK, //🤔
    E_UGHH, //😩
    E_SWET, //😅
    E_ROFL, //🤣
    E_HART, //❤
    E_FIRE, //🔥
    E_LMAO, //😂
    E_HRNY, //😍
    E_PRAY, //🙏
    E_OKAY, //👌
    E_CRYY, //😭
    E_LOVD, //😍
    E_COOL, //😎
    E_GRIN, //😁
    E_WINK, //😉
    E_KISS, //😘
    E_ROLL,
    E_ANGL, //😇
    E_SPOK, //😱
    E_TONG, //
    E_PRTY,
    E_COMM,
    E_SKUL,
    E_PEAC,
    E_BEEE,
    E_TRAIN,
    E_BUSS
};

const uint32_t PROGMEM unicode_map[] = {
    [E_BBB]  = 0x1f171,
    [E_100]  = 0x1F4AF,
    [E_EYES] = 0x1f440,
    [E_CLAP] = 0x1f44f,
    [E_GRIM] = 0x1f62c,
    [E_THNK] = 0x1f914,
    [E_UGHH] = 0x1f629,
    [E_SWET] = 0x1f605,
    [E_LMAO] = 0x1f602,
    [E_HART] = 0x2764,
    [E_FIRE] = 0x1f525,
    [E_ROFL] = 0x1f923,
    [E_HRNY] = 0x1f60d,
    [E_PRAY] = 0x1f64f,
    [E_OKAY] = 0x1f44c,
    [E_CRYY] = 0x1f62d,
    [E_LOVD] = 0x1f970,
    [E_COOL] = 0x1f60e,
    [E_GRIN] = 0x1f601,
    [E_WINK] = 0x1f609,
    [E_KISS] = 0x1f618,
    [E_ROLL] = 0x1f612,
    [E_ANGL] = 0x1f607,
    [E_SPOK] = 0x1f631,
    [E_TONG] = 0x1f61c,
    [E_PRTY] = 0x1f389,
    [E_COMM] = 0x262d,
    [E_SKUL] = 0x2620,
    [E_PEAC] = 0x270c,
    [E_BEEE] = 0x1f41d,
    [E_BUSS] = 0x1f68e,
    [E_TRAIN] = 0x1f682
};
