# Bank Client Management System - C++ Console Application

## 🏦 Project Overview  
A comprehensive bank client management system through CLI (Command Line Interface), designed to efficiently and securely manage financial records. Combines the power of C++ with user-friendly design, built according to best programming practices.

## 🌟 Key Features:
- **Smart Data Management**: Full CRUD system (Create-Read-Update-Delete)
- **Secure Storage**: Data storage in encrypted text files
- **Intuitive Interface**: Clean design with visual formatting
- **Advanced Validation**: Robust input validation for all data types
- **High Flexibility**: Supports unlimited client entries

## 🔧 Technical Architecture:
```cpp
struct stInformationClientBank {
    string accountNumber; // Unique account number
    string pinCode;       // Encrypted PIN code
    string name;          // Client's full name
    string phone;         // Verified phone number
    double accountBalance;// Balance in USD
    bool markDeleteClient;// Smart deletion flag
};
```
