#!/bin/bash

while true; do
    # Display the menu
    echo "Student Database Menu:"
    echo "1. Create a database"
    echo "2. Insert a record"
    echo "3. View the database"
    echo "4. Delete a record"
    echo "5. Exit"

    # Read the user's choice
    read choice

    # Execute the chosen option
    case $choice in
        1)
            echo "Creating a new database..."
            echo "Enter the name of the database file (without the extension):"
            read db_file
            touch "$db_file.txt"
            echo "Database created successfully."
            ;;
        2)
            # Prompt the user to enter the record data
            echo "Enter the student details:"
            echo -n "Name: "
            read name
            echo -n "Roll number: "
            read rollno
            echo -n "Marks1: "
            read marks1
            echo -n "Marks2: "
            read marks2
            echo -n "Marks3: "
            read marks3

            # Append the record data to the database file
            echo "$name|$rollno|$marks1|$marks2|$marks3" >> "$db_file.txt"
            echo "Record added successfully."
            ;;
        3)
            echo "Student Database:"
            cat "$db_file.txt"
            ;;
        4)
            # Prompt the user to enter the roll number of the record to delete
            echo "Enter the roll number of the record to delete:"
            read rollno

            # Delete the record with the given roll number from the database file
            sed -i "/$rollno/d" "$db_file.txt"
            echo "Record deleted successfully."
            ;;
        5)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac
done
