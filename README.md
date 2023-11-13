# College Management System (CMS)

The College Management System (CMS) is a command-line application that helps manage student and faculty data for different departments in a college.

# Features

- Different roles: Head of Department (HoD), Coordinator, and Faculty.
- Role-based access with passwords.
- Departments: BCA and MCA.
- Functionality for displaying and entering student and faculty data.
- Search for specific students and faculty members.
- Password protection and account locking for multiple failed attempts.

# Usage

Here is the guide that contains step by step instructions on how to setup and run this system effectively.

## Table of Contents

1. [System Requirements](#1-system-requirements)
2. [Installation](#2-installation)
3. [User Roles and Access](#3-user-roles-and-access)
4. [Main Menu](#4-main-menu)
5. [Department Selection](#5-department-selection)
6. [User Actions](#6-user-actions)
7. [Exiting the System](#7-exiting-the-system)

## 1. System Requirements

Before you begin using the College Management System, ensure that your system meets the following requirements:

- C++ Compiler (e.g., GCC)
- git (to clone the repository)
- Terminal or Command Prompt

## 2. Installation

To use the College Management System, follow these steps:

1. Open git bash in the desired directory, clone the project repository to your local machine using this command:
   ```bash
   git clone https://github.com/amansingh169/College-Management_system

2. Now you can use any c++ compiler to build the application either in vscode (a code editor) or command prompt.

3. Compile the code with the following instructions:
    1. Open a C++ compiler in the directory where the code is situated and type the following command:
        ```bash
        g++ cms.cpp -o cms

    2. Run the application:
        ```bash
        ./cms

## 3. User Roles and Access

- **Head of Department (HoD):** 
    - Highest authority with access to all functions.
    - Password: hod123

- **Coordinator:**
    - Limited access, unable to enter faculty data.
    - Password: coordinator456

- **Faculty:**
    - Limited access, unable to enter both student and faculty data.
    - Password: faculty789

## 4. Main Menu

The main menu provides you with the following options:

- Head of Department (HoD)
- Coordinator
- Faculty
- Exit

Select your user role by entering the corresponding number, and the system will prompt you for a password.

## 5. Department Selection
Once you enter the correct password for your role, you will be prompted to choose a department:

- BCA
- MCA
- Exit

Select the department based on your responsibilities.

## 6. User Actions
Each user role has a different set of actions available:

- Show all student data
- Show all faculty data
- Enter student data (if allowed)
- Enter faculty data (if allowed)
- Display data of a specific student
- Display data of a specific faculty
- Exit the current section

Choose the desired action by entering the corresponding number, and follow the on-screen instructions to complete the action.

## 7. Exiting the System

You can exit the system at any time by selecting the "Exit" option. This will take you back to the main menu where you can switch users or exit the application completely.

# Contributing

We welcome contributions to the College Management System project. If you would like to add new features or improve the code, follow these steps:

1. Fork the project repository.
2. Create a new branch for your feature or improvement.
3. Commit your changes and push the branch to your fork.
4. Open a pull request to propose your changes.

Please contact me [here](https://www.instagram.com/wacky_aman77/) (my insta) to discuss changes, gonna be a bit casual.

# Author

- [Aman Singh](https://github.com/amansingh169)

Feel free to add more details, documentation, and instructions as needed. Customize it to your project's specific requirements.

Keep developing! and

Correct you posture RIGHT NOW!!!
