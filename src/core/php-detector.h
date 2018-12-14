#include "helpers.h"

#ifndef OFIG_PHP_DETECTOR_H
#define OFIG_PHP_DETECTOR_H

using namespace std;

void isPHPInstalled() {
    cout << "Result: " << exec("php -v");
}


#endif //OFIG_PHP_DETECTOR_H