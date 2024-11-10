#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
using namespace std;
fstream DataFile;
fstream DataNotification;

void main_menu();
void PrintMenu(string Prompt = "", int num = 60);
void PrintEqual(int, string ch = "*");// "★");
void DeleletClient();
void BeforePrint();
string EnterAccountNumber(string Enter="Enter Account Number");
void PressAnyKey();
void LoadFromFile();
void LoadToFile();
void AddClient();
void UpdateClient();
void FindClient();
void Deposit();
void WithDraw();
void BeforePrintBalance();
void AllBalance();
string ConvertName(string);
bool CheckName(string Name);
string  EnterName();
void DeletAllClints();
void  DeletOneClient();
void LoanMoney();
void MainMenuePrint();
void PrintClintsWithLoan();
void PrintClintsWithoutLoan();
void TurnFromAccountTOAnother();
void Notification();
void LoadToFileNotification();
void LoadFromFileNotification();
void InputSetNotification(string S1, double Temp, string S2, string account, string S3);
string EnterPassword();
bool CheckPassword(string pass);
class CLIENT {
private:
    string name;
    string AccountNumber;
    int phone;
    double AccountBalance;
    int pincode;
    string PassWord;
    string Email;

public:
/*
    class EMAIL {
    private:
    

    public:
        
    };

*/
    void PrintAllClient() {
        {
            cout<<"| "<< left << setw(10) << AccountNumber
                <<"| "<< left << setw(10) << PassWord
                <<"| "<< left << setw(10) << pincode
                <<"| "<< left << setw(20) << name
                <<"| "<< left << setw(15) << phone
                <<"| "<< left << setw(10) << AccountBalance
                <<"| "<< left << setw(12) << Email << endl;

        }
    }
    void PrintOneClient() {

        cout<< "Account Number  -:> " << AccountNumber << endl
            << "Password        -:> " << PassWord << endl
            << "Pin Code        -:> " << pincode << endl
            << "Nmae            -:> " << name << endl
            << "Phone           -:> " << phone << endl
            << "Email           -:> " << Email<<endl
            << "Balance         -:> " << AccountBalance<<endl;


    }
    bool CheckIfFind(string Account) {
        if (Account == AccountNumber)
            return true;
        else
            return false;
    }
    void InputAccount2(string &ACC) {
        AccountNumber = ACC;
       
    }
    void InputName2(string &nn) {
       name = nn;
       
    }
    void InputAccount() {
        cout << "Enter Account Number -:> ";
        cin >> AccountNumber;
    }
    void InputPhone() {
        cout << "Enter phone -:> ";
        cin >> phone;
    }
    void InputPinCode() {
        cout << "Enter PinCode -:> ";
        cin >> pincode;
    } 
    void InputName() {
        cout << "Enter name -:> ";
        getline(cin >> ws, name);
    }
    void InputBalance() {
        cout << "Enter Account Balance -:> ";
        cin >> AccountBalance;
    }
    double ReturnBalance() {
    
        return AccountBalance;
    }
    void TurnBalance(double Balance) {

        AccountBalance = Balance;
    }


    string Diveded() {
        string N;
        stringstream ss;
        ss << AccountNumber <<" "<<PassWord<< " " << pincode << " "
            << quoted(name) << " " << phone << " "
            <<Email<<" " << AccountBalance;


        return ss.str();
    }
    void Load(string P) {
        stringstream ss(P);
        ss >> AccountNumber >>PassWord>> pincode
            >> quoted(name) >> phone>> Email
            >> AccountBalance;

    }
    void PrintAllBalance() {
        {
            cout << "| " << left << setw(10) << AccountNumber
               
                 << "| " << left << setw(20) << name
                
                 << "| " << left << setw(10) << AccountBalance << endl;

        }
    }
    void InputEmail() {
        cout << "Enter your Email -:> ";
        cin >> Email;
        Email = Email + "@ATA.com";

    }
    void InputPassWord() {
        cout << "Enter Passaword -:> ";
        cin >> PassWord;
    }
    void InputPassWord2(string Pass) {
        PassWord=Pass;
    }
    string ReturnPassWord() {
        return PassWord;
    }
};
vector<CLIENT>Vect;
vector<string>SetNotification;

CLIENT FillVect() {
    CLIENT Add;
    //, name;
   // int pincode, phone;
    //double AccountBalance;
    string check;
back:

    check=EnterAccountNumber();// this var for checking if there is Account with the same number
    if (Vect.size() > 0) {

        for (int i = 0; i < Vect.size(); i++)
        {
            if (Vect[i].CheckIfFind(check)) {
                cout << "Sorry!! Client with [" << check
                    << "] already exist,Enter Anthor Account Number" << endl;
                goto back;
            }
        }
    }
   
        Add.InputAccount2(check);
        //Add.InputPassWord();
        BackPass:
        string pass = EnterPassword();
         
            if (CheckPassword(pass) ) {
                Add.InputPassWord2(pass);

        }
            else {
                cout << "You Entered Not Valid Password,Must be More Or Equal To [7] letters? " << endl;
                goto BackPass;
            }

    Add.InputPinCode();
    Back:
    string Name = EnterName();
    if (CheckName(Name))
    {
       Name=ConvertName(Name);
       Add.InputName2(Name);

    }
    else {
        cout << " The Name That you Enered is Unvalid Try Again :" << endl;
        goto Back;

    }

   // Add.InputName();
    Add.InputPhone();
    Add.InputEmail();
    Add.InputBalance();
    return Add;

}
void BeforePrint() {
    cout << "\t\t\t\033[31mClient List (" << Vect.size() << ") Client(s) \033[0m\n";
    //PrintMenu("Print All Client");
    cout << endl;
    PrintEqual(100, "_");
    cout << left << setw(12) << "| Number"
        << left << setw(12) << "| Password "
        << left << setw(12) << "| Pin Code "
        << left << setw(22) << "| Name"
        << left << setw(17) << "| Phone"
        << left << setw(12) << "| Balance "
        << left << setw(15) << "| Email " << endl;
    PrintEqual(100, "_");


}
void main_menu() {
    //  LoadFromFile();
   // system("cls");
   
    PrintMenu("Main Menu");

    cout << "\t\t" << "\033[35m[1]  Show Client List \033[0m" << endl;
    cout << "\t\t" << "[2]  Add New Client" << endl;
    cout << "\t\t" << "\033[36m[3]  Delete Client \033[0m" << endl;
    cout << "\t\t" << "\033[33m[4]  Update Client info \033[0m" << endl;
    cout << "\t\t" << "\033[32m[5]  Find Client \033[0m" << endl;
    cout << "\t\t" << "\033[34m[6]  Transactions \033[0m" << endl;
    cout << "\t\t" << "\033[83m[7]  Special Of Bank \033[0m" << endl;
    cout << "\t\t" << "\033[35m[8]  Notification Of The Bank \033[0m" << endl;
    cout << "\t\t" << "\033[31m[9]  Exit\033[0m" << endl;
    PrintEqual(60);

}
void PrintMenu(string Prompt, int num) {
    PrintEqual(num);
    cout << "\t\t" << "\033[41m" << Prompt << "\033[0m" << endl;
    PrintEqual(num);
}
void PrintEqual(int count, string ch) {
    cout << "\033[32m";
    for (int i = 0; i < count; i++)
    {
        cout << ch;
    }
    cout << "\033[0m" << endl;
}
void LoadToFile() {

    DataFile.open("Data.txt", ios::out);
    if (DataFile.is_open())
        for (int i = 0; i < Vect.size(); i++)
        {
            string temp = Vect[i].Diveded();
            DataFile << temp << endl;
        }
    DataFile.close();
}
void LoadFromFile() {
    DataFile.open("Data.txt", ios::in);
    //int i=0;
    string line;
    if (DataFile.is_open())
    {

        while (getline(DataFile, line)) {
            CLIENT A;
            A.Load(line);
            Vect.push_back(A);
            //i++;
        }
    }
    else
        cout << "The file not opened"<<endl;

    DataFile.close();
}
void AddClient() {
    Start:
    //LoadFromFile();
    CLIENT a;
    PrintMenu("\033[0m\033[46mAdd New Client");
    a = FillVect();

        Vect.push_back(a);
        char YN;
        cout << "Client Add Successfully,Do you wnat to add more clients? Y/N -:> ";
        cin >> YN;
        if (YN == 'Y' || YN == 'y'){
            system("cls");
            LoadToFile();
            goto Start;
        }
        else
    LoadToFile();


            return;
   
    
   // PressAnyKey();
}
void PressAnyKey() {
    string H;
    cout << "Prees any key to go to  main menue . . .";
    cin >> H;
 //   main_menu();

}
string EnterAccountNumber(string Enter) {
    string check;
    cout << Enter<<"-:> ";
    getline(cin >> ws, check);
    return check;
}
void DeleletClient() {
    char YN;
    int Choose;
Start:
        system("cls");
    PrintMenu("\n\t\tDelelet Client Screen\n", 40);
    cout <<"\t\t\033[42m[1] Delet All Clints.\033[0m\n "
        << "\t\t\033[46m[2] Delet One Client .\033[0m\n "
        << "\t\t\033[36m[3] Main menue.\033[0m\n ";
    PrintEqual(40,"~");
    cout << "Choose What You Want To Do [1 to 3 ]? ";
    cin >> Choose;
    switch (Choose)
    {
    case 1:
        system("cls"); 
        DeletAllClints();
        PressAnyKey();
        system("cls");
    LoadToFile();
        goto Start;
        break;
    case 2:

        system("cls");
        DeletOneClient();
        LoadToFile();
     //  PressAnyKey();

		goto Start;
        break;

    case 3:
        // PressAnyKey();
        break;
    }
    
}
void UpdateClient() {
    char YN;
    PrintMenu("\n\t\tUpdate Client Info Screen\n", 40);
Start:
    cout << endl;
    string Enter = EnterAccountNumber();
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(Enter)) {
            Vect[i].PrintOneClient();
            cout << endl;
            PrintEqual(25, "_-");
            cout << "\n\nAre You sure to update This client -:> Y/N";
            cin >> YN;
            if (YN == 'Y' || YN == 'y') {
                //cout << "\nClient Deleted Successfully,Do you wnat to Delete more clients? Y/N -:> ";
              //  Vect.erase(Vect.begin() + i);
                Vect[i].InputPinCode();
                Vect[i].InputName();
                Vect[i].InputPhone();
                Vect[i].InputEmail();
                Vect[i].InputBalance();


                break;

            }

            else if (YN == 'n' || YN == 'N') {
                // goto Start;
                cout << "Not Updated " << endl;
                return;
            }
        }
        if (i + 1 == Vect.size()) {
            cout << "Try Again not Found this Client \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
            if (Enter != "0")
                goto Start;
            else {
                system("cls");
                return;
            }
        }
        }
    LoadToFile();
    }
void FindClient() {
    char YN;
    PrintMenu("\n\t\t\033[32m  Find Client \033[0m\n", 40);
Start:
    cout << endl;
    string Enter = EnterAccountNumber();
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(Enter)) {
            Vect[i].PrintOneClient();
            
            return;

        }
        else if (Vect.size()==i+1)
        {
            cout << "Try Again not Found this Client \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
            if (Enter != "0")
                goto Start;
            else {
                system("cls");
                return;
            }

        }
    }
}
void Transaction() {
    int choose;
Back:
    system("cls");
    PrintMenu("\n\t\t Transaction menue Screen \n", 40);
    cout << "\t\t\033[42m[1] Deposit.\033[0m\n "
         << "\t\t\033[46m[2] Withdrow.\033[0m\n "
         << "\t\t\033[44m[3] Loan.\033[0m\n "
         << "\t\t\033[45m[4] Turn From Account To Another.\033[0m\n "
         << "\t\t\033[43m[5] Total Balance.\033[0m\n "
         << "\t\t\033[36m[6] Main menue.\033[0m\n ";
    PrintEqual(40);
    cout << "Choose What You Want To Do [1 to 4 ]? ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            system("cls");
            Deposit();
            PressAnyKey();
            goto Back;
            break;
          case 2:
              system("cls");
              WithDraw();
              PressAnyKey();
            goto Back;
            break;
             case 3:
                 system("cls");
                 LoanMoney();
                     PressAnyKey();
                 goto Back;
                 break;
            case 4:
              system("cls");
              TurnFromAccountTOAnother();
              PressAnyKey();
            goto Back;
            break;
            
             case 5:
                 system("cls");
                 AllBalance();
                     PressAnyKey();
                 goto Back;
                 break;
             case 6:
                 return;

        default:
            cout << "not here " << endl;
                 PressAnyKey();

            break;
        }
        

}
void Deposit() {

    char YN;
    double Number;//for adding account balance to its account 
    PrintMenu("\n\t\t Deposit Screen \n", 40);
Start:
    cout << endl;
    string Enter = EnterAccountNumber();
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(Enter)) {
            Vect[i].PrintOneClient();
            cout << endl;
            PrintEqual(25, "_-");
            cout << "\n\nPlease Enter Deposit Amount ? ";
            cin >> Number;
            cout << "\n\nAre You sure to Preform This transaction  -:> Y/N ";
            cin >> YN;
            if (YN == 'Y' || YN == 'y') {
                InputSetNotification("Done, Deposit {",Number, "}  To This Account [", Enter, "] ...");

                Number += Vect[i].ReturnBalance();
                Vect[i].TurnBalance(Number);
                cout << "Done successfully. New Balance is : " << Number << endl;
                LoadToFileNotification();
                break;

            }
            else {
                cout << "Not Performed Transaction " << endl;

                return;
            }
        }
        else if(Vect.size()==i+1){
            cout << "Try Again not Found this Client \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
            if (Enter != "0")
                goto Start;
            else {
                system("cls");
                return;
            }
        }
    }
    LoadToFile();
}
void WithDraw() {


    char YN;
    double Number;//for adding account balance to its account 
    PrintMenu("\n\t\t Withdraw Screen \n", 40);
Start:
    cout << endl;
    string Enter = EnterAccountNumber();
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(Enter)) {
            Vect[i].PrintOneClient();
            cout << endl;
            PrintEqual(25, "_-");
            cout << "\n\nPlease Enter Withdraw Amount ? ";
            cin >> Number;
            if (Number <= Vect[i].ReturnBalance()) {
                cout << "\n\nAre You sure to Preform This transaction  -:> Y/N ";
                cin >> YN;
                if (YN == 'Y' || YN == 'y') {
                    InputSetNotification("Done, Withdraw {", Number, "} From This Account [", Enter, "] ...");
                    LoadToFileNotification();
                    Number = Vect[i].ReturnBalance() - Number;
                    Vect[i].TurnBalance(Number);
                    LoadToFile();
                    cout << "Done successfully. New Balance is : " << Number << endl;
                    break;

                }
                else {
                    LoadToFile();

                    return;
                }

            }
            else {
                cout << "The Money That you WithDrow is more that you have in your account "<<endl;

            }
        }
        else if (Vect.size() == i + 1) {
            cout << "Try Again not Found this Client \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
            if (Enter != "0")
                goto Start;
            else {
               // system("cls");
                return;
            }

        }
        LoadToFile();

    }
}
void AllBalance() {
    double Temp=0;
    BeforePrintBalance();
    for (size_t i = 0; i < Vect.size(); i++)
    {
        Vect[i].PrintAllBalance();
        Temp += Vect[i].ReturnBalance();
    }
    PrintEqual(40, "$");
    cout << "\t\t    Total Balance | " << Temp << endl;

}
void BeforePrintBalance() {

    cout << "\t\t\t\033[31mClient List (" << Vect.size() << ") Client(s) \033[0m\n";
    PrintMenu("Print All Client");
    cout << endl;
    PrintEqual(70, "_");
    cout << left << setw(12) << "| Number"
        << left << setw(22) << "| Name"
        << left << setw(12) << "| Balance " << endl;
    PrintEqual(70, "_");


}
string ConvertName(string Name) {
    string Temp = "";
    for (size_t i = 0; i < Name.length(); i++)
    {
        if (i == 0)
        Temp+=toupper(Name[0]);
        else if (Name[i] == ' ') {

            Temp +=' ';
            Temp +=toupper(Name[i + 1]);
        }

        else
            Temp += tolower(Name[i]);
    }
  return Temp;

}
bool CheckName(string Name) {
    int count = 0;
    for (size_t i = 0; i < Name.length(); i++)
    {
        if (Name[i] < 'A' && Name[i] != ' ')
            return false;
        else if (Name[i] > 'Z' && Name[i] < 'a')
            return false;
        else if (Name[i] == ' ')
            continue;
    }
  
        return true;
  

}
string  EnterName() {
    string name;
    cout << "Enter name -:> ";
    getline(cin >> ws, name);
    return name;
}
string  EnterPassword() {
    string password;
    cout << "Enter Password -:> ";
    getline(cin >> ws, password);
    return password;
}
void  DeletAllClints() {
    char YN;
    PrintMenu("\n\t\t Delet All Clints \n", 40);
    cout << endl;
    cout<<  Vect.size()<< " Are You sure To Delet All Clints Y/N? ";
    cin >> YN;
    if (YN == 'Y' || YN == 'y') {
        int Empty = Vect.size();
        for (size_t i = 0; i <Empty; i++)
        {
            Vect.erase(Vect.begin());

            if (i==Empty-1)
            {
                
        cout <<Vect.size()<< " Done successfully. All Clints Deleted " << endl;
                
            }

        }
    }
    else {
       // PressAnyKey();

        return;
    }

}
void  DeletOneClient() {
    char YN;
    string password;
    PrintMenu("\n\t\t Delet One Client Screen \n", 40);
    {
    Back:
        string Enter = EnterAccountNumber();
        for (int i = 0; i < Vect.size(); i++)
        {
            if (Vect[i].CheckIfFind(Enter)) {
                BackPassword:
                cout << " Enter The Password Of This Client -:> ";
                cin >> password;
                if(password==Vect[i].ReturnPassWord()) {
                    Vect[i].PrintOneClient();
                cout << endl;
                PrintEqual(25, "<>");
                cout << "\n\nAre You sure to Delete This client -:> Y/N";
                cin >> YN;
                {
                if (YN == 'Y' || YN == 'y') {
                    cout << "\nClient Deleted Successfully ,Do you want to Delete more Clients? Y/N -:> ";
                    Vect.erase(Vect.begin() + i);
                    cin >> YN;
                    if (YN == 'Y' || YN == 'y')
                    {
                        system("cls");
                        goto Back;
                    }
                    else
                        break;
                }
            else if (YN == 'n' || YN == 'N') {
                    // goto Start;
                    cout << "\t\t\033[32mNot Deleteted\033[0m" << endl;
                    PressAnyKey();
                    break;
                }
                }

                }
                else {
                    cout << "\033[31m The password that entered is not correct,try again?\033[0m 'Enter 0 to Exit This Screen'"<<endl;
                    if (password == "0"){
                        system("cls");
                        return;
                    }
                    else
                    goto BackPassword;
                    }


            }
            else if (i + 1 == Vect.size()) {
                cout << "Not find Try again \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
                if (Enter != "0")
                    goto Back;
                else {
                    system("cls");
                    return;
                }

            }
        }
    }
}
void LoanMoney() {
    char YN;
    double Moneyloan;
    PrintMenu("\n\t\t Loan Money From The Bank \n", 40);

Back:
    string Enter = EnterAccountNumber();
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(Enter)) {
            Vect[i].PrintOneClient();
            cout << endl;
            PrintEqual(25, "<>");
            cout << "\n\nAre You sure to Loan  From The Bank to This Client -:> Y/N";
            cin >> YN;

            if (YN == 'Y' || YN == 'y') {
                cout << "Enter How Many Money Do You Want to Loan ? ";
                cin >> Moneyloan;
                if(Moneyloan<=100000 && Vect[i].ReturnBalance()<=0) {
                   // for Notification
                    InputSetNotification("Done, Load {", Moneyloan, "} From The Bank To This Account [", Enter, "] ...");
                    LoadToFileNotification();
                    Moneyloan +=-Vect[i].ReturnBalance();
                    Moneyloan =-Moneyloan;
                    Vect[i].TurnBalance(Moneyloan);

                cout << "\nDone Successfully,,your Amount is "<<Moneyloan<<endl;
                LoadToFile();

                return;
                }
                else if (!(Moneyloan <= 100000 && Vect[i].ReturnBalance() == 0) && Vect[i].ReturnBalance() == i+1)
                {
                    cout << "Wrong Entered,You maybe want to loan more than 100,000 or your Balance more Than 0 "<<endl;
                    return;
                  
                }
               

            }
            else if (YN == 'n' || YN == 'N') {
                // goto Start;
                cout << "\t\t\033[32mNot Loaned \033[0m" << endl;
             //   PressAnyKey();
                break;
            }

        }
        else if (i + 1 == Vect.size()) {
            cout << "Not find Try again \033[31m 'Enter 0 to Exit This Screen' \033[0m¿¿ " << endl;
            if (Enter != "0")
                goto Back;
            else {
                system("cls");
                return;
            }

        }
    }


}
void MainMenuePrint() {
    Back:
    system("cls");
    PrintMenu("\n\t\t Main Menue of all Clients \n", 40);
    cout << endl;
    int choose;

    cout<< "\t\t\033[42m[1] Print All Clients.\033[0m\n "
        << "\t\t\033[46m[2] Print Clints With Loan.\033[0m\n "
        << "\t\t\033[44m[3] Print Clints Without Loan.\033[0m\n "
        << "\t\t\033[36m[4] Main menue.\033[0m\n ";
    PrintEqual(40);
    cout << "Choose What You Want To Do [1 to 4 ]? ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        system("cls");
        PrintMenu("\n\t\t Print ALl Clints Screen \n", 40);
    BeforePrint();
    for (int i = 0; i < Vect.size(); i++)
    {
        Vect[i].PrintAllClient();
    }
    PrintEqual(50, "+_");
        PressAnyKey();
        goto Back;
        break;
    case 2:
        system("cls");
        PrintClintsWithLoan();
        PressAnyKey();
       
        goto Back;
        break;

    case 3:
        system("cls");
        PrintClintsWithoutLoan();
        PressAnyKey();
        goto Back;
        break;
    case 4:
        return;

    default:
        cout << "not here " << endl;
        PressAnyKey();

        break;
    }
}
void PrintClintsWithLoan() {
    PrintMenu("\n\t\t Print Clints With Loan Screen \n", 40);
    cout << endl;
    BeforePrint();
   
    {
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].ReturnBalance() < 0) {
        Vect[i].PrintAllClient();
       
        }
    }

    }
    PrintEqual(50, "+_");

}
void PrintClintsWithoutLoan() {
    PrintMenu("\n\t\t Print Clints Without Loan Screen \n", 40);
    cout << endl;
    BeforePrint();
   
    {
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].ReturnBalance() > 0) {
        Vect[i].PrintAllClient();

        
        }
    }

    }
    PrintEqual(50, "+_");

}
void  SpecialOfTheBank() {
    PrintMenu("\n\t\t Print Clints Without Loan Screen \n", 40);
    cout << endl;
    int WithLoan = 0, WithoutLoan = 0;

    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].ReturnBalance() < 0) {
            WithLoan++;

        }
    }
    for (int i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].ReturnBalance() > 0) {
            WithoutLoan++;


        }
    }
    cout << "\tAll The Client Bank Of is         :" << Vect.size()<<endl;
    cout << "\tAll The Client With Loan is       :" << WithLoan<<endl;
    cout << "\tAll The Client Without Loan is    :" << WithoutLoan<<endl;
    cout << "\t----------------------------------------------" << endl;
    cout << "\tAll Client                        :" << Vect.size()<<endl;
   
}
void TurnFromAccountTOAnother() {
    int i,j;
    double Temp;
    Start:
    PrintMenu("\n\t\t Turn From Account To Another  \n", 40);
    cout << endl;
    Back:
    string TurnFrom,TurnTo,PassWord;
    TurnFrom = EnterAccountNumber("Enter Account Number That You Want to Turn From it ");
    for ( i = 0; i < Vect.size(); i++)
    {
        if (Vect[i].CheckIfFind(TurnFrom))
            break;
        else if (Vect.size() == i + 1) {
            cout << "The Count is not found " << endl;
            goto Back;

        }
    }
    Pass:
    PassWord = EnterAccountNumber("Enter The Password of This Account ");
    if (!(Vect[i].ReturnPassWord()==PassWord))
    {
        cout << "Sorry,,The Password is Wroing " << endl;
        //system("cls");
        goto Pass;
    }
    Lab:
    TurnTo = EnterAccountNumber("Enter Account Number That You Want to Turn to it ");
    cout << endl;
    for (j = 0; j < Vect.size(); j++)
    {
        if (Vect[j].CheckIfFind(TurnTo))
            break;
        else if (Vect.size() == j + 1) {
            cout << "The Count That you Want to Turn To it is not found " << endl;
            goto Lab;

        }
    }
    Here:
    double Num;
    cout << "How Many money you want to trun it from [" << TurnFrom << "] to [" << TurnTo << "] ? ";
    cin >> Temp;
    if (Temp<=Vect[i].ReturnBalance())
    {
        Num = Vect[i].ReturnBalance() - Temp;
        Vect[i].TurnBalance(Num);
        InputSetNotification("Done Deducted{", Temp, "} From  Account [", TurnFrom, "] ...");
        Num = Vect[j].ReturnBalance() + Temp;
        Vect[j].TurnBalance(Num);
        InputSetNotification("Done Deposit {", Temp, "} to  Account [", TurnTo, "] ...");
        LoadToFileNotification();
        LoadToFile();


    }
    else {
      
        cout << "The Money That you Want ["<<Temp<<"] to Turn  it is More that What You Have ["<< Vect[i].ReturnBalance()<<"] ?" << endl;
        goto Here;
    }



}
void Notification() {
    PrintMenu("\n\t\t All Notification Of Bank  \n", 40);
    cout << endl;
   // SetNotification.push_back(show);
    for (size_t i = 0; i <SetNotification.size();i++)
    {
        cout << SetNotification[i] << endl;
    }
   

}

void LoadToFileNotification() {

    DataNotification.open("Notification.txt", ios::out);
    if (DataNotification.is_open())
        for (int i = 0; i < SetNotification.size(); i++)
        {
            string temp = SetNotification[i];
            DataNotification << temp << endl;
        }
    DataNotification.close();
}
void LoadFromFileNotification() {
    DataNotification.open("Notification.txt", ios::in);
    //int i=0;
    string line;
    if (DataNotification.is_open())
    {

        while (getline(DataNotification, line)) {
          
            SetNotification.push_back(line);
        }
    }
    else
        cout << "The file not opened" << endl;

    DataNotification.close();
}
void InputSetNotification(string S1,double Temp,string S2,string account,string S3){
    stringstream ss;
    ss << S1 << Temp << S2 << account<<S3;
    
   //S1 = "Done Deducted {" + to_string( Temp);
   // inputtoSetNotification += "} From  Account [" + TurnFrom + "]  ";
    SetNotification.push_back(ss.str());
    LoadToFileNotification();
    }

bool CheckPassword(string pass) {
    for (size_t i = 0; i <pass.length(); i++)
    {
        if (pass.size() < 7) {
            return false;
        }

    }
    return true;

}
int main() {
  //  system("color 9D");
    LoadFromFile();
    LoadFromFileNotification();
       int choose;

    do{
       system("cls");
       main_menu();
       cout << "\033[44m \033[4mChoose What You Want to Do ? [1 to 7] ->: \033[0m\033[0m";
       cin >> choose;
       switch (choose)
       {
       case 1:
           system("cls");
           MainMenuePrint();
           break;

       case 2:
           system("cls");
           AddClient();
           break;
       case 3:
           system("cls");
           DeleletClient();
           break;
       case 4:
           system("cls");
           UpdateClient();
           break;
        case 5:
           system("cls");
           FindClient();
           cout << endl;
          PressAnyKey();
           
           break;
            case 6:
           system("cls");
           Transaction();
           cout << endl;
           PressAnyKey();
           
           break;

            case 7:
               system("cls");
               SpecialOfTheBank();
               cout << endl;
           PressAnyKey();
           break;
            case 8:
               system("cls");
               Notification();
               cout << endl;
           PressAnyKey();
           break;

       }
    } while (choose != 9);
     
  cout << endl<<"\t\t Program Done " << endl;
}