
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <istream>
#include <iomanip>
#include <limits> 
#include <cmath> 


using namespace std;

//---------------------------------- Preproccessor --------------------------------

#define kRUN_PROGRAMM 1 
#define _Intger int 

//-------------------------------- Constants of System ---------------------------

unsigned short _Intger const kZERO{ 0 };
unsigned short _Intger const kONE{ 1 };
unsigned short _Intger const kNUMBER_TAB = { 2 };
unsigned short _Intger const kNUMBER_LINE = { 1 };
unsigned short _Intger const kNUMBER_ASCII_SPACE = { 32 };
unsigned short _Intger const kFULL_ACCESS_ENTERD_ALL_CHISE_YES  = { 127 };
string const kUSERNAME_ADMIN_STRING = "Admin";


//------------------------------- File name --------------------------------------

string const kFILE_NAME_CLIENT_INFORMATION = "Information_Client.txt";
string const kFILE_NAME_INFORMATION_USER = "Information_User.txt";


//--------------------------- Constants of Deparment System -----------------------

enum enChoiseDepartmentBank {

    kSHOW_INFORMATION_CLIENT_SECTION = 1,
    kADD_CLIENT_SECTION = 2,
    kDELETE_CLIENT = 3,
    kUPDATE_CLIENT = 4,
    kFIND_CLIENT = 5,
    kTRANSACTION = 6,
    kMANGE_USERS = 7,
    kLOGOUT = 8,

};

enum enChoiseDepartmentTransaction {

    kDEPOSIT_BALANCE = 1,
    kWITHDRAW_BALANCE = 2,
    kTOTAL_BALANCE = 3,
    kBACK_MAIN_MENU = 4,

};

enum enChoiseDepartmentMangeUsers {

    kLIST_USER = 1,
    kADD_NEW_USER = 2,
    kDELETE_USER = 3,
    kUPDATE_USER = 4,
    kFIND_USER = 5,
    kMAIN_MENU_BANK = 6

};

enum enChoiseDepartmentPersmission {

    kALL_PERSMISSION_ALL_OPERATION = -1 ,
    kSHOW_INFORMATION_CLIENT_SECTION_PERSMISSION = 1,
    kADD_CLIENT_SECTION_PERSMISSION = 2,
    kDELETE_CLIENT_PERSMISSION = 4,
    kUPDATE_CLIENT_PERSMISSION = 8,
    kFIND_CLIENT_PERSMISSION = 16,
    kTRANSACTION_PERSMISSION = 32,
    kMANGE_USERS_PERSMISSION = 64


};


//-------------------------------- Inforamtion Every Client in system bank -----------------------

struct stInformationClientBank {

    //Records ( Data ) 
    string accountNumber{ "" };
    string pinCode{ "" };
    string name{ "" };
    string phone{ "" };
    long double accountBalance{ 0.0 };

    //Flags 
    bool markDeleteClient = { false };

};

struct stInformationUsers {

    //Records ( Data ) 
    string username{ "" };
    string password{ "" };
    _Intger persmission{};

    //Flags 
    bool markDeleteUser{ false };

};

//-------------------------------- Forward Declarations ------------------------------

void mainBank();
void FunctionTransaction(vector<stInformationClientBank>& vectorInformationClient);


//-------------- Function Styling code ( Tabs , Lines  , Clear , button pause ) -------------------

string FunctionPrintTabs(unsigned const short _Intger kNUMBER_TABS) {

    string tab{ "" };
    if (kNUMBER_TABS <= ::kZERO)
        return tab;

    for (_Intger counter{ ::kONE }; counter <= kNUMBER_TABS; counter++)
        tab += "\t";

    return tab;

}

string FunctionCreateNewLine(unsigned const short _Intger kNUMBER_NEW_LINE) {

    string newLine{ "" };
    if (kNUMBER_NEW_LINE <= ::kZERO)
        return newLine;

    for (_Intger counter{ ::kONE }; counter <= kNUMBER_NEW_LINE; counter++)
        newLine += '\n';

    return newLine;
}

void clearSecreenOnDetailes(void) {

    system("cls");
}

void ButtonGoBackMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Menu .... ";
    system("pause>0");

}

void ButtonGoBackMenuTransaction(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Transaction Menu .... ";
    system("pause>0");

}

void ButtonGoBackMainMenuMangeUser(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Main Menu Mange User .... ";
    system("pause>0");

}
//-------------------------------------------------- Ends -------------------------------------------------------------



//--------------------------------------- Functions Header ( Secreen ) The Welcome the bank ----------------------------

void HeaderMenuBank(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                         Main Menu Secreen                    +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);

}

void footerEverySecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void footerEverySecreenTransaction(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentAddNewClient(void) {
    cout << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      Add a new Client section                +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "-[Add New Client]" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}

void headerDepartmentShowClientsList(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+-----------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Show Client(s) List section                 +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+-----------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

//---------------- Find Client according account number (Secreen) --------------------------
void headerDepartmentFindClientAccordingAN(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                         Find Client section                  +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentDeleteClient(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                       Delete Client section                  +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentUpdateClient(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                  Update Inforamtion Client section           +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentExitProgram(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                            Exit Programm                     +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentTranscationMenuSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                           Transaction Menu Section                       +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentDepositOperationSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                                Deposit Operation                         +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentWithDrawOperationSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                               Withdraw Operation                         +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentMainMenuMangeUsers(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      Main Menu Mange Users                   +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);

}

void headerDepartmentLoginAccount(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                          Login Account                       +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerDepartmentAddNewUsers(void) {
    cout << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Add a new Users section                  +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "-[Add New User]" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}

void headerDepartmentWarningMessage(void) {

    cout << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                 Message Warning This Operation               +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);

}

void headerDepartmentDeleteUser(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                        Delete User section                   +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}

void headerSectionAddUser_PersmissionSection(void) {

    cout << FunctionCreateNewLine(kNUMBER_LINE+::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                       Persmission Secreen                    +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);

}

void HeaderTabBarSectionShowClientList(unsigned long int numberClient) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3) << "Client list ( " << numberClient << " ) Client(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|    Account Number    |    Pin Code    |         Client Name                   |       Phone       |    Balance ($)  |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void HeaderTabBarSectionShowUserList(unsigned long int numberUser) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3) << "User list ( " << numberUser << " ) User(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|        Username        |        Password        |                  Persmission            |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void HeaderTabBarSectionShowClientBalanceList_TransactionSection(unsigned long int numberClient) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3) << "Balance list ( " << numberClient << " ) Client(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|    Account Number   |                    Client Name               |        Balance ($)   |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));


}

void headerDepartmentFindUser(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                         Find User section                    +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|" << FunctionCreateNewLine(kNUMBER_LINE + ::kONE);
}
void footerSectionShowClientList(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void footerMainMenuMangeUsers(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+_______________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void footerSectionShowBalanceListTransaction(long double const& kTOTAL_BALANCE_ALL_CLIENT) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB + (::kONE + ::kONE + ::kONE + ::kONE)) << "     Total Balance = " << fixed << setprecision(3) << kTOTAL_BALANCE_ALL_CLIENT << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}

void footerSectionShowListsUser() {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}

//-------------------------------------------- End Function Secreen ------------------------------------



//-------------------------------------------- Function print menu -------------------------------------

void bodyInformationMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Show Client List                                       +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Add New Client                                         +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Delete Client                                          +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Update Client                                          +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [5]- Find Client                                            +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [6]- Transaction                                            +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [7]- Mange Users                                            +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [8]- Logout                                                 +|" << FunctionCreateNewLine(kNUMBER_LINE);

    footerEverySecreen();

}

void bodyInformationTransactionMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Deposit Operation                                                  +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Withdraw Operation                                                 +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Total Balance                                                      +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Main Menu                                                          +|" << FunctionCreateNewLine(kNUMBER_LINE);

    footerEverySecreenTransaction();

}

void bodyInformationMenuMagneUsers(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- List Users                                              +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Add new Users                                           +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Delete Users                                            +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Update Users                                            +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [5]- Find User                                               +|" << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [6]- Main Menu Bank                                          +|" << FunctionCreateNewLine(kNUMBER_LINE);

    footerMainMenuMangeUsers();

}

//-----------------------------------------    End    -----------------------------------------


//-----------------Function Read Number and String and Character ( and convert Character ) , and readEvery Client of information --------------

_Intger readNumberPositiveInteger(const string kMESSAGE) {

    _Intger numberToInputUser{ ::kZERO };

    do {

        cout << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
        cin >> numberToInputUser;

        while (cin.fail()) {

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Invalid Input, " << kMESSAGE;
            cin >> numberToInputUser;

        }

    } while (numberToInputUser < ::kZERO);
    return numberToInputUser;

}

long double readNumberFloatingPointPositive(const string kMESSAGE) {

    long double numberToInputUser{ ::kZERO };

    do {

        cout << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
        cin >> numberToInputUser;

        while (cin.fail()) {

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Invalid Input, " << kMESSAGE;
            cin >> numberToInputUser;

        }

    } while (numberToInputUser < ::kZERO);

    return numberToInputUser;
}

char readCharacter(string const kMESSAGE) {

    char character{ ' ' };
    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
    cin >> character;

    return character;
}

char convertCharacterUpperToLower(char const kCHARACTER) {

    return (kCHARACTER | ::kNUMBER_ASCII_SPACE);

}

string readText(string const kMESSAGE) {

    string textToInputUser{ "" };
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
    getline(cin >> ws, textToInputUser);

    return textToInputUser;
}

stInformationClientBank readAnyClient() {

    stInformationClientBank client{ "" };

    client.pinCode = readText("Enter Pin Code : ");
    client.name = readText("Enter Name : ");
    client.phone = readText("Enter Phone : ");
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    client.accountBalance = readNumberFloatingPointPositive("Enter Account Balance : ");

    return client;
}

_Intger  readPersmiision() {

    _Intger persmission{ ::kZERO };

    char ChoisePersmission = {' '};

    headerSectionAddUser_PersmissionSection();

    cout << FunctionCreateNewLine(::kNUMBER_LINE+::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Do You To Give Full Access [Y/N] : ";
    cin >> ChoisePersmission;

    if (convertCharacterUpperToLower(ChoisePersmission) == 'y') {
        persmission = enChoiseDepartmentPersmission::kALL_PERSMISSION_ALL_OPERATION ;
        return persmission;
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE ) << FunctionPrintTabs(::kNUMBER_TAB) << "Do You To Give Access to : " << FunctionCreateNewLine(::kNUMBER_LINE);

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Show Client List [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kSHOW_INFORMATION_CLIENT_SECTION_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Add New Client   [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kADD_CLIENT_SECTION_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Delete Client    [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kDELETE_CLIENT_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Update Client    [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kUPDATE_CLIENT_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Find Client      [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kFIND_CLIENT_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Transaction      [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y') persmission += enChoiseDepartmentPersmission::kTRANSACTION_PERSMISSION;

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Mange Users      [Y/N] ? ";
        cin >> ChoisePersmission;
        if (convertCharacterUpperToLower(ChoisePersmission) == 'y')  persmission += enChoiseDepartmentPersmission::kMANGE_USERS_PERSMISSION;

        if(persmission == ::kFULL_ACCESS_ENTERD_ALL_CHISE_YES )
              persmission = enChoiseDepartmentPersmission::kALL_PERSMISSION_ALL_OPERATION;

        //Cheak the Choise Full Access is no --> and enterd the all persmission is Yes and total persmiss is 127 --> convert 127 = -1 ( All Persmission )
        return persmission;
    }


}

stInformationUsers readAnyUser() {

    stInformationUsers user;

    user.password = readText("Enter Password : ");
    user.persmission = readPersmiision();
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    footerEverySecreen();

    return user;
}

stInformationClientBank readEveryClientToUpdateClient() {

    stInformationClientBank client{ "" };

    client.pinCode = readText("Enter Pin Code : ");
    client.name = readText("Enter Name : ");
    client.phone = readText("Enter Phone : ");
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    client.accountBalance = readNumberFloatingPointPositive("Enter Account Balance : ");

    return client;
}


//------------------------------------- End This reads Function ----------------------------------


//--------------------------------------- Function converting -------------------------------------

string convertRecordToLine(stInformationClientBank const& kINFO_EVERY_CLIENT, string const kDILEMTER = "#//#") {

    string line{ "" };

    line += kINFO_EVERY_CLIENT.accountNumber + kDILEMTER;
    line += kINFO_EVERY_CLIENT.pinCode + kDILEMTER;
    line += kINFO_EVERY_CLIENT.name + kDILEMTER;
    line += kINFO_EVERY_CLIENT.phone + kDILEMTER;
    line += to_string(kINFO_EVERY_CLIENT.accountBalance); 

    return line;

}

string convertRecordToLineUserSection(stInformationUsers const& kINFO_EVERY_USER, string const kDILEMTER = "**//**") {

    string line{ "" };

    line += kINFO_EVERY_USER.username + kDILEMTER;
    line += kINFO_EVERY_USER.password + kDILEMTER;
    line += to_string(kINFO_EVERY_USER.persmission); // Convert permission to string

    return line;

}

vector<string> splitWord(string  line, string const kDILEMTER) {

    vector<string> splits;
    short pos = 0;
    string sWord;

    while ((pos = line.find(kDILEMTER)) != std::string::npos)
    {
        sWord = line.substr(0, pos);
        if (sWord != "")
        {
            splits.push_back(sWord);
        }

        line.erase(0, pos + kDILEMTER.length());
    }

    if (line != "")
    {
        splits.push_back(line);
    }

    return splits;
}

stInformationClientBank convertLineToRecord(vector <string>& Line) {

    stInformationClientBank client;

    if (Line.size() >= 5) {
        try {
            client.accountNumber = Line[0];
            client.pinCode = Line[1];
            client.name = Line[2];
            client.phone = Line[3];
            client.accountBalance = stold(Line[4]);
        }
        catch (...) {
            cout << "Error parsing client data from file.";
        }
    }

    return client;

}

stInformationUsers convertLineToRecordSectionUser(vector <string>& Line) {

    stInformationUsers infoUser;

    if (Line.size() >= 3) {
        try {
            infoUser.username = Line[0];
            infoUser.password = Line[1];
            infoUser.persmission = stoi(Line[2]);
        }
        catch (...) {
            cout << "Error parsing user data from file.";
        }
    }

    return infoUser;

}

//---------------------------------   End Function converting  ------------------------------------------------


//---------------------------- Function storing information in file and vector ---------------------------------

void loadDataToFile(string const kFILE_NAME, vector<stInformationClientBank>& infoClient, string const kDILEMTER = "#//#") {

    fstream fileClient;

    fileClient.open(kFILE_NAME, ios::out);

    if (fileClient.is_open()) {

        string line{ "" };

        for (stInformationClientBank& kINFO_CLIENT : infoClient) {
            if (kINFO_CLIENT.markDeleteClient == false) {
                line = convertRecordToLine(kINFO_CLIENT, kDILEMTER);
                fileClient << line << endl;
            }
        }
        fileClient.close();
    }
}

void loadDataToFileUserSection(string const kFILE_NAME, vector<stInformationUsers>& infoUser, string const kDILEMTER = "**//**") {

    fstream fileClient;

    fileClient.open(kFILE_NAME, ios::out);

    if (fileClient.is_open()) {
        string line{ "" };
        for (stInformationUsers& kINFO_USER : infoUser) {
            if (kINFO_USER.markDeleteUser == false) {
                line = convertRecordToLineUserSection(kINFO_USER, kDILEMTER);
                fileClient << line << endl;
            }

        }
        fileClient.close();
    }
}

vector<stInformationClientBank> loadDataFromFile(string const kFILE_NAME, string const kDILEMTER = "#//#") {

    vector<stInformationClientBank> infoAllClientInFile;

    fstream file;
    file.open(kFILE_NAME, ios::in);
    if (file.is_open()) {

        string line{ "" };
        stInformationClientBank client;

        while (getline(file, line)) {
            vector<string> infoLine = splitWord(line, kDILEMTER);
            client = convertLineToRecord(infoLine);
            infoAllClientInFile.push_back(client);
        }
        file.close();
    }

    return infoAllClientInFile;
}

vector<stInformationUsers> loadDataFromFileUserSection(string const kFILE_NAME, string const kDILEMTER = "**//**") {

    vector<stInformationUsers> infoAllUser;

    fstream file;
    file.open(kFILE_NAME, ios::in);
    if (file.is_open()) {

        string line{ "" };
        stInformationUsers infoUser;

        while (getline(file, line)) {
            vector<string> infoLine = splitWord(line, kDILEMTER);
            infoUser = convertLineToRecordSectionUser(infoLine);
            infoAllUser.push_back(infoUser);
        }
        file.close();
    }

    return infoAllUser;
}

//---------------------------- end function storing ------------------------------------


//--------------------------- Function print One Client Information ---------------------


void printInfomationClientOne(stInformationClientBank const& kINFO_CLIENT_ONE) {


    cout << "| " << left << setw(21) << kINFO_CLIENT_ONE.accountNumber << "| ",
        cout << left << setw(15) << kINFO_CLIENT_ONE.pinCode << "| ",
        cout << left << setw(38) << kINFO_CLIENT_ONE.name << "| ",
        cout << left << setw(18) << kINFO_CLIENT_ONE.phone << "| ",
        cout << left << setw(16) << kINFO_CLIENT_ONE.accountBalance << "|";

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

//------- Information client one to print ( account number , name client , balance ) of Section Transactions  ------- 

void printInfomationClientOneDepartmentTransaction(stInformationClientBank const& kINFO_CLIENT_ONE) {


    cout << "| " << left << setw(19) << kINFO_CLIENT_ONE.accountNumber << "| ";
    cout << left << setw(42) << kINFO_CLIENT_ONE.name << "| ";
    cout << left << setw(26) << kINFO_CLIENT_ONE.accountBalance << "|";

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printInfomationUserOne(stInformationUsers const& kINFO_USER) {


    cout << "| " << left << setw(23) << kINFO_USER.username << "| ",
        cout << left << setw(23) << kINFO_USER.password << "| ",
        cout << left << setw(41) << kINFO_USER.persmission << "|";

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printInformationEveryClient(stInformationClientBank& const  kCLIENT) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Following are the Client Details : " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Account Number   : " << kCLIENT.accountNumber << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Pin Code         : " << kCLIENT.pinCode << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Name             : " << kCLIENT.name << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Phone            : " << kCLIENT.phone << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Account Balance  : " << kCLIENT.accountBalance << '$' << FunctionCreateNewLine(::kNUMBER_LINE);

}

void printInformationEveryUser(stInformationUsers& const  kINFO_USER) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Following are the User Details : " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Username         : " << kINFO_USER.username << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Password         : " << kINFO_USER.password << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Persmission      : " << kINFO_USER.persmission << FunctionCreateNewLine(::kNUMBER_LINE);


}


//----------------------------------  End Function Print ---------------------------


//-------------------------------Start Operation Section Client --------------------

void functionAddNewClient(vector<stInformationClientBank>& vectorInformationClient) {

    stInformationClientBank infoClient;
    char choise{ 'Y' };

    do {

        clearSecreenOnDetailes();
        headerDepartmentAddNewClient();

        bool exitsAccountNumber;
        string accountNumber;

        do {
            exitsAccountNumber = false;
            accountNumber = readText("Enter Account Number : ");

            for (const auto& kCLIENT : vectorInformationClient) {
                if (kCLIENT.accountNumber == accountNumber) {
                    exitsAccountNumber = true;
                    cout << FunctionPrintTabs(::kNUMBER_TAB) << "Aleart !!!! Account Number [ " << kCLIENT.accountNumber << " ]  already exists, try again." << FunctionCreateNewLine(::kONE);
                    break;
                }
            }

        } while (exitsAccountNumber);

        infoClient = readAnyClient();
        infoClient.accountNumber = accountNumber;

        vectorInformationClient.push_back(infoClient);

        // Save immediately after adding
        loadDataToFile(::kFILE_NAME_CLIENT_INFORMATION, vectorInformationClient, "#//#");

        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB) << "Client added successfully. Do you want to add more clients? [Y/N] : ";
        cin >> choise;

    } while (convertCharacterUpperToLower(choise) == 'y');

    footerEverySecreen();
    ButtonGoBackMenu();
}

void FunctionShowClientLists(string const kFILE_NAME) {

    vector<stInformationClientBank>  infoClient = loadDataFromFile(kFILE_NAME, "#//#");
    unsigned long _Intger numberClient = infoClient.size();

    HeaderTabBarSectionShowClientList(numberClient);

    for (stInformationClientBank const& client : infoClient) {
        printInfomationClientOne(client);
    }

    footerSectionShowClientList();
    ButtonGoBackMenu();
}

bool isFoundAccountNumberInFile(string const kACCOUNT_NUMBER_CLIENT, stInformationClientBank& kCLIENT, vector<stInformationClientBank>& vClients) {

    for (stInformationClientBank& C : vClients) {

        if (C.accountNumber == kACCOUNT_NUMBER_CLIENT) {
            kCLIENT = C;
            return true;
        }
    }
    return false;
}

void FunctionFindClient(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentFindClientAccordingAN();

    string const kACCOUNT_NUMBER = readText("Enter Account Number : ");

    stInformationClientBank kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(kACCOUNT_NUMBER, kINFO_ONE_CLIENT, kINFO_CLIENT))
        printInformationEveryClient(kINFO_ONE_CLIENT);
    else 
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Account Number ( " << kACCOUNT_NUMBER << " ) Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
    

    footerEverySecreen();
    ButtonGoBackMenu();
}

bool makeFlagDeleteClient(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT) {

    for (stInformationClientBank& cli : kINFO_CLIENT) {
        if (kACCOUNT_NUMBER == cli.accountNumber) {

            cli.markDeleteClient = true;
            return true;

        }
    }
    return false;
}

void FunctionDeleteClient(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentDeleteClient();

    string const kACCOUNT_NUMBER = readText("Enter Account Number : ");

    stInformationClientBank kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(kACCOUNT_NUMBER, kINFO_ONE_CLIENT, kINFO_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want delete this client ? [Y/N]  : ")) == 'y')) {
            makeFlagDeleteClient(kACCOUNT_NUMBER, kINFO_CLIENT);
            loadDataToFile(::kFILE_NAME_CLIENT_INFORMATION, kINFO_CLIENT, "#//#");

            // Reload data into the vector after deletion
            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME_CLIENT_INFORMATION, "#//#");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Client Deleted Successfully (: ";
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Account Number [ " << kACCOUNT_NUMBER << " ] Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
    }

    ButtonGoBackMenu();
}

void updateClientDirct(string const kNACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT) {

    for (stInformationClientBank& client : kINFO_CLIENT) {

        if (kNACCOUNT_NUMBER == client.accountNumber) {

            stInformationClientBank updatedClient = readEveryClientToUpdateClient();
            client.pinCode = updatedClient.pinCode;
            client.name = updatedClient.name;
            client.phone = updatedClient.phone;
            client.accountBalance = updatedClient.accountBalance;

            break;
        }
    }
}

void FunctionUpdateClient(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentUpdateClient();

    string const kACCOUNT_NUMBER = readText("Enter Account Number : ");
    stInformationClientBank kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(kACCOUNT_NUMBER, kINFO_ONE_CLIENT, kINFO_CLIENT)) {
        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Update this client ? [Y/N]  : ")) == 'y')) {

            updateClientDirct(kACCOUNT_NUMBER, kINFO_CLIENT);
            loadDataToFile(::kFILE_NAME_CLIENT_INFORMATION, kINFO_CLIENT, "#//#");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Updated Successfully (: " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) ;
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number [ " << kACCOUNT_NUMBER << " ] Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
    }

    ButtonGoBackMenu();
}

//------------------------------------------- Function Transaction ------------------------------------------

void depositOperation(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount, stInformationClientBank& kINFO_ONE_CLIENT) {

    for (stInformationClientBank& client : kINFO_CLIENT) {
        if (client.accountNumber == kACCOUNT_NUMBER) {
            client.accountBalance += ammount;
            kINFO_ONE_CLIENT = client;

            break;
        }
    }
}

void withdrawOperation(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount , stInformationClientBank& kINFO_ONE_CLIENT ) {

    for (stInformationClientBank& client : kINFO_CLIENT) {
        if (client.accountNumber == kACCOUNT_NUMBER) {
            client.accountBalance -= ammount;
            kINFO_ONE_CLIENT = client;
            break;
        }
    }
}

bool validationSmallerAmmountOfBalanceWithdraw(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount) {

    for (const stInformationClientBank& client : kINFO_CLIENT) {
        if (kACCOUNT_NUMBER == client.accountNumber) {
            if (ammount > client.accountBalance) {
                return true;
            }
            break; // Found the client, no need to loop further
        }
    }
    return false;
}

void FunctionOperationWithDrawBalance(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentWithDrawOperationSecreen();

    string const kACCOUNT_NUMBER = readText("Enter Account Number : ");
    stInformationClientBank kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(kACCOUNT_NUMBER, kINFO_ONE_CLIENT, kINFO_CLIENT)) {
        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreenTransaction();
        cout << FunctionCreateNewLine(::kNUMBER_LINE);

        long double ammountBalance;
        bool flagSmaller;

        do {
            ammountBalance = readNumberFloatingPointPositive("Please, Enter Withdraw Ammount : ");
            flagSmaller = validationSmallerAmmountOfBalanceWithdraw(kACCOUNT_NUMBER, kINFO_CLIENT, ammountBalance);
            if (flagSmaller) {
                cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
                    << "Ammount Exceeds the balance, you can withdraw up to [ " << kINFO_ONE_CLIENT.accountBalance << " ] " << FunctionCreateNewLine(::kNUMBER_LINE);
            }
        } while (flagSmaller);

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Perform this Transaction Withdraw of this client ? [Y/N]  : ")) == 'y')) {
            withdrawOperation(kACCOUNT_NUMBER, kINFO_CLIENT, ammountBalance , kINFO_ONE_CLIENT );
            loadDataToFile(::kFILE_NAME_CLIENT_INFORMATION, kINFO_CLIENT, "#//#");
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Withdraw Ammount is Successfully (: ";
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number [ " << kACCOUNT_NUMBER << " ] Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreenTransaction();
    }

    ButtonGoBackMenuTransaction();
}

void FunctionOperationDepositBalance(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentDepositOperationSecreen();

    string accountNumber = readText("Enter Account Number : ");
    stInformationClientBank kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT, kINFO_CLIENT)) {
        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreenTransaction();
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        long double const kAMMOUNT = readNumberFloatingPointPositive("Please, Enter Deposit Ammount : ");

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Perform this Transaction Deposit of this client ? [Y/N]  : ")) == 'y')) {
            depositOperation(accountNumber, kINFO_CLIENT, kAMMOUNT , kINFO_ONE_CLIENT );
            loadDataToFile(::kFILE_NAME_CLIENT_INFORMATION, kINFO_CLIENT, "#//#");
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Deposit Ammount is Successfully (: ";
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number ( " << accountNumber << " ) Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreenTransaction();
    }

    ButtonGoBackMenuTransaction();
}

long double calculationAllClientBalance(vector<stInformationClientBank>& vectorInformationClient) {

    long double totalBalanceAllClient{ 0 };
    for (const stInformationClientBank& client : vectorInformationClient)
        totalBalanceAllClient += client.accountBalance;

    return totalBalanceAllClient;
}

void FunctionShowBalanceLists(string const kFILE_NAME) {

    vector<stInformationClientBank>  infoClient = loadDataFromFile(kFILE_NAME, "#//#");
    unsigned long int numberClient = infoClient.size();

    HeaderTabBarSectionShowClientBalanceList_TransactionSection(numberClient);

    for (stInformationClientBank const& client : infoClient) {
        printInfomationClientOneDepartmentTransaction(client);
    }

    footerSectionShowBalanceListTransaction(calculationAllClientBalance(infoClient));
    ButtonGoBackMenuTransaction();
}


//--------------------------------------- Start Operation Section Usres -----------------------------------------

bool isFoundUserNameAndPaawordInFile(string const& kUSERNAME, string const& kPASSWORD, stInformationUsers& currentUser) {

    vector<stInformationUsers>  vUsers = loadDataFromFileUserSection(::kFILE_NAME_INFORMATION_USER, "**//**");

    for (stInformationUsers const& user : vUsers) {
        if (kUSERNAME == user.username && kPASSWORD == user.password) {
            currentUser = user;
            return true;
        }
    }
    return false;
}

void functionLoginUser(stInformationUsers& currentUser) {

    clearSecreenOnDetailes();
    headerDepartmentLoginAccount();

    bool loginFailed = true;
    do {
        string const kUSERNAME = readText("Enter the Username, Please : ");
        string const kPAAWORD  = readText("Enter the password, Please : ");

        if (isFoundUserNameAndPaawordInFile(kUSERNAME, kPAAWORD, currentUser)) {
            loginFailed = false;
        }
        else {
            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Invalid Username/Password, Try Again." << FunctionCreateNewLine(::kNUMBER_LINE);
        }

    } while (loginFailed);
}

bool isPersmiisionThisOperation(_Intger const &kPERSMISSION, _Intger operation) {

    return ((kPERSMISSION & operation) == operation); 
}

void messageDeniendAccessThisOperation() {

         clearSecreenOnDetailes();
        headerDepartmentWarningMessage();

        cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "Access Deneid," << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "You don't have permission to do " << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB + ::kONE) << "This , Please contant your Admin . " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

        cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";

        ButtonGoBackMenu();
    
}

void FunctionShowListsUser(string const kFILE_NAME) {

    vector<stInformationUsers>  infoUsers = loadDataFromFileUserSection(kFILE_NAME, "**//**");
    unsigned short int numberUser = infoUsers.size();

    HeaderTabBarSectionShowUserList(numberUser);

    for (stInformationUsers const& kINFO_USER : infoUsers) {
        printInfomationUserOne(kINFO_USER);
    }

    footerSectionShowListsUser();
    ButtonGoBackMainMenuMangeUser();
}

void functionAddNewUser(vector<stInformationUsers>& vectorInformationUser) {

    char choise{ 'Y' };

    do {
        clearSecreenOnDetailes();
        headerDepartmentAddNewUsers();

        bool exitsUsername;
        string username;

        do {
            exitsUsername = { false };
            username = readText("Enter The Username : ");

            for (const auto& kUSER : vectorInformationUser) {
                if (kUSER.username == username) {
                    exitsUsername = { true };
                    cout << FunctionCreateNewLine(::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Alert! Username [ " << kUSER.username << " ] already exists, try again." << FunctionCreateNewLine(::kONE);
                    break;
                }
            }
        } while (exitsUsername);

        stInformationUsers infoUser = readAnyUser();
        infoUser.username = username;

        vectorInformationUser.push_back(infoUser);

        // Save immediately
        loadDataToFileUserSection(::kFILE_NAME_INFORMATION_USER, vectorInformationUser, "**//**");

        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB) << "--[ User added successfully. Do you want to add more users? [Y/N] ] : ";
        cin >> choise;
    } while (convertCharacterUpperToLower(choise) == 'y');

    ButtonGoBackMainMenuMangeUser();
}

bool makeFlagDeleteUser(string const kUSERNAME, vector<stInformationUsers>& kINFO_USER) {

    for (stInformationUsers& infoUser : kINFO_USER) {

        if (kUSERNAME == infoUser.username) {
            infoUser.markDeleteUser = { true };
            return { true };

        }
    }
    return { false };
}

bool isFoundUserNameInFile(string const kUSERNAME, stInformationUsers& kUSER, vector<stInformationUsers>& vUsers) {

    for (stInformationUsers& infoUser : vUsers) {

        if (infoUser.username == kUSERNAME) {
            kUSER = infoUser;
            return { true };
        }
    }
    return { false };
}

void FunctionDeleteUser(vector<stInformationUsers>& kINFO_USERS ) {

    clearSecreenOnDetailes();
    headerDepartmentDeleteUser();

    string const kUSERNAME = readText("Enter Username : ");

    stInformationUsers kINFO_USER_ONE;

    if (isFoundUserNameInFile(kUSERNAME, kINFO_USER_ONE, kINFO_USERS)) {
        printInformationEveryUser(kINFO_USER_ONE);
        footerEverySecreen();
        cout << FunctionCreateNewLine(::kNUMBER_LINE);

        if (kINFO_USER_ONE.username == "Admin") {

            cout << FunctionCreateNewLine(::kNUMBER_LINE)

                << FunctionPrintTabs(::kNUMBER_TAB)
                << "The Username [ " << kUSERNAME << " ] is It is the account that controls all"
                << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
                << "features of the project and has the right to give permissions"
                << FunctionCreateNewLine(::kNUMBER_LINE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "to all Users within the database"
                << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Deletion of the main account controlling the project "
                << FunctionCreateNewLine(::kNUMBER_LINE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "is not allowed"
                << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE + ::kONE) ;
                
                 ButtonGoBackMainMenuMangeUser();
                         return; 
        }

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want delete this User ? [Y/N]  : ")) == 'y')) {
            makeFlagDeleteUser(kUSERNAME, kINFO_USERS);
            loadDataToFileUserSection(::kFILE_NAME_INFORMATION_USER, kINFO_USERS, "**//**");

            // Reload data into the vector after deletion
            kINFO_USERS = loadDataFromFileUserSection(::kFILE_NAME_INFORMATION_USER, "**//**");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE+ ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "--[ User Deleted Successfully (: ]" << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) ;
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Username ( " << kUSERNAME << " ) Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
    }

    ButtonGoBackMainMenuMangeUser();
}

void updateUserDirct(string const kUSERNAME, vector<stInformationUsers>& kINFO_USERS) {

    for (stInformationUsers& infoUser  : kINFO_USERS) {

        if (kUSERNAME == infoUser.username) {

            stInformationUsers updatedUser = readAnyUser();

            updatedUser.username = kUSERNAME ;
            infoUser.password = updatedUser.password;
            infoUser.persmission = updatedUser.persmission;

            break;
        }
    }
}

void FunctionUpdateUser(vector<stInformationUsers>& kINFO_USERS) {

    clearSecreenOnDetailes();
    headerDepartmentUpdateClient();

    string const kUSERNAME = readText("Enter Username : ");
    string const kUSERNAME_ADMIN_STRING  = "Admin" ;

    stInformationUsers kINFO_USER_ONE;

    if (isFoundUserNameInFile(kUSERNAME, kINFO_USER_ONE, kINFO_USERS)) {
        printInformationEveryUser(kINFO_USER_ONE);
        footerEverySecreen();

        if (kINFO_USER_ONE.username == ::kUSERNAME_ADMIN_STRING ) {

           cout << FunctionCreateNewLine(::kNUMBER_LINE)

                << FunctionPrintTabs(::kNUMBER_TAB)
                << "The Username [ " << kUSERNAME << " ] is It is the account that controls all"
                << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
                << "features of the project and has the right to give permissions"
                << FunctionCreateNewLine(::kNUMBER_LINE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "to all Users within the database"
                << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Update of the main account controlling the project "
                << FunctionCreateNewLine(::kNUMBER_LINE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "is not allowed"
                << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE + ::kONE);

                            ButtonGoBackMainMenuMangeUser();
                                         return;
        }
        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Update this User ? [Y/N]  : ")) == 'y')) {

            updateUserDirct(kUSERNAME, kINFO_USERS);
            loadDataToFileUserSection(::kFILE_NAME_INFORMATION_USER, kINFO_USERS, "**//**");
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE +::kONE )
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "--[ User Updated Successfully (: ]"<< FunctionCreateNewLine(::kNUMBER_LINE + ::kONE ) ;
        }
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Username [ " << kUSERNAME << " ] Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
                    footerEverySecreen();
    }

    ButtonGoBackMainMenuMangeUser();
}

void FunctionFindUser (vector<stInformationUsers>& kINFO_USER ) {

    clearSecreenOnDetailes();
    headerDepartmentFindUser();

    string const kUSERNAME  = readText("Enter Username : ");


    stInformationUsers  kINFO_USER_ONE;

    if (isFoundUserNameInFile(kUSERNAME, kINFO_USER_ONE, kINFO_USER)) {
        printInformationEveryUser(kINFO_USER_ONE);
        footerEverySecreen();

        if (kUSERNAME == ::kUSERNAME_ADMIN_STRING)

            cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Username [ " << kUSERNAME << " ] is It is the account that controls all"
            << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB)
            << "features of the project and has the right to give permissions"
            << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "to all Users within the database"
            << FunctionCreateNewLine(::kNUMBER_LINE);

    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Username [ " << kUSERNAME << " ] Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
    }

    ButtonGoBackMainMenuMangeUser();
}

void welcomeMangeUserSection(void) {
    clearSecreenOnDetailes();
    headerDepartmentMainMenuMangeUsers();
    bodyInformationMenuMagneUsers();
    cout << FunctionCreateNewLine(::kONE);
}

void FunctionMangeUsers(vector<stInformationUsers>& vectorInformationUsers) {


    while (true) {
        welcomeMangeUserSection();

        _Intger choise = readNumberPositiveInteger("Enter the Choice : ");

        enChoiseDepartmentMangeUsers choiseDepartment = static_cast<enChoiseDepartmentMangeUsers>(choise);

        switch (choiseDepartment) {

        case enChoiseDepartmentMangeUsers::kLIST_USER:
            FunctionShowListsUser(::kFILE_NAME_INFORMATION_USER);
            break;

        case enChoiseDepartmentMangeUsers::kADD_NEW_USER:
            functionAddNewUser(vectorInformationUsers);
            break;

        case enChoiseDepartmentMangeUsers::kFIND_USER : 
            FunctionFindUser(vectorInformationUsers);
            break;
        case enChoiseDepartmentMangeUsers::kDELETE_USER : 
            FunctionDeleteUser(vectorInformationUsers);
             break; 
        case enChoiseDepartmentMangeUsers::kUPDATE_USER : 
            FunctionUpdateUser(vectorInformationUsers); 
            break;
        case enChoiseDepartmentMangeUsers::kMAIN_MENU_BANK:
            return;

        default:
            cout << FunctionCreateNewLine(::kNUMBER_LINE + 1)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
            ButtonGoBackMainMenuMangeUser();
        }
    }
}


void welcomeMainMenuSection(void) {

    clearSecreenOnDetailes();
    HeaderMenuBank();
    bodyInformationMenu();
    cout << FunctionCreateNewLine(::kONE);

}

void mainBank() {

    while (true)
    {
        vector<stInformationClientBank> vectorInformationClient = loadDataFromFile(::kFILE_NAME_CLIENT_INFORMATION);
        vector<stInformationUsers> vectorInformationUsers = loadDataFromFileUserSection(::kFILE_NAME_INFORMATION_USER);
        stInformationUsers currentUser{};

        //Hello User
        functionLoginUser(currentUser);

        while (true )
        {

            welcomeMainMenuSection();

            _Intger choise = readNumberPositiveInteger("Enter the Choice : ");

            enChoiseDepartmentBank choiseDepartment = static_cast<enChoiseDepartmentBank>(choise);

            switch (choiseDepartment) {

            case enChoiseDepartmentBank::kSHOW_INFORMATION_CLIENT_SECTION:
                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kSHOW_INFORMATION_CLIENT_SECTION_PERSMISSION ) ) )
                    FunctionShowClientLists(::kFILE_NAME_CLIENT_INFORMATION);
                else
                    messageDeniendAccessThisOperation();
                break;

            case enChoiseDepartmentBank::kADD_CLIENT_SECTION:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kADD_CLIENT_SECTION_PERSMISSION ) ) )
                    functionAddNewClient(vectorInformationClient);
                else
                    messageDeniendAccessThisOperation();
                break;

            case enChoiseDepartmentBank::kDELETE_CLIENT:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kDELETE_CLIENT_PERSMISSION ) ) )
                    FunctionDeleteClient(vectorInformationClient);             
                else
                    messageDeniendAccessThisOperation();

                break;

            case enChoiseDepartmentBank::kUPDATE_CLIENT:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kUPDATE_CLIENT_PERSMISSION ) ) )
                    FunctionUpdateClient(vectorInformationClient);
                else
                    messageDeniendAccessThisOperation();
                break;

            case enChoiseDepartmentBank::kFIND_CLIENT:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kFIND_CLIENT_PERSMISSION ) ) )
                    FunctionFindClient(vectorInformationClient);
                else
                    messageDeniendAccessThisOperation();

                break;

            case enChoiseDepartmentBank::kTRANSACTION:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kTRANSACTION_PERSMISSION ) ) )
                    FunctionTransaction(vectorInformationClient);
                else
                    messageDeniendAccessThisOperation();
                break;

            case enChoiseDepartmentBank::kMANGE_USERS:

                if (isPersmiisionThisOperation(currentUser.persmission, static_cast<int> (enChoiseDepartmentPersmission::kMANGE_USERS_PERSMISSION ) ) )
                    FunctionMangeUsers(vectorInformationUsers);
                else
                    messageDeniendAccessThisOperation();
                break;

            case enChoiseDepartmentBank::kLOGOUT:
                functionLoginUser(currentUser);
                break;

            default:
                cout << FunctionCreateNewLine(::kNUMBER_LINE + 1)
                    << FunctionPrintTabs(::kNUMBER_TAB)
                    << "Invalid Choice! Please try again.\n";
                ButtonGoBackMenu();
            }
        }
    }
}

void welcomeTransactionSection(void) {

    clearSecreenOnDetailes();
    headerDepartmentTranscationMenuSecreen();
    bodyInformationTransactionMenu();
    cout << FunctionCreateNewLine(::kONE);

}

void FunctionTransaction(vector<stInformationClientBank>& vectorInformationClient) {

    while (true) {

        welcomeTransactionSection();

        _Intger choise = readNumberPositiveInteger("Enter the Choice : ");

        enChoiseDepartmentTransaction choiseDepartment = static_cast<enChoiseDepartmentTransaction>(choise);

        switch (choiseDepartment) {

        case enChoiseDepartmentTransaction::kDEPOSIT_BALANCE:
            FunctionOperationDepositBalance(vectorInformationClient);
            break;

        case enChoiseDepartmentTransaction::kWITHDRAW_BALANCE:
            FunctionOperationWithDrawBalance(vectorInformationClient);
            break;

        case enChoiseDepartmentTransaction::kTOTAL_BALANCE:
            FunctionShowBalanceLists(::kFILE_NAME_CLIENT_INFORMATION);
            break;

        case enChoiseDepartmentTransaction::kBACK_MAIN_MENU:
            return; 

        default:
            cout << FunctionCreateNewLine(::kNUMBER_LINE + 1)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
            ButtonGoBackMenuTransaction();
        }
    }
}

//------------------ End Function ---------------------


_Intger main() {

        #if kRUN_PROGRAMM
             mainBank();
        #else
              cout << "Welcome Bank System (:";
        #endif 


    return 0;
}