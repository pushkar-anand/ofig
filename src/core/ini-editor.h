#ifndef OFIG_INI_EDITOR_H
#define OFIG_INI_EDITOR_H

#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

void edit(const string &ini_file_path, const string &config_to_edit, const string &new_value) {
    fstream infile, outfile;
    infile.open(ini_file_path.c_str(), ios::in);
    outfile.open("php.ini.temp", ios::out);
    string line;
    long curr_pos;
    while (infile) {
        curr_pos = infile.tellg();
        getline(infile, line);
        if (!line.empty()) {
            auto first_char = line.front();

            if (first_char != '[') {
                stringstream stream(line);
                string read_config, eq, cur_val;
                stream >> read_config >> eq >> cur_val;

                if (config_to_edit == read_config) {
                    string wr;
                    wr += config_to_edit;
                    wr += " = ";
                    wr += new_value;
                    outfile << wr << endl;
                } else {
                    outfile << line << endl;
                }
            } else {
                outfile << line << endl;
            }
        }
    }
    infile.close();
    outfile.close();
    remove(ini_file_path.c_str());
    rename("php.ini.temp", ini_file_path.c_str());
}


#endif //OFIG_INI_EDITOR_H
