<?php
// Start session
session_start();

// Check if session variables are set
if (isset($_SESSION['schedule_id'], $_SESSION['bus_id'], $_SESSION['bus_no'], $_SESSION['origin'], $_SESSION['destination'], $_SESSION['dep_date'], $_SESSION['dep_time'], $_SESSION['arr_time'], $_SESSION['duration'], $_SESSION['distance'], $_SESSION['price'])) {
    // Access session variables
    $schedule_id = $_SESSION['schedule_id'];
    $bus_id = $_SESSION['bus_id'];
    $bus_no = $_SESSION['bus_no'];
    $origin = $_SESSION['origin'];
    $destination = $_SESSION['destination'];
    $dep_date = $_SESSION['dep_date'];
    $dep_time = $_SESSION['dep_time'];
    $arr_time = $_SESSION['arr_time'];
    $duration = $_SESSION['duration'];
    $distance = $_SESSION['distance'];
    $price = $_SESSION['price'];

    // Display session data
    echo "<h2>Schedule Information</h2>";
    echo "Schedule ID: " . htmlspecialchars($schedule_id) . "<br>";
    echo "Bus ID: " . htmlspecialchars($bus_id) . "<br>";
    echo "Bus Number: " . htmlspecialchars($bus_no) . "<br>";
    echo "Origin: " . htmlspecialchars($origin) . "<br>";
    echo "Destination: " . htmlspecialchars($destination) . "<br>";
    echo "Departure Date: " . htmlspecialchars($dep_date) . "<br>";
    echo "Departure Time: " . htmlspecialchars($dep_time) . "<br>";
    echo "Arrival Time: " . htmlspecialchars($arr_time) . "<br>";
    echo "Duration: " . htmlspecialchars($duration) . "<br>";
    echo "Distance: " . htmlspecialchars($distance) . "<br>";
    echo "Price: " . htmlspecialchars($price) . "<br>";
} else {
    echo "Session variables not set.";
}
?>
