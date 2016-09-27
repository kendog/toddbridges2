<?php

class DB
{

    protected static $connection;

    protected $server;
    protected $username;
    protected $password;
    protected $database;

    public function __construct($server, $username, $password, $db) {
    
        $this->server = $server;
        $this->username = $username;
        $this->password = $password;
        $this->database = $db;

    }

    /**
     * Connect to the database
     */
    public function connect() {    
        if(!isset(self::$connection)) {
            self::$connection = new mysqli($this->server,$this->username,$this->password,$this->database);
        }
        if(self::$connection === false) {
            return false;
        }
        return self::$connection;
    }

    /**
     * Query the database
     */
    public function query($sql) {
        // Connect to the database
        $connection = $this->connect();

        // Query the database
        $result = $connection -> query($sql);

        return $result;
    }

    /**
     * Fetch rows from the database (SELECT query)
     */
    public function select($sql) {
        $rows = array();
        $result = $this -> query($sql);
        if($result === false) {
            return false;
        }
        while ($row = $result -> fetch_assoc()) {
            $rows[] = $row;
        }
        return $rows;
    }

};
?>