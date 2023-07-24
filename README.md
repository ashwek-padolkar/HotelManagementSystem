#Hotel Management System


#Summary
This C++ program implements a basic Hotel Management System. The program allows the hotel manager to perform various operations related to managing rooms and guests. The main functionalities include adding rooms, checking in guests, checking out guests, searching for customers, and generating a guest summary report.


#Features
1. Add rooms: The hotel manager can add rooms to the system by specifying room details such as room number, type (AC/Non-AC), bed type (Single/Double), size (Big/Small), and daily rent.

2. Check-In Room: Customers can be checked in to the available rooms by providing their details such as name, address, phone number, check-in date, check-out date, and advance payment.

3. Available Rooms: The system allows the manager to see a list of available rooms that are not currently occupied by any 
 customer.

4. Search Customer: The manager can search for a customer by their name and get details such as room number and address.

5. Check-Out Room: The hotel manager can check out customers from their rooms. The program calculates the total amount due and displays the details of the customer and the payment.

6. Guest Summary Report: The system generates a summary report of all checked-in guests, displaying their names, room numbers, and addresses.


#How to Use
1. Run the program: Compile and run the Hm.cpp file using a C++ compiler.

2. Choose an option: After running the program, a menu will be displayed with various options. Enter the corresponding number to perform the desired operation.

3. Follow the on-screen instructions: The program will guide you through the process of adding rooms, checking in guests, checking out guests, and other operations.


#Important Notes
1. The maximum number of rooms and customers that can be managed by the system is set to 50. If the limit is reached, no more rooms or customers can be added.

2. The phone number provided during check-in is validated using exception handling to ensure it has exactly 10 digits.

3. The program maintains a list of rooms and their availability status, which is updated when customers check in or out.
