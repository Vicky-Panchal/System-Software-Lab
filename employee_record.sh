#!/bin/bash

EMPLOYEE_FILE="employee_records.txt"

add_record() {
	echo "-----------------------------"
	echo "Enter Employee Name:"
	read name
	echo "Enter Employee Number:"
	read emp_num
	echo "Enter Employee Telephone Number:"
	read tele_number

	if grep -q "^.*:$emp_num:.*$" "$EMPLOYEE_FILE"; then
        echo "Employee Number already exists. Please enter a unique Employee Number."
    else
        echo "$name:$emp_num:$tele_number" >> "$EMPLOYEE_FILE"
        echo "Record added successfully."
    fi
	echo "-----------------------------"
}

delete_record() {
	echo "-----------------------------"
	echo "Enter the employee number to delete:"
	read emp_num

	grep -v "^.*:$emp_num:.*$" "$EMPLOYEE_FILE" > temp_file
	mv temp_file "$EMPLOYEE_FILE"
	echo "Record deleted successfully."
	echo "-----------------------------"
}

search_employee() {
	echo "-----------------------------"
	echo "Enter the employee name or number to search:"
	read search_query

	grep -i "$search_query" "$EMPLOYEE_FILE"
	echo "-----------------------------"
}

list_records() {
	echo "-----------------------------"
	cat "$EMPLOYEE_FILE"
	echo "-----------------------------"
}

sort_records() {
	echo "-----------------------------"
	sort -t ':' -k1,1 "$EMPLOYEE_FILE"
	echo "-----------------------------"
}


while true; do
	echo "-----------------------------"
	echo "Employee Record Management System"
	echo "-----------------------------"
	echo "1. Add Record"
	echo "2. Delete Record"
	echo "3. Search Employee"
	echo "4. List All Records"
	echo "5. Sort Records"
	echo "6. Exit"
	echo "-----------------------------"
	echo "Enter your choice (1-6):"
	read choice

	case $choice in
		1)
			add_record
			;;
		2)
			delete_record
			;;

		3)
			search_employee
			;;
		
		4)
			list_records
			;;

		5)
			sort_records
			;;

		6)
			echo "Exiting the program, Goodbye!"
			exit 0
			;;

		*)
			echo "Invalid choice. Please try again."
			;;

		esac
	done
