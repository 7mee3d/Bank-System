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

## 📸 Screenshots (Optional)

![Program Interface](images/screenshot.png)


---

## 🤝 Contributing

Love this project? Want to improve it?  
Feel free to submit **Issues** or **Pull Requests** on GitHub — your contributions are highly appreciated! 🙌

---

## 📜 License

This project is **open-source** and free for academic, educational, and personal use.  
Use it, modify it, and share it — no strings attached! 🎓

---

Thank you for checking out the Bank Management System!  
Happy coding and banking! 💙🚀
