//
// Created by dovyj on 17/04/2024.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "board.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;


void board::tap() {
    for (Bug* bug : bug_vector) {
        bug->move();
    }
}
