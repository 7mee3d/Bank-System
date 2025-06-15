# 🏦 Bank Management System

Welcome to the **Bank Management System** — a powerful, console-based C++ application designed to make managing bank customers, users, and transactions easier, safer, and more efficient! 🎉 Whether you're learning, prototyping, or running a small-scale banking operation, this system has got you covered with a clean interface, flexible permissions, and reliable data storage.

---

## ✨ Features You'll Love

### 👥 Customer Management
- ➕ Add new customers effortlessly  
- ❌ Delete customers securely  
- ✏️ Update customer details anytime  
- 🔍 Search for customers quickly  
- 📋 View a detailed list of all customers  
- Each customer record stores: **Account Number, PIN, Name, Phone, Balance, and Deletion Status**

### 💰 Banking Transactions
- 💸 Deposit and withdraw funds with ease  
- 📊 View total balance across all accounts  
- 🔐 Transaction operations are permission-controlled to keep things safe!

### 👨‍💻 User Management
- 👤 Add, remove, update, and search users (employees/admins)  
- 🔑 Assign and modify granular permissions per user  
- 👀 View all users and their access levels at a glance

### 🛡️ Advanced Permission System
- Customize permissions such as managing customers, performing transactions, and user administration  
- Support for full-access admins and restricted roles — perfect for team environments!

### 💾 Data Storage
- All data saved in plain text files (`Information_Client.txt` & `Information_User.txt`)  
- No complicated databases needed — simple, portable, and easy to maintain!

### 🎨 User-Friendly Interface
- Clean console menus for smooth navigation  
- Clear headers, footers, and tabbed layouts for readability

---

## 🛠️ Requirements

- A modern **C++ compiler** (GCC, MSVC, Clang, or compatible)  
- **Windows** or **Linux** with console/terminal support  
- Any **text editor** or **IDE** (Visual Studio Code, Code::Blocks, Visual Studio, etc.)  
- No external database dependencies — just plain text files!

---

## 📂 Project Structure

| 📁 File/Folder              | 📝 Description                              |
|----------------------------|--------------------------------------------|
| `main.cpp`                 | 🖥️ The main source code file                |
| `Information_Client.txt`   | 👥 Stores customer data                      |
| `Information_User.txt`     | 👨‍💻 Stores user (employee/admin) data       |
| `README.md`                | 📖 This documentation file                   |

---

## 🧩 Code Architecture Overview

- **Constants & Enums**  
  Define menu options, permissions, filenames, and system-wide constants.

- **Structs**  
  - `stInformationClientBank`: All customer details (account number, PIN, name, phone, balance, deletion flag)  
  - `stInformationUsers`: All user details (username, password, permissions, deletion flag)

- **Helper Functions**  
  - Output formatting (tabs, new lines)  
  - Screen clearing & pausing for smooth UX  
  - Menu headers & footers for consistent UI

- **Main Menus**  
  - Customer Management  
  - Banking Transactions  
  - User Management  
  - Permissions Management  
  - Logout / Exit

- **File Handling**  
  - Load and save customer/user data from/to text files  
  - Auto-create files if missing to ensure smooth startup

---

## 🚀 Getting Started

1. **Download all project files** (`main.cpp`, `Information_Client.txt`, `Information_User.txt`) into a single folder.  
2. **Open `main.cpp`** in your favorite C++ IDE or text editor.  
3. **Compile and run** the program using your C++ compiler.  
4. **Follow the intuitive on-screen menus** to manage customers, users, and transactions like a pro!

---

## 📝 Important Notes

- Make sure `Information_Client.txt` and `Information_User.txt` are in the same folder as the executable.  
- If these files don’t exist, the program will create them automatically — no worries!  
- Supports multiple users with customizable permissions — perfect for teams.  
- For testing, you can manually edit the text files, but be cautious to keep the format consistent.

---

## 📸 Screens Bank System 

## 📸 Login Secreen 

![Image](https://github.com/user-attachments/assets/2b63ddec-aa79-4a7f-982c-684d0cf28f99)

---
## 📸 Main menu Bank Secreen 

![Image](https://github.com/user-attachments/assets/34165e66-1b79-4349-ae2a-c2e9e2f6f3dd)

---
## 📸 Option One [ Show Cleints List ] 

![Image](https://github.com/user-attachments/assets/ae2bb697-5ec7-46cf-8e19-7d317556cf80)

---
## 📸 Option Two [ Add new client ] 
![Image](https://github.com/user-attachments/assets/8aa162f2-e6c3-4f44-858c-b5da97c1edd1)

![Image](https://github.com/user-attachments/assets/e6c0b663-259d-48ac-8c31-e0b53ee19010)

---
## 📸 Option Three [ Delete Cleint according account number ] 

![Image](https://github.com/user-attachments/assets/64aec87d-9789-4377-b251-ea39e45ad9e3)
![Image](https://github.com/user-attachments/assets/d2b0065e-3db1-41b6-a3b3-9dcb4fb63f4d)

---
## 📸 Option Four [ Update Cleint according account number ] 

![Image](https://github.com/user-attachments/assets/d9b284f3-c963-4f71-8fd7-4767c88eb5c6) 
![Image](https://github.com/user-attachments/assets/0c6809f3-7670-4a2a-b7a2-91d80621b0c3)

---

## 📸 Option Five [ Find client according account number ] 

![Image](https://github.com/user-attachments/assets/67010fde-f8b2-4979-8198-b009e30f836d) 

![Image](https://github.com/user-attachments/assets/7e320c32-10bb-4f8a-8b1a-63dc4eb526e4)

---

## 📸 Option six [ Transactions ] 

### Main menu secreen Transactions . 

![Image](https://github.com/user-attachments/assets/bf4fe58e-707c-456b-9a78-011f43c8c69a)

### 📸 Option one Transaction [ Deposit Opertion ] 

![Image](https://github.com/user-attachments/assets/89012189-c0f1-4d20-a649-98eaa079004e) 

![Image](https://github.com/user-attachments/assets/1079c64b-e602-44df-863e-cec9e3bab647) 

### 📸 Option Two Transaction [ Withdraw Opertion ] 

![Image](https://github.com/user-attachments/assets/5bb1964e-b471-42e9-a8e4-48928fb7adeb) 

![Image](https://github.com/user-attachments/assets/9a84eb00-613f-4fb7-a3d7-4179960cede7)

![Image](https://github.com/user-attachments/assets/3944308f-4042-40e0-9064-bbacdda6aed6)

### 📸 Option Three Transaction [ Show All Balance Client ] 

![Image](https://github.com/user-attachments/assets/3facba97-cf0c-400f-99e3-2c8496acca73) 

---

## 📸 Option Seven [ Mange Users ] 

## 📸  Main Menu Mange Users 

![Image](https://github.com/user-attachments/assets/18934398-df7a-4c5c-b125-edc2f6931c3a)

### 📸 Option One Mange Users [ Show All Users ] 

![Image](https://github.com/user-attachments/assets/c5a1ffa6-584b-4537-b8e5-635c2cb48e0b)

### 📸 Option Two Mange Users [ Add new user ] 

![Image](https://github.com/user-attachments/assets/f10965b5-b302-449f-8d1e-b6becdb27b95) 

![Image](https://github.com/user-attachments/assets/a00a346b-9fc3-4941-9839-d9e244730dcf)

![Image](https://github.com/user-attachments/assets/59f0c397-f219-42d7-8a6d-14cc23868df3)

![Image](https://github.com/user-attachments/assets/00f9c4c8-29e7-41ae-8697-c503eec27b52)

### 📸 Option Three Mange Users [ Delete User according username ] 

![Image](https://github.com/user-attachments/assets/33b9c229-3620-4f2d-88aa-0b518547e2fa)

![Image](https://github.com/user-attachments/assets/d6a3e08e-9e1f-4abe-8ca4-f883f4c23e65)

![Image](https://github.com/user-attachments/assets/8311df42-fe77-44a4-aa4c-1192a3321da3)

### 📸 Option Forue Mange Users [ Update User according username ] 

![Image](https://github.com/user-attachments/assets/814be4dd-11ed-449a-a119-bb26c68700f9)

![Image](https://github.com/user-attachments/assets/f0804c86-0917-4dec-b849-37d130a8c4e2)

### 📸 Option One Mange User [ Show all users after updateing and delete users ] 

![Image](https://github.com/user-attachments/assets/81eb9665-8cd3-4e3c-98d7-81c603b5d90b)

### 📸 Option Five Mange Users [ Find User according username ] 

![Image](https://github.com/user-attachments/assets/bf86ed1e-0730-4a39-8536-a8a1183e8946)

![Image](https://github.com/user-attachments/assets/301d963a-ab47-4e19-8ec7-3a8ea8277dd7)

---
## 📸 Option Eight [ Logout Bank ] 

![Image](https://github.com/user-attachments/assets/c7b5b7e1-5a35-479b-b9ed-79f8e503f04c)

---


---

## 🤝 Contributing

Love this project? Want to improve it?  
Feel free to submit **Issues** or **Pull Requests** on GitHub — your contributions are highly appreciated! 🙌

---

# 👨💻 Author

**Ahmed Jehad Ahmed**  


🔗 [GitHub Profile](https://github.com/7mee3d)

📧 [Email Contact](mailto:enginnerahemdjehad2004@gmail.com)



---

Thank you for checking out the Bank Management System!  
Happy coding and banking! 💙🚀
