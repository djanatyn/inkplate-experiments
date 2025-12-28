#ifndef EVENTS_DATA_H
#define EVENTS_DATA_H

#include <Arduino.h>

// Number of astronomical events
const uint16_t ASTRO_EVENT_COUNT = 410;

// Event dates (month, day)
struct AstroEventDate {
    uint32_t year;
    uint8_t month;
    uint8_t day;
};

const AstroEventDate ASTRO_EVENTS[] PROGMEM = {
    {2025, 1, 3},  // 2025/1/3: Conjunction of the Moon and Venus
    {2025, 1, 3},  // 2025/1/3: Quadrantid meteor shower 2025
    {2025, 1, 3},  // 2025/1/3: Close approach of the Moon and Venus
    {2025, 1, 4},  // 2025/1/4: The Earth at perihelion
    {2025, 1, 4},  // 2025/1/4: Close approach of the Moon and Saturn
    {2025, 1, 4},  // 2025/1/4: Conjunction of the Moon and Saturn
    {2025, 1, 6},  // 2025/1/6: Moon at First Quarter
    {2025, 1, 10},  // 2025/1/10: Close approach of the Moon and M45
    {2025, 1, 10},  // 2025/1/10: Venus at greatest elongation east
    {2025, 1, 10},  // 2025/1/10: Close approach of the Moon and Jupiter
    {2025, 1, 10},  // 2025/1/10: Conjunction of the Moon and Jupiter
    {2025, 1, 12},  // 2025/1/12: Venus at dichotomy
    {2025, 1, 12},  // 2025/1/12: Mars at perigee
    {2025, 1, 13},  // 2025/1/13: Comet C/2024 G3 (ATLAS) passes perigee
    {2025, 1, 13},  // 2025/1/13: Comet C/2024 G3 (ATLAS) passes perihelion
    {2025, 1, 13},  // 2025/1/13: Full Moon
    {2025, 1, 14},  // 2025/1/14: Conjunction of the Moon and Mars
    {2025, 1, 14},  // 2025/1/14: Close approach of the Moon and Mars
    {2025, 1, 16},  // 2025/1/16: Mars at opposition
    {2025, 1, 18},  // 2025/1/18: Close approach of Venus and Saturn
    {2025, 1, 19},  // 2025/1/19: γ-Ursae Minorid meteor shower 2025
    {2025, 1, 20},  // 2025/1/20: Conjunction of Venus and Saturn
    {2025, 1, 21},  // 2025/1/21: Moon at Last Quarter
    {2025, 2, 1},  // 2025/2/1: Conjunction of the Moon and Venus
    {2025, 2, 1},  // 2025/2/1: Close approach of the Moon and Venus
    {2025, 2, 2},  // 2025/2/2: Venus at highest altitude in evening sky
    {2025, 2, 4},  // 2025/2/4: Jupiter ends retrograde motion
    {2025, 2, 5},  // 2025/2/5: Moon at First Quarter
    {2025, 2, 6},  // 2025/2/6: Close approach of the Moon and M45
    {2025, 2, 7},  // 2025/2/7: Close approach of the Moon and Jupiter
    {2025, 2, 7},  // 2025/2/7: Conjunction of the Moon and Jupiter
    {2025, 2, 9},  // 2025/2/9: Conjunction of the Moon and Mars
    {2025, 2, 9},  // 2025/2/9: Close approach of the Moon and Mars
    {2025, 2, 12},  // 2025/2/12: Full Moon
    {2025, 2, 16},  // 2025/2/16: Venus at greatest brightness
    {2025, 2, 20},  // 2025/2/20: Moon at Last Quarter
    {2025, 2, 24},  // 2025/2/24: Mars ends retrograde motion
    {2025, 3, 1},  // 2025/3/1: Conjunction of the Moon and Venus
    {2025, 3, 5},  // 2025/3/5: Close approach of the Moon and M45
    {2025, 3, 6},  // 2025/3/6: Close approach of the Moon and Jupiter
    {2025, 3, 6},  // 2025/3/6: Conjunction of the Moon and Jupiter
    {2025, 3, 6},  // 2025/3/6: Moon at First Quarter
    {2025, 3, 7},  // 2025/3/7: Mercury at dichotomy
    {2025, 3, 8},  // 2025/3/8: Mercury at highest altitude in evening sky
    {2025, 3, 8},  // 2025/3/8: Mercury at greatest elongation east
    {2025, 3, 9},  // 2025/3/9: Conjunction of the Moon and Mars
    {2025, 3, 9},  // 2025/3/9: Close approach of the Moon and Mars
    {2025, 3, 14},  // 2025/3/14: Full Moon
    {2025, 3, 14},  // 2025/3/14: Total lunar eclipse
    {2025, 3, 20},  // 2025/3/20: March equinox
    {2025, 3, 22},  // 2025/3/22: Moon at Last Quarter
    {2025, 3, 23},  // 2025/3/23: Saturn ring plane crossing
    {2025, 3, 29},  // 2025/3/29: Partial solar eclipse
    {2025, 4, 1},  // 2025/4/1: Close approach of the Moon and M45
    {2025, 4, 2},  // 2025/4/2: Close approach of the Moon and Jupiter
    {2025, 4, 3},  // 2025/4/3: Conjunction of the Moon and Jupiter
    {2025, 4, 5},  // 2025/4/5: Moon at First Quarter
    {2025, 4, 5},  // 2025/4/5: Conjunction of the Moon and Mars
    {2025, 4, 5},  // 2025/4/5: Close approach of the Moon and Mars
    {2025, 4, 13},  // 2025/4/13: Full Moon
    {2025, 4, 19},  // 2025/4/19: Mercury at highest altitude in morning sky
    {2025, 4, 21},  // 2025/4/21: Moon at Last Quarter
    {2025, 4, 21},  // 2025/4/21: Mercury at greatest elongation west
    {2025, 4, 22},  // 2025/4/22: Lyrid meteor shower 2025
    {2025, 4, 23},  // 2025/4/23: π-Puppid meteor shower 2025
    {2025, 4, 24},  // 2025/4/24: Venus at greatest brightness
    {2025, 4, 24},  // 2025/4/24: Mercury at dichotomy
    {2025, 4, 25},  // 2025/4/25: Conjunction of the Moon and Venus
    {2025, 4, 25},  // 2025/4/25: Close approach of the Moon and Saturn
    {2025, 4, 25},  // 2025/4/25: Close approach of the Moon and Venus
    {2025, 4, 25},  // 2025/4/25: Conjunction of the Moon and Saturn
    {2025, 4, 28},  // 2025/4/28: Close approach of Venus, Saturn and Neptune
    {2025, 4, 29},  // 2025/4/29: Conjunction of Venus and Saturn
    {2025, 4, 30},  // 2025/4/30: Close approach of the Moon and Jupiter
    {2025, 4, 30},  // 2025/4/30: Conjunction of the Moon and Jupiter
    {2025, 5, 3},  // 2025/5/3: Conjunction of the Moon and Mars
    {2025, 5, 4},  // 2025/5/4: Close approach of the Moon and Mars
    {2025, 5, 4},  // 2025/5/4: Moon at First Quarter
    {2025, 5, 6},  // 2025/5/6: η-Aquariid meteor shower 2025
    {2025, 5, 6},  // 2025/5/6: Equinox on Saturn
    {2025, 5, 8},  // 2025/5/8: η-Lyrid meteor shower 2025
    {2025, 5, 12},  // 2025/5/12: Full Moon
    {2025, 5, 20},  // 2025/5/20: Moon at Last Quarter
    {2025, 5, 22},  // 2025/5/22: Close approach of the Moon and Saturn
    {2025, 5, 22},  // 2025/5/22: Conjunction of the Moon and Saturn
    {2025, 5, 23},  // 2025/5/23: Close approach of the Moon and Venus
    {2025, 5, 23},  // 2025/5/23: Conjunction of the Moon and Venus
    {2025, 5, 31},  // 2025/5/31: Venus at greatest elongation west
    {2025, 6, 1},  // 2025/6/1: Conjunction of the Moon and Mars
    {2025, 6, 1},  // 2025/6/1: Close approach of the Moon and Mars
    {2025, 6, 1},  // 2025/6/1: Venus at dichotomy
    {2025, 6, 3},  // 2025/6/3: Moon at First Quarter
    {2025, 6, 10},  // 2025/6/10: Daytime Arietid meteor shower 2025
    {2025, 6, 11},  // 2025/6/11: Full Moon
    {2025, 6, 18},  // 2025/6/18: Moon at Last Quarter
    {2025, 6, 19},  // 2025/6/19: Close approach of the Moon, Saturn and Neptune
    {2025, 6, 19},  // 2025/6/19: Conjunction of the Moon and Saturn
    {2025, 6, 21},  // 2025/6/21: June solstice
    {2025, 6, 22},  // 2025/6/22: Conjunction of the Moon and Venus
    {2025, 6, 26},  // 2025/6/26: Mercury at highest altitude in evening sky
    {2025, 6, 27},  // 2025/6/27: June Bootid meteor shower 2025
    {2025, 6, 28},  // 2025/6/28: Mercury at dichotomy
    {2025, 6, 30},  // 2025/6/30: Conjunction of the Moon and Mars
    {2025, 6, 30},  // 2025/6/30: Close approach of the Moon and Mars
    {2025, 7, 2},  // 2025/7/2: Moon at First Quarter
    {2025, 7, 3},  // 2025/7/3: The Earth at aphelion
    {2025, 7, 4},  // 2025/7/4: Mercury at greatest elongation east
    {2025, 7, 10},  // 2025/7/10: Full Moon
    {2025, 7, 13},  // 2025/7/13: Saturn enters retrograde motion
    {2025, 7, 16},  // 2025/7/16: Close approach of the Moon, Saturn and Neptune
    {2025, 7, 16},  // 2025/7/16: Conjunction of the Moon and Saturn
    {2025, 7, 18},  // 2025/7/18: Moon at Last Quarter
    {2025, 7, 20},  // 2025/7/20: Close approach of the Moon and M45
    {2025, 7, 21},  // 2025/7/21: Conjunction of the Moon and Venus
    {2025, 7, 28},  // 2025/7/28: Close approach of the Moon and Mars
    {2025, 7, 28},  // 2025/7/28: Conjunction of the Moon and Mars
    {2025, 7, 28},  // 2025/7/28: Piscis Austrinid meteor shower 2025
    {2025, 7, 30},  // 2025/7/30: Southern δ-Aquariid meteor shower 2025
    {2025, 7, 30},  // 2025/7/30: α-Capricornid meteor shower 2025
    {2025, 8, 1},  // 2025/8/1: Venus at highest altitude in morning sky
    {2025, 8, 1},  // 2025/8/1: Moon at First Quarter
    {2025, 8, 9},  // 2025/8/9: Full Moon
    {2025, 8, 12},  // 2025/8/12: Close approach of Venus and Jupiter
    {2025, 8, 12},  // 2025/8/12: Conjunction of Venus and Jupiter
    {2025, 8, 12},  // 2025/8/12: Close approach of the Moon, Saturn and Neptune
    {2025, 8, 12},  // 2025/8/12: Conjunction of the Moon and Saturn
    {2025, 8, 12},  // 2025/8/12: Perseid meteor shower 2025
    {2025, 8, 16},  // 2025/8/16: Moon at Last Quarter
    {2025, 8, 16},  // 2025/8/16: Close approach of the Moon and M45
    {2025, 8, 18},  // 2025/8/18: κ-Cygnid meteor shower 2025
    {2025, 8, 19},  // 2025/8/19: Mercury at greatest elongation west
    {2025, 8, 19},  // 2025/8/19: Conjunction of the Moon and Jupiter
    {2025, 8, 19},  // 2025/8/19: Close approach of the Moon and Jupiter
    {2025, 8, 20},  // 2025/8/20: Conjunction of the Moon and Venus
    {2025, 8, 21},  // 2025/8/21: Mercury at highest altitude in morning sky
    {2025, 8, 21},  // 2025/8/21: Mercury at dichotomy
    {2025, 8, 26},  // 2025/8/26: Close approach of the Moon and Mars
    {2025, 8, 26},  // 2025/8/26: Conjunction of the Moon and Mars
    {2025, 8, 31},  // 2025/8/31: Moon at First Quarter
    {2025, 9, 1},  // 2025/9/1: Aurigid meteor shower 2025
    {2025, 9, 7},  // 2025/9/7: Full Moon
    {2025, 9, 7},  // 2025/9/7: Total lunar eclipse
    {2025, 9, 8},  // 2025/9/8: Close approach of the Moon, Saturn and Neptune
    {2025, 9, 8},  // 2025/9/8: Conjunction of the Moon and Saturn
    {2025, 9, 9},  // 2025/9/9: September ε-Perseid meteor shower 2025
    {2025, 9, 12},  // 2025/9/12: Close approach of the Moon and M45
    {2025, 9, 14},  // 2025/9/14: Moon at Last Quarter
    {2025, 9, 16},  // 2025/9/16: Conjunction of the Moon and Jupiter
    {2025, 9, 16},  // 2025/9/16: Close approach of the Moon and Jupiter
    {2025, 9, 21},  // 2025/9/21: Saturn at opposition
    {2025, 9, 21},  // 2025/9/21: Partial solar eclipse
    {2025, 9, 22},  // 2025/9/22: September equinox
    {2025, 9, 27},  // 2025/9/27: Daytime Sextantid meteor shower 2025
    {2025, 9, 29},  // 2025/9/29: Moon at First Quarter
    {2025, 10, 5},  // 2025/10/5: October Camelopardalid meteor shower 2025
    {2025, 10, 5},  // 2025/10/5: Close approach of the Moon and Saturn
    {2025, 10, 6},  // 2025/10/6: Conjunction of the Moon and Saturn
    {2025, 10, 7},  // 2025/10/7: Full Moon
    {2025, 10, 8},  // 2025/10/8: Draconid meteor shower 2025
    {2025, 10, 10},  // 2025/10/10: Close approach of the Moon and M45
    {2025, 10, 10},  // 2025/10/10: Southern Taurid meteor shower 2025
    {2025, 10, 11},  // 2025/10/11: δ-Aurigid meteor shower 2025
    {2025, 10, 13},  // 2025/10/13: Moon at Last Quarter
    {2025, 10, 13},  // 2025/10/13: Conjunction of the Moon and Jupiter
    {2025, 10, 14},  // 2025/10/14: Close approach of the Moon and Jupiter
    {2025, 10, 18},  // 2025/10/18: ε-Geminid meteor shower 2025
    {2025, 10, 21},  // 2025/10/21: Orionid meteor shower 2025
    {2025, 10, 24},  // 2025/10/24: Leonis Minorid meteor shower 2025
    {2025, 10, 29},  // 2025/10/29: Moon at First Quarter
    {2025, 10, 29},  // 2025/10/29: Mercury at greatest elongation east
    {2025, 11, 1},  // 2025/11/1: Mercury at highest altitude in evening sky
    {2025, 11, 2},  // 2025/11/2: Close approach of the Moon and Saturn
    {2025, 11, 2},  // 2025/11/2: Conjunction of the Moon and Saturn
    {2025, 11, 4},  // 2025/11/4: Mercury at dichotomy
    {2025, 11, 5},  // 2025/11/5: Full Moon
    {2025, 11, 6},  // 2025/11/6: Close approach of the Moon and M45
    {2025, 11, 10},  // 2025/11/10: Conjunction of the Moon and Jupiter
    {2025, 11, 10},  // 2025/11/10: Close approach of the Moon and Jupiter
    {2025, 11, 11},  // 2025/11/11: Jupiter enters retrograde motion
    {2025, 11, 12},  // 2025/11/12: Moon at Last Quarter
    {2025, 11, 12},  // 2025/11/12: Northern Taurid meteor shower 2025
    {2025, 11, 17},  // 2025/11/17: Leonid meteor shower 2025
    {2025, 11, 17},  // 2025/11/17: The Pleiades cluster is well placed
    {2025, 11, 21},  // 2025/11/21: α-Monocerotid meteor shower 2025
    {2025, 11, 27},  // 2025/11/27: The Hyades cluster is well placed
    {2025, 11, 28},  // 2025/11/28: Saturn ends retrograde motion
    {2025, 11, 28},  // 2025/11/28: Moon at First Quarter
    {2025, 11, 28},  // 2025/11/28: November Orionid meteor shower 2025
    {2025, 11, 29},  // 2025/11/29: Close approach of the Moon and Saturn
    {2025, 11, 29},  // 2025/11/29: Conjunction of the Moon and Saturn
    {2025, 12, 4},  // 2025/12/4: Close approach of the Moon and M45
    {2025, 12, 4},  // 2025/12/4: Mercury at dichotomy
    {2025, 12, 4},  // 2025/12/4: Full Moon
    {2025, 12, 6},  // 2025/12/6: December φ-Cassiopeid meteor shower 2025
    {2025, 12, 6},  // 2025/12/6: Mercury at highest altitude in morning sky
    {2025, 12, 7},  // 2025/12/7: Puppid-Velid meteor shower 2025
    {2025, 12, 7},  // 2025/12/7: Conjunction of the Moon and Jupiter
    {2025, 12, 7},  // 2025/12/7: Close approach of the Moon and Jupiter
    {2025, 12, 8},  // 2025/12/8: Mercury at greatest elongation west
    {2025, 12, 9},  // 2025/12/9: Monocerotid meteor shower 2025
    {2025, 12, 11},  // 2025/12/11: Moon at Last Quarter
    {2025, 12, 12},  // 2025/12/12: σ-Hydrid meteor shower 2025
    {2025, 12, 14},  // 2025/12/14: Geminid meteor shower 2025
    {2025, 12, 16},  // 2025/12/16: Comae Berenicid meteor shower 2025
    {2025, 12, 20},  // 2025/12/20: December Leonis Minorid meteor shower 2025
    {2025, 12, 21},  // 2025/12/21: December solstice
    {2025, 12, 22},  // 2025/12/22: Ursid meteor shower 2025
    {2025, 12, 27},  // 2025/12/27: Close approach of the Moon and Saturn
    {2025, 12, 27},  // 2025/12/27: Conjunction of the Moon and Saturn
    {2025, 12, 27},  // 2025/12/27: Moon at First Quarter
    {2025, 12, 31},  // 2025/12/31: Close approach of the Moon and M45
    {2026, 1, 3},  // 2026/1/3: Full Moon
    {2026, 1, 3},  // 2026/1/3: The Earth at perihelion
    {2026, 1, 3},  // 2026/1/3: Conjunction of the Moon and Jupiter
    {2026, 1, 3},  // 2026/1/3: Quadrantid meteor shower 2026
    {2026, 1, 3},  // 2026/1/3: Close approach of the Moon and Jupiter
    {2026, 1, 9},  // 2026/1/9: Jupiter at perigee
    {2026, 1, 10},  // 2026/1/10: Jupiter at opposition
    {2026, 1, 10},  // 2026/1/10: Moon at Last Quarter
    {2026, 1, 19},  // 2026/1/19: γ-Ursae Minorid meteor shower 2026
    {2026, 1, 23},  // 2026/1/23: Close approach of the Moon, Saturn and Neptune
    {2026, 1, 23},  // 2026/1/23: Conjunction of the Moon and Saturn
    {2026, 1, 26},  // 2026/1/26: Moon at First Quarter
    {2026, 1, 27},  // 2026/1/27: Close approach of the Moon and M45
    {2026, 1, 31},  // 2026/1/31: Conjunction of the Moon and Jupiter
    {2026, 1, 31},  // 2026/1/31: Close approach of the Moon and Jupiter
    {2026, 2, 1},  // 2026/2/1: Full Moon
    {2026, 2, 9},  // 2026/2/9: Moon at Last Quarter
    {2026, 2, 17},  // 2026/2/17: Annular solar eclipse
    {2026, 2, 19},  // 2026/2/19: Mercury at greatest elongation east
    {2026, 2, 19},  // 2026/2/19: Mercury at dichotomy
    {2026, 2, 20},  // 2026/2/20: Mercury at highest altitude in evening sky
    {2026, 2, 24},  // 2026/2/24: Close approach of the Moon and M45
    {2026, 2, 24},  // 2026/2/24: Moon at First Quarter
    {2026, 2, 27},  // 2026/2/27: Conjunction of the Moon and Jupiter
    {2026, 2, 27},  // 2026/2/27: Close approach of the Moon and Jupiter
    {2026, 3, 3},  // 2026/3/3: Total lunar eclipse
    {2026, 3, 3},  // 2026/3/3: Full Moon
    {2026, 3, 11},  // 2026/3/11: Jupiter ends retrograde motion
    {2026, 3, 11},  // 2026/3/11: Moon at Last Quarter
    {2026, 3, 20},  // 2026/3/20: March equinox
    {2026, 3, 23},  // 2026/3/23: Close approach of the Moon and M45
    {2026, 3, 25},  // 2026/3/25: Moon at First Quarter
    {2026, 3, 26},  // 2026/3/26: Conjunction of the Moon and Jupiter
    {2026, 3, 26},  // 2026/3/26: Close approach of the Moon and Jupiter
    {2026, 3, 27},  // 2026/3/27: Mercury at highest altitude in morning sky
    {2026, 4, 2},  // 2026/4/2: Full Moon
    {2026, 4, 3},  // 2026/4/3: Mercury at greatest elongation west
    {2026, 4, 3},  // 2026/4/3: Mercury at dichotomy
    {2026, 4, 10},  // 2026/4/10: Moon at Last Quarter
    {2026, 4, 22},  // 2026/4/22: Lyrid meteor shower 2026
    {2026, 4, 22},  // 2026/4/22: Conjunction of the Moon and Jupiter
    {2026, 4, 22},  // 2026/4/22: Close approach of the Moon and Jupiter
    {2026, 4, 24},  // 2026/4/24: π-Puppid meteor shower 2026
    {2026, 4, 24},  // 2026/4/24: Moon at First Quarter
    {2026, 5, 1},  // 2026/5/1: Full Moon
    {2026, 5, 6},  // 2026/5/6: η-Aquariid meteor shower 2026
    {2026, 5, 8},  // 2026/5/8: η-Lyrid meteor shower 2026
    {2026, 5, 9},  // 2026/5/9: Moon at Last Quarter
    {2026, 5, 13},  // 2026/5/13: Close approach of the Moon and Saturn
    {2026, 5, 13},  // 2026/5/13: Conjunction of the Moon and Saturn
    {2026, 5, 19},  // 2026/5/19: Conjunction of the Moon and Venus
    {2026, 5, 19},  // 2026/5/19: Close approach of the Moon and Venus
    {2026, 5, 20},  // 2026/5/20: Conjunction of the Moon and Jupiter
    {2026, 5, 20},  // 2026/5/20: Close approach of the Moon and Jupiter
    {2026, 5, 23},  // 2026/5/23: Moon at First Quarter
    {2026, 5, 31},  // 2026/5/31: Blue Moon
    {2026, 6, 5},  // 2026/6/5: Venus at highest altitude in evening sky
    {2026, 6, 8},  // 2026/6/8: Moon at Last Quarter
    {2026, 6, 9},  // 2026/6/9: Conjunction of Venus and Jupiter
    {2026, 6, 9},  // 2026/6/9: Close approach of Venus and Jupiter
    {2026, 6, 9},  // 2026/6/9: Mercury at dichotomy
    {2026, 6, 10},  // 2026/6/10: Close approach of the Moon and Saturn
    {2026, 6, 10},  // 2026/6/10: Conjunction of the Moon and Saturn
    {2026, 6, 10},  // 2026/6/10: Daytime Arietid meteor shower 2026
    {2026, 6, 10},  // 2026/6/10: Mercury at highest altitude in evening sky
    {2026, 6, 15},  // 2026/6/15: Mercury at greatest elongation east
    {2026, 6, 17},  // 2026/6/17: Conjunction of the Moon and Jupiter
    {2026, 6, 17},  // 2026/6/17: Close approach of the Moon and Jupiter
    {2026, 6, 17},  // 2026/6/17: Conjunction of the Moon and Venus
    {2026, 6, 17},  // 2026/6/17: Close approach of the Moon and Venus
    {2026, 6, 21},  // 2026/6/21: June solstice
    {2026, 6, 21},  // 2026/6/21: Moon at First Quarter
    {2026, 6, 27},  // 2026/6/27: June Bootid meteor shower 2026
    {2026, 6, 29},  // 2026/6/29: Full Moon
    {2026, 7, 6},  // 2026/7/6: The Earth at aphelion
    {2026, 7, 7},  // 2026/7/7: Close approach of the Moon and Saturn
    {2026, 7, 7},  // 2026/7/7: Moon at Last Quarter
    {2026, 7, 7},  // 2026/7/7: Conjunction of the Moon and Saturn
    {2026, 7, 10},  // 2026/7/10: Close approach of the Moon and M45
    {2026, 7, 11},  // 2026/7/11: Close approach of the Moon and Mars
    {2026, 7, 11},  // 2026/7/11: Conjunction of the Moon and Mars
    {2026, 7, 17},  // 2026/7/17: Close approach of the Moon and Venus
    {2026, 7, 17},  // 2026/7/17: Conjunction of the Moon and Venus
    {2026, 7, 21},  // 2026/7/21: Moon at First Quarter
    {2026, 7, 26},  // 2026/7/26: Saturn enters retrograde motion
    {2026, 7, 29},  // 2026/7/29: Piscis Austrinid meteor shower 2026
    {2026, 7, 29},  // 2026/7/29: Full Moon
    {2026, 7, 30},  // 2026/7/30: Southern δ-Aquariid meteor shower 2026
    {2026, 7, 30},  // 2026/7/30: α-Capricornid meteor shower 2026
    {2026, 8, 2},  // 2026/8/2: Mercury at greatest elongation west
    {2026, 8, 3},  // 2026/8/3: Close approach of the Moon and Saturn
    {2026, 8, 4},  // 2026/8/4: Conjunction of the Moon and Saturn
    {2026, 8, 5},  // 2026/8/5: Mercury at highest altitude in morning sky
    {2026, 8, 5},  // 2026/8/5: Mercury at dichotomy
    {2026, 8, 6},  // 2026/8/6: Moon at Last Quarter
    {2026, 8, 7},  // 2026/8/7: Close approach of the Moon and M45
    {2026, 8, 9},  // 2026/8/9: Conjunction of the Moon and Mars
    {2026, 8, 9},  // 2026/8/9: Close approach of the Moon and Mars
    {2026, 8, 12},  // 2026/8/12: Total solar eclipse
    {2026, 8, 12},  // 2026/8/12: Venus at dichotomy
    {2026, 8, 13},  // 2026/8/13: Perseid meteor shower 2026
    {2026, 8, 14},  // 2026/8/14: Venus at greatest elongation east
    {2026, 8, 16},  // 2026/8/16: Close approach of the Moon and Venus
    {2026, 8, 16},  // 2026/8/16: Conjunction of the Moon and Venus
    {2026, 8, 18},  // 2026/8/18: κ-Cygnid meteor shower 2026
    {2026, 8, 20},  // 2026/8/20: Moon at First Quarter
    {2026, 8, 28},  // 2026/8/28: Partial lunar eclipse
    {2026, 8, 28},  // 2026/8/28: Full Moon
    {2026, 8, 31},  // 2026/8/31: Close approach of the Moon and Saturn
    {2026, 8, 31},  // 2026/8/31: Conjunction of the Moon and Saturn
    {2026, 9, 1},  // 2026/9/1: Aurigid meteor shower 2026
    {2026, 9, 3},  // 2026/9/3: Close approach of the Moon and M45
    {2026, 9, 4},  // 2026/9/4: Moon at Last Quarter
    {2026, 9, 6},  // 2026/9/6: Conjunction of the Moon and Mars
    {2026, 9, 6},  // 2026/9/6: Close approach of the Moon and Mars
    {2026, 9, 8},  // 2026/9/8: Conjunction of the Moon and Jupiter
    {2026, 9, 8},  // 2026/9/8: Close approach of the Moon and Jupiter
    {2026, 9, 9},  // 2026/9/9: September ε-Perseid meteor shower 2026
    {2026, 9, 14},  // 2026/9/14: Conjunction of the Moon and Venus
    {2026, 9, 14},  // 2026/9/14: Close approach of the Moon and Venus
    {2026, 9, 18},  // 2026/9/18: Moon at First Quarter
    {2026, 9, 22},  // 2026/9/22: Venus at greatest brightness
    {2026, 9, 23},  // 2026/9/23: September equinox
    {2026, 9, 26},  // 2026/9/26: Full Moon
    {2026, 9, 27},  // 2026/9/27: Close approach of the Moon and Saturn
    {2026, 9, 27},  // 2026/9/27: Conjunction of the Moon and Saturn
    {2026, 9, 27},  // 2026/9/27: Daytime Sextantid meteor shower 2026
    {2026, 9, 30},  // 2026/9/30: Close approach of the Moon and M45
    {2026, 10, 3},  // 2026/10/3: Moon at Last Quarter
    {2026, 10, 4},  // 2026/10/4: Saturn at opposition
    {2026, 10, 5},  // 2026/10/5: Conjunction of the Moon and Mars
    {2026, 10, 5},  // 2026/10/5: Close approach of the Moon and Mars
    {2026, 10, 6},  // 2026/10/6: October Camelopardalid meteor shower 2026
    {2026, 10, 6},  // 2026/10/6: Conjunction of the Moon and Jupiter
    {2026, 10, 6},  // 2026/10/6: Close approach of the Moon and Jupiter
    {2026, 10, 8},  // 2026/10/8: Mercury at highest altitude in evening sky
    {2026, 10, 9},  // 2026/10/9: Draconid meteor shower 2026
    {2026, 10, 10},  // 2026/10/10: Southern Taurid meteor shower 2026
    {2026, 10, 11},  // 2026/10/11: δ-Aurigid meteor shower 2026
    {2026, 10, 12},  // 2026/10/12: Mercury at greatest elongation east
    {2026, 10, 17},  // 2026/10/17: Mercury at dichotomy
    {2026, 10, 18},  // 2026/10/18: Moon at First Quarter
    {2026, 10, 18},  // 2026/10/18: ε-Geminid meteor shower 2026
    {2026, 10, 21},  // 2026/10/21: Orionid meteor shower 2026
    {2026, 10, 24},  // 2026/10/24: Close approach of the Moon and Saturn
    {2026, 10, 24},  // 2026/10/24: Conjunction of the Moon and Saturn
    {2026, 10, 24},  // 2026/10/24: Leonis Minorid meteor shower 2026
    {2026, 10, 26},  // 2026/10/26: Full Moon
    {2026, 10, 28},  // 2026/10/28: Close approach of the Moon and M45
    {2026, 11, 1},  // 2026/11/1: Moon at Last Quarter
    {2026, 11, 2},  // 2026/11/2: Close approach of the Moon and Mars
    {2026, 11, 2},  // 2026/11/2: Conjunction of the Moon and Mars
    {2026, 11, 2},  // 2026/11/2: Close approach of the Moon and Jupiter
    {2026, 11, 2},  // 2026/11/2: Conjunction of the Moon and Jupiter
    {2026, 11, 12},  // 2026/11/12: Northern Taurid meteor shower 2026
    {2026, 11, 15},  // 2026/11/15: Conjunction of Jupiter and Mars
    {2026, 11, 16},  // 2026/11/16: Close approach of Jupiter and Mars
    {2026, 11, 17},  // 2026/11/17: Moon at First Quarter
    {2026, 11, 18},  // 2026/11/18: Leonid meteor shower 2026
    {2026, 11, 18},  // 2026/11/18: Mercury at dichotomy
    {2026, 11, 18},  // 2026/11/18: The Pleiades cluster is well placed
    {2026, 11, 20},  // 2026/11/20: Close approach of the Moon and Saturn
    {2026, 11, 20},  // 2026/11/20: Mercury at highest altitude in morning sky
    {2026, 11, 21},  // 2026/11/21: Mercury at greatest elongation west
    {2026, 11, 21},  // 2026/11/21: Conjunction of the Moon and Saturn
    {2026, 11, 21},  // 2026/11/21: α-Monocerotid meteor shower 2026
    {2026, 11, 24},  // 2026/11/24: Close approach of the Moon and M45
    {2026, 11, 24},  // 2026/11/24: Full Moon
    {2026, 11, 27},  // 2026/11/27: Venus at greatest brightness
    {2026, 11, 28},  // 2026/11/28: November Orionid meteor shower 2026
    {2026, 11, 28},  // 2026/11/28: The Hyades cluster is well placed
    {2026, 11, 30},  // 2026/11/30: Close approach of the Moon and Jupiter
    {2026, 11, 30},  // 2026/11/30: Conjunction of the Moon and Jupiter
    {2026, 11, 30},  // 2026/11/30: Close approach of the Moon and Mars
    {2026, 11, 30},  // 2026/11/30: Conjunction of the Moon and Mars
    {2026, 12, 1},  // 2026/12/1: Moon at Last Quarter
    {2026, 12, 5},  // 2026/12/5: Conjunction of the Moon and Venus
    {2026, 12, 6},  // 2026/12/6: December φ-Cassiopeid meteor shower 2026
    {2026, 12, 7},  // 2026/12/7: Puppid-Velid meteor shower 2026
    {2026, 12, 9},  // 2026/12/9: Monocerotid meteor shower 2026
    {2026, 12, 11},  // 2026/12/11: Saturn ends retrograde motion
    {2026, 12, 11},  // 2026/12/11: Venus at highest altitude in morning sky
    {2026, 12, 12},  // 2026/12/12: σ-Hydrid meteor shower 2026
    {2026, 12, 13},  // 2026/12/13: Jupiter enters retrograde motion
    {2026, 12, 14},  // 2026/12/14: Geminid meteor shower 2026
    {2026, 12, 16},  // 2026/12/16: Comae Berenicid meteor shower 2026
    {2026, 12, 17},  // 2026/12/17: Moon at First Quarter
    {2026, 12, 18},  // 2026/12/18: Close approach of the Moon and Saturn
    {2026, 12, 18},  // 2026/12/18: Conjunction of the Moon and Saturn
    {2026, 12, 20},  // 2026/12/20: December Leonis Minorid meteor shower 2026
    {2026, 12, 21},  // 2026/12/21: December solstice
    {2026, 12, 21},  // 2026/12/21: Close approach of the Moon and M45
    {2026, 12, 22},  // 2026/12/22: Ursid meteor shower 2026
    {2026, 12, 24},  // 2026/12/24: Full Moon
    {2026, 12, 27},  // 2026/12/27: Close approach of the Moon and Jupiter
    {2026, 12, 27},  // 2026/12/27: Conjunction of the Moon and Jupiter
    {2026, 12, 28},  // 2026/12/28: Close approach of the Moon and Mars
    {2026, 12, 28},  // 2026/12/28: Conjunction of the Moon and Mars
    {2026, 12, 30},  // 2026/12/30: Moon at Last Quarter
};

// Event names (stored in PROGMEM)
const char ASTRO_NAME_0[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_1[] PROGMEM = "Quadrantid meteor shower 2025";
const char ASTRO_NAME_2[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_3[] PROGMEM = "The Earth at perihelion";
const char ASTRO_NAME_4[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_5[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_6[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_7[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_8[] PROGMEM = "Venus at greatest elongation east";
const char ASTRO_NAME_9[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_10[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_11[] PROGMEM = "Venus at dichotomy";
const char ASTRO_NAME_12[] PROGMEM = "Mars at perigee";
const char ASTRO_NAME_13[] PROGMEM = "Comet C/2024 G3 (ATLAS) passes perigee";
const char ASTRO_NAME_14[] PROGMEM = "Comet C/2024 G3 (ATLAS) passes perihelion";
const char ASTRO_NAME_15[] PROGMEM = "Full Moon";
const char ASTRO_NAME_16[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_17[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_18[] PROGMEM = "Mars at opposition";
const char ASTRO_NAME_19[] PROGMEM = "Close approach of Venus and Saturn";
const char ASTRO_NAME_20[] PROGMEM = "γ-Ursae Minorid meteor shower 2025";
const char ASTRO_NAME_21[] PROGMEM = "Conjunction of Venus and Saturn";
const char ASTRO_NAME_22[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_23[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_24[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_25[] PROGMEM = "Venus at highest altitude in evening sky";
const char ASTRO_NAME_26[] PROGMEM = "Jupiter ends retrograde motion";
const char ASTRO_NAME_27[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_28[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_29[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_30[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_31[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_32[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_33[] PROGMEM = "Full Moon";
const char ASTRO_NAME_34[] PROGMEM = "Venus at greatest brightness";
const char ASTRO_NAME_35[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_36[] PROGMEM = "Mars ends retrograde motion";
const char ASTRO_NAME_37[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_38[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_39[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_40[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_41[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_42[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_43[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_44[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_45[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_46[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_47[] PROGMEM = "Full Moon";
const char ASTRO_NAME_48[] PROGMEM = "Total lunar eclipse";
const char ASTRO_NAME_49[] PROGMEM = "March equinox";
const char ASTRO_NAME_50[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_51[] PROGMEM = "Saturn ring plane crossing";
const char ASTRO_NAME_52[] PROGMEM = "Partial solar eclipse";
const char ASTRO_NAME_53[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_54[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_55[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_56[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_57[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_58[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_59[] PROGMEM = "Full Moon";
const char ASTRO_NAME_60[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_61[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_62[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_63[] PROGMEM = "Lyrid meteor shower 2025";
const char ASTRO_NAME_64[] PROGMEM = "π-Puppid meteor shower 2025";
const char ASTRO_NAME_65[] PROGMEM = "Venus at greatest brightness";
const char ASTRO_NAME_66[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_67[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_68[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_69[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_70[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_71[] PROGMEM = "Close approach of Venus, Saturn and Neptune";
const char ASTRO_NAME_72[] PROGMEM = "Conjunction of Venus and Saturn";
const char ASTRO_NAME_73[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_74[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_75[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_76[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_77[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_78[] PROGMEM = "η-Aquariid meteor shower 2025";
const char ASTRO_NAME_79[] PROGMEM = "Equinox on Saturn";
const char ASTRO_NAME_80[] PROGMEM = "η-Lyrid meteor shower 2025";
const char ASTRO_NAME_81[] PROGMEM = "Full Moon";
const char ASTRO_NAME_82[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_83[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_84[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_85[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_86[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_87[] PROGMEM = "Venus at greatest elongation west";
const char ASTRO_NAME_88[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_89[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_90[] PROGMEM = "Venus at dichotomy";
const char ASTRO_NAME_91[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_92[] PROGMEM = "Daytime Arietid meteor shower 2025";
const char ASTRO_NAME_93[] PROGMEM = "Full Moon";
const char ASTRO_NAME_94[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_95[] PROGMEM = "Close approach of the Moon, Saturn and Neptune";
const char ASTRO_NAME_96[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_97[] PROGMEM = "June solstice";
const char ASTRO_NAME_98[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_99[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_100[] PROGMEM = "June Bootid meteor shower 2025";
const char ASTRO_NAME_101[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_102[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_103[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_104[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_105[] PROGMEM = "The Earth at aphelion";
const char ASTRO_NAME_106[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_107[] PROGMEM = "Full Moon";
const char ASTRO_NAME_108[] PROGMEM = "Saturn enters retrograde motion";
const char ASTRO_NAME_109[] PROGMEM = "Close approach of the Moon, Saturn and Neptune";
const char ASTRO_NAME_110[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_111[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_112[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_113[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_114[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_115[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_116[] PROGMEM = "Piscis Austrinid meteor shower 2025";
const char ASTRO_NAME_117[] PROGMEM = "Southern δ-Aquariid meteor shower 2025";
const char ASTRO_NAME_118[] PROGMEM = "α-Capricornid meteor shower 2025";
const char ASTRO_NAME_119[] PROGMEM = "Venus at highest altitude in morning sky";
const char ASTRO_NAME_120[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_121[] PROGMEM = "Full Moon";
const char ASTRO_NAME_122[] PROGMEM = "Close approach of Venus and Jupiter";
const char ASTRO_NAME_123[] PROGMEM = "Conjunction of Venus and Jupiter";
const char ASTRO_NAME_124[] PROGMEM = "Close approach of the Moon, Saturn and Neptune";
const char ASTRO_NAME_125[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_126[] PROGMEM = "Perseid meteor shower 2025";
const char ASTRO_NAME_127[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_128[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_129[] PROGMEM = "κ-Cygnid meteor shower 2025";
const char ASTRO_NAME_130[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_131[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_132[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_133[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_134[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_135[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_136[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_137[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_138[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_139[] PROGMEM = "Aurigid meteor shower 2025";
const char ASTRO_NAME_140[] PROGMEM = "Full Moon";
const char ASTRO_NAME_141[] PROGMEM = "Total lunar eclipse";
const char ASTRO_NAME_142[] PROGMEM = "Close approach of the Moon, Saturn and Neptune";
const char ASTRO_NAME_143[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_144[] PROGMEM = "September ε-Perseid meteor shower 2025";
const char ASTRO_NAME_145[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_146[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_147[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_148[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_149[] PROGMEM = "Saturn at opposition";
const char ASTRO_NAME_150[] PROGMEM = "Partial solar eclipse";
const char ASTRO_NAME_151[] PROGMEM = "September equinox";
const char ASTRO_NAME_152[] PROGMEM = "Daytime Sextantid meteor shower 2025";
const char ASTRO_NAME_153[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_154[] PROGMEM = "October Camelopardalid meteor shower 2025";
const char ASTRO_NAME_155[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_156[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_157[] PROGMEM = "Full Moon";
const char ASTRO_NAME_158[] PROGMEM = "Draconid meteor shower 2025";
const char ASTRO_NAME_159[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_160[] PROGMEM = "Southern Taurid meteor shower 2025";
const char ASTRO_NAME_161[] PROGMEM = "δ-Aurigid meteor shower 2025";
const char ASTRO_NAME_162[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_163[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_164[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_165[] PROGMEM = "ε-Geminid meteor shower 2025";
const char ASTRO_NAME_166[] PROGMEM = "Orionid meteor shower 2025";
const char ASTRO_NAME_167[] PROGMEM = "Leonis Minorid meteor shower 2025";
const char ASTRO_NAME_168[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_169[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_170[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_171[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_172[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_173[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_174[] PROGMEM = "Full Moon";
const char ASTRO_NAME_175[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_176[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_177[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_178[] PROGMEM = "Jupiter enters retrograde motion";
const char ASTRO_NAME_179[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_180[] PROGMEM = "Northern Taurid meteor shower 2025";
const char ASTRO_NAME_181[] PROGMEM = "Leonid meteor shower 2025";
const char ASTRO_NAME_182[] PROGMEM = "The Pleiades cluster is well placed";
const char ASTRO_NAME_183[] PROGMEM = "α-Monocerotid meteor shower 2025";
const char ASTRO_NAME_184[] PROGMEM = "The Hyades cluster is well placed";
const char ASTRO_NAME_185[] PROGMEM = "Saturn ends retrograde motion";
const char ASTRO_NAME_186[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_187[] PROGMEM = "November Orionid meteor shower 2025";
const char ASTRO_NAME_188[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_189[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_190[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_191[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_192[] PROGMEM = "Full Moon";
const char ASTRO_NAME_193[] PROGMEM = "December φ-Cassiopeid meteor shower 2025";
const char ASTRO_NAME_194[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_195[] PROGMEM = "Puppid-Velid meteor shower 2025";
const char ASTRO_NAME_196[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_197[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_198[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_199[] PROGMEM = "Monocerotid meteor shower 2025";
const char ASTRO_NAME_200[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_201[] PROGMEM = "σ-Hydrid meteor shower 2025";
const char ASTRO_NAME_202[] PROGMEM = "Geminid meteor shower 2025";
const char ASTRO_NAME_203[] PROGMEM = "Comae Berenicid meteor shower 2025";
const char ASTRO_NAME_204[] PROGMEM = "December Leonis Minorid meteor shower 2025";
const char ASTRO_NAME_205[] PROGMEM = "December solstice";
const char ASTRO_NAME_206[] PROGMEM = "Ursid meteor shower 2025";
const char ASTRO_NAME_207[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_208[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_209[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_210[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_211[] PROGMEM = "Full Moon";
const char ASTRO_NAME_212[] PROGMEM = "The Earth at perihelion";
const char ASTRO_NAME_213[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_214[] PROGMEM = "Quadrantid meteor shower 2026";
const char ASTRO_NAME_215[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_216[] PROGMEM = "Jupiter at perigee";
const char ASTRO_NAME_217[] PROGMEM = "Jupiter at opposition";
const char ASTRO_NAME_218[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_219[] PROGMEM = "γ-Ursae Minorid meteor shower 2026";
const char ASTRO_NAME_220[] PROGMEM = "Close approach of the Moon, Saturn and Neptune";
const char ASTRO_NAME_221[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_222[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_223[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_224[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_225[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_226[] PROGMEM = "Full Moon";
const char ASTRO_NAME_227[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_228[] PROGMEM = "Annular solar eclipse";
const char ASTRO_NAME_229[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_230[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_231[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_232[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_233[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_234[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_235[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_236[] PROGMEM = "Total lunar eclipse";
const char ASTRO_NAME_237[] PROGMEM = "Full Moon";
const char ASTRO_NAME_238[] PROGMEM = "Jupiter ends retrograde motion";
const char ASTRO_NAME_239[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_240[] PROGMEM = "March equinox";
const char ASTRO_NAME_241[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_242[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_243[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_244[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_245[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_246[] PROGMEM = "Full Moon";
const char ASTRO_NAME_247[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_248[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_249[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_250[] PROGMEM = "Lyrid meteor shower 2026";
const char ASTRO_NAME_251[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_252[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_253[] PROGMEM = "π-Puppid meteor shower 2026";
const char ASTRO_NAME_254[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_255[] PROGMEM = "Full Moon";
const char ASTRO_NAME_256[] PROGMEM = "η-Aquariid meteor shower 2026";
const char ASTRO_NAME_257[] PROGMEM = "η-Lyrid meteor shower 2026";
const char ASTRO_NAME_258[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_259[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_260[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_261[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_262[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_263[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_264[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_265[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_266[] PROGMEM = "Blue Moon";
const char ASTRO_NAME_267[] PROGMEM = "Venus at highest altitude in evening sky";
const char ASTRO_NAME_268[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_269[] PROGMEM = "Conjunction of Venus and Jupiter";
const char ASTRO_NAME_270[] PROGMEM = "Close approach of Venus and Jupiter";
const char ASTRO_NAME_271[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_272[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_273[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_274[] PROGMEM = "Daytime Arietid meteor shower 2026";
const char ASTRO_NAME_275[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_276[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_277[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_278[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_279[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_280[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_281[] PROGMEM = "June solstice";
const char ASTRO_NAME_282[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_283[] PROGMEM = "June Bootid meteor shower 2026";
const char ASTRO_NAME_284[] PROGMEM = "Full Moon";
const char ASTRO_NAME_285[] PROGMEM = "The Earth at aphelion";
const char ASTRO_NAME_286[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_287[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_288[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_289[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_290[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_291[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_292[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_293[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_294[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_295[] PROGMEM = "Saturn enters retrograde motion";
const char ASTRO_NAME_296[] PROGMEM = "Piscis Austrinid meteor shower 2026";
const char ASTRO_NAME_297[] PROGMEM = "Full Moon";
const char ASTRO_NAME_298[] PROGMEM = "Southern δ-Aquariid meteor shower 2026";
const char ASTRO_NAME_299[] PROGMEM = "α-Capricornid meteor shower 2026";
const char ASTRO_NAME_300[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_301[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_302[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_303[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_304[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_305[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_306[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_307[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_308[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_309[] PROGMEM = "Total solar eclipse";
const char ASTRO_NAME_310[] PROGMEM = "Venus at dichotomy";
const char ASTRO_NAME_311[] PROGMEM = "Perseid meteor shower 2026";
const char ASTRO_NAME_312[] PROGMEM = "Venus at greatest elongation east";
const char ASTRO_NAME_313[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_314[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_315[] PROGMEM = "κ-Cygnid meteor shower 2026";
const char ASTRO_NAME_316[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_317[] PROGMEM = "Partial lunar eclipse";
const char ASTRO_NAME_318[] PROGMEM = "Full Moon";
const char ASTRO_NAME_319[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_320[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_321[] PROGMEM = "Aurigid meteor shower 2026";
const char ASTRO_NAME_322[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_323[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_324[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_325[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_326[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_327[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_328[] PROGMEM = "September ε-Perseid meteor shower 2026";
const char ASTRO_NAME_329[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_330[] PROGMEM = "Close approach of the Moon and Venus";
const char ASTRO_NAME_331[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_332[] PROGMEM = "Venus at greatest brightness";
const char ASTRO_NAME_333[] PROGMEM = "September equinox";
const char ASTRO_NAME_334[] PROGMEM = "Full Moon";
const char ASTRO_NAME_335[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_336[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_337[] PROGMEM = "Daytime Sextantid meteor shower 2026";
const char ASTRO_NAME_338[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_339[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_340[] PROGMEM = "Saturn at opposition";
const char ASTRO_NAME_341[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_342[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_343[] PROGMEM = "October Camelopardalid meteor shower 2026";
const char ASTRO_NAME_344[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_345[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_346[] PROGMEM = "Mercury at highest altitude in evening sky";
const char ASTRO_NAME_347[] PROGMEM = "Draconid meteor shower 2026";
const char ASTRO_NAME_348[] PROGMEM = "Southern Taurid meteor shower 2026";
const char ASTRO_NAME_349[] PROGMEM = "δ-Aurigid meteor shower 2026";
const char ASTRO_NAME_350[] PROGMEM = "Mercury at greatest elongation east";
const char ASTRO_NAME_351[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_352[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_353[] PROGMEM = "ε-Geminid meteor shower 2026";
const char ASTRO_NAME_354[] PROGMEM = "Orionid meteor shower 2026";
const char ASTRO_NAME_355[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_356[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_357[] PROGMEM = "Leonis Minorid meteor shower 2026";
const char ASTRO_NAME_358[] PROGMEM = "Full Moon";
const char ASTRO_NAME_359[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_360[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_361[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_362[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_363[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_364[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_365[] PROGMEM = "Northern Taurid meteor shower 2026";
const char ASTRO_NAME_366[] PROGMEM = "Conjunction of Jupiter and Mars";
const char ASTRO_NAME_367[] PROGMEM = "Close approach of Jupiter and Mars";
const char ASTRO_NAME_368[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_369[] PROGMEM = "Leonid meteor shower 2026";
const char ASTRO_NAME_370[] PROGMEM = "Mercury at dichotomy";
const char ASTRO_NAME_371[] PROGMEM = "The Pleiades cluster is well placed";
const char ASTRO_NAME_372[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_373[] PROGMEM = "Mercury at highest altitude in morning sky";
const char ASTRO_NAME_374[] PROGMEM = "Mercury at greatest elongation west";
const char ASTRO_NAME_375[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_376[] PROGMEM = "α-Monocerotid meteor shower 2026";
const char ASTRO_NAME_377[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_378[] PROGMEM = "Full Moon";
const char ASTRO_NAME_379[] PROGMEM = "Venus at greatest brightness";
const char ASTRO_NAME_380[] PROGMEM = "November Orionid meteor shower 2026";
const char ASTRO_NAME_381[] PROGMEM = "The Hyades cluster is well placed";
const char ASTRO_NAME_382[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_383[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_384[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_385[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_386[] PROGMEM = "Moon at Last Quarter";
const char ASTRO_NAME_387[] PROGMEM = "Conjunction of the Moon and Venus";
const char ASTRO_NAME_388[] PROGMEM = "December φ-Cassiopeid meteor shower 2026";
const char ASTRO_NAME_389[] PROGMEM = "Puppid-Velid meteor shower 2026";
const char ASTRO_NAME_390[] PROGMEM = "Monocerotid meteor shower 2026";
const char ASTRO_NAME_391[] PROGMEM = "Saturn ends retrograde motion";
const char ASTRO_NAME_392[] PROGMEM = "Venus at highest altitude in morning sky";
const char ASTRO_NAME_393[] PROGMEM = "σ-Hydrid meteor shower 2026";
const char ASTRO_NAME_394[] PROGMEM = "Jupiter enters retrograde motion";
const char ASTRO_NAME_395[] PROGMEM = "Geminid meteor shower 2026";
const char ASTRO_NAME_396[] PROGMEM = "Comae Berenicid meteor shower 2026";
const char ASTRO_NAME_397[] PROGMEM = "Moon at First Quarter";
const char ASTRO_NAME_398[] PROGMEM = "Close approach of the Moon and Saturn";
const char ASTRO_NAME_399[] PROGMEM = "Conjunction of the Moon and Saturn";
const char ASTRO_NAME_400[] PROGMEM = "December Leonis Minorid meteor shower 2026";
const char ASTRO_NAME_401[] PROGMEM = "December solstice";
const char ASTRO_NAME_402[] PROGMEM = "Close approach of the Moon and M45";
const char ASTRO_NAME_403[] PROGMEM = "Ursid meteor shower 2026";
const char ASTRO_NAME_404[] PROGMEM = "Full Moon";
const char ASTRO_NAME_405[] PROGMEM = "Close approach of the Moon and Jupiter";
const char ASTRO_NAME_406[] PROGMEM = "Conjunction of the Moon and Jupiter";
const char ASTRO_NAME_407[] PROGMEM = "Close approach of the Moon and Mars";
const char ASTRO_NAME_408[] PROGMEM = "Conjunction of the Moon and Mars";
const char ASTRO_NAME_409[] PROGMEM = "Moon at Last Quarter";

const char* const ASTRO_NAMES[] PROGMEM = {
    ASTRO_NAME_0,
    ASTRO_NAME_1,
    ASTRO_NAME_2,
    ASTRO_NAME_3,
    ASTRO_NAME_4,
    ASTRO_NAME_5,
    ASTRO_NAME_6,
    ASTRO_NAME_7,
    ASTRO_NAME_8,
    ASTRO_NAME_9,
    ASTRO_NAME_10,
    ASTRO_NAME_11,
    ASTRO_NAME_12,
    ASTRO_NAME_13,
    ASTRO_NAME_14,
    ASTRO_NAME_15,
    ASTRO_NAME_16,
    ASTRO_NAME_17,
    ASTRO_NAME_18,
    ASTRO_NAME_19,
    ASTRO_NAME_20,
    ASTRO_NAME_21,
    ASTRO_NAME_22,
    ASTRO_NAME_23,
    ASTRO_NAME_24,
    ASTRO_NAME_25,
    ASTRO_NAME_26,
    ASTRO_NAME_27,
    ASTRO_NAME_28,
    ASTRO_NAME_29,
    ASTRO_NAME_30,
    ASTRO_NAME_31,
    ASTRO_NAME_32,
    ASTRO_NAME_33,
    ASTRO_NAME_34,
    ASTRO_NAME_35,
    ASTRO_NAME_36,
    ASTRO_NAME_37,
    ASTRO_NAME_38,
    ASTRO_NAME_39,
    ASTRO_NAME_40,
    ASTRO_NAME_41,
    ASTRO_NAME_42,
    ASTRO_NAME_43,
    ASTRO_NAME_44,
    ASTRO_NAME_45,
    ASTRO_NAME_46,
    ASTRO_NAME_47,
    ASTRO_NAME_48,
    ASTRO_NAME_49,
    ASTRO_NAME_50,
    ASTRO_NAME_51,
    ASTRO_NAME_52,
    ASTRO_NAME_53,
    ASTRO_NAME_54,
    ASTRO_NAME_55,
    ASTRO_NAME_56,
    ASTRO_NAME_57,
    ASTRO_NAME_58,
    ASTRO_NAME_59,
    ASTRO_NAME_60,
    ASTRO_NAME_61,
    ASTRO_NAME_62,
    ASTRO_NAME_63,
    ASTRO_NAME_64,
    ASTRO_NAME_65,
    ASTRO_NAME_66,
    ASTRO_NAME_67,
    ASTRO_NAME_68,
    ASTRO_NAME_69,
    ASTRO_NAME_70,
    ASTRO_NAME_71,
    ASTRO_NAME_72,
    ASTRO_NAME_73,
    ASTRO_NAME_74,
    ASTRO_NAME_75,
    ASTRO_NAME_76,
    ASTRO_NAME_77,
    ASTRO_NAME_78,
    ASTRO_NAME_79,
    ASTRO_NAME_80,
    ASTRO_NAME_81,
    ASTRO_NAME_82,
    ASTRO_NAME_83,
    ASTRO_NAME_84,
    ASTRO_NAME_85,
    ASTRO_NAME_86,
    ASTRO_NAME_87,
    ASTRO_NAME_88,
    ASTRO_NAME_89,
    ASTRO_NAME_90,
    ASTRO_NAME_91,
    ASTRO_NAME_92,
    ASTRO_NAME_93,
    ASTRO_NAME_94,
    ASTRO_NAME_95,
    ASTRO_NAME_96,
    ASTRO_NAME_97,
    ASTRO_NAME_98,
    ASTRO_NAME_99,
    ASTRO_NAME_100,
    ASTRO_NAME_101,
    ASTRO_NAME_102,
    ASTRO_NAME_103,
    ASTRO_NAME_104,
    ASTRO_NAME_105,
    ASTRO_NAME_106,
    ASTRO_NAME_107,
    ASTRO_NAME_108,
    ASTRO_NAME_109,
    ASTRO_NAME_110,
    ASTRO_NAME_111,
    ASTRO_NAME_112,
    ASTRO_NAME_113,
    ASTRO_NAME_114,
    ASTRO_NAME_115,
    ASTRO_NAME_116,
    ASTRO_NAME_117,
    ASTRO_NAME_118,
    ASTRO_NAME_119,
    ASTRO_NAME_120,
    ASTRO_NAME_121,
    ASTRO_NAME_122,
    ASTRO_NAME_123,
    ASTRO_NAME_124,
    ASTRO_NAME_125,
    ASTRO_NAME_126,
    ASTRO_NAME_127,
    ASTRO_NAME_128,
    ASTRO_NAME_129,
    ASTRO_NAME_130,
    ASTRO_NAME_131,
    ASTRO_NAME_132,
    ASTRO_NAME_133,
    ASTRO_NAME_134,
    ASTRO_NAME_135,
    ASTRO_NAME_136,
    ASTRO_NAME_137,
    ASTRO_NAME_138,
    ASTRO_NAME_139,
    ASTRO_NAME_140,
    ASTRO_NAME_141,
    ASTRO_NAME_142,
    ASTRO_NAME_143,
    ASTRO_NAME_144,
    ASTRO_NAME_145,
    ASTRO_NAME_146,
    ASTRO_NAME_147,
    ASTRO_NAME_148,
    ASTRO_NAME_149,
    ASTRO_NAME_150,
    ASTRO_NAME_151,
    ASTRO_NAME_152,
    ASTRO_NAME_153,
    ASTRO_NAME_154,
    ASTRO_NAME_155,
    ASTRO_NAME_156,
    ASTRO_NAME_157,
    ASTRO_NAME_158,
    ASTRO_NAME_159,
    ASTRO_NAME_160,
    ASTRO_NAME_161,
    ASTRO_NAME_162,
    ASTRO_NAME_163,
    ASTRO_NAME_164,
    ASTRO_NAME_165,
    ASTRO_NAME_166,
    ASTRO_NAME_167,
    ASTRO_NAME_168,
    ASTRO_NAME_169,
    ASTRO_NAME_170,
    ASTRO_NAME_171,
    ASTRO_NAME_172,
    ASTRO_NAME_173,
    ASTRO_NAME_174,
    ASTRO_NAME_175,
    ASTRO_NAME_176,
    ASTRO_NAME_177,
    ASTRO_NAME_178,
    ASTRO_NAME_179,
    ASTRO_NAME_180,
    ASTRO_NAME_181,
    ASTRO_NAME_182,
    ASTRO_NAME_183,
    ASTRO_NAME_184,
    ASTRO_NAME_185,
    ASTRO_NAME_186,
    ASTRO_NAME_187,
    ASTRO_NAME_188,
    ASTRO_NAME_189,
    ASTRO_NAME_190,
    ASTRO_NAME_191,
    ASTRO_NAME_192,
    ASTRO_NAME_193,
    ASTRO_NAME_194,
    ASTRO_NAME_195,
    ASTRO_NAME_196,
    ASTRO_NAME_197,
    ASTRO_NAME_198,
    ASTRO_NAME_199,
    ASTRO_NAME_200,
    ASTRO_NAME_201,
    ASTRO_NAME_202,
    ASTRO_NAME_203,
    ASTRO_NAME_204,
    ASTRO_NAME_205,
    ASTRO_NAME_206,
    ASTRO_NAME_207,
    ASTRO_NAME_208,
    ASTRO_NAME_209,
    ASTRO_NAME_210,
    ASTRO_NAME_211,
    ASTRO_NAME_212,
    ASTRO_NAME_213,
    ASTRO_NAME_214,
    ASTRO_NAME_215,
    ASTRO_NAME_216,
    ASTRO_NAME_217,
    ASTRO_NAME_218,
    ASTRO_NAME_219,
    ASTRO_NAME_220,
    ASTRO_NAME_221,
    ASTRO_NAME_222,
    ASTRO_NAME_223,
    ASTRO_NAME_224,
    ASTRO_NAME_225,
    ASTRO_NAME_226,
    ASTRO_NAME_227,
    ASTRO_NAME_228,
    ASTRO_NAME_229,
    ASTRO_NAME_230,
    ASTRO_NAME_231,
    ASTRO_NAME_232,
    ASTRO_NAME_233,
    ASTRO_NAME_234,
    ASTRO_NAME_235,
    ASTRO_NAME_236,
    ASTRO_NAME_237,
    ASTRO_NAME_238,
    ASTRO_NAME_239,
    ASTRO_NAME_240,
    ASTRO_NAME_241,
    ASTRO_NAME_242,
    ASTRO_NAME_243,
    ASTRO_NAME_244,
    ASTRO_NAME_245,
    ASTRO_NAME_246,
    ASTRO_NAME_247,
    ASTRO_NAME_248,
    ASTRO_NAME_249,
    ASTRO_NAME_250,
    ASTRO_NAME_251,
    ASTRO_NAME_252,
    ASTRO_NAME_253,
    ASTRO_NAME_254,
    ASTRO_NAME_255,
    ASTRO_NAME_256,
    ASTRO_NAME_257,
    ASTRO_NAME_258,
    ASTRO_NAME_259,
    ASTRO_NAME_260,
    ASTRO_NAME_261,
    ASTRO_NAME_262,
    ASTRO_NAME_263,
    ASTRO_NAME_264,
    ASTRO_NAME_265,
    ASTRO_NAME_266,
    ASTRO_NAME_267,
    ASTRO_NAME_268,
    ASTRO_NAME_269,
    ASTRO_NAME_270,
    ASTRO_NAME_271,
    ASTRO_NAME_272,
    ASTRO_NAME_273,
    ASTRO_NAME_274,
    ASTRO_NAME_275,
    ASTRO_NAME_276,
    ASTRO_NAME_277,
    ASTRO_NAME_278,
    ASTRO_NAME_279,
    ASTRO_NAME_280,
    ASTRO_NAME_281,
    ASTRO_NAME_282,
    ASTRO_NAME_283,
    ASTRO_NAME_284,
    ASTRO_NAME_285,
    ASTRO_NAME_286,
    ASTRO_NAME_287,
    ASTRO_NAME_288,
    ASTRO_NAME_289,
    ASTRO_NAME_290,
    ASTRO_NAME_291,
    ASTRO_NAME_292,
    ASTRO_NAME_293,
    ASTRO_NAME_294,
    ASTRO_NAME_295,
    ASTRO_NAME_296,
    ASTRO_NAME_297,
    ASTRO_NAME_298,
    ASTRO_NAME_299,
    ASTRO_NAME_300,
    ASTRO_NAME_301,
    ASTRO_NAME_302,
    ASTRO_NAME_303,
    ASTRO_NAME_304,
    ASTRO_NAME_305,
    ASTRO_NAME_306,
    ASTRO_NAME_307,
    ASTRO_NAME_308,
    ASTRO_NAME_309,
    ASTRO_NAME_310,
    ASTRO_NAME_311,
    ASTRO_NAME_312,
    ASTRO_NAME_313,
    ASTRO_NAME_314,
    ASTRO_NAME_315,
    ASTRO_NAME_316,
    ASTRO_NAME_317,
    ASTRO_NAME_318,
    ASTRO_NAME_319,
    ASTRO_NAME_320,
    ASTRO_NAME_321,
    ASTRO_NAME_322,
    ASTRO_NAME_323,
    ASTRO_NAME_324,
    ASTRO_NAME_325,
    ASTRO_NAME_326,
    ASTRO_NAME_327,
    ASTRO_NAME_328,
    ASTRO_NAME_329,
    ASTRO_NAME_330,
    ASTRO_NAME_331,
    ASTRO_NAME_332,
    ASTRO_NAME_333,
    ASTRO_NAME_334,
    ASTRO_NAME_335,
    ASTRO_NAME_336,
    ASTRO_NAME_337,
    ASTRO_NAME_338,
    ASTRO_NAME_339,
    ASTRO_NAME_340,
    ASTRO_NAME_341,
    ASTRO_NAME_342,
    ASTRO_NAME_343,
    ASTRO_NAME_344,
    ASTRO_NAME_345,
    ASTRO_NAME_346,
    ASTRO_NAME_347,
    ASTRO_NAME_348,
    ASTRO_NAME_349,
    ASTRO_NAME_350,
    ASTRO_NAME_351,
    ASTRO_NAME_352,
    ASTRO_NAME_353,
    ASTRO_NAME_354,
    ASTRO_NAME_355,
    ASTRO_NAME_356,
    ASTRO_NAME_357,
    ASTRO_NAME_358,
    ASTRO_NAME_359,
    ASTRO_NAME_360,
    ASTRO_NAME_361,
    ASTRO_NAME_362,
    ASTRO_NAME_363,
    ASTRO_NAME_364,
    ASTRO_NAME_365,
    ASTRO_NAME_366,
    ASTRO_NAME_367,
    ASTRO_NAME_368,
    ASTRO_NAME_369,
    ASTRO_NAME_370,
    ASTRO_NAME_371,
    ASTRO_NAME_372,
    ASTRO_NAME_373,
    ASTRO_NAME_374,
    ASTRO_NAME_375,
    ASTRO_NAME_376,
    ASTRO_NAME_377,
    ASTRO_NAME_378,
    ASTRO_NAME_379,
    ASTRO_NAME_380,
    ASTRO_NAME_381,
    ASTRO_NAME_382,
    ASTRO_NAME_383,
    ASTRO_NAME_384,
    ASTRO_NAME_385,
    ASTRO_NAME_386,
    ASTRO_NAME_387,
    ASTRO_NAME_388,
    ASTRO_NAME_389,
    ASTRO_NAME_390,
    ASTRO_NAME_391,
    ASTRO_NAME_392,
    ASTRO_NAME_393,
    ASTRO_NAME_394,
    ASTRO_NAME_395,
    ASTRO_NAME_396,
    ASTRO_NAME_397,
    ASTRO_NAME_398,
    ASTRO_NAME_399,
    ASTRO_NAME_400,
    ASTRO_NAME_401,
    ASTRO_NAME_402,
    ASTRO_NAME_403,
    ASTRO_NAME_404,
    ASTRO_NAME_405,
    ASTRO_NAME_406,
    ASTRO_NAME_407,
    ASTRO_NAME_408,
    ASTRO_NAME_409
};

// Event descriptions (stored in PROGMEM)
const char ASTRO_DESC_0[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 1°26'.";
const char ASTRO_DESC_1[] PROGMEM = "The Quadrantid meteor shower reaches\nits peak.";
const char ASTRO_DESC_2[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_3[] PROGMEM = "The Earth reaches its closest point to\nthe Sun.";
const char ASTRO_DESC_4[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_5[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 40'.";
const char ASTRO_DESC_6[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_7[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_8[] PROGMEM = "Venus is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_9[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_10[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n5°25'.";
const char ASTRO_DESC_11[] PROGMEM = "Venus reaches half phase in the evening\nsky.";
const char ASTRO_DESC_12[] PROGMEM = "Mars reaches its closest point to the\nEarth – marking the best time to observe\nit in 1970.";
const char ASTRO_DESC_13[] PROGMEM = "Comet C/2024 G3 (ATLAS) makes its\nclosest approach to the Earth.";
const char ASTRO_DESC_14[] PROGMEM = "Comet C/2024 G3 (ATLAS) makes its\nclosest approach to the Sun.";
const char ASTRO_DESC_15[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_16[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 13'.";
const char ASTRO_DESC_17[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_18[] PROGMEM = "Mars is optimally positioned for\nobservation, appears at its closest,\nbrightest and largest.";
const char ASTRO_DESC_19[] PROGMEM = "Venus and Saturn pass within 2°10' of\neach other.";
const char ASTRO_DESC_20[] PROGMEM = "The γ-Ursae Minorid meteor shower\nreaches its peak.";
const char ASTRO_DESC_21[] PROGMEM = "Venus and Saturn share the same right\nascension, at a separation of 2°31'.";
const char ASTRO_DESC_22[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_23[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 2°20'.";
const char ASTRO_DESC_24[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_25[] PROGMEM = "Venus is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_26[] PROGMEM = "Jupiter returns to its usual eastward\nmotion after opposition.";
const char ASTRO_DESC_27[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_28[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_29[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_30[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n5°29'.";
const char ASTRO_DESC_31[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 46'.";
const char ASTRO_DESC_32[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_33[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_34[] PROGMEM = "Venus reaches its greatest brightness in\nthe evening sky.";
const char ASTRO_DESC_35[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_36[] PROGMEM = "Mars returns to its usual eastward\nmotion after opposition.";
const char ASTRO_DESC_37[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 6°23'.";
const char ASTRO_DESC_38[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_39[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_40[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n5°33'.";
const char ASTRO_DESC_41[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_42[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_43[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_44[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_45[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 1°40'.";
const char ASTRO_DESC_46[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_47[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_48[] PROGMEM = "There will be an eclipse of the Moon,\nvisible from the Americas, Antarctica,\nAlaska, north-eastern  Russia and\nAfrica.";
const char ASTRO_DESC_49[] PROGMEM = "Day and night have equal length: the\nbeginning of astronomical spring in the\nnorthern hemisphere.";
const char ASTRO_DESC_50[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_51[] PROGMEM = "Saturn's seasons are changing, making\nits rings appear edge-on from the Earth.";
const char ASTRO_DESC_52[] PROGMEM = "There will be an eclipse of the Sun,\nvisible from parts of the Americas,\nwestern  Russia, Europe and Africa.";
const char ASTRO_DESC_53[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_54[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_55[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n5°30'.";
const char ASTRO_DESC_56[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_57[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 2°09'.";
const char ASTRO_DESC_58[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_59[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_60[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_61[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_62[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_63[] PROGMEM = "The Lyrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_64[] PROGMEM = "The π-Puppid meteor shower reaches its\npeak.";
const char ASTRO_DESC_65[] PROGMEM = "Venus reaches its greatest brightness in\nthe dawn sky.";
const char ASTRO_DESC_66[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_67[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 2°23'.";
const char ASTRO_DESC_68[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_69[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_70[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 2°17'.";
const char ASTRO_DESC_71[] PROGMEM = "Venus, Saturn and Neptune pass within\n3°42' of one another.";
const char ASTRO_DESC_72[] PROGMEM = "Venus and Saturn share the same right\nascension, at a separation of 3°43'.";
const char ASTRO_DESC_73[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_74[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n5°23'.";
const char ASTRO_DESC_75[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 2°04'.";
const char ASTRO_DESC_76[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_77[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_78[] PROGMEM = "The η-Aquariid meteor shower reaches\nits peak.";
const char ASTRO_DESC_79[] PROGMEM = "Saturn's seasons are changing, making\nits rings appear edge-on from the Earth.";
const char ASTRO_DESC_80[] PROGMEM = "The η-Lyrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_81[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_82[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_83[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_84[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 2°49'.";
const char ASTRO_DESC_85[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_86[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 3°59'.";
const char ASTRO_DESC_87[] PROGMEM = "Venus is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_88[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 1°23'.";
const char ASTRO_DESC_89[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_90[] PROGMEM = "Venus reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_91[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_92[] PROGMEM = "The Daytime Arietid meteor shower\nreaches its peak.";
const char ASTRO_DESC_93[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_94[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_95[] PROGMEM = "The Moon, Saturn and Neptune pass close\nto one another.";
const char ASTRO_DESC_96[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°23'.";
const char ASTRO_DESC_97[] PROGMEM = "21 June will be the longest day of 2025\nin the northern hemisphere.";
const char ASTRO_DESC_98[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 7°10'.";
const char ASTRO_DESC_99[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_100[] PROGMEM = "The June Bootid meteor shower reaches\nits peak.";
const char ASTRO_DESC_101[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_102[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 12'.";
const char ASTRO_DESC_103[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_104[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_105[] PROGMEM = "The Earth reaches its furthest point\nfrom the Sun.";
const char ASTRO_DESC_106[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_107[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_108[] PROGMEM = "Saturn reverses its direction of motion\nacross the sky.";
const char ASTRO_DESC_109[] PROGMEM = "The Moon, Saturn and Neptune pass close\nto one another.";
const char ASTRO_DESC_110[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°50'.";
const char ASTRO_DESC_111[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_112[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_113[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 7°07'.";
const char ASTRO_DESC_114[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_115[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 1°17'.";
const char ASTRO_DESC_116[] PROGMEM = "The Piscis Austrinid meteor shower\nreaches its peak.";
const char ASTRO_DESC_117[] PROGMEM = "The Southern δ-Aquariid meteor shower\nreaches its peak.";
const char ASTRO_DESC_118[] PROGMEM = "The α-Capricornid meteor shower reaches\nits peak.";
const char ASTRO_DESC_119[] PROGMEM = "Venus is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_120[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_121[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_122[] PROGMEM = "Venus and Jupiter pass within 51' of\neach other.";
const char ASTRO_DESC_123[] PROGMEM = "Venus and Jupiter share the same right\nascension, at a separation of 51'.";
const char ASTRO_DESC_124[] PROGMEM = "The Moon, Saturn and Neptune pass close\nto one another.";
const char ASTRO_DESC_125[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 4°02'.";
const char ASTRO_DESC_126[] PROGMEM = "The Perseid meteor shower reaches its\npeak.";
const char ASTRO_DESC_127[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_128[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_129[] PROGMEM = "The κ-Cygnid meteor shower reaches its\npeak.";
const char ASTRO_DESC_130[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_131[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n4°46'.";
const char ASTRO_DESC_132[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_133[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 4°52'.";
const char ASTRO_DESC_134[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_135[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_136[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_137[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 2°47'.";
const char ASTRO_DESC_138[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_139[] PROGMEM = "The Aurigid meteor shower reaches its\npeak.";
const char ASTRO_DESC_140[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_141[] PROGMEM = "There will be an eclipse of the Moon,\nvisible from Antarctica, Asia, Russia,\nAfrica, Oceania and Europe.";
const char ASTRO_DESC_142[] PROGMEM = "The Moon, Saturn and Neptune pass close\nto one another.";
const char ASTRO_DESC_143[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°59'.";
const char ASTRO_DESC_144[] PROGMEM = "The September ε-Perseid meteor shower\nreaches its peak.";
const char ASTRO_DESC_145[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_146[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_147[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n4°33'.";
const char ASTRO_DESC_148[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_149[] PROGMEM = "Saturn is optimally positioned for\nobservation, appears at its closest,\nbrightest and largest.";
const char ASTRO_DESC_150[] PROGMEM = "There will be an eclipse of the Sun,\nvisible from parts of Antarctica and\nOceania.";
const char ASTRO_DESC_151[] PROGMEM = "Day and night have equal length: the\nbeginning of astronomical autumn in the\nnorthern hemisphere.";
const char ASTRO_DESC_152[] PROGMEM = "The Daytime Sextantid meteor shower\nreaches its peak.";
const char ASTRO_DESC_153[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_154[] PROGMEM = "The October Camelopardalid meteor shower\nreaches its peak.";
const char ASTRO_DESC_155[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_156[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°47'.";
const char ASTRO_DESC_157[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_158[] PROGMEM = "The Draconid meteor shower reaches its\npeak.";
const char ASTRO_DESC_159[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_160[] PROGMEM = "The Southern Taurid meteor shower\nreaches its peak.";
const char ASTRO_DESC_161[] PROGMEM = "The δ-Aurigid meteor shower reaches\nits peak.";
const char ASTRO_DESC_162[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_163[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n4°16'.";
const char ASTRO_DESC_164[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_165[] PROGMEM = "The ε-Geminid meteor shower reaches\nits peak.";
const char ASTRO_DESC_166[] PROGMEM = "The Orionid meteor shower reaches its\npeak.";
const char ASTRO_DESC_167[] PROGMEM = "The Leonis Minorid meteor shower reaches\nits peak.";
const char ASTRO_DESC_168[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_169[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_170[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_171[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_172[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°39'.";
const char ASTRO_DESC_173[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_174[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_175[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_176[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°56'.";
const char ASTRO_DESC_177[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_178[] PROGMEM = "Jupiter reverses its direction of motion\nacross the sky.";
const char ASTRO_DESC_179[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_180[] PROGMEM = "The Northern Taurid meteor shower\nreaches its peak.";
const char ASTRO_DESC_181[] PROGMEM = "The Leonid meteor shower reaches its\npeak.";
const char ASTRO_DESC_182[] PROGMEM = "The Pleiades open star cluster (M45;\nmag 1.3) in Taurus culminates at around\nmidnight local time.";
const char ASTRO_DESC_183[] PROGMEM = "The α-Monocerotid meteor shower reaches\nits peak.";
const char ASTRO_DESC_184[] PROGMEM = "The Hyades open star cluster (Collinder\n50; mag 1.0) in Taurus culminates at\naround midnight local time.";
const char ASTRO_DESC_185[] PROGMEM = "Saturn returns to its usual eastward\nmotion after opposition.";
const char ASTRO_DESC_186[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_187[] PROGMEM = "The November Orionid meteor shower\nreaches its peak.";
const char ASTRO_DESC_188[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_189[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 3°45'.";
const char ASTRO_DESC_190[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_191[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_192[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_193[] PROGMEM = "The December φ-Cassiopeid meteor shower\nreaches its peak.";
const char ASTRO_DESC_194[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_195[] PROGMEM = "The Puppid-Velid meteor shower reaches\nits peak.";
const char ASTRO_DESC_196[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°42'.";
const char ASTRO_DESC_197[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_198[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_199[] PROGMEM = "The Monocerotid meteor shower reaches\nits peak.";
const char ASTRO_DESC_200[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_201[] PROGMEM = "The σ-Hydrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_202[] PROGMEM = "The Geminid meteor shower reaches its\npeak.";
const char ASTRO_DESC_203[] PROGMEM = "The Comae Berenicid meteor shower\nreaches its peak.";
const char ASTRO_DESC_204[] PROGMEM = "The December Leonis Minorid meteor\nshower reaches its peak.";
const char ASTRO_DESC_205[] PROGMEM = "21 December will be the shortest day of\n2025 in the northern hemisphere.";
const char ASTRO_DESC_206[] PROGMEM = "The Ursid meteor shower reaches its\npeak.";
const char ASTRO_DESC_207[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_208[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 4°01'.";
const char ASTRO_DESC_209[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_210[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_211[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_212[] PROGMEM = "The Earth reaches its closest point to\nthe Sun.";
const char ASTRO_DESC_213[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°41'.";
const char ASTRO_DESC_214[] PROGMEM = "The Quadrantid meteor shower reaches\nits peak.";
const char ASTRO_DESC_215[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_216[] PROGMEM = "Jupiter reaches its closest point to the\nEarth – marking the best time to observe\nit in 1970.";
const char ASTRO_DESC_217[] PROGMEM = "Jupiter is optimally positioned for\nobservation, appears at its closest,\nbrightest and largest.";
const char ASTRO_DESC_218[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_219[] PROGMEM = "The γ-Ursae Minorid meteor shower\nreaches its peak.";
const char ASTRO_DESC_220[] PROGMEM = "The Moon, Saturn and Neptune pass close\nto one another.";
const char ASTRO_DESC_221[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 4°21'.";
const char ASTRO_DESC_222[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_223[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_224[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°50'.";
const char ASTRO_DESC_225[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_226[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_227[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_228[] PROGMEM = "There will be an eclipse of the Sun,\nvisible from Antarctica.";
const char ASTRO_DESC_229[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_230[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_231[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_232[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_233[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_234[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°57'.";
const char ASTRO_DESC_235[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_236[] PROGMEM = "There will be an eclipse of the Moon,\nvisible from the Americas, Russia, Asia,\nAntarctica, Oceania and Alaska.";
const char ASTRO_DESC_237[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_238[] PROGMEM = "Jupiter returns to its usual eastward\nmotion after opposition.";
const char ASTRO_DESC_239[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_240[] PROGMEM = "Day and night have equal length: the\nbeginning of astronomical spring in the\nnorthern hemisphere.";
const char ASTRO_DESC_241[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_242[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_243[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°52'.";
const char ASTRO_DESC_244[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_245[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_246[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_247[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_248[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_249[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_250[] PROGMEM = "The Lyrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_251[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°33'.";
const char ASTRO_DESC_252[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_253[] PROGMEM = "The π-Puppid meteor shower reaches its\npeak.";
const char ASTRO_DESC_254[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_255[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_256[] PROGMEM = "The η-Aquariid meteor shower reaches\nits peak.";
const char ASTRO_DESC_257[] PROGMEM = "The η-Lyrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_258[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_259[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_260[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 5°41'.";
const char ASTRO_DESC_261[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 2°56'.";
const char ASTRO_DESC_262[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_263[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n3°05'.";
const char ASTRO_DESC_264[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_265[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_266[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_267[] PROGMEM = "Venus is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_268[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_269[] PROGMEM = "Venus and Jupiter share the same right\nascension, at a separation of 1°38'.";
const char ASTRO_DESC_270[] PROGMEM = "Venus and Jupiter pass within 1°36' of\neach other.";
const char ASTRO_DESC_271[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_272[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_273[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°11'.";
const char ASTRO_DESC_274[] PROGMEM = "The Daytime Arietid meteor shower\nreaches its peak.";
const char ASTRO_DESC_275[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_276[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_277[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n2°32'.";
const char ASTRO_DESC_278[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_279[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 17'.";
const char ASTRO_DESC_280[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_281[] PROGMEM = "21 June will be the longest day of 2026\nin the northern hemisphere.";
const char ASTRO_DESC_282[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_283[] PROGMEM = "The June Bootid meteor shower reaches\nits peak.";
const char ASTRO_DESC_284[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_285[] PROGMEM = "The Earth reaches its furthest point\nfrom the Sun.";
const char ASTRO_DESC_286[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_287[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_288[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°39'.";
const char ASTRO_DESC_289[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_290[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_291[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 5°19'.";
const char ASTRO_DESC_292[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_293[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 2°01'.";
const char ASTRO_DESC_294[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_295[] PROGMEM = "Saturn reverses its direction of motion\nacross the sky.";
const char ASTRO_DESC_296[] PROGMEM = "The Piscis Austrinid meteor shower\nreaches its peak.";
const char ASTRO_DESC_297[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_298[] PROGMEM = "The Southern δ-Aquariid meteor shower\nreaches its peak.";
const char ASTRO_DESC_299[] PROGMEM = "The α-Capricornid meteor shower reaches\nits peak.";
const char ASTRO_DESC_300[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_301[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_302[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°57'.";
const char ASTRO_DESC_303[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_304[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_305[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_306[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_307[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 4°24'.";
const char ASTRO_DESC_308[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_309[] PROGMEM = "There will be an eclipse of the Sun,\nvisible from eastern  Greenland and\nSpain.";
const char ASTRO_DESC_310[] PROGMEM = "Venus reaches half phase in the evening\nsky.";
const char ASTRO_DESC_311[] PROGMEM = "The Perseid meteor shower reaches its\npeak.";
const char ASTRO_DESC_312[] PROGMEM = "Venus is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_313[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_314[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 2°04'.";
const char ASTRO_DESC_315[] PROGMEM = "The κ-Cygnid meteor shower reaches its\npeak.";
const char ASTRO_DESC_316[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_317[] PROGMEM = "There will be an eclipse of the Moon,\nvisible from the Americas, Antarctica,\nAfrica and Europe.";
const char ASTRO_DESC_318[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_319[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_320[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 7°02'.";
const char ASTRO_DESC_321[] PROGMEM = "The Aurigid meteor shower reaches its\npeak.";
const char ASTRO_DESC_322[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_323[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_324[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 3°00'.";
const char ASTRO_DESC_325[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_326[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of 50'.";
const char ASTRO_DESC_327[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_328[] PROGMEM = "The September ε-Perseid meteor shower\nreaches its peak.";
const char ASTRO_DESC_329[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 31'.";
const char ASTRO_DESC_330[] PROGMEM = "The Moon and Venus pass close to each\nother.";
const char ASTRO_DESC_331[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_332[] PROGMEM = "Venus reaches its greatest brightness in\nthe evening sky.";
const char ASTRO_DESC_333[] PROGMEM = "Day and night have equal length: the\nbeginning of astronomical autumn in the\nnorthern hemisphere.";
const char ASTRO_DESC_334[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_335[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_336[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°55'.";
const char ASTRO_DESC_337[] PROGMEM = "The Daytime Sextantid meteor shower\nreaches its peak.";
const char ASTRO_DESC_338[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_339[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_340[] PROGMEM = "Saturn is optimally positioned for\nobservation, appears at its closest,\nbrightest and largest.";
const char ASTRO_DESC_341[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 1°08'.";
const char ASTRO_DESC_342[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_343[] PROGMEM = "The October Camelopardalid meteor shower\nreaches its peak.";
const char ASTRO_DESC_344[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of 10'.";
const char ASTRO_DESC_345[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_346[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_347[] PROGMEM = "The Draconid meteor shower reaches its\npeak.";
const char ASTRO_DESC_348[] PROGMEM = "The Southern Taurid meteor shower\nreaches its peak.";
const char ASTRO_DESC_349[] PROGMEM = "The δ-Aurigid meteor shower reaches\nits peak.";
const char ASTRO_DESC_350[] PROGMEM = "Mercury is bright and well placed in the\nevening sky.";
const char ASTRO_DESC_351[] PROGMEM = "Mercury reaches half phase in the\nevening sky.";
const char ASTRO_DESC_352[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_353[] PROGMEM = "The ε-Geminid meteor shower reaches\nits peak.";
const char ASTRO_DESC_354[] PROGMEM = "The Orionid meteor shower reaches its\npeak.";
const char ASTRO_DESC_355[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_356[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°47'.";
const char ASTRO_DESC_357[] PROGMEM = "The Leonis Minorid meteor shower reaches\nits peak.";
const char ASTRO_DESC_358[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_359[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_360[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_361[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_362[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 1°03'.";
const char ASTRO_DESC_363[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_364[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of 31'.";
const char ASTRO_DESC_365[] PROGMEM = "The Northern Taurid meteor shower\nreaches its peak.";
const char ASTRO_DESC_366[] PROGMEM = "Jupiter and Mars share the same right\nascension, at a separation of 1°14'.";
const char ASTRO_DESC_367[] PROGMEM = "Jupiter and Mars pass within 1°11' of\neach other.";
const char ASTRO_DESC_368[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_369[] PROGMEM = "The Leonid meteor shower reaches its\npeak.";
const char ASTRO_DESC_370[] PROGMEM = "Mercury reaches half phase in the dawn\nsky.";
const char ASTRO_DESC_371[] PROGMEM = "The Pleiades open star cluster (M45;\nmag 1.3) in Taurus culminates at around\nmidnight local time.";
const char ASTRO_DESC_372[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_373[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_374[] PROGMEM = "Mercury is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_375[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°47'.";
const char ASTRO_DESC_376[] PROGMEM = "The α-Monocerotid meteor shower reaches\nits peak.";
const char ASTRO_DESC_377[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_378[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_379[] PROGMEM = "Venus reaches its greatest brightness in\nthe dawn sky.";
const char ASTRO_DESC_380[] PROGMEM = "The November Orionid meteor shower\nreaches its peak.";
const char ASTRO_DESC_381[] PROGMEM = "The Hyades open star cluster (Collinder\n50; mag 1.0) in Taurus culminates at\naround midnight local time.";
const char ASTRO_DESC_382[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_383[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n1°09'.";
const char ASTRO_DESC_384[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_385[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 3°20'.";
const char ASTRO_DESC_386[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";
const char ASTRO_DESC_387[] PROGMEM = "The Moon and Venus share the same right\nascension, at a separation of 7°09'.";
const char ASTRO_DESC_388[] PROGMEM = "The December φ-Cassiopeid meteor shower\nreaches its peak.";
const char ASTRO_DESC_389[] PROGMEM = "The Puppid-Velid meteor shower reaches\nits peak.";
const char ASTRO_DESC_390[] PROGMEM = "The Monocerotid meteor shower reaches\nits peak.";
const char ASTRO_DESC_391[] PROGMEM = "Saturn returns to its usual eastward\nmotion after opposition.";
const char ASTRO_DESC_392[] PROGMEM = "Venus is bright and well placed in the\ndawn sky.";
const char ASTRO_DESC_393[] PROGMEM = "The σ-Hydrid meteor shower reaches its\npeak.";
const char ASTRO_DESC_394[] PROGMEM = "Jupiter reverses its direction of motion\nacross the sky.";
const char ASTRO_DESC_395[] PROGMEM = "The Geminid meteor shower reaches its\npeak.";
const char ASTRO_DESC_396[] PROGMEM = "The Comae Berenicid meteor shower\nreaches its peak.";
const char ASTRO_DESC_397[] PROGMEM = "The Moon reaches first quarter phase –\nappearing high in the sky at sunset and\nremaining visible until around midnight.";
const char ASTRO_DESC_398[] PROGMEM = "The Moon and Saturn pass close to each\nother.";
const char ASTRO_DESC_399[] PROGMEM = "The Moon and Saturn share the same right\nascension, at a separation of 6°54'.";
const char ASTRO_DESC_400[] PROGMEM = "The December Leonis Minorid meteor\nshower reaches its peak.";
const char ASTRO_DESC_401[] PROGMEM = "21 December will be the shortest day of\n2026 in the northern hemisphere.";
const char ASTRO_DESC_402[] PROGMEM = "The Moon and M45 pass close to each\nother.";
const char ASTRO_DESC_403[] PROGMEM = "The Ursid meteor shower reaches its\npeak.";
const char ASTRO_DESC_404[] PROGMEM = "The Moon reaches full phase and is\nvisible for much of the night.";
const char ASTRO_DESC_405[] PROGMEM = "The Moon and Jupiter pass close to each\nother.";
const char ASTRO_DESC_406[] PROGMEM = "The Moon and Jupiter share the same\nright ascension, at a separation of\n1°31'.";
const char ASTRO_DESC_407[] PROGMEM = "The Moon and Mars pass close to each\nother.";
const char ASTRO_DESC_408[] PROGMEM = "The Moon and Mars share the same right\nascension, at a separation of 5°19'.";
const char ASTRO_DESC_409[] PROGMEM = "The Moon reaches last quarter phase –\nrising in the east at around midnight\nand appearing high in the sky by\nsunrise.";

const char* const ASTRO_DESCS[] PROGMEM = {
    ASTRO_DESC_0,
    ASTRO_DESC_1,
    ASTRO_DESC_2,
    ASTRO_DESC_3,
    ASTRO_DESC_4,
    ASTRO_DESC_5,
    ASTRO_DESC_6,
    ASTRO_DESC_7,
    ASTRO_DESC_8,
    ASTRO_DESC_9,
    ASTRO_DESC_10,
    ASTRO_DESC_11,
    ASTRO_DESC_12,
    ASTRO_DESC_13,
    ASTRO_DESC_14,
    ASTRO_DESC_15,
    ASTRO_DESC_16,
    ASTRO_DESC_17,
    ASTRO_DESC_18,
    ASTRO_DESC_19,
    ASTRO_DESC_20,
    ASTRO_DESC_21,
    ASTRO_DESC_22,
    ASTRO_DESC_23,
    ASTRO_DESC_24,
    ASTRO_DESC_25,
    ASTRO_DESC_26,
    ASTRO_DESC_27,
    ASTRO_DESC_28,
    ASTRO_DESC_29,
    ASTRO_DESC_30,
    ASTRO_DESC_31,
    ASTRO_DESC_32,
    ASTRO_DESC_33,
    ASTRO_DESC_34,
    ASTRO_DESC_35,
    ASTRO_DESC_36,
    ASTRO_DESC_37,
    ASTRO_DESC_38,
    ASTRO_DESC_39,
    ASTRO_DESC_40,
    ASTRO_DESC_41,
    ASTRO_DESC_42,
    ASTRO_DESC_43,
    ASTRO_DESC_44,
    ASTRO_DESC_45,
    ASTRO_DESC_46,
    ASTRO_DESC_47,
    ASTRO_DESC_48,
    ASTRO_DESC_49,
    ASTRO_DESC_50,
    ASTRO_DESC_51,
    ASTRO_DESC_52,
    ASTRO_DESC_53,
    ASTRO_DESC_54,
    ASTRO_DESC_55,
    ASTRO_DESC_56,
    ASTRO_DESC_57,
    ASTRO_DESC_58,
    ASTRO_DESC_59,
    ASTRO_DESC_60,
    ASTRO_DESC_61,
    ASTRO_DESC_62,
    ASTRO_DESC_63,
    ASTRO_DESC_64,
    ASTRO_DESC_65,
    ASTRO_DESC_66,
    ASTRO_DESC_67,
    ASTRO_DESC_68,
    ASTRO_DESC_69,
    ASTRO_DESC_70,
    ASTRO_DESC_71,
    ASTRO_DESC_72,
    ASTRO_DESC_73,
    ASTRO_DESC_74,
    ASTRO_DESC_75,
    ASTRO_DESC_76,
    ASTRO_DESC_77,
    ASTRO_DESC_78,
    ASTRO_DESC_79,
    ASTRO_DESC_80,
    ASTRO_DESC_81,
    ASTRO_DESC_82,
    ASTRO_DESC_83,
    ASTRO_DESC_84,
    ASTRO_DESC_85,
    ASTRO_DESC_86,
    ASTRO_DESC_87,
    ASTRO_DESC_88,
    ASTRO_DESC_89,
    ASTRO_DESC_90,
    ASTRO_DESC_91,
    ASTRO_DESC_92,
    ASTRO_DESC_93,
    ASTRO_DESC_94,
    ASTRO_DESC_95,
    ASTRO_DESC_96,
    ASTRO_DESC_97,
    ASTRO_DESC_98,
    ASTRO_DESC_99,
    ASTRO_DESC_100,
    ASTRO_DESC_101,
    ASTRO_DESC_102,
    ASTRO_DESC_103,
    ASTRO_DESC_104,
    ASTRO_DESC_105,
    ASTRO_DESC_106,
    ASTRO_DESC_107,
    ASTRO_DESC_108,
    ASTRO_DESC_109,
    ASTRO_DESC_110,
    ASTRO_DESC_111,
    ASTRO_DESC_112,
    ASTRO_DESC_113,
    ASTRO_DESC_114,
    ASTRO_DESC_115,
    ASTRO_DESC_116,
    ASTRO_DESC_117,
    ASTRO_DESC_118,
    ASTRO_DESC_119,
    ASTRO_DESC_120,
    ASTRO_DESC_121,
    ASTRO_DESC_122,
    ASTRO_DESC_123,
    ASTRO_DESC_124,
    ASTRO_DESC_125,
    ASTRO_DESC_126,
    ASTRO_DESC_127,
    ASTRO_DESC_128,
    ASTRO_DESC_129,
    ASTRO_DESC_130,
    ASTRO_DESC_131,
    ASTRO_DESC_132,
    ASTRO_DESC_133,
    ASTRO_DESC_134,
    ASTRO_DESC_135,
    ASTRO_DESC_136,
    ASTRO_DESC_137,
    ASTRO_DESC_138,
    ASTRO_DESC_139,
    ASTRO_DESC_140,
    ASTRO_DESC_141,
    ASTRO_DESC_142,
    ASTRO_DESC_143,
    ASTRO_DESC_144,
    ASTRO_DESC_145,
    ASTRO_DESC_146,
    ASTRO_DESC_147,
    ASTRO_DESC_148,
    ASTRO_DESC_149,
    ASTRO_DESC_150,
    ASTRO_DESC_151,
    ASTRO_DESC_152,
    ASTRO_DESC_153,
    ASTRO_DESC_154,
    ASTRO_DESC_155,
    ASTRO_DESC_156,
    ASTRO_DESC_157,
    ASTRO_DESC_158,
    ASTRO_DESC_159,
    ASTRO_DESC_160,
    ASTRO_DESC_161,
    ASTRO_DESC_162,
    ASTRO_DESC_163,
    ASTRO_DESC_164,
    ASTRO_DESC_165,
    ASTRO_DESC_166,
    ASTRO_DESC_167,
    ASTRO_DESC_168,
    ASTRO_DESC_169,
    ASTRO_DESC_170,
    ASTRO_DESC_171,
    ASTRO_DESC_172,
    ASTRO_DESC_173,
    ASTRO_DESC_174,
    ASTRO_DESC_175,
    ASTRO_DESC_176,
    ASTRO_DESC_177,
    ASTRO_DESC_178,
    ASTRO_DESC_179,
    ASTRO_DESC_180,
    ASTRO_DESC_181,
    ASTRO_DESC_182,
    ASTRO_DESC_183,
    ASTRO_DESC_184,
    ASTRO_DESC_185,
    ASTRO_DESC_186,
    ASTRO_DESC_187,
    ASTRO_DESC_188,
    ASTRO_DESC_189,
    ASTRO_DESC_190,
    ASTRO_DESC_191,
    ASTRO_DESC_192,
    ASTRO_DESC_193,
    ASTRO_DESC_194,
    ASTRO_DESC_195,
    ASTRO_DESC_196,
    ASTRO_DESC_197,
    ASTRO_DESC_198,
    ASTRO_DESC_199,
    ASTRO_DESC_200,
    ASTRO_DESC_201,
    ASTRO_DESC_202,
    ASTRO_DESC_203,
    ASTRO_DESC_204,
    ASTRO_DESC_205,
    ASTRO_DESC_206,
    ASTRO_DESC_207,
    ASTRO_DESC_208,
    ASTRO_DESC_209,
    ASTRO_DESC_210,
    ASTRO_DESC_211,
    ASTRO_DESC_212,
    ASTRO_DESC_213,
    ASTRO_DESC_214,
    ASTRO_DESC_215,
    ASTRO_DESC_216,
    ASTRO_DESC_217,
    ASTRO_DESC_218,
    ASTRO_DESC_219,
    ASTRO_DESC_220,
    ASTRO_DESC_221,
    ASTRO_DESC_222,
    ASTRO_DESC_223,
    ASTRO_DESC_224,
    ASTRO_DESC_225,
    ASTRO_DESC_226,
    ASTRO_DESC_227,
    ASTRO_DESC_228,
    ASTRO_DESC_229,
    ASTRO_DESC_230,
    ASTRO_DESC_231,
    ASTRO_DESC_232,
    ASTRO_DESC_233,
    ASTRO_DESC_234,
    ASTRO_DESC_235,
    ASTRO_DESC_236,
    ASTRO_DESC_237,
    ASTRO_DESC_238,
    ASTRO_DESC_239,
    ASTRO_DESC_240,
    ASTRO_DESC_241,
    ASTRO_DESC_242,
    ASTRO_DESC_243,
    ASTRO_DESC_244,
    ASTRO_DESC_245,
    ASTRO_DESC_246,
    ASTRO_DESC_247,
    ASTRO_DESC_248,
    ASTRO_DESC_249,
    ASTRO_DESC_250,
    ASTRO_DESC_251,
    ASTRO_DESC_252,
    ASTRO_DESC_253,
    ASTRO_DESC_254,
    ASTRO_DESC_255,
    ASTRO_DESC_256,
    ASTRO_DESC_257,
    ASTRO_DESC_258,
    ASTRO_DESC_259,
    ASTRO_DESC_260,
    ASTRO_DESC_261,
    ASTRO_DESC_262,
    ASTRO_DESC_263,
    ASTRO_DESC_264,
    ASTRO_DESC_265,
    ASTRO_DESC_266,
    ASTRO_DESC_267,
    ASTRO_DESC_268,
    ASTRO_DESC_269,
    ASTRO_DESC_270,
    ASTRO_DESC_271,
    ASTRO_DESC_272,
    ASTRO_DESC_273,
    ASTRO_DESC_274,
    ASTRO_DESC_275,
    ASTRO_DESC_276,
    ASTRO_DESC_277,
    ASTRO_DESC_278,
    ASTRO_DESC_279,
    ASTRO_DESC_280,
    ASTRO_DESC_281,
    ASTRO_DESC_282,
    ASTRO_DESC_283,
    ASTRO_DESC_284,
    ASTRO_DESC_285,
    ASTRO_DESC_286,
    ASTRO_DESC_287,
    ASTRO_DESC_288,
    ASTRO_DESC_289,
    ASTRO_DESC_290,
    ASTRO_DESC_291,
    ASTRO_DESC_292,
    ASTRO_DESC_293,
    ASTRO_DESC_294,
    ASTRO_DESC_295,
    ASTRO_DESC_296,
    ASTRO_DESC_297,
    ASTRO_DESC_298,
    ASTRO_DESC_299,
    ASTRO_DESC_300,
    ASTRO_DESC_301,
    ASTRO_DESC_302,
    ASTRO_DESC_303,
    ASTRO_DESC_304,
    ASTRO_DESC_305,
    ASTRO_DESC_306,
    ASTRO_DESC_307,
    ASTRO_DESC_308,
    ASTRO_DESC_309,
    ASTRO_DESC_310,
    ASTRO_DESC_311,
    ASTRO_DESC_312,
    ASTRO_DESC_313,
    ASTRO_DESC_314,
    ASTRO_DESC_315,
    ASTRO_DESC_316,
    ASTRO_DESC_317,
    ASTRO_DESC_318,
    ASTRO_DESC_319,
    ASTRO_DESC_320,
    ASTRO_DESC_321,
    ASTRO_DESC_322,
    ASTRO_DESC_323,
    ASTRO_DESC_324,
    ASTRO_DESC_325,
    ASTRO_DESC_326,
    ASTRO_DESC_327,
    ASTRO_DESC_328,
    ASTRO_DESC_329,
    ASTRO_DESC_330,
    ASTRO_DESC_331,
    ASTRO_DESC_332,
    ASTRO_DESC_333,
    ASTRO_DESC_334,
    ASTRO_DESC_335,
    ASTRO_DESC_336,
    ASTRO_DESC_337,
    ASTRO_DESC_338,
    ASTRO_DESC_339,
    ASTRO_DESC_340,
    ASTRO_DESC_341,
    ASTRO_DESC_342,
    ASTRO_DESC_343,
    ASTRO_DESC_344,
    ASTRO_DESC_345,
    ASTRO_DESC_346,
    ASTRO_DESC_347,
    ASTRO_DESC_348,
    ASTRO_DESC_349,
    ASTRO_DESC_350,
    ASTRO_DESC_351,
    ASTRO_DESC_352,
    ASTRO_DESC_353,
    ASTRO_DESC_354,
    ASTRO_DESC_355,
    ASTRO_DESC_356,
    ASTRO_DESC_357,
    ASTRO_DESC_358,
    ASTRO_DESC_359,
    ASTRO_DESC_360,
    ASTRO_DESC_361,
    ASTRO_DESC_362,
    ASTRO_DESC_363,
    ASTRO_DESC_364,
    ASTRO_DESC_365,
    ASTRO_DESC_366,
    ASTRO_DESC_367,
    ASTRO_DESC_368,
    ASTRO_DESC_369,
    ASTRO_DESC_370,
    ASTRO_DESC_371,
    ASTRO_DESC_372,
    ASTRO_DESC_373,
    ASTRO_DESC_374,
    ASTRO_DESC_375,
    ASTRO_DESC_376,
    ASTRO_DESC_377,
    ASTRO_DESC_378,
    ASTRO_DESC_379,
    ASTRO_DESC_380,
    ASTRO_DESC_381,
    ASTRO_DESC_382,
    ASTRO_DESC_383,
    ASTRO_DESC_384,
    ASTRO_DESC_385,
    ASTRO_DESC_386,
    ASTRO_DESC_387,
    ASTRO_DESC_388,
    ASTRO_DESC_389,
    ASTRO_DESC_390,
    ASTRO_DESC_391,
    ASTRO_DESC_392,
    ASTRO_DESC_393,
    ASTRO_DESC_394,
    ASTRO_DESC_395,
    ASTRO_DESC_396,
    ASTRO_DESC_397,
    ASTRO_DESC_398,
    ASTRO_DESC_399,
    ASTRO_DESC_400,
    ASTRO_DESC_401,
    ASTRO_DESC_402,
    ASTRO_DESC_403,
    ASTRO_DESC_404,
    ASTRO_DESC_405,
    ASTRO_DESC_406,
    ASTRO_DESC_407,
    ASTRO_DESC_408,
    ASTRO_DESC_409
};

#endif
