#ifndef OFIG_PHP_DETECTOR_H
#define OFIG_PHP_DETECTOR_H

#include <sstream>
#include <core/helpers.h>


using namespace std;

bool isPHPInstalled() {
    string result = execAndGetResult("php -v");
    if (result.find("not found") != string::npos) {
        cout << "PHP is not installed" << '\n';
        return false;
    }
    return true;
}

void getPhpConfigDir() {
    string php_grep = execAndGetResult("php -i | grep 'Configuration File' ");
    stringstream parse(php_grep);
}


#endif //OFIG_PHP_DETECTOR_H
