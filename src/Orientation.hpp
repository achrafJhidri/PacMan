#pragma once
#pragma clang diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-function"

enum class Orientation {
    NONE = 0,
    
    // Basic
    NORTH = 1 << 0,
    SOUTH = 1 << 1,
    EAST =  1 << 2,
    WEST =  1 << 3,

    // Composed
    NORTH_EAST = NORTH | EAST,
    NORTH_WEST = NORTH | WEST,
    SOUTH_EAST = SOUTH | EAST,
    SOUTH_WEST = SOUTH | WEST,
};

static bool operator&(Orientation o1, Orientation o2) {
    return ((int)o1 & (int)o2) != 0;
}
