#include "accdb.h"

accdb::accdb(string s_hostname,
             string s_port,
             string s_username,
             string s_passwd,
             string s_db,
             int s_mode)
{
    /* Constructor mean */
    hostname = s_hostname;
    port = s_port;
    username = s_username;
    passwd = s_passwd;
    db = s_db;
    mode = s_mode;
};

accdb::~accdb(){
    /* ini destruktor */

    cout <<"(.)(.)===>>>"<<endl;
}

int accdb::WriteToDB(){
    int status;

    cout<<"menulis ke db"<<endl;

    status =1;
    /* if there is no error status = 1 */
    return status;

}


void accdb::testing_db(){
    /* just for testing database */
    cout<<"tested"<<endl;
    cout<<"host     : "<<this->hostname<<endl;
    cout<<"username : "<<this->username<<endl;
    cout<<"password : "<<this->passwd<<endl;
    cout<<"port     : "<<this->port<<endl;
    cout<<"database : "<<this->db<<endl;
    cout<<"mode     : "<<this->mode<<endl;


    /* write database*/

    /* read database */


}
