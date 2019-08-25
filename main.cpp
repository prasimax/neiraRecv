#include <QCoreApplication>
#include "myserver.h"
#include "accdb.h"


int main(int argc, char *argv[])
{


    //MyServer server;
    //server.startServer();

    /* Check connection database */

    /*test variable */
    int mode = 1;
    int stats;
    string host=argv[1];
    string port = argv[2];
    string uname = argv[3];
    string passwd = argv[4];
    string db = argv[5];

    accdb akses_db(host, port, uname, passwd, db, mode);
    //akses_db.testing_db();
    akses_db.WriteToDB();

    cout <<"status"<<endl;



    return 0;
}
