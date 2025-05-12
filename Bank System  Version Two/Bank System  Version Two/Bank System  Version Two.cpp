// Bank System 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

#define RUN 1 

//Constants of System 

unsigned short int const kZERO{ 0 };
unsigned short int const kONE{ 1 };
unsigned short int const kNUMBER_TAB = { 2 };
unsigned short int const kNUMBER_LINE = { 1 };
unsigned short int const kNUMBER_ASCII_SPACE = { 32 };

//File name 
string const kFILE_NAME = "Information_Client.txt";

// Constants of Deparment System 
enum enChoiseDepartmentBank {

    kSHOW_INFORMATION_CLIENT_SECTION = 1,
    kADD_CLIENT_SECTION = 2,
    kDELETE_CLIENT = 3,
    kUPDATE_CLIENT = 4,
    kFIND_CLIENT = 5,
    kTRANSACTION = 6,
    kEXIT = 7

};

enum enChoiseDepartmentTransaction {

    kDEPOSIT_BALANCE  = 1,
    kWITHDRAW_BALANCE = 2,
    kTOTAL_BALANCE = 3,
    kBACK_MAIN_MENU = 4,

};
// Inforamtion Every Client in system bank 
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

//Function Styling code ( Tabs , Lines  , Clear , button pause ) 
string FunctionPrintTabs(unsigned const short int kNUMBER_TABS) {

    string tab{ "" };
    if (kNUMBER_TABS <= ::kZERO)
        return tab;

    for (int counter{ ::kONE }; counter <= kNUMBER_TABS; counter++)
        tab += "\t";

    return tab;

}

string FunctionCreateNewLine(unsigned const short int kNUMBER_NEW_LINE) {

    string newLine{ "" };
    if (kNUMBER_NEW_LINE <= ::kZERO)
        return newLine;

    for (int counter{ ::kONE }; counter <= kNUMBER_NEW_LINE; counter++)
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

void ButtonGoBackMenuTransaction (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE +::kONE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Pass any Key To go Back To The Transaction Menu .... ";
    system("pause>0");

}
//Ends 



//Functions Header ( Secreen ) The Welcome the bank 

void HeaderMenuBank(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                         Main Menu Secreen                    +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void footerEverySecreen(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void footerEverySecreenTransaction(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n\n";
}

void headerDepartmentAddNewClient(void) {
    cout << FunctionCreateNewLine(kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Add a new Client section                 +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "-[Add New Client]" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}

void headerDepartmentShowClientsList(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+-----------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                     Show Client(s) List section                 +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+-----------------------------------------------------------------+|\n\n";
}

//Find Client according account number (Secreen)
void headerDepartmentFindClientAccordingAN(void) {
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      Find Client section                     +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void headerDepartmentDeleteClient(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                      Delete Client section                   +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void headerDepartmentUpdateClient(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+               Update Inforamtion Client section              +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void headerDepartmentExitProgram(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                           Exit Programm                      +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------+|\n\n";
}

void headerDepartmentTranscationMenuSecreen (void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                           Transaction Menu Section                       +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n\n";
}

void headerDepartmentDepositOperationSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                               Deposit Operation                          +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n\n";
}

void headerDepartmentWithDrawOperationSecreen(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+                               Withdraw Operation                         +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+--------------------------------------------------------------------------+|\n\n";
}
void HeaderTabBarSectionShowClientList(unsigned long int numberClient) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3) << "Client list ( " << numberClient << " ) Client(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|    Account Number    |    Pin Code    |         Client Name                   |       Phone       |    Balance ($)  |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void HeaderTabBarSectionShowClientBalanceList_TransactionSection(unsigned long int numberClient) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3) << "Balance list ( " << numberClient << " ) Client(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout <<  "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout <<  "|    Account Number    |            Client Name                   |        Balance ($)       |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));


}
void footerSectionShowClientList(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void footerSectionShowBalanceListTransaction (long double const & kTOTAL_BALANCE_ALL_CLIENT ) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+__________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB + (::kONE + ::kONE + ::kONE + ::kONE )) << "    Total Balance = " << fixed << setprecision(3) << kTOTAL_BALANCE_ALL_CLIENT << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
}
// End Function Secreen 

//Function print menu 

void bodyInformationMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Show Client List                                        +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Add New Client                                          +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Delete Client                                           +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Update Client                                           +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [5]- Find Client                                             +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [6]- Transaction                                             +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [7]- Exit Bank                                               +|\n";

    footerEverySecreen();

}

void bodyInformationTransactionMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Deposit Operation                                                   +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Withdraw Operation                                                  +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Total Balance                                                       +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Main Menu                                                           +|\n";

    footerEverySecreenTransaction();

}
//End 

//Function Read Number and String and Character ( and convert Character ) , and readEvery Client of information 

int readNumberPositiveInteger(const string kMESSAGE) {

    int numberToInputUser{ ::kZERO };

    do {

        cout << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
        cin >> numberToInputUser;

        while (cin.fail()) {

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
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
            cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
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

    // cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Enter Account Number : ";
    // getline(cin >> ws, client.accountNumber);


    client.pinCode = readText("Enter Pin Code : ");
    client.name = readText("Enter Name : ");
    client.phone = readText("Enter Phone : ");
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    client.accountBalance = readNumberFloatingPointPositive("Enter Account Balance : ");

    return client;
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

//End This reads Function 


//Function converting 
string convertRecordToLine(stInformationClientBank const& kINFO_EVERY_CLIENT, string const kDILEMTER = "#//#") {

    string line{ "" };

    line += kINFO_EVERY_CLIENT.accountNumber + kDILEMTER;
    line += kINFO_EVERY_CLIENT.pinCode + kDILEMTER;
    line += kINFO_EVERY_CLIENT.name + kDILEMTER;
    line += kINFO_EVERY_CLIENT.phone + kDILEMTER;
    line += to_string(kINFO_EVERY_CLIENT.accountBalance) + "$";

    return line;

}

vector<string> splitWord(string  line, string const kDILEMTER = "#//#") {

    vector<string> splits;
    int poisitonWord{ ::kZERO };
    string newWord{ "" };

    while ((poisitonWord = line.find(kDILEMTER)) != string::npos) {

        newWord = line.substr(0, poisitonWord);
        if (newWord != "")
            splits.push_back(newWord);

        line.erase(0, poisitonWord + kDILEMTER.length());

    }

    if (!line.empty())
        splits.push_back(line);

    return splits;
}

stInformationClientBank convertLineToRecord(vector <string> Line, string const kDILEMTER = "#//#") {

    stInformationClientBank client;

    //5--> NUmber size of vector ( information) ( struct )
  //  if (Line.size() >= 5) {
    try {
        client.accountNumber = Line[0];
        client.pinCode = Line[1];
        client.name = Line[2];
        client.phone = Line[3];
        client.accountBalance = stold(Line[4]);
    }
    catch (...) {
        cout << "Outing range ";
    }
    // }

    return client;

}

//End Function converting 

//Function storing information in file and vector 

/*
void loadDataToFile_NewClient(string const kFILE_NAME_INFORMATION_CLIENT, vector<stInformationClientBank>& infoClient, string const kDILEMTER = "#//#") {

    fstream fileClient{};

    fileClient.open(kFILE_NAME, ios::out | ios::app);

    if (fileClient.is_open()) {

        string line{ "" };

        for (const stInformationClientBank& kINFO_CLIENT : infoClient) {

            line = convertRecordToLine(kINFO_CLIENT, kDILEMTER);
            if(line!= "")
            fileClient << line << FunctionCreateNewLine(::kNUMBER_LINE);

        }
    }

    fileClient.close();
}
*/

void loadDataToFile(string const kFILE_NAME_INFORMATION_CLIENT, vector<stInformationClientBank>& infoClient, string const kDILEMTER = "#//#") {

    fstream fileClient{};

    fileClient.open(kFILE_NAME, ios::out);

    if (fileClient.is_open()) {

        string line{ "" };

        for (const stInformationClientBank& kINFO_CLIENT : infoClient) {
            if (kINFO_CLIENT.markDeleteClient == false) {
                line = convertRecordToLine(kINFO_CLIENT, kDILEMTER);
                fileClient << line << FunctionCreateNewLine(::kNUMBER_LINE);
            }

        }
        fileClient.close();
    }


}

vector<stInformationClientBank> loadDataFromFile(string const kFILE_NAME, string const kDILEMTER = "#//#") {

    vector<stInformationClientBank> infoAllClientInFile;
    vector<string>infoLine;

    fstream file;
    file.open(::kFILE_NAME, ios::in);
    if (file.is_open()) {

        string line{ "" };
        stInformationClientBank client;

        while (getline(file, line)) {
            infoLine = splitWord(line, kDILEMTER);
            client = convertLineToRecord(infoLine);
            infoAllClientInFile.push_back(client);
        }

    }
    file.close();
    return infoAllClientInFile;
}

//end function storing 


//Function print One Client Information 

void printInfomationClientOne(stInformationClientBank const& kINFO_CLIENT_ONE) {


    cout << "| " << left << setw(21) << kINFO_CLIENT_ONE.accountNumber << "| ",
        cout << left << setw(15) << kINFO_CLIENT_ONE.pinCode << "| ",
        cout << left << setw(38) << kINFO_CLIENT_ONE.name << "| ",
        cout << left << setw(18) << kINFO_CLIENT_ONE.phone << "| ",
        cout << left << setw(16) << kINFO_CLIENT_ONE.accountBalance << "|";
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

}

// Information client one to print ( account number , name client , balance ) of Section Transactions 
void printInfomationClientOneDepartmentTransaction(stInformationClientBank const& kINFO_CLIENT_ONE) {


         cout <<  "| " << left << setw(21) << kINFO_CLIENT_ONE.accountNumber << "| ",
        cout <<  left << setw(41) << kINFO_CLIENT_ONE.name << "| ",
        cout <<  left << setw(25) << kINFO_CLIENT_ONE.accountBalance << "|";

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


//End Function Print 


// Start Operation Section 

void functionAddNewClient(vector<stInformationClientBank>& vectorInformationClient) {

    stInformationClientBank infoClient;
    char choise{ 'Y' };

    while (convertCharacterUpperToLower(choise) == 'y') {

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

        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB) << "Client added successfully. Do you want to add more clients? [Y/N] : ";
        cin >> choise;
    }

    // كتابة كل العملاء مرة واحدة بعد الانتهاء
    loadDataToFile(::kFILE_NAME, vectorInformationClient, "#//#");

    footerEverySecreen();
    ButtonGoBackMenu();
}

void FunctionShowClientLists(string const kFILE_NAME) {


    vector<stInformationClientBank>  infoClient;

    infoClient = loadDataFromFile(kFILE_NAME, "#//#");

    unsigned short int numberClient = infoClient.size();

    HeaderTabBarSectionShowClientList(numberClient);

    for (stInformationClientBank const& client : infoClient) {

        printInfomationClientOne(client);

    }

    footerSectionShowClientList();
    ButtonGoBackMenu();
}

bool isFoundAccountNumberInFile(string const kACCOUNT_NUMBER_CLIENT, stInformationClientBank& const  kCLIENT) {

    vector<stInformationClientBank>  infoClient;
    infoClient = loadDataFromFile(kFILE_NAME, "#//#");

    for (stInformationClientBank const& kCLIENT_INFO_ACCORDING_INDEX : infoClient) {

        if (kACCOUNT_NUMBER_CLIENT == kCLIENT_INFO_ACCORDING_INDEX.accountNumber) {
            kCLIENT = kCLIENT_INFO_ACCORDING_INDEX;
            return true;
        }
    }
    return false;
}

void FunctionFindClient(vector<stInformationClientBank> const& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentFindClientAccordingAN();

    string accountNumber{ "" };
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "Enter Account Number : ";
    getline(cin >> ws, accountNumber);

    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();
        ButtonGoBackMenu();

    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Account Number ( " << accountNumber << " ) Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
        ButtonGoBackMenu();
    }

}

bool makeFlagDeleteClient(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, stInformationClientBank& client) {

    for (stInformationClientBank& cli : kINFO_CLIENT) {
        if (kACCOUNT_NUMBER == cli.accountNumber) {
            cli.markDeleteClient = true;
            client = cli;
            return true;
        }
    }
    return false;
}

void FunctionDeleteClient(vector<stInformationClientBank>& kINFO_CLIENT) {


    clearSecreenOnDetailes();
    headerDepartmentFindClientAccordingAN();

    char answerAreDelete = 'n';
    string accountNumber{ "" };
    accountNumber = readText("Enter Account Number : ");


    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want delete this client ? [Y/N]  : ")) == 'y')) {

            makeFlagDeleteClient(accountNumber, kINFO_CLIENT, kINFO_ONE_CLIENT);
            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#");
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE) << FunctionPrintTabs(::kNUMBER_TAB) << "Client Delete Successfully (: ";

            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME);
        }
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        ButtonGoBackMenu();
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Account Number ( " << accountNumber << " ) Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
        ButtonGoBackMenu();
    }

}

void updateClientDirct(string const kNACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT) {

    for (stInformationClientBank& client : kINFO_CLIENT) {
        if (kNACCOUNT_NUMBER == client.accountNumber) {
            stInformationClientBank updatedClient = readEveryClientToUpdateClient();
            updatedClient.accountNumber = kNACCOUNT_NUMBER;
            client = updatedClient;
            break;
        }
    }
}

void FunctionUpdateClient(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentUpdateClient();

    string accountNumber{ "" };
    accountNumber = readText("Enter Account Number : ");
    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {
        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Update this client ? [Y/N]  : ")) == 'y')) {

            //Operation updateClient 
            updateClientDirct(accountNumber, kINFO_CLIENT);
            //Loading after update Client in the file 
            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Update Successfully (: ";

            // Reload the data in vector 
            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME);
        }
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        ButtonGoBackMenu();
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number ( " << accountNumber << " ) Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
        ButtonGoBackMenu();
    }
}

// Function Transaction 

void depositOperation(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount) {

    for (stInformationClientBank& client : kINFO_CLIENT) {

        if (client.accountNumber == kACCOUNT_NUMBER) {
            client.accountBalance += ammount;
            break;
        }
    }

}

void withdrawOperation(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount) {

    for (stInformationClientBank& client : kINFO_CLIENT) {

        if (client.accountNumber == kACCOUNT_NUMBER) {
            client.accountBalance -= ammount;
            break;
        }
    }

}
bool validationSmallerAmmountOfBalanceWithdraw(string const kACCOUNT_NUMBER, vector<stInformationClientBank>& kINFO_CLIENT, long double ammount) {

    for (const stInformationClientBank& client : kINFO_CLIENT) {
        if (kACCOUNT_NUMBER == client.accountNumber)
            if (ammount >  client.accountBalance) {
                return true;
                break;
            }
    }

    return false; 
}
void FunctionOperationWithDrawBalance(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentWithDrawOperationSecreen();

    string accountNumber{ "" };
    accountNumber = readText("Enter Account Number : ");
    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreenTransaction();
        cout << FunctionCreateNewLine(::kNUMBER_LINE);

        long double ammountBalance ;

        bool flagSmaller = true;
        do {

            ammountBalance = readNumberFloatingPointPositive("Please, Enter Withdraw Ammount : ");
            flagSmaller =  validationSmallerAmmountOfBalanceWithdraw(accountNumber, kINFO_CLIENT, ammountBalance);
            if (flagSmaller)
                cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Ammount Exceeds the balance , You can withdraw up to [ " << ammountBalance << " ] " << FunctionCreateNewLine(::kNUMBER_LINE);

        } while (flagSmaller);

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Perform this Transaction Withdraw of this client ? [Y/N]  : ")) == 'y')) {

            //Operation withdraw 
            withdrawOperation(accountNumber, kINFO_CLIENT, ammountBalance);
            //Loading after update Client in the file 
            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Withdraw Ammount is Successfully (: ";

            // Reload the data in vector 
            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME);
        }
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        ButtonGoBackMenuTransaction();
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number ( " << accountNumber << " ) Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreenTransaction();
        ButtonGoBackMenuTransaction();
    }
}


void FunctionOperationDepositBalance(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentDepositOperationSecreen();

    string accountNumber{ "" };
    accountNumber = readText("Enter Account Number : ");
    stInformationClientBank  kINFO_ONE_CLIENT;
    
    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreenTransaction();
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        long double const kAMMOUNT = readNumberFloatingPointPositive("Please, Enter Deposit Ammount : ");

        if ((convertCharacterUpperToLower(readCharacter("Are sure you want Perform this Transaction Deposit of this client ? [Y/N]  : ")) == 'y')) {

            //Operation Depoist 
            depositOperation(accountNumber, kINFO_CLIENT , kAMMOUNT);
            //Loading after update Client in the file 
            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#");

            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Depoist Ammount is Successfully (: ";

            // Reload the data in vector 
            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME);
        }
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        ButtonGoBackMenuTransaction();
    }
    else {

        cout << FunctionCreateNewLine(::kNUMBER_LINE)
            << FunctionPrintTabs(::kNUMBER_TAB)
            << "The Account Number ( " << accountNumber << " ) Not Found ): "
            << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreenTransaction();
        ButtonGoBackMenuTransaction();
    }
}

long double calculationAllClientBalance(vector<stInformationClientBank>& vectorInformationClient) {

    long double totalBalanceAllClient{ 0 }; 
    for (const stInformationClientBank& client : vectorInformationClient)
        totalBalanceAllClient += client.accountBalance; 

    return totalBalanceAllClient; 
}

void FunctionShowBalanceLists(string const kFILE_NAME) {


    vector<stInformationClientBank>  infoClient;

    infoClient = loadDataFromFile(kFILE_NAME, "#//#");

    unsigned short int numberClient = infoClient.size();

    HeaderTabBarSectionShowClientBalanceList_TransactionSection(numberClient);

    for (stInformationClientBank const& client : infoClient) {

        printInfomationClientOneDepartmentTransaction(client);

    }

    footerSectionShowBalanceListTransaction(calculationAllClientBalance (infoClient));
    ButtonGoBackMenuTransaction();
}
void exitBank(void) {

    clearSecreenOnDetailes();
    headerDepartmentExitProgram();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + (::kONE + ::kONE)) << FunctionPrintTabs(::kNUMBER_TAB + (::kONE + ::kONE)) << "Thank you To Using My Bank Sir (: " << FunctionCreateNewLine(::kNUMBER_LINE + 3);
    system("pause>0");
}

void FunctionTransaction(vector<stInformationClientBank>& vectorInformationClient);

void welcomeMainMenuSection(void) {

    clearSecreenOnDetailes();
    HeaderMenuBank();
    bodyInformationMenu();

    cout << FunctionCreateNewLine(::kONE);

}
void mainBank() {

    int choise{ ::kZERO };
    //Loading Data in file to vector 
    vector<stInformationClientBank> vectorInformationClient = loadDataFromFile(::kFILE_NAME);

    int counter{ ::kZERO };

    while (--counter) {

        welcomeMainMenuSection();

        choise = readNumberPositiveInteger("Enter the Choise : ");
        enChoiseDepartmentBank choiseDepartment = static_cast<enChoiseDepartmentBank> (choise);

        switch (choiseDepartment) {

        case enChoiseDepartmentBank::kSHOW_INFORMATION_CLIENT_SECTION:

            FunctionShowClientLists(::kFILE_NAME);
            break;

        case enChoiseDepartmentBank::kADD_CLIENT_SECTION:

            functionAddNewClient(vectorInformationClient);
            break;

        case enChoiseDepartmentBank::kDELETE_CLIENT:

            FunctionDeleteClient(vectorInformationClient);
            break;

        case enChoiseDepartmentBank::kUPDATE_CLIENT:

            FunctionUpdateClient(vectorInformationClient);
            break;

        case enChoiseDepartmentBank::kFIND_CLIENT:

            FunctionFindClient(vectorInformationClient);
            break;

        case enChoiseDepartmentBank::kTRANSACTION : 
            FunctionTransaction(vectorInformationClient);
           //ButtonGoBackMenu();
            break;
        case enChoiseDepartmentBank::kEXIT:

            exitBank();
            exit(0);

        default:

            cout << FunctionCreateNewLine(::kNUMBER_LINE + 1) <<
                FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
            ButtonGoBackMenu();
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

    int choise{ ::kZERO };
    int counter{ ::kZERO };

    while (--counter) {
        //Welcome
        welcomeTransactionSection();


        choise = readNumberPositiveInteger("Enter the Choise : ");
        enChoiseDepartmentTransaction choiseDepartment = static_cast<enChoiseDepartmentTransaction> (choise);

        switch (choiseDepartment) {

        case enChoiseDepartmentTransaction::kDEPOSIT_BALANCE :

            FunctionOperationDepositBalance(vectorInformationClient);
            break;

        case enChoiseDepartmentTransaction::kWITHDRAW_BALANCE : 
            FunctionOperationWithDrawBalance(vectorInformationClient);
            break; 

        case enChoiseDepartmentTransaction::kTOTAL_BALANCE : 
            FunctionShowBalanceLists(::kFILE_NAME);
            break; 
        case enChoiseDepartmentTransaction::kBACK_MAIN_MENU :

            mainBank();
            break;

        default:

            cout << FunctionCreateNewLine(::kNUMBER_LINE + 1) <<
                FunctionPrintTabs(::kNUMBER_TAB)
                << "Invalid Choice! Please try again.\n";
            ButtonGoBackMenuTransaction();
        }
    }
}
 
int main() {


#if RUN
    void (*START_PROGRAMM_SYSTEM_BANK) (void) = mainBank;

    START_PROGRAMM_SYSTEM_BANK();

#else
    cout << "Welcome Bank System (:";

#endif 

    return 0;

}