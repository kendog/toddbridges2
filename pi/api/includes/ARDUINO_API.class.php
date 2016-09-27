<?php

require_once 'API.class.php';
require_once 'DB.class.php';

class ARDUINO_API extends API
{
    //protected $User;
    protected $db;
    protected $serial;

    public function __construct($request, $origin) {
        parent::__construct($request);

		$server = "localhost";
		$username = "api_user";
		$password = "password";
		$database = "eg";
		
		$this->db = new DB($server,$username,$password,$database);

    }

    /**
     * Endpoint: users
     */
     protected function users() {
        if ($this->method == 'GET') {
        	$sql = "SELECT * from Users";
			return $this->db->select($sql);
        } else {
            return "Wrong Method";
        }
     }
     
    /**
     * Endpoint: analog
     */
     protected function analog() {
        if ($this->method == 'GET') {
        
        	$result = [];
        	$result["status"] = "error";
        
        	$sql = "SELECT * from Analog";
        	$resultset = $this->db->select($sql);

	        if ($resultset)	{
	        	$result["results"] = $resultset;
        		$result["status"] = "success";
			}
			
			return $result;


        } else if ($this->method == 'POST') {        
        
        	$body = json_decode($this->file,true);
        
        	$result = [];
        	$result["status"] = "no changes";
       		$items = [];	        		
        		
			foreach ($body as $key => $value) {
	        	$sql = "UPDATE Analog SET value='" . $value . "' WHERE name='" . $key . "'";	        	
	        	if ($this->db->query($sql))	{
		        	$items[$key] = $value;
        			$result["status"] = "success";
	        	}	        	
			}
        	$result["updated"] = $items;

			return $result;
			
        } else {
            return "Wrong Method";
        }
     }
     
    /**
     * Endpoint: syncdb
     */
     protected function syncdb() {
        if ($this->method == 'GET') {
        	system('/usr/bin/python /var/www/html/services/analogRead.py > /dev/null 2>&1');		
        	$result["status"] = "success";        	
        	return $result;
        } else {
            return "Wrong Method";
        }
     }
     
 };
 ?>