// Bank System 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

unsigned short int const kZERO{ 0 };
unsigned short int const kONE{ 1 };
unsigned short int const kNUMBER_TAB = { 2 };
unsigned short int const kNUMBER_LINE = { 1 };

string const kFILE_NAME = "Information_Client.txt";

enum enChoiseDepartmentBank {

    kSHOW_INFORMATION_CLIENT_SECTION = 1 , 
    kADD_CLIENT_SECTION =2 , 
    kDELETE_CLIENT = 3 , 
    kUPDATE_CLIENT = 4 ,
    kFIND_CLIENT = 5 , 
    kEXIT = 6 

};
struct stInformationClientBank {

    //Records ( Data ) 
    string accountNumber{ "" };
    string pinCode{ "" };
    string name{ "" };
    string phone{ "" };
    double accountBalance{ 0.0 };

    //Flags 
    bool markDeleteClient = { false };

};

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
void bodyInformationMenu(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [1]- Show Client List                                        +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [2]- Add New Client                                          +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [3]- Delete Client                                           +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [4]- Update Client                                           +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [5]- Find Client                                             +|\n";
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "|+ [6]- Exit Bank                                               +|\n";

    footerEverySecreen();

}

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

double readNumberFloatingPointPositive(const string kMESSAGE) {

    double numberToInputUser{ ::kZERO };

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

string readText(string const kMESSAGE) {

    string textToInputUser{ "" };
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << kMESSAGE;
    getline(cin >> ws, textToInputUser);
    return textToInputUser;
}

stInformationClientBank readEveryClient() {

    stInformationClientBank client{ "" };

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "Enter Account Number : ";
    getline(cin >> ws, client.accountNumber);
    client.pinCode = readText("Enter Pin Code : ");
    client.name = readText("Enter Name : ");
    client.phone = readText("Enter Phone : ");
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    client.accountBalance = readNumberFloatingPointPositive("Enter Account Balance : ");

    return client;
}

stInformationClientBank readEveryClientToUpdateClient () {

    stInformationClientBank client{ "" };

    client.pinCode = readText("Enter Pin Code : ");
    client.name = readText("Enter Name : ");
    client.phone = readText("Enter Phone : ");
    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    client.accountBalance = readNumberFloatingPointPositive("Enter Account Balance : ");

    return client;
}
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
    int poisitonWord{ 0 };
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

    if (Line.size() >= 5) {
        client.accountNumber = Line[0];
        client.pinCode = Line[1];
        client.name = Line[2];
        client.phone = Line[3];
        client.accountBalance = stod(Line[4]);
    }

    return client;

}
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

void loadDataToFile(string const kFILE_NAME_INFORMATION_CLIENT, vector<stInformationClientBank>& infoClient, string const kDILEMTER = "#//#"  ) {

    fstream fileClient{};

    fileClient.open(kFILE_NAME, ios::out);

    if (fileClient.is_open()) {

        string line{ "" };

        for (const stInformationClientBank& kINFO_CLIENT : infoClient) {
            if (kINFO_CLIENT.markDeleteClient == false ){
                line = convertRecordToLine(kINFO_CLIENT, kDILEMTER);
                fileClient << line << FunctionCreateNewLine(::kNUMBER_LINE);
            }
            
        }
    }

    fileClient.close();
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
void functionAddNewClient(vector<stInformationClientBank>& vectorInformationClient) {

    stInformationClientBank infoClient;
    char choise{ 'Y' };
    vector<stInformationClientBank> TempvectorInformationClient; 

    while (choise == 'Y' || choise == 'y') {

        clearSecreenOnDetailes();
        headerDepartmentAddNewClient();
        infoClient = readEveryClient();
        TempvectorInformationClient.push_back(infoClient);
        loadDataToFile_NewClient(::kFILE_NAME, TempvectorInformationClient, "#//#");
        cout << FunctionCreateNewLine(::kNUMBER_LINE);
        cout << FunctionPrintTabs(::kNUMBER_TAB) << "Client Add Successfully, do you want to add more clients? [Y/N] : ";
        cin >> choise;
        TempvectorInformationClient.clear(); 
        
    }
    vectorInformationClient = loadDataFromFile(::kFILE_NAME);
    footerEverySecreen();
    ButtonGoBackMenu();
}

void HeaderTabBarSectionShowClientList(unsigned long int numberClient) {

    clearSecreenOnDetailes();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);
    cout << FunctionPrintTabs(::kNUMBER_TAB + 3)  << "Client list ( " << numberClient << " ) Client(s) " << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE);

    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|    Account Number    |    Pin Code    |         Client Name                   |       Phone       |    Balance ($)  |" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void footerSectionShowClientList(void) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << "|+___________________________________________________________________________________________________________________+|" << FunctionCreateNewLine((::kNUMBER_LINE + ::kONE));

}

void printInfomationClientOne(stInformationClientBank const& kINFO_CLIENT_ONE) {


    cout << "| " << left << setw(21) << kINFO_CLIENT_ONE.accountNumber << "| ",
        cout << left << setw(15) << kINFO_CLIENT_ONE.pinCode << "| ",
        cout << left << setw(38) << kINFO_CLIENT_ONE.name << "| ",
        cout << left << setw(18) << kINFO_CLIENT_ONE.phone << "| ",
        cout << left << setw(16) << kINFO_CLIENT_ONE.accountBalance << "|";
    cout << FunctionCreateNewLine(::kNUMBER_LINE);

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


void printInformationEveryClient(stInformationClientBank& const  kCLIENT) {

    cout << FunctionCreateNewLine(::kNUMBER_LINE);

    cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Following are the Client Details : " << FunctionCreateNewLine(::kNUMBER_LINE+::kONE);

    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Account Number   : " << kCLIENT.accountNumber << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Pin Code         : " << kCLIENT.pinCode << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Name             : " << kCLIENT.name << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Phone            : " << kCLIENT.phone << FunctionCreateNewLine(::kNUMBER_LINE);
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "- Account Balance  : " << kCLIENT.accountBalance<< '$' << FunctionCreateNewLine(::kNUMBER_LINE);

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

bool makeFlagDeleteClient(string const kACCOUNT_NUMBER, vector<stInformationClientBank> & kINFO_CLIENT, stInformationClientBank& client) {

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
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "Enter Account Number : ";
    getline(cin >> ws, accountNumber);

    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {

        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        cout << FunctionPrintTabs(::kNUMBER_TAB) << "Are sure you want delete this client ? [Y/N]  : ";
        cin >> answerAreDelete;

        if (answerAreDelete == 'y' || answerAreDelete == 'Y') {

            makeFlagDeleteClient (accountNumber , kINFO_CLIENT , kINFO_ONE_CLIENT);
            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#" );
            cout <<FunctionCreateNewLine(::kNUMBER_LINE+::kONE ) <<  FunctionPrintTabs(::kNUMBER_TAB) << "Client Delete Successfully (: ";

            kINFO_CLIENT = loadDataFromFile(::kFILE_NAME);
        }
        cout <<  FunctionCreateNewLine(::kNUMBER_LINE );
        ButtonGoBackMenu();
    }
    else {
        cout << FunctionCreateNewLine(::kNUMBER_LINE) << FunctionPrintTabs(::kNUMBER_TAB) << "The Account Number ( " << accountNumber << " ) Not Found ): " << FunctionCreateNewLine(::kNUMBER_LINE);
        footerEverySecreen();
        ButtonGoBackMenu();
    }

}



void FunctionUpdateClient(vector<stInformationClientBank>& kINFO_CLIENT) {

    clearSecreenOnDetailes();
    headerDepartmentUpdateClient();
    char answerAreUpdate = 'n';

    string accountNumber{ "" };
    cout << FunctionPrintTabs(::kNUMBER_TAB) << "Enter Account Number : ";
    getline(cin >> ws, accountNumber);

    stInformationClientBank  kINFO_ONE_CLIENT;

    if (isFoundAccountNumberInFile(accountNumber, kINFO_ONE_CLIENT)) {
        printInformationEveryClient(kINFO_ONE_CLIENT);
        footerEverySecreen();

        cout << FunctionPrintTabs(::kNUMBER_TAB) << "Are sure you want Update this client ? [Y/N]  : ";
        cin >> answerAreUpdate;

        if (answerAreUpdate == 'y' || answerAreUpdate == 'Y') {

            for (stInformationClientBank& cli : kINFO_CLIENT) {
                if (accountNumber == cli.accountNumber) {
                    stInformationClientBank updatedClient = readEveryClientToUpdateClient();
                    updatedClient.accountNumber = accountNumber;
                    cli = updatedClient;
                    break;
                }
            }

            loadDataToFile(::kFILE_NAME, kINFO_CLIENT, "#//#");
            cout << FunctionCreateNewLine(::kNUMBER_LINE + ::kONE)
                << FunctionPrintTabs(::kNUMBER_TAB)
                << "Client Update Successfully (: ";

            // Reload the data
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

void exitBank(void) {

    clearSecreenOnDetailes();
    headerDepartmentExitProgram();
    cout << FunctionCreateNewLine(::kNUMBER_LINE + (::kONE + ::kONE)) << FunctionPrintTabs(::kNUMBER_TAB + (::kONE + ::kONE)) << "Thank you To Using My Bank Sir (: " << FunctionCreateNewLine(::kNUMBER_LINE + 3);
    system("pause>0");
}

void mainBank() {

    int choise = ::kZERO;
    vector<stInformationClientBank> vectorInformationClient = loadDataFromFile(::kFILE_NAME);

    int counter{ ::kZERO };

    while (--counter) {

        clearSecreenOnDetailes();
        HeaderMenuBank();
        bodyInformationMenu();
        cout << endl;

        choise = readNumberPositiveInteger("Enter the Choise : ");

        enChoiseDepartmentBank choiseDepartment = static_cast<enChoiseDepartmentBank> (choise); 
        switch (choiseDepartment) {

        case enChoiseDepartmentBank::kSHOW_INFORMATION_CLIENT_SECTION : 
            
            FunctionShowClientLists(::kFILE_NAME);
            break;

        case enChoiseDepartmentBank::kADD_CLIENT_SECTION: 

            functionAddNewClient(vectorInformationClient);
            vectorInformationClient = loadDataFromFile(::kFILE_NAME);
            break;

        case enChoiseDepartmentBank::kDELETE_CLIENT :

            FunctionDeleteClient(vectorInformationClient);
            vectorInformationClient = loadDataFromFile(::kFILE_NAME);
            break;
      
        case enChoiseDepartmentBank::kUPDATE_CLIENT :

            FunctionUpdateClient(vectorInformationClient);
            vectorInformationClient = loadDataFromFile(::kFILE_NAME);
            break;

        case enChoiseDepartmentBank::kFIND_CLIENT : 

            FunctionFindClient(vectorInformationClient);
            break;

        case enChoiseDepartmentBank::kEXIT :

            exitBank();  
            return;

        default:
            cout << FunctionPrintTabs(::kNUMBER_TAB) 
                << "\nInvalid Choice! Please try again.\n";
            ButtonGoBackMenu();
        }
    }
}

int main() {


    mainBank();
    return 0;
}