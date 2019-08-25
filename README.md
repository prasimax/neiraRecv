# Untuk database percobaan

```bash
CREATE TABLE IF NOT EXISTS sippoh (
    id INT AUTO_INCREMENT,
    title VARCHAR(255),
    start_date DATE,
    due_date DATE,
    status TINYINT,
    priority TINYINT,
    description TEXT,
    PRIMARY KEY (id)
);
```


## Akses
```sh
username : trumonuser
password : trumonpassword
port : 3306
database : sippoh
```
# neiraRecv
