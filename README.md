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
database : testrumon 
table : sippoh
```
# neiraRecv

How to use 

```bash
NeiraRecv hostname port username password db
```

Add sql command for creating database 

```sql

CREATE TABLE `NeiraRecv` (
`id` INT(11) NOT NULL AUTO_INCREMENT,
`data` BLOB NOT NULL,
`created_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY (`id`)
);

```