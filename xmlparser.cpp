#include "xmlparser.h"

void XmlParser::get_file_path(string file_path)
{
    this->file_path = file_path;
}

void XmlParser::parse()
{
    ifstream configXML (file_path.c_str(), ios::out);
    check_file(configXML.is_open());

    string row;
    while (getline(configXML, row))
    {
//        cout << row << endl;
        analysis(row);
    }

    configXML.close();
}

void XmlParser::message(string info)
{
    cout << "------------------------------" << endl;
    cout << info << endl;
    cout << "------------------------------" << endl;
}

void XmlParser::check_file(bool is_open)
{
    if (is_open)
    {
        message("XML file loaded successfully");
    }
    else
    {
        message("Error in atempt to read XML file");
        exit(-1);
    }
}

void XmlParser::analysis(string row)
{

    if (row.find(Chars::LB) != string::npos && row.find(Chars::RB) != string::npos)
    {
        if (row.find(Chars::DI) != string::npos && row.rfind(Chars::DI) != string::npos && ( row.find(Chars::DI) != row.rfind(Chars::DI) ))
        {
            if (row.find("version") != string::npos)
            {
                size_t version_pos_first = row.find("\"") != string::npos ? row.find("\"") : row.find("'");
                row.erase(row.begin(), row.begin() + version_pos_first + 1);
                size_t version_pos_last = row.find("\"") != string::npos ? row.find("\"") : row.find("'");

                xml_version = row.substr(0, version_pos_last);
                row.erase(row.begin(), row.begin() + version_pos_last + 1);
            }
            if (row.find("encoding") != string::npos)
            {
//                cout << row << endl;
                size_t encoding_pos_first = row.find("\"") != string::npos ? row.find("\"") : row.find("'");
                row.erase(row.begin(), row.begin() + encoding_pos_first + 1);
                size_t encoding_pos_last = row.find("\"") != string::npos ? row.find("\"") : row.find("'");

//                cout << row << endl;

                encoding = row.substr(0, encoding_pos_last);
            }
        }
    }
}

XmlParser::XmlParser()
{
    // test path
    file_path = "/home/maxwell/QTProjects/ReadAndCount/Config/parameters.xml";
    still_searching = false;
}

XmlParser::~XmlParser()
{
    cout << xml_version << endl;
    cout << encoding << endl;
//    xml_version.clear();
//    encoding.clear();
}
