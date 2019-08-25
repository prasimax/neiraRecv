#ifndef ACCDB_H
#define ACCDB_H

/* for standard libary*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <typeinfo>

/* for database connection */
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

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
    void WriteToDB();
    ~accdb();

private:
    string hostname;
    string port;
    string username;
    string passwd;
    string db;
    int mode;

    


};

#endif // ACCDB_H
