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
    vector<extension> ext_configs;
};


#endif //OFIG_CONFIG_DATA_STRUCTURE_H
