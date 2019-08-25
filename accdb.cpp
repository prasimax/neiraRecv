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

void accdb::WriteToDB(){
    struct membuf : streambuf {
    membuf(char* base, std::size_t n) {
            this->setg(base, base, base + n);
        }
    };
    

    /* just for testing database */
    cout<<"tested"<<endl;
    cout<<"host     : "<<this->hostname<<endl;
    cout<<"username : "<<this->username<<endl;
    cout<<"password : "<<this->passwd<<endl;
    cout<<"port     : "<<this->port<<endl;
    cout<<"database : "<<this->db<<endl;
    cout<<"mode     : "<<this->mode<<endl;

    /* Variable declaration ***********************************************/
    streampos size;
    char * memblock;

    /* Declare filename */
    ifstream file("temporal.txt", ios::in|ios::binary|ios::ate);
    //ofstream myFile ("kalista.jpg", ios::out | ios::binary);
    size_t length_buff;


    try{
        /* SQL dependency needed to executeQuery ******************************/
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement *prep_stmt;


        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect(this->hostname, this->username, this->passwd);



        /* Connect to the MySQL Trumon database */
        con->setSchema(this->db);
        stmt = con->createStatement();

        /* cek read and write file **********************************************/
        if(file.is_open()){
            /* This function will insert the Blob *********************************/
            size= file.tellg();
            memblock = new char[size];
            file.seekg(0, ios::beg);
            file.read(memblock, size);
            cout<<"Size"<<size<<endl;
            //instance lenth_buff to get lenght buffer
            length_buff = size;
            cout<<"length_buff keeksekusi"<<endl;

            membuf mbuf(memblock, length_buff);
            istream blob_file(&mbuf);

            file.close();
            cout<<"The entire file content is in memory"<<endl;

            prep_stmt = con->prepareStatement("INSERT INTO NeiraRecv(data) VALUES (?)");
            
            prep_stmt->setBlob(1, &blob_file);
            prep_stmt->executeUpdate();

            /* close some varieble to release connection and memory */
            delete prep_stmt;
            delete con;
            delete stmt;
            delete[] memblock;
        }

        else {
            cout <<"Unable ot open file"<<endl;
        }

        cout << "ending of the day"<<endl;
        
    }
    catch(sql::SQLException &e){
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "Something error"<< endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    
    /* if there is no error status = 1 */
    

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
     try{
      /* Sql driver to check driver statements *****************************/
      sql::Driver *driver;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      sql::PreparedStatement *insert_stmt, *prep_stmt, *update_stmt;

      /**********************************************************************/
      cout<<"Write to text table "<<endl;
      driver = get_driver_instance();
      con = driver->connect(this->hostname, this->username, this->passwd);
      con->setSchema(this->db);

      /* Insert statement *************************************/
      insert_stmt  = con->prepareStatement("INSERT INTO sippoh (title) VALUES (?)");
      insert_stmt -> setString(1, "percobaan");

      insert_stmt -> executeUpdate();




      /* Clean all memory ***************************************************/
      //delete driver
      delete con;
      delete stmt;
      delete res;
      delete prep_stmt;
      delete update_stmt;
      delete insert_stmt;

    }
    catch(sql::SQLException &e){
      /* SQL Exceptions *****************************************************/
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "Something error"<< endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }


    /* read database */


}
