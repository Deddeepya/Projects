<?php
// Start session
session_start();

// Check if 'schedule_info' key exists in POST data
if (isset($_POST['schedule_info'])) {
    // Decode JSON data into PHP associative array
    $schedule_info = json_decode($_POST['schedule_info'], true);

    // Validate JSON decoding
    if ($schedule_info !== null) {
        // Access and process the received data
        $schedule_id = $schedule_info['schedule_id'];
        $bus_id = $schedule_info['bus_id'];
        $bus_no = $schedule_info['bus_no'];
        $origin = $schedule_info['origin'];
        $destination = $schedule_info['destination'];
        $dep_date = $schedule_info['dep_date'];
        $dep_time = $schedule_info['dep_time'];
        $arr_time = $schedule_info['arr_time'];
        $duration = $schedule_info['duration'];
        $distance = $schedule_info['distance'];
        $price = $schedule_info['price'];

        // Store data in session variables
        $_SESSION['schedule_id'] = $schedule_id;
        $_SESSION['bus_id'] = $bus_id;
        $_SESSION['bus_no'] = $bus_no;
        $_SESSION['origin'] = $origin;
        $_SESSION['destination'] = $destination;
        $_SESSION['dep_date'] = $dep_date;
        $_SESSION['dep_time'] = $dep_time;
        $_SESSION['arr_time'] = $arr_time;
        $_SESSION['duration'] = $duration;
        $_SESSION['distance'] = $distance;
        $_SESSION['price'] = $price;

        // Return success message (optional)
        echo "Session variables set successfully.";
    } else {
        echo "Error decoding JSON data.";
    }
} else {
    echo "No 'schedule_info' data received.";
}
?>
