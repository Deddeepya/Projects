<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <!-- <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous"> -->
    <link rel="stylesheet" href="navbar.css?ykyfk">
    <link rel="stylesheet" href="To-From.css?hh">
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

  <!-- PHP and MySQL integration -->
  <?php
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
  else{
    // echo "HII<br>";
  }
  
  // SQL query
  $sql = "SELECT distinct origin FROM Routes";
  $from = $conn->query($sql);

  $sql = "SELECT distinct destination FROM Routes";
  $to = $conn->query($sql);

  // Close connection
  $conn->close();
  ?>

  <form style="transform: scale(1.3); width: fit-content; margin: auto;" action="busses.php" method="post">
    <div style="width: fit-content; margin: auto; margin-top: 200px; background-color: white; padding: 20px 20px; box-shadow: 0px 0px 10px black;">
        <label class="text" for="from">From</label>
        <div class="break"></div>
        <select class="text" id="from" name="from">
          <?php
          if ($from->num_rows > 0) {
              while ($row = $from->fetch_assoc()) {
                  echo '<option value="' . $row['origin'] . '">' . $row['origin'] . '</option>';
              }
          }
          ?>
        </select>
        <div class="break"></div>

        <label class="text" for="to">To</label>
        <div class="break"></div>
        <select class="text" id="to" name="to">
          <?php
          if ($to->num_rows > 0) {
              while ($row = $to->fetch_assoc()) {
                  echo '<option value="' . $row['destination'] . '">' . $row['destination'] . '</option>';
              }
          }
          ?>
        </select>
        <div class="break"></div>
        
        <label class="text" for="date">Date</label>
        <div class="break"></div>
        <input class="text" type="date" id="date" name="date">
        <br><br>

        <input class="text" style="background-color: #fdd150; border-width: 0px; width: 60px; height: 20px; cursor: pointer;" type="submit" value="Submit">
    </div>
  </form>

</body>
</html>