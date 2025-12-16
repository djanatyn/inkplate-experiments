#ifndef GAMES_METADATA_H
#define GAMES_METADATA_H

#include <Arduino.h>

struct GameMetadata {
    const char* date;
    const char* black_player;
    const char* white_player;
    const char* black_rank;
    const char* white_rank;
};

// Metadata strings (stored in PROGMEM)
const char GAME_0_DATE[] PROGMEM = "2021-02-13";
const char GAME_0_BLACK[] PROGMEM = "shelly613";
const char GAME_0_WHITE[] PROGMEM = "djanatyn";
const char GAME_0_BLACK_RANK[] PROGMEM = "12k";
const char GAME_0_WHITE_RANK[] PROGMEM = "13k";
const char GAME_1_DATE[] PROGMEM = "2024-06-13";
const char GAME_1_BLACK[] PROGMEM = "Rembane";
const char GAME_1_WHITE[] PROGMEM = "djanatyn";
const char GAME_1_BLACK_RANK[] PROGMEM = "12k";
const char GAME_1_WHITE_RANK[] PROGMEM = "12k";
const char GAME_2_DATE[] PROGMEM = "2023-01-30";
const char GAME_2_BLACK[] PROGMEM = "djanatyn";
const char GAME_2_WHITE[] PROGMEM = "Arbitraria";
const char GAME_2_BLACK_RANK[] PROGMEM = "10k";
const char GAME_2_WHITE_RANK[] PROGMEM = "6k";
const char GAME_3_DATE[] PROGMEM = "2017-12-22";
const char GAME_3_BLACK[] PROGMEM = "djanatyn";
const char GAME_3_WHITE[] PROGMEM = "RoninMiyamotoMusashi";
const char GAME_3_BLACK_RANK[] PROGMEM = "11k";
const char GAME_3_WHITE_RANK[] PROGMEM = "11k";
const char GAME_4_DATE[] PROGMEM = "2019-02-18";
const char GAME_4_BLACK[] PROGMEM = "StarAnkh760";
const char GAME_4_WHITE[] PROGMEM = "djanatyn";
const char GAME_4_BLACK_RANK[] PROGMEM = "9k";
const char GAME_4_WHITE_RANK[] PROGMEM = "9k";
const char GAME_5_DATE[] PROGMEM = "2017-10-12";
const char GAME_5_BLACK[] PROGMEM = "djanatyn";
const char GAME_5_WHITE[] PROGMEM = "Tomaszovich";
const char GAME_5_BLACK_RANK[] PROGMEM = "12k";
const char GAME_5_WHITE_RANK[] PROGMEM = "10k";
const char GAME_6_DATE[] PROGMEM = "2020-05-16";
const char GAME_6_BLACK[] PROGMEM = "GeoT";
const char GAME_6_WHITE[] PROGMEM = "djanatyn";
const char GAME_6_BLACK_RANK[] PROGMEM = "13k";
const char GAME_6_WHITE_RANK[] PROGMEM = "11k";
const char GAME_7_DATE[] PROGMEM = "2025-07-18";
const char GAME_7_BLACK[] PROGMEM = "กระบือ";
const char GAME_7_WHITE[] PROGMEM = "djanatyn";
const char GAME_7_BLACK_RANK[] PROGMEM = "6k";
const char GAME_7_WHITE_RANK[] PROGMEM = "15k";
const char GAME_8_DATE[] PROGMEM = "2023-03-18";
const char GAME_8_BLACK[] PROGMEM = "0000.27";
const char GAME_8_WHITE[] PROGMEM = "djanatyn";
const char GAME_8_BLACK_RANK[] PROGMEM = "12k";
const char GAME_8_WHITE_RANK[] PROGMEM = "10k";
const char GAME_9_DATE[] PROGMEM = "2017-08-08";
const char GAME_9_BLACK[] PROGMEM = "djanatyn";
const char GAME_9_WHITE[] PROGMEM = "GnuGo";
const char GAME_9_BLACK_RANK[] PROGMEM = "11k";
const char GAME_9_WHITE_RANK[] PROGMEM = "2k";
const char GAME_10_DATE[] PROGMEM = "2020-05-06";
const char GAME_10_BLACK[] PROGMEM = "djanatyn";
const char GAME_10_WHITE[] PROGMEM = "will1951";
const char GAME_10_BLACK_RANK[] PROGMEM = "11k";
const char GAME_10_WHITE_RANK[] PROGMEM = "9k";
const char GAME_11_DATE[] PROGMEM = "2025-03-29";
const char GAME_11_BLACK[] PROGMEM = "getgoing";
const char GAME_11_WHITE[] PROGMEM = "djanatyn";
const char GAME_11_BLACK_RANK[] PROGMEM = "15k";
const char GAME_11_WHITE_RANK[] PROGMEM = "14k";
const char GAME_12_DATE[] PROGMEM = "2020-01-18";
const char GAME_12_BLACK[] PROGMEM = "just maybe";
const char GAME_12_WHITE[] PROGMEM = "djanatyn";
const char GAME_12_BLACK_RANK[] PROGMEM = "10k";
const char GAME_12_WHITE_RANK[] PROGMEM = "9k";
const char GAME_13_DATE[] PROGMEM = "2017-11-16";
const char GAME_13_BLACK[] PROGMEM = "sungmoon";
const char GAME_13_WHITE[] PROGMEM = "djanatyn";
const char GAME_13_BLACK_RANK[] PROGMEM = "13k";
const char GAME_13_WHITE_RANK[] PROGMEM = "11k";
const char GAME_14_DATE[] PROGMEM = "2018-03-15";
const char GAME_14_BLACK[] PROGMEM = "djanatyn";
const char GAME_14_WHITE[] PROGMEM = "rafael.auriemo";
const char GAME_14_BLACK_RANK[] PROGMEM = "9k";
const char GAME_14_WHITE_RANK[] PROGMEM = "?";
const char GAME_15_DATE[] PROGMEM = "2022-12-30";
const char GAME_15_BLACK[] PROGMEM = "manom";
const char GAME_15_WHITE[] PROGMEM = "djanatyn";
const char GAME_15_BLACK_RANK[] PROGMEM = "8k";
const char GAME_15_WHITE_RANK[] PROGMEM = "10k";
const char GAME_16_DATE[] PROGMEM = "2017-09-28";
const char GAME_16_BLACK[] PROGMEM = "djanatyn";
const char GAME_16_WHITE[] PROGMEM = "aliebling";
const char GAME_16_BLACK_RANK[] PROGMEM = "11k";
const char GAME_16_WHITE_RANK[] PROGMEM = "10k";
const char GAME_17_DATE[] PROGMEM = "2019-10-17";
const char GAME_17_BLACK[] PROGMEM = "phuctoan1507";
const char GAME_17_WHITE[] PROGMEM = "djanatyn";
const char GAME_17_BLACK_RANK[] PROGMEM = "9k";
const char GAME_17_WHITE_RANK[] PROGMEM = "10k";
const char GAME_18_DATE[] PROGMEM = "2018-10-08";
const char GAME_18_BLACK[] PROGMEM = "MayuPandoraNoda";
const char GAME_18_WHITE[] PROGMEM = "djanatyn";
const char GAME_18_BLACK_RANK[] PROGMEM = "8k";
const char GAME_18_WHITE_RANK[] PROGMEM = "7k";
const char GAME_19_DATE[] PROGMEM = "2020-04-19";
const char GAME_19_BLACK[] PROGMEM = "CnH2n2";
const char GAME_19_WHITE[] PROGMEM = "djanatyn";
const char GAME_19_BLACK_RANK[] PROGMEM = "10k";
const char GAME_19_WHITE_RANK[] PROGMEM = "9k";
const char GAME_20_DATE[] PROGMEM = "2019-11-17";
const char GAME_20_BLACK[] PROGMEM = "djanatyn";
const char GAME_20_WHITE[] PROGMEM = "dubble_a_ron";
const char GAME_20_BLACK_RANK[] PROGMEM = "9k";
const char GAME_20_WHITE_RANK[] PROGMEM = "9k";
const char GAME_21_DATE[] PROGMEM = "2017-05-29";
const char GAME_21_BLACK[] PROGMEM = "GnuGo";
const char GAME_21_WHITE[] PROGMEM = "djanatyn";
const char GAME_21_BLACK_RANK[] PROGMEM = "3k";
const char GAME_21_WHITE_RANK[] PROGMEM = "?";
const char GAME_22_DATE[] PROGMEM = "2019-10-10";
const char GAME_22_BLACK[] PROGMEM = "djanatyn";
const char GAME_22_WHITE[] PROGMEM = "luckygohappy";
const char GAME_22_BLACK_RANK[] PROGMEM = "9k";
const char GAME_22_WHITE_RANK[] PROGMEM = "10k";
const char GAME_23_DATE[] PROGMEM = "2018-07-17";
const char GAME_23_BLACK[] PROGMEM = "aliebling";
const char GAME_23_WHITE[] PROGMEM = "djanatyn";
const char GAME_23_BLACK_RANK[] PROGMEM = "7k";
const char GAME_23_WHITE_RANK[] PROGMEM = "7k";
const char GAME_24_DATE[] PROGMEM = "2018-02-09";
const char GAME_24_BLACK[] PROGMEM = "djanatyn";
const char GAME_24_WHITE[] PROGMEM = "schuun168";
const char GAME_24_BLACK_RANK[] PROGMEM = "10k";
const char GAME_24_WHITE_RANK[] PROGMEM = "11k";
const char GAME_25_DATE[] PROGMEM = "2019-06-12";
const char GAME_25_BLACK[] PROGMEM = "djanatyn";
const char GAME_25_WHITE[] PROGMEM = "TheSixth";
const char GAME_25_BLACK_RANK[] PROGMEM = "9k";
const char GAME_25_WHITE_RANK[] PROGMEM = "5k";
const char GAME_26_DATE[] PROGMEM = "2017-09-13";
const char GAME_26_BLACK[] PROGMEM = "djanatyn";
const char GAME_26_WHITE[] PROGMEM = "Tatapaulette";
const char GAME_26_BLACK_RANK[] PROGMEM = "14k";
const char GAME_26_WHITE_RANK[] PROGMEM = "4k";
const char GAME_27_DATE[] PROGMEM = "2023-02-11";
const char GAME_27_BLACK[] PROGMEM = "milkri";
const char GAME_27_WHITE[] PROGMEM = "djanatyn";
const char GAME_27_BLACK_RANK[] PROGMEM = "7k";
const char GAME_27_WHITE_RANK[] PROGMEM = "9k";
const char GAME_28_DATE[] PROGMEM = "2018-11-26";
const char GAME_28_BLACK[] PROGMEM = "Rey Feroz";
const char GAME_28_WHITE[] PROGMEM = "djanatyn";
const char GAME_28_BLACK_RANK[] PROGMEM = "11k";
const char GAME_28_WHITE_RANK[] PROGMEM = "9k";
const char GAME_29_DATE[] PROGMEM = "2018-10-22";
const char GAME_29_BLACK[] PROGMEM = "djanatyn";
const char GAME_29_WHITE[] PROGMEM = "Babyacapulco69";
const char GAME_29_BLACK_RANK[] PROGMEM = "8k";
const char GAME_29_WHITE_RANK[] PROGMEM = "9k";
const char GAME_30_DATE[] PROGMEM = "2018-11-27";
const char GAME_30_BLACK[] PROGMEM = "bvdkki";
const char GAME_30_WHITE[] PROGMEM = "djanatyn";
const char GAME_30_BLACK_RANK[] PROGMEM = "8k";
const char GAME_30_WHITE_RANK[] PROGMEM = "8k";
const char GAME_31_DATE[] PROGMEM = "2020-11-28";
const char GAME_31_BLACK[] PROGMEM = "djanatyn";
const char GAME_31_WHITE[] PROGMEM = "will1951";
const char GAME_31_BLACK_RANK[] PROGMEM = "11k";
const char GAME_31_WHITE_RANK[] PROGMEM = "12k";
const char GAME_32_DATE[] PROGMEM = "2023-03-17";
const char GAME_32_BLACK[] PROGMEM = "william2015";
const char GAME_32_WHITE[] PROGMEM = "djanatyn";
const char GAME_32_BLACK_RANK[] PROGMEM = "14k";
const char GAME_32_WHITE_RANK[] PROGMEM = "10k";
const char GAME_33_DATE[] PROGMEM = "2018-02-14";
const char GAME_33_BLACK[] PROGMEM = "arstneio";
const char GAME_33_WHITE[] PROGMEM = "djanatyn";
const char GAME_33_BLACK_RANK[] PROGMEM = "11k";
const char GAME_33_WHITE_RANK[] PROGMEM = "10k";
const char GAME_34_DATE[] PROGMEM = "2018-03-19";
const char GAME_34_BLACK[] PROGMEM = "Arbitraria";
const char GAME_34_WHITE[] PROGMEM = "djanatyn";
const char GAME_34_BLACK_RANK[] PROGMEM = "5k";
const char GAME_34_WHITE_RANK[] PROGMEM = "10k";
const char GAME_35_DATE[] PROGMEM = "2018-01-20";
const char GAME_35_BLACK[] PROGMEM = "tuhan";
const char GAME_35_WHITE[] PROGMEM = "djanatyn";
const char GAME_35_BLACK_RANK[] PROGMEM = "13k";
const char GAME_35_WHITE_RANK[] PROGMEM = "10k";
const char GAME_36_DATE[] PROGMEM = "2017-08-08";
const char GAME_36_BLACK[] PROGMEM = "tilax";
const char GAME_36_WHITE[] PROGMEM = "djanatyn";
const char GAME_36_BLACK_RANK[] PROGMEM = "17k";
const char GAME_36_WHITE_RANK[] PROGMEM = "10k";
const char GAME_37_DATE[] PROGMEM = "2019-04-26";
const char GAME_37_BLACK[] PROGMEM = "Tomaszovich";
const char GAME_37_WHITE[] PROGMEM = "djanatyn";
const char GAME_37_BLACK_RANK[] PROGMEM = "11k";
const char GAME_37_WHITE_RANK[] PROGMEM = "9k";
const char GAME_38_DATE[] PROGMEM = "2023-01-03";
const char GAME_38_BLACK[] PROGMEM = "tborri";
const char GAME_38_WHITE[] PROGMEM = "djanatyn";
const char GAME_38_BLACK_RANK[] PROGMEM = "10k";
const char GAME_38_WHITE_RANK[] PROGMEM = "10k";
const char GAME_39_DATE[] PROGMEM = "2018-03-18";
const char GAME_39_BLACK[] PROGMEM = "djanatyn";
const char GAME_39_WHITE[] PROGMEM = "ariosto.nen";
const char GAME_39_BLACK_RANK[] PROGMEM = "9k";
const char GAME_39_WHITE_RANK[] PROGMEM = "10k";
const char GAME_40_DATE[] PROGMEM = "2018-12-24";
const char GAME_40_BLACK[] PROGMEM = "djanatyn";
const char GAME_40_WHITE[] PROGMEM = "pulentoshorizo";
const char GAME_40_BLACK_RANK[] PROGMEM = "9k";
const char GAME_40_WHITE_RANK[] PROGMEM = "9k";
const char GAME_41_DATE[] PROGMEM = "2017-12-09";
const char GAME_41_BLACK[] PROGMEM = "djanatyn";
const char GAME_41_WHITE[] PROGMEM = "TheSplitHouse";
const char GAME_41_BLACK_RANK[] PROGMEM = "10k";
const char GAME_41_WHITE_RANK[] PROGMEM = "10k";
const char GAME_42_DATE[] PROGMEM = "2021-04-10";
const char GAME_42_BLACK[] PROGMEM = "Luxly";
const char GAME_42_WHITE[] PROGMEM = "djanatyn";
const char GAME_42_BLACK_RANK[] PROGMEM = "12k";
const char GAME_42_WHITE_RANK[] PROGMEM = "12k";
const char GAME_43_DATE[] PROGMEM = "2017-10-18";
const char GAME_43_BLACK[] PROGMEM = "djanatyn";
const char GAME_43_WHITE[] PROGMEM = "mozturk";
const char GAME_43_BLACK_RANK[] PROGMEM = "12k";
const char GAME_43_WHITE_RANK[] PROGMEM = "13k";
const char GAME_44_DATE[] PROGMEM = "2023-09-15";
const char GAME_44_BLACK[] PROGMEM = "djanatyn";
const char GAME_44_WHITE[] PROGMEM = "Blueclay";
const char GAME_44_BLACK_RANK[] PROGMEM = "11k";
const char GAME_44_WHITE_RANK[] PROGMEM = "11k";
const char GAME_45_DATE[] PROGMEM = "2020-04-22";
const char GAME_45_BLACK[] PROGMEM = "djanatyn";
const char GAME_45_WHITE[] PROGMEM = "go888";
const char GAME_45_BLACK_RANK[] PROGMEM = "9k";
const char GAME_45_WHITE_RANK[] PROGMEM = "8k";
const char GAME_46_DATE[] PROGMEM = "2019-09-24";
const char GAME_46_BLACK[] PROGMEM = "djanatyn";
const char GAME_46_WHITE[] PROGMEM = "tiger2018";
const char GAME_46_BLACK_RANK[] PROGMEM = "9k";
const char GAME_46_WHITE_RANK[] PROGMEM = "8k";
const char GAME_47_DATE[] PROGMEM = "2018-01-20";
const char GAME_47_BLACK[] PROGMEM = "RoninMiyamotoMusashi";
const char GAME_47_WHITE[] PROGMEM = "djanatyn";
const char GAME_47_BLACK_RANK[] PROGMEM = "11k";
const char GAME_47_WHITE_RANK[] PROGMEM = "10k";
const char GAME_48_DATE[] PROGMEM = "2023-09-15";
const char GAME_48_BLACK[] PROGMEM = "Bobbybobsonjr";
const char GAME_48_WHITE[] PROGMEM = "djanatyn";
const char GAME_48_BLACK_RANK[] PROGMEM = "12k";
const char GAME_48_WHITE_RANK[] PROGMEM = "11k";
const char GAME_49_DATE[] PROGMEM = "2023-03-18";
const char GAME_49_BLACK[] PROGMEM = "jinkim";
const char GAME_49_WHITE[] PROGMEM = "djanatyn";
const char GAME_49_BLACK_RANK[] PROGMEM = "6k";
const char GAME_49_WHITE_RANK[] PROGMEM = "10k";

// Metadata array
const GameMetadata GAMES_METADATA[] PROGMEM = {
    { GAME_0_DATE, GAME_0_BLACK, GAME_0_WHITE, GAME_0_BLACK_RANK, GAME_0_WHITE_RANK },
    { GAME_1_DATE, GAME_1_BLACK, GAME_1_WHITE, GAME_1_BLACK_RANK, GAME_1_WHITE_RANK },
    { GAME_2_DATE, GAME_2_BLACK, GAME_2_WHITE, GAME_2_BLACK_RANK, GAME_2_WHITE_RANK },
    { GAME_3_DATE, GAME_3_BLACK, GAME_3_WHITE, GAME_3_BLACK_RANK, GAME_3_WHITE_RANK },
    { GAME_4_DATE, GAME_4_BLACK, GAME_4_WHITE, GAME_4_BLACK_RANK, GAME_4_WHITE_RANK },
    { GAME_5_DATE, GAME_5_BLACK, GAME_5_WHITE, GAME_5_BLACK_RANK, GAME_5_WHITE_RANK },
    { GAME_6_DATE, GAME_6_BLACK, GAME_6_WHITE, GAME_6_BLACK_RANK, GAME_6_WHITE_RANK },
    { GAME_7_DATE, GAME_7_BLACK, GAME_7_WHITE, GAME_7_BLACK_RANK, GAME_7_WHITE_RANK },
    { GAME_8_DATE, GAME_8_BLACK, GAME_8_WHITE, GAME_8_BLACK_RANK, GAME_8_WHITE_RANK },
    { GAME_9_DATE, GAME_9_BLACK, GAME_9_WHITE, GAME_9_BLACK_RANK, GAME_9_WHITE_RANK },
    { GAME_10_DATE, GAME_10_BLACK, GAME_10_WHITE, GAME_10_BLACK_RANK, GAME_10_WHITE_RANK },
    { GAME_11_DATE, GAME_11_BLACK, GAME_11_WHITE, GAME_11_BLACK_RANK, GAME_11_WHITE_RANK },
    { GAME_12_DATE, GAME_12_BLACK, GAME_12_WHITE, GAME_12_BLACK_RANK, GAME_12_WHITE_RANK },
    { GAME_13_DATE, GAME_13_BLACK, GAME_13_WHITE, GAME_13_BLACK_RANK, GAME_13_WHITE_RANK },
    { GAME_14_DATE, GAME_14_BLACK, GAME_14_WHITE, GAME_14_BLACK_RANK, GAME_14_WHITE_RANK },
    { GAME_15_DATE, GAME_15_BLACK, GAME_15_WHITE, GAME_15_BLACK_RANK, GAME_15_WHITE_RANK },
    { GAME_16_DATE, GAME_16_BLACK, GAME_16_WHITE, GAME_16_BLACK_RANK, GAME_16_WHITE_RANK },
    { GAME_17_DATE, GAME_17_BLACK, GAME_17_WHITE, GAME_17_BLACK_RANK, GAME_17_WHITE_RANK },
    { GAME_18_DATE, GAME_18_BLACK, GAME_18_WHITE, GAME_18_BLACK_RANK, GAME_18_WHITE_RANK },
    { GAME_19_DATE, GAME_19_BLACK, GAME_19_WHITE, GAME_19_BLACK_RANK, GAME_19_WHITE_RANK },
    { GAME_20_DATE, GAME_20_BLACK, GAME_20_WHITE, GAME_20_BLACK_RANK, GAME_20_WHITE_RANK },
    { GAME_21_DATE, GAME_21_BLACK, GAME_21_WHITE, GAME_21_BLACK_RANK, GAME_21_WHITE_RANK },
    { GAME_22_DATE, GAME_22_BLACK, GAME_22_WHITE, GAME_22_BLACK_RANK, GAME_22_WHITE_RANK },
    { GAME_23_DATE, GAME_23_BLACK, GAME_23_WHITE, GAME_23_BLACK_RANK, GAME_23_WHITE_RANK },
    { GAME_24_DATE, GAME_24_BLACK, GAME_24_WHITE, GAME_24_BLACK_RANK, GAME_24_WHITE_RANK },
    { GAME_25_DATE, GAME_25_BLACK, GAME_25_WHITE, GAME_25_BLACK_RANK, GAME_25_WHITE_RANK },
    { GAME_26_DATE, GAME_26_BLACK, GAME_26_WHITE, GAME_26_BLACK_RANK, GAME_26_WHITE_RANK },
    { GAME_27_DATE, GAME_27_BLACK, GAME_27_WHITE, GAME_27_BLACK_RANK, GAME_27_WHITE_RANK },
    { GAME_28_DATE, GAME_28_BLACK, GAME_28_WHITE, GAME_28_BLACK_RANK, GAME_28_WHITE_RANK },
    { GAME_29_DATE, GAME_29_BLACK, GAME_29_WHITE, GAME_29_BLACK_RANK, GAME_29_WHITE_RANK },
    { GAME_30_DATE, GAME_30_BLACK, GAME_30_WHITE, GAME_30_BLACK_RANK, GAME_30_WHITE_RANK },
    { GAME_31_DATE, GAME_31_BLACK, GAME_31_WHITE, GAME_31_BLACK_RANK, GAME_31_WHITE_RANK },
    { GAME_32_DATE, GAME_32_BLACK, GAME_32_WHITE, GAME_32_BLACK_RANK, GAME_32_WHITE_RANK },
    { GAME_33_DATE, GAME_33_BLACK, GAME_33_WHITE, GAME_33_BLACK_RANK, GAME_33_WHITE_RANK },
    { GAME_34_DATE, GAME_34_BLACK, GAME_34_WHITE, GAME_34_BLACK_RANK, GAME_34_WHITE_RANK },
    { GAME_35_DATE, GAME_35_BLACK, GAME_35_WHITE, GAME_35_BLACK_RANK, GAME_35_WHITE_RANK },
    { GAME_36_DATE, GAME_36_BLACK, GAME_36_WHITE, GAME_36_BLACK_RANK, GAME_36_WHITE_RANK },
    { GAME_37_DATE, GAME_37_BLACK, GAME_37_WHITE, GAME_37_BLACK_RANK, GAME_37_WHITE_RANK },
    { GAME_38_DATE, GAME_38_BLACK, GAME_38_WHITE, GAME_38_BLACK_RANK, GAME_38_WHITE_RANK },
    { GAME_39_DATE, GAME_39_BLACK, GAME_39_WHITE, GAME_39_BLACK_RANK, GAME_39_WHITE_RANK },
    { GAME_40_DATE, GAME_40_BLACK, GAME_40_WHITE, GAME_40_BLACK_RANK, GAME_40_WHITE_RANK },
    { GAME_41_DATE, GAME_41_BLACK, GAME_41_WHITE, GAME_41_BLACK_RANK, GAME_41_WHITE_RANK },
    { GAME_42_DATE, GAME_42_BLACK, GAME_42_WHITE, GAME_42_BLACK_RANK, GAME_42_WHITE_RANK },
    { GAME_43_DATE, GAME_43_BLACK, GAME_43_WHITE, GAME_43_BLACK_RANK, GAME_43_WHITE_RANK },
    { GAME_44_DATE, GAME_44_BLACK, GAME_44_WHITE, GAME_44_BLACK_RANK, GAME_44_WHITE_RANK },
    { GAME_45_DATE, GAME_45_BLACK, GAME_45_WHITE, GAME_45_BLACK_RANK, GAME_45_WHITE_RANK },
    { GAME_46_DATE, GAME_46_BLACK, GAME_46_WHITE, GAME_46_BLACK_RANK, GAME_46_WHITE_RANK },
    { GAME_47_DATE, GAME_47_BLACK, GAME_47_WHITE, GAME_47_BLACK_RANK, GAME_47_WHITE_RANK },
    { GAME_48_DATE, GAME_48_BLACK, GAME_48_WHITE, GAME_48_BLACK_RANK, GAME_48_WHITE_RANK },
    { GAME_49_DATE, GAME_49_BLACK, GAME_49_WHITE, GAME_49_BLACK_RANK, GAME_49_WHITE_RANK },
};

#endif
