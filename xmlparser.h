#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace::std;

enum Chars
{
    LB = '<', RB = '>', DI = '?',
    ET = '/', EM = '!', DS = '-'
};

class XmlParser
{
private:
    string file_path;
    bool still_searching;
    string xml_version;
    string encoding;
    map<string, string> variables_and_values_list;
public:
    void get_file_path(string);
    void parse();
    void message(string);
    void check_file(bool);
    void analysis(string);
    XmlParser();
    ~XmlParser();
};

#endif // XMLPARSER_H
