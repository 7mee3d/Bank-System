# 🏦 Bank Management System in C++

Welcome to the **Bank Management System** – a console-based application developed using **modern C++** that simulates real-world banking operations such as managing client accounts, processing deposits and withdrawals, and storing data persistently using file I/O.

This project is designed with clean code practices, modular functions, and an easy-to-navigate menu system, making it suitable for beginner to intermediate programmers who want to understand file handling, structs, and formatted console interfaces in C++.

---

## 🧠 Motivation

Banking is one of the most common domains for applying programming skills. The goal of this project is to:

- Practice working with **structures**, **file I/O**, and **modular code** in C++
- Simulate a real-world problem with persistent data storage
- Provide a fully functional CLI (Command Line Interface) banking application
- Learn how to handle input/output, validations, and formatted text display

---

## 🚀 Features and Functionalities

| #   | Feature                        | Description                                                                 |
|-----|--------------------------------|-----------------------------------------------------------------------------|
| 1️⃣ | Add New Client                 | Allows adding new customer records including name, account number, and balance |
| 2️⃣ | Display All Clients           | Displays client data in a neatly formatted table                           |
| 3️⃣ | Update Client Info             | Modify any detail of an existing client                                    |
| 4️⃣ | Delete Client                  | Remove a client based on account number                                    |
| 5️⃣ | Find a Client                  | Search by account number and display detailed info                         |
| 6️⃣ | Deposit Money                  | Add funds to a selected account                                            |
| 7️⃣ | Withdraw Money                 | Withdraw from a client account with validation                             |
| 8️⃣ | Show Total Balance             | Displays the sum of all client balances                                    |
| 9️⃣ | Exit Program                   | Gracefully terminates the application                                      |

---

## 📂 Data Management

All data is stored in a plain-text file called:


## Information Client 


This ensures that:
- 🧠 Data is **persistent** across sessions
- 🔁 Every operation (add/update/delete) is reflected in the file
- 🔒 Sensitive operations are handled with care to avoid data corruption

---

## 📊 Table Format Display

Client data is displayed in a tabular format using `iomanip` for clean alignment:





---


## 🛠 Technologies Used

- **Language**: C++
- **File Handling**: `fstream`, `ifstream`, `ofstream`
- **Console Utilities**: `iostream`, `iomanip`, `string`
- **Modular Design**: All operations are built as separate functions for reusability and clarity

---


# 📌 Benefits of This Project
📖 Educational: Great for students learning file I/O and basic data structures

🧱 Modular Code: Functions are reusable and well-separated

🎯 Real-World Simulation: Mimics the flow of actual banking systems

💾 Offline Persistence: No need for databases – data is saved directly to text files

🔁 User-Friendly Navigation: Easy to interact via numbered menus

⛔ Input Validation: Handles invalid or incomplete data gracefully

--- 

# 🧪 Sample Workflow

### 1- User runs the program

### 2- Main menu is shown

### 3- User selects “Add Client”

### 4- System requests details and saves them to the file

### 5- User chooses “Show All Clients”

### 6- Data is retrieved from the file and shown as a table

---

# 🔄 Future Enhancements

### 🔐 Add login & admin roles

### 📈 Track transaction history

### 📦 Switch to database (SQLite, MySQL)

### 🖥 GUI with Qt or Web-based frontend

### 📊 Export reports to CSV or PDF

---

# 🧑‍💻 How to Run

### 1- Clone or download this repository: 

``` cpp

git clone https://github.com/your-username/BankingSystem.git
cd BankingSystem

```

### 2- Compile the code:

```
g++ main.cpp -o bank
```

### 3- Run the program:

```
./bank
```

--- 


# 👨💻 Author

**Ahmed Jehad Ahmed**  


🔗 [GitHub Profile](https://github.com/7mee3d)

📧 [Email Contact](mailto:enginnerahemdjehad2004@gmail.com)
