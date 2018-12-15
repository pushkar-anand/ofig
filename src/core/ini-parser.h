#ifndef OFIG_INI_PARSER_H
#define OFIG_INI_PARSER_H

#include <fstream>
#include <cstdio>
#include <core/helpers.h>
#include <core/config-data-structure.h>
#include <sstream>

string orig_name = "php.orig.ini";

void remove_comments(const string &ini_file_path) {
    fstream infile, outfile;

    infile.open(ini_file_path.c_str(), ios::in);
    outfile.open("php.parsed.ini", ios::out);

    string x;
    char comment_char = ';';
    while (infile) {
        getline(infile, x);
        auto first_char = x.front();

        if (first_char != comment_char && !x.empty()) {
            outfile << x << endl;
        }
    }
    infile.close();
    outfile.close();

    rename(ini_file_path.c_str(), orig_name.c_str());
    rename("php.parsed.ini", "php.ini");
}

iniData parse(const string &ini_file_path) {
    configValuePair value_pair;
    vector<configValuePair> value_pair_list;

    extension ext_data;
    vector<extension> ext_data_list;

    iniData ini_data;

    fstream infile;
    string line;
    bool first_ext = true;

    infile.open(ini_file_path.c_str(), ios::in);

    while (infile) {
        getline(infile, line);
        if (!line.empty()) {
            auto first_char = line.front();

            if (first_char == '[') {
                unsigned long first = line.find('[');
                unsigned long last = line.find(']');
                string strNew = line.substr(first + 1, last - first - 1);
                ext_data.ext_name = strNew;
                if (first_ext) {
                    first_ext = false;
                } else {
                    ext_data.configs = value_pair_list;
                    value_pair_list.clear();
                    ext_data_list.emplace_back(ext_data);
                }
            } else {
                stringstream stream(line);
                string config, eq, val;

                stream >> config >> eq >> val;

                value_pair.name = config;
                value_pair.value = val;
                //cout<<config<<" is set to "<<val<<endl;
                value_pair_list.emplace_back(value_pair);
            }
        }
    }
    ini_data.ext_configs = ext_data_list;
    infile.close();
    return ini_data;
}


iniData parse_ini(const string &ini_file_path) {
    if (!file_exists(orig_name)) {
        remove_comments(ini_file_path);
    }
    return parse(ini_file_path);
}


#endif //OFIG_INI_PARSER_H
