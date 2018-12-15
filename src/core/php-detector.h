#ifndef OFIG_PHP_DETECTOR_H
#define OFIG_PHP_DETECTOR_H

#include <sstream>
#include <vector>
#include <core/helpers.h>


using namespace std;

bool isPHPInstalled() {
    string result = execAndGetResult("php -v");
    if (result.find("not found") != string::npos) {
        cout << "PHP is not installed" << endl;
        return false;
    }
    return true;
}

vector<string> getPhpConfigDir() {
    vector<string> list;
    if (isPHPInstalled()) {
        string php_grep = execAndGetResult("php -i | grep 'Configuration File' ");
        stringstream parse(php_grep);

        string x, config_path, config_file;
        parse >> x >> x >> x >> x >> x >> config_path;
        parse >> x >> x >> x >> x >> config_file;
        list.emplace_back(config_path);

        //TODO load other config
    }
    return list;
}


#endif //OFIG_PHP_DETECTOR_H
