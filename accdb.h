#ifndef ACCDB_H
#define ACCDB_H

#include <iostream>

/* for database connection */


using namespace std;

class accdb
{

public:
    accdb(string s_hostname,
          string s_port,
          string s_username,
          string s_passwd,
          string s_db,
          int s_mode);
    void testing_db();
    ~accdb();

private:
    string hostname;
    string port;
    string username;
    string passwd;
    string db;
    int mode;

    int WriteToDB();


};

#endif // ACCDB_H
