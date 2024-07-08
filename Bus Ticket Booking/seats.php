<?php

  // Start session
  session_start();

  $schedule_id = $_SESSION['schedule_id'];

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

  $sql = "SELECT seat_number from Bookings where Bookings.schedule_id = ? ";

  // Prepare and bind
  $stmt = $conn->prepare($sql);
  $stmt->bind_param("s", $schedule_id );

  // Execute the statement
  $stmt->execute();

  // Get the result
  $result = $stmt->get_result();

  $booked_seats = array();

  // Fetch each row and store it in the array
  while ($row = $result->fetch_assoc()) {
    $booked_seats[] = $row['seat_number'];
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
    <link rel="stylesheet" href="navbar.css?v12vg34">
    <link rel="stylesheet" href="seats.css?fjkuqp">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
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

      <div style="margin: auto; width: fit-content; color: #ffc107; font-size: 25px; margin-top: 50px;" class="selected_seats_info_text">Select Your Seats</div>
      <div class="container">
        <ul class="contents_list">
          <li class="contents" style="margin-left: 80px;">
            <div class="bus_layout"> 
              <div class="steering"><img src="steering.svg" alt="#" height="45px" width="45px"></div>
              <ul class="seats_rows_list">
                <li>
                  <ul class="seats_row" style="margin-left: 0px;">
                    <li id="1" class="seats break available"><div class="hover_text">Seat No : 1</div></li>
                    <li id="5" class="seats break available"><div class="hover_text">Seat No : 5</div></li>
                    <li id="9" class="seats break available"><div class="hover_text">Seat No : 9</div></li>
                    <li id="13" class="seats break available"><div class="hover_text">Seat No : 13</div></li>
                    <li id="17" class="seats break available"><div class="hover_text">Seat No : 17</div></li>
                    <li id="21" class="seats break available"><div class="hover_text">Seat No : 21</div></li>
                    <li id="25" class="seats break available"><div class="hover_text">Seat No : 25</div></li>
                    <li id="29" class="seats break available"><div class="hover_text">Seat No : 29</div></li>
                    <li id="33" class="seats available"><div class="hover_text">Seat No : 33</div></li>
                  </ul>
                </li>
                <li>
                  <ul class="seats_row">
                    <li id="2" class="seats break available"><div class="hover_text">Seat No : 2</div></li>
                    <li id="6" class="seats break available"><div class="hover_text">Seat No : 6</div></li>
                    <li id="10" class="seats break available"><div class="hover_text">Seat No : 10</div></li>
                    <li id="14" class="seats break available"><div class="hover_text">Seat No : 14</div></li>
                    <li id="18" class="seats break available"><div class="hover_text">Seat No : 18</div></li>
                    <li id="22" class="seats break available"><div class="hover_text">Seat No : 22</div></li>
                    <li id="26" class="seats break available"><div class="hover_text">Seat No : 26</div></li>
                    <li id="30" class="seats break available"><div class="hover_text">Seat No : 30</div></li>
                    <li id="34" class="seats available"><div class="hover_text">Seat No : 34</div></li>
                  </ul>
                </li>
                <li>
                  <div id="walk_way">
                  </div>
                </li>
                <li>
                  <ul class="seats_row">
                    <li id="3" class="seats break available"><div class="hover_text">Seat No : 3</div></li>
                    <li id="7" class="seats break available"><div class="hover_text">Seat No : 7</div></li>
                    <li id="11" class="seats break available"><div class="hover_text">Seat No : 11</div></li>
                    <li id="15" class="seats break available"><div class="hover_text">Seat No : 15</div></li>
                    <li id="19" class="seats break available"><div class="hover_text">Seat No : 19</div></li>
                    <li id="23" class="seats break available"><div class="hover_text">Seat No : 23</div></li>
                    <li id="27" class="seats break available"><div class="hover_text">Seat No : 27</div></li>
                    <li id="31" class="seats break available"><div class="hover_text">Seat No : 31</div></li>
                    <li id="35" class="seats available"><div class="hover_text">Seat No : 35</div></li>
                  </ul>
                </li>
                <li>
                  <ul class="seats_row" style="margin-right: 0px;">
                    <li id="4" class="seats break available"><div class="hover_text">Seat No : 4</div></li>
                    <li id="8" class="seats break available"><div class="hover_text">Seat No : 8</div></li>
                    <li id="12" class="seats break available"><div class="hover_text">Seat No : 12</div></li>
                    <li id="16" class="seats break available"><div class="hover_text">Seat No : 16</div></li>
                    <li id="20" class="seats break available"><div class="hover_text">Seat No : 20</div></li>
                    <li id="24" class="seats break available"><div class="hover_text">Seat No : 24</div></li>
                    <li id="28" class="seats break available"><div class="hover_text">Seat No : 28</div></li>
                    <li id="32" class="seats break available"><div class="hover_text">Seat No : 32</div></li>
                    <li id="36" class="seats available"><div class="hover_text">Seat No : 36</div></li>
                  </ul>
                </li>
              </ul>
            </div>
          </li>
          
          <li class="contents" style="margin-right: 0px;">
            <div class="selected_seats_info">
              
              <div>
                <div class="selected_seats_info_text" style="margin-bottom: 15px;">SEAT LEGEND</div>
                <div style="display: flex; margin-bottom: 0px;">
                  <div style="display: flex; width: fit-content; margin-right: 60px; align-items: center;"><div class="seats" style="border: 0.5px solid rgb(137, 137, 137); margin-right: 10px;"></div><div class="selected_seats_info_text" style="font-weight: 300; font-size: 14px;">Available</div></div>
                  <div style="display: flex; align-items: center;"><div class="seats booked" style="margin-right: 10px;"></div><div class="selected_seats_info_text" style="font-weight: 300; font-size: 14px;">Unavailable</div></div>
                </div>
                <div style="display: flex; margin-top: 12px; align-items: center;"><div class="seats" style="background-color: #ffc107; border: 0.5px solid #ffc107; margin-right: 10px;"></div><div class="selected_seats_info_text" style="font-weight: 300; font-size: 14px;">Selected</div></div>
              </div>

              <div style="margin-top: 18px; border-top: 0.5px solid rgb(130, 130, 130); border-bottom: 0.5px solid rgb(130, 130, 130); padding: 12px 0px;">
                <div style="display: flex;">
                  <div class="selected_seats_info_text" style="width: fit-content; margin-right: auto;">SEAT NO.</div>
                  <ul id="seats_list" style="list-style-type: none; display: flex;">

                  </ul>
                </div>
              </div>

              <div>
                <div class="selected_seats_info_text" style="margin-top: 12px;">FARE DETAILS</div>
                <div style="display: flex; align-items: center; margin-top: 12px;"><div class="selected_seats_info_text" style="font-weight: 300; font-size: 14px; width: fit-content; margin-right: auto;">Amount</div><div class="selected_seats_info_text" style="font-weight: 500; font-size: 14px;">INR 1040.00</div></div>
                <div id="proceed_to_book" class="selected_seats_info_text" style="font-weight: 300; font-size: 14.5px; display: flex; justify-content: center; background-color: #ffc107; padding: 8px 0px; margin-top: 18px; cursor: pointer;">PROCEED TO BOOK</div>
              </div>

            </div>
          </li>
          
        </ul>
      </div>
      
      <script>
        let booked_seats = <?php echo json_encode($booked_seats); ?>;
        for (let x of booked_seats) {
          let id=""+x;
          document.getElementById(id).classList.replace('available', 'booked');
        }
      </script>

      <script>
        let no_seats = 0;
        let seats_list=document.getElementById("seats_list");
        document.addEventListener('click', function(event) {
            if (event.target.classList.contains('available')) {
                if(no_seats<6){
                  event.target.classList.replace('available', 'selected');
                  no_seats++;
                }
                else{
                  alert('you cannot select more than 6 seats');
                }
            } else if (event.target.classList.contains('selected')) {
                event.target.classList.replace('selected', 'available');
                no_seats--;
            }
            updateSeatList();
        });

        function updateSeatList() {
            seats_list.innerHTML = '';
            let selectedSeats = document.querySelectorAll('.selected');
            let seatIds = [];
            selectedSeats.forEach(seat => {
                seatIds.push(seat.id);
            });

            if (seatIds.length > 0) {
                let seatText = document.createElement('li');
                seatText.classList.add('selected_seats_info_text');
                seatText.style.fontSize = '16px';
                seatText.style.fontWeight = '500';
                seatText.textContent = seatIds.join(', ');
                seats_list.appendChild(seatText);
            }
        }

        const seats = document.querySelectorAll('.seats');
        seats.forEach(seat => {
          seat.addEventListener('mousemove', function (event) {
              if (this.classList.contains('available') || this.classList.contains('selected')) {
                  const hoverText = this.querySelector('.hover_text');
                  hoverText.style.left = `${event.pageX + 10}px`; // 10px offset to the right of the cursor
                  hoverText.style.top = `${event.pageY + 10}px`; // 10px offset below the cursor
              }
          });

          seat.addEventListener('mouseenter', function () {
              if (this.classList.contains('available') || this.classList.contains('selected')) {
                  const hoverText = this.querySelector('.hover_text');
                  hoverText.style.display = 'block';
              }
          });

          seat.addEventListener('mouseleave', function () {
              if (this.classList.contains('available') || this.classList.contains('selected')) {
                  const hoverText = this.querySelector('.hover_text');
                  hoverText.style.display = 'none';
              }
          });
      });

      let btn = document.getElementById("proceed_to_book");
      btn.addEventListener('mouseenter', () =>{
        btn.style.backgroundColor="#ffcf40";
      });
      btn.addEventListener('mouseleave', () =>{
        btn.style.backgroundColor="#ffc107";
      });
    </script>
</body>
</html>