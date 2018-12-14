#include "helpers.h"

#ifndef OFIG_PHP_DETECTOR_H
#define OFIG_PHP_DETECTOR_H

using namespace std;

bool isPHPInstalled() {
    string result = exec("php -v");
    if (result.find("not found") != string::npos) {
        cout << "PHP is not installed" << '\n';
        return false;
    }
    return true;
}

void getPhpConfigDir() {
    string php_grep = exec("php -i | grep 'Configuration File' ");
}


#endif //OFIG_PHP_DETECTOR_H
