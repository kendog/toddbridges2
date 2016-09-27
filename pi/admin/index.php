<?php
$servername = "localhost";
$username = "api_user";
$password = "password";
$dbname = "eg";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT * FROM Analog";
$result = $conn->query($sql);
$conn->close();
?>

<html>
	<head>
		<title>Electric Garden Admin</title>
		<link rel="stylesheet" type="text/css" href="css/styles.css">
	</head>

	<body>


		<ul class="analogin">
<?php
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
?>
			<li><div><?php echo $row["name"]?></div><div><?php echo $row["value"]?></div></li>
<?php
    }
}
?>
		</ul>


	</body>
</html>
