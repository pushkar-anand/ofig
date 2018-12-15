#ifndef OFIG_CONFIG_DATA_STRUCTURE_H
#define OFIG_CONFIG_DATA_STRUCTURE_H

#include <string>
#include <vector>

using namespace std;

struct configValuePair {
    string name;
    string value;
    string name_hash;
};

struct extension {
    string ext_name;
    vector<configValuePair> configs;
};

struct iniData {
    //for PHP default config
    extension php_default;
    //for all other extensions
    vector<extension> ext_configs;

    iniData() {
        php_default.ext_name = "PHP";
    }
};


#endif //OFIG_CONFIG_DATA_STRUCTURE_H
