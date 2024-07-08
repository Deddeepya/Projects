<?php

  $origin = htmlspecialchars($_POST['from']);
  $destination = htmlspecialchars($_POST['to']);
  $date = htmlspecialchars($_POST['date']);

  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "bus_ticket_booking";

  // Create connection
  $conn = new mysqli($servername, $username, $password, $dbname);

  // Check connection
  if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
  }

  $sql = "SELECT t.schedule_id,bus_id, bus_number, origin, destination, departure_time, arrival_time, distance, date, 36-COUNT(booking_id) as available_seats
  FROM (
      SELECT schedule_id, bus_id, bus_number, origin, destination, departure_time, arrival_time, distance, date
      FROM Schedules
      NATURAL JOIN Routes
      NATURAL JOIN Buses
      WHERE origin = ? AND destination = ? AND date = ?
  ) as t
  LEFT JOIN Bookings ON Bookings.schedule_id = t.schedule_id
  GROUP BY bus_id, bus_number, origin, destination, departure_time, arrival_time, distance, date,schedule_id";

  // Prepare and bind
  $stmt = $conn->prepare($sql);
  $stmt->bind_param("sss", $origin, $destination, $date);

  // Execute the statement
  $stmt->execute();

  // Get the result
  $result = $stmt->get_result();
  // echo $result->num_rows;

  // Initialize an array to store the rows
$rows = array();

// Fetch each row and store it in the array
while ($row = $result->fetch_assoc()) {
    $rows[] = $row;
}

// Free the result set
$result->free();

// Close the statement
$stmt->close();

// Close the connection
$conn->close();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous"> -->
    <link rel="stylesheet" href="navbar.css?v12cgn34">
    <link rel="stylesheet" href="busses.css?hyhydrj">
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script>
      function highlight(element) {
          element.style.transform = "scale(1.01)";
          element.style.backgroundColor = "#ffdd77";
          element.style.boxShadow = "5px 5px 20px black";
          element.style.cursor = "pointer";
        }

      function un_highlight(element){
        element.style.transform = "scale(1)";
        element.style.backgroundColor = "rgb(255, 255, 255)";
        element.style.boxShadow = "0px 0px 0px black";
        element.style.cursor = "default";
      }
    </script>
</head>
<body style="margin: 0px; background-color: rgb(58, 55, 55);">
  <div class="header">
    <div class="navbar-container">
      <ul class="navbar">
        <li class="nav">
          <a class="nav-text" href="welcome.html">HOME</a>
        </li>
        <li class="nav">
          <a class="nav-text" href="#">ABOUT US</a>
        </li>
        <li class="nav">
          <a class="nav-text" href="#">CONTACT</a>
        </li>
        <li class="nav">
          <a class="nav-text" href="#">SIGN IN</a>
        </li>
      </ul>
    </div>
  </div>
  

  <div style="margin: auto; margin-top: 50px; width: fit-content;">
    <h2 style="color : #ffc107;">
    <?php
    echo count($rows).' Results Found !';
    ?>  
    </h2>
  </div>

  <div class="schedule-list-container">
    <ul class="schedule-list">
        
    <?php

      $i = 0;
      foreach ($rows as $row) {

        $departure_time=$row["departure_time"];
        $departure_time=substr($departure_time,0,-3);

        $arrival_time=$row["arrival_time"];
        $arrival_time=substr($arrival_time,0,-3);
              
        // Convert times to DateTime objects
        $startDateTime = DateTime::createFromFormat('H:i', $departure_time);
        $endDateTime = DateTime::createFromFormat('H:i', $arrival_time);
              
        // If end time is on the next day, add 1 day to endDateTime
        if ($endDateTime < $startDateTime) {
            $endDateTime->add(new DateInterval('P1D')); // Add 1 day
        }
        
        // Calculate the interval (duration) between start and end times
        $duration = $startDateTime->diff($endDateTime);
        $duration_min = 60*($duration->h)+($duration->i); 
        $duration = $duration->h.'hr '.$duration->i.'min';

        $distance = $row["distance"];
        $price = 1200*($distance/650)*(660/$duration_min);

        $rows[$i]['departure_time'] = $departure_time;
        $rows[$i]['arrival_time'] = $arrival_time;
        $rows[$i]['date'] = $date;
        $rows[$i]['duration'] = $duration;
        $rows[$i]['distance'] = $distance;
        $rows[$i]['price'] = $price;

      echo '<li class="schedule">
          <div onmouseenter="highlight(this)" onmouseleave="un_highlight(this)" onclick="fetch_seats(this)" id="'.$i.'" class="schedule-items-list-container">
            <ul class="schedule-items-list">
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h2>BUS '.$row["bus_id"].'</h2>
                    <h5 style="margin-top: 5px;">'.$row["bus_number"].'</h5>
                  </div>
                </li>
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h2>'.$departure_time.'</h2>
                    <h5 style="margin-top: 5px;">'.$row["origin"].'</h5>
                  </div>
                </li>
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h4>'.$duration.'</h4>
                  </div>
                </li>
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h2>'.$arrival_time.'</h2>
                    <h5 style="margin-top: 5px;">'.$row["destination"].'</h5>
                  </div>
                </li>
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h5 style="display: inline;">INR</h5>
                    <h3 style="display: inline;">'.$price.'</h3>
                  </div>
                </li>
                <li class="schedule-items">
                  <div class="schedule-items-text" >
                    <h3 style="display: inline;">'.$row["available_seats"].'</h3>
                    <h5 style="display: inline;">Seats available</h5>
                  </div>
                </li>
            </ul>
          </div>
        </li>';
        $i++;
      }
      ?>
      </ul>
  </div>  

  <script>
    function fetch_seats(element){
      // let id = element.id;
      // document.write(id);
      // window.location.href = "display_session.php";

      let id = element.id;
      var rows = <?php echo json_encode($rows); ?>;
      var row = rows[id];
      
      var data = {
          schedule_id: row['schedule_id'],
          bus_id: row['bus_id'],
          bus_no: row['bus_number'],
          origin: row['origin'], 
          destination: row['destination'], 
          dep_date: row['date'],
          dep_time: row['departure_time'],
          arr_time: row['arrival_time'],
          duration: row['duration'],
          distance: row['distance'],
          price: row['price']
      };

      // Sending data to PHP via AJAX
      $.ajax({
          type: 'POST',
          url: 'set_session.php',
          data: { schedule_info: JSON.stringify(data) },
          success: function(response) {
              console.log(response); // Response from PHP
              window.location.href = "seats.php";
          },
          error: function(xhr, status, error) {
              console.error('Error:', error); // Log any errors
          }
      });
    }
  </script>

</body>
</html>


<!-- SELECT bus_id,bus_number,origin,destination,departure_time,arrival_time,distance,date from Schedules NATURAL JOIN Routes NATURAL JOIN Buses where origin='vizag'and destination='hyderabad' and date='2024-06-25'; -->
