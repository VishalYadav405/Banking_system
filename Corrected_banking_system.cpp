
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <string>
#include <cstring>
#include<map>



using namespace std;
//#include "bank_employ_side.cpp"
string PASS;
vector<int> char_value;
vector<string> account_type;
long AN = 0;
long saving_initial_ammount = 10000;
long current_initial_ammount = 100000;
vector<float> interest_rate;
long below_NRV_charge;
long max_transaction_charge;
long atm_charge;
double transaction_charge_persent;

void set_char_value(){
    char_value.push_back(1);
    for(int i=1;i<26;i++){
        char_value.push_back(char_value[i-1]*2 +i+1);
    }
}

class transaction{
    public:
    long ammount;
    string comment;

    transaction* next;
    transaction* prev;

};

class account{
    public:
    long account_number;
    long account_type;
    long total_ammount;
    transaction* last_transaction;
   // long NRV;          // change NRV to double
    long atm_transaction;
    long total_transaction;


    // account* next;
    // account* prev;
    
};


class customer{
    public:
    string first_name, middle_name, last_name, email_id, password;
    long customer_id, mobile_number;
    map<long, account>  customer_accounts;
    
};

//customer* customer_head;
map<long, customer*> mp;

void print_services(){
    cout << "1. Account Opening \n";
    cout << "2. Login \n";
    cout << "3. Exit \n";

}

long generate_customer_id(string name){
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    long customer_id = 0;
    for(int i=0;i<name.size();i++){
        customer_id += char_value[name[i]-65];
    }
    return customer_id;
}


long add_initial_ammount_to_account(int type){
    long initial_ammount;
    cout<< "Add initial ammount\n";
    cin >> initial_ammount;

    if(type ==1){
        if(initial_ammount  >= saving_initial_ammount){
        return initial_ammount;
        }
        else {
            cout << "Minimum amount needed to open an account is Rs ";
            cout << saving_initial_ammount<<endl;
            return add_initial_ammount_to_account(type);
        }
    }
    else{
        if(initial_ammount  >= current_initial_ammount){
        return initial_ammount;
        }
        else {
            cout << "Minimum amount needed to open an account is Rs ";
            cout << current_initial_ammount<<endl;
            return add_initial_ammount_to_account(type);
        }
    }

}

void make_new_account(int type){
    
    cout<<"Give the following deatils for opening new account\n";
    cout << "Enter your First name\n";

    string first_name, middle_name="", last_name="";

    cin>>first_name;

    long customer_id = generate_customer_id(first_name);

    cout << "Enter your Middle name\n";
    cin >> middle_name;
    cout << "Enter your last name\n";
    cin >> last_name;

    int DOB_D,DOB_M,DOB_Y;
    cout<< "enter your year of birth\n";
    cin >> DOB_Y;
    cout<<" enter your month of birth\n";
    cin >> DOB_M;
    cout<< " enter your day of birth\n";
    cin >> DOB_D;

    long mobile_number;
    cout<< "Enter your Mobile number\n";
    cin >> mobile_number;

    string email_id, address, password;
    cout<< " enter your email id\n";
    cin >> email_id;

    cout<< "Enter your address\n";
    cin >> address;
    //cin.getline(address, 200);

    cout<< "Create password\n";
    cout<<"enter your password\n";
    cin >>password;

    long initial_ammount;
    initial_ammount = add_initial_ammount_to_account(type);
    if(initial_ammount!=0){
        //make an node and add to linklist of  name customer_list
        customer* temp = new customer;
        // while(temp){
        //     temp = temp->next;
        // }

        temp->first_name = first_name;
        
        temp->last_name = last_name;
        temp->middle_name = middle_name;
        temp->mobile_number = mobile_number;
        
        temp->customer_id = customer_id;
     cout<<customer_id<<endl;
        temp->email_id = email_id;
        temp->password = password;
       // temp->customer_accounts = new account;

        account* user_account = new account;
        user_account->account_number = AN;
        user_account->account_type = type;
        user_account->atm_transaction=0;
        user_account->total_ammount = initial_ammount;
        user_account->last_transaction = new transaction;
        user_account->total_transaction = 0;

        user_account->last_transaction->ammount = initial_ammount;
        user_account->last_transaction->comment = "Initial_money_added";
        user_account->last_transaction->next = NULL;
        user_account->last_transaction->prev = NULL;

        temp->customer_accounts[AN++] = *user_account;
      //  (temp->customer_accounts).push_back(*user_account);

            
        mp[customer_id] = temp;

        cout <<"Your savings account created successfully\n";
      //  cout<<mp[customer_id]->first_name<<endl;
       // cout<<mp[customer_id]->mobile_number<<endl;
    }

    
    return;

}

long LA(){
    cout<<"Enter how much loan you want or type -1 to exit\n";
    long loan_ammount;
    cin >>loan_ammount;
    if(loan_ammount >= 500000){
        return loan_ammount;
    }
    if(loan_ammount == -1){
        return -1;
    }
    else {
        cout<<"Minimun loan ammount is 5000000\n";
        return LA();
    }
}


void add_new_account(long customer_id, int type){
   // account *temp = mp[customer_id]->customer_accounts;

   // account *new_account = new account;

   // while( != NULL) temp = temp->next;
   long initial_ammount;
    if(type>2){
        initial_ammount = LA();
        if(initial_ammount == -1) return;
    }
    else{
        initial_ammount = add_initial_ammount_to_account(type);
    }
    //new_account.
    cout<<"Initial ammount is: "<<initial_ammount<<endl;

    account* user_account = new account;
    user_account->account_number = AN;
    user_account->account_type = type;
    user_account->atm_transaction=0;
    user_account->total_ammount = initial_ammount;
    user_account->last_transaction = new transaction;
    user_account->total_transaction = 0;

    user_account->last_transaction->ammount = initial_ammount;
    user_account->last_transaction->comment = "Initial_money_added";
    user_account->last_transaction->next = NULL;
    user_account->last_transaction->prev = NULL;

cout<<"Account created successfully\n";

    mp[customer_id]->customer_accounts[AN++] = *user_account;
    //  (temp->customer_accounts).push_back(*user_account);

    cout <<"Your savings account created successfully\n";
   //loan->customer_accounts[AN] = *loan_account;
    //(mp[customer_id]->customer_accounts).push_back(*loan_account);
}

void make_transaction_with_selected_account(long customer_id, long account_number){
    cout<<"type Customer id of user jisko tum bhejna cahete ho\n";
    long receiver_customer_id, receiver_account_number;
    cin>>receiver_customer_id;
    cout<<"Type account number of receiver:\n";
    cin>>receiver_account_number;

    if(mp.find(receiver_customer_id) == mp.end() && mp[receiver_customer_id]->customer_accounts.find(receiver_account_number) == mp[receiver_customer_id]->customer_accounts.end()){
        cout<< "This customer id and user not found\n";
        return;
    }

    cout<<"Enter ammount you want to send\n";
    long ammount;
    cin>>ammount;

    customer* this_customer = mp[customer_id];
    account this_account = this_customer->customer_accounts[account_number];

    if(this_account.total_ammount < ammount){
        cout<< "You not have this much ammount in your bank \n";
        return;
    }
 
    cout<<"I am at step 1\n";

    customer *receiver_customer = mp[receiver_customer_id];
    account receiver_account = receiver_customer->customer_accounts[receiver_account_number];

    cout<<"I am at step 2\n";
    
    transaction *sender_transaction = new transaction;
    transaction *receiver_transaction = new transaction;

    cout<<"I am at step 3\n";

    string sender_name = this_customer->first_name + " "+ this_customer->middle_name+ " " + this_customer->last_name;
    string receiver_name = receiver_customer->first_name + " " + receiver_customer->middle_name+ " "+ receiver_customer->last_name;
    string _ammount = to_string(ammount);
    string sender_comment = "send " + _ammount + " to " + receiver_name;
    string receiver_comment = "receive "+ _ammount + "from " + sender_name;

cout<<"I am at step 4\n";

    sender_transaction->ammount = ammount;
    sender_transaction->comment = sender_comment;
    sender_transaction->prev = mp[customer_id]->customer_accounts[account_number].last_transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction->next = sender_transaction;
   // this_account.last_transaction = sender_transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction = this_account.last_transaction->next;
    mp[customer_id]->customer_accounts[account_number].total_ammount -= ammount;
    mp[customer_id]->customer_accounts[account_number].total_transaction = this_account.total_transaction +1;
    
    cout<<"I am at step 5\n";

   // sender_transaction = sender_transaction->prev;
   // cout<<sender_transaction->ammount << "   "<< sender_transaction->comment<<endl;
   // cout<<receiver_transaction->ammount<<"  "<<receiver_transaction->comment<<endl;


    receiver_transaction->ammount = ammount;
    receiver_transaction->comment = receiver_comment;
    receiver_transaction->prev = mp[receiver_customer_id]->customer_accounts[receiver_account_number].last_transaction;
    mp[receiver_customer_id]->customer_accounts[receiver_account_number].last_transaction->next = receiver_transaction;
    mp[receiver_customer_id]->customer_accounts[receiver_account_number].last_transaction= receiver_account.last_transaction->next;
   // receiver_account.last_transaction = receiver_transaction;
    mp[receiver_customer_id]->customer_accounts[receiver_account_number].total_ammount += ammount;

    cout<<"----------------------------------------\n";
    cout<<"Transaction complete \n";
    cout<<"----------------------------------------\n";
    
}

void Make_an_transaction(long customer_id){
    cout<<"Choice By which account you want to make transaction\n";
    

    customer *this_customer = mp[customer_id];
    map<long, account> user_accounts = this_customer->customer_accounts;
    
    vector<long> user_account_numbers; 

  //  cout<<"Select One Option\n";
    int i=1;
    for(auto x: user_accounts){
        cout<<i++<<". Account Number: "<<x.first<<"      Account type: "<<account_type[x.second.account_type -1]<<endl;
        user_account_numbers.push_back(x.first);
    }

    cout<<"Select one Account or type 0 to logout\n";
    int responce;
    cin>>responce;
    if(responce ==0 )return;
    else if(responce<=user_account_numbers.size()){
        make_transaction_with_selected_account(customer_id, user_account_numbers[responce -1]);
        
    }
    else {
        cout<<"Select Key is Wrong";
        Make_an_transaction(customer_id);
    }

}

void open_new_account(){
    cout<< "Which account you want to open\n";
    cout << "1. Saving Account\n";
    cout << "2. Current Account\n";
    cout << "3. Loan Account\n";
    cout << "4. exit\n";
    int type;
    cin >>type;
   // int k=0;
   if(type == 1 || type ==2 ){
        make_new_account(type);
    }
    else if(type ==3){
        cout<<"For opening Loan account, first open savings or current account in this bank";
        return;
    }
    else if(type==4){
        return;
    }
    else {
        cout<<"please choice correct key\n";
        open_new_account();
    }
}

void open_loan_account(long customer_id){
    cout<< "Select which loan you want\n";
    cout<<"1. Home loan\n";
    cout<<"2. Car loan\n";
    cout<<"3. Personal Loan\n";
    cout<<"4. Business Loan\n";
    cout<<"5. Exit\n";
        
    int type;
    cin>>type;
    if(type==1 || type ==2 || type==3 ||type==4)add_new_account(customer_id, type+2);
    if(type ==5 )return;
    else{
        cout<<"Please select right key\n";
        open_loan_account(customer_id);
    }

}


void open_account_of_existing_customer(){
    long customer_id;
    string password;
    cout << "Enter your Customer ID\n";
    cin >> customer_id;
    cout<< "Enter your password\n";
    cin >> password;

    if(mp.find(customer_id) == mp.end() && mp[customer_id]->password != password){
        cout<< "Authentication Failed!!!  customer id and password are not correct\n";
        return;
    }
    cout<< "Which account you want to open\n";
    cout << "1. Saving Account\n";
    cout << "2. Current Account\n";
    cout << "3. Loan Account\n";
    cout << "4. exit\n";

    int responce;
    cin>>responce;

    if(responce==1 || responce==2){
        add_new_account(customer_id, responce);
    }
    else if(responce ==3){
        open_loan_account(customer_id);  
    }
    else if(responce ==4 ){
        return;
    }
    else{
        cout<<"Please type correect key\n";
    }



}


void open_account(){
    cout << " Do you already have an account in this bank? \n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "3. exit\n";
    int n;
    cin >> n;

    if(n ==1){
       open_account_of_existing_customer();
    }
    else if (n==2){
        open_new_account();
    }
    else if(n==3){
        return;
    }
    else {
        cout << "Please Type 1 for Yes, 2 for No and 3 for exit";
        open_account();
    }

}

void print_transaction_history(account this_account){
    cout<<"How many transaction you want to see\n";
    int number_of_transaction;
    cin >>number_of_transaction;
    transaction *temp = this_account.last_transaction;
    if(temp){
        while(temp && number_of_transaction--){
            cout<<"Ammount: "<<temp->ammount<<"       Comment: "<<temp->comment<<endl;
            temp =temp->prev;
        }
    }
    else cout<<"No_transaction found\n";
}

void print_user_info(long customer_id){
    cout<<"\n\n\n";
    cout<<"-----------------------------------------------\n";
    customer *this_customer = mp[customer_id];
    cout<<"Name: " <<this_customer->first_name+ " " + this_customer->middle_name+ " "+ this_customer->last_name << endl;
    cout<<"Customer id: "<< this_customer->customer_id <<endl;
    cout<<"Mobile Number: "<<this_customer->mobile_number<<endl;
    cout<<"Email: "<<this_customer->email_id<<endl;

}
long give_account_option(long customer_id){
    customer *this_customer = mp[customer_id];
    map<long, account> user_accounts = this_customer->customer_accounts;
    
    vector<long> user_account_numbers; 

    cout<<"Select One Option\n";
    int i=1;
    for(auto x: user_accounts){
        cout<<i++<<". Account Number: "<<x.first<<"      Account type: "<<account_type[x.second.account_type -1]<<endl;
        user_account_numbers.push_back(x.first);
    }

    cout<<"Select one Account or type 0 to logout\n";
    int responce;
    cin>>responce;
    if(responce ==0 )return 0;
    else if(responce<=user_account_numbers.size()) return user_account_numbers[responce -1];
    else return -1;

}

void Account_Details(long customer_id, long account_number){
    print_user_info(customer_id);

    
    customer *this_customer = mp[customer_id];
    account this_account = (this_customer)->customer_accounts[account_number];
    cout<<"Account balance: "<<this_account.total_ammount<<endl;
    cout<<"Account Number: "<<this_account.account_number<<"       Account Type: "<<account_type[this_account.account_type-1]<<endl;
    cout<<"This Month atm transaction: "<<this_account.atm_transaction<<"          total tranaction: "<<this_account.total_transaction<<endl;

    cout<<"select one option\n";
    cout<<"1. view transaction History\n";
    cout<<"2. back\n";
    int responce;
    cin>>responce;
    if(responce==1){
        print_transaction_history(this_account);
        Account_Details(customer_id, account_number);
    }
    else if(responce==2){
      return;
    }    
}

void Customer_Details(long customer_id){
    print_user_info(customer_id);
    long account_number = give_account_option(customer_id);
    if(account_number ==0) return;
    else if(account_number == -1){
        cout<<"Select Key is Wrong";
        Customer_Details(customer_id);
    }
    else{
        Account_Details(customer_id, account_number);
        Customer_Details(customer_id);
    }
}

void withdrow_money_using_atm(long customer_id){
    print_user_info(customer_id);
    long account_number = give_account_option(customer_id);

    long ammount;
    cout<<"Enter ammount that you want to withdrow\n";
    cin>>ammount;

    if(mp[customer_id]->customer_accounts[account_number].total_ammount < ammount) cout<<"You not have sufficient balance\n";

    mp[customer_id]->customer_accounts[account_number].total_ammount -= ammount;
    mp[customer_id]->customer_accounts[account_number].total_transaction +=1;
    mp[customer_id]->customer_accounts[account_number].atm_transaction +=1;
    
    transaction* new_atm_transaction = new transaction;
    new_atm_transaction->ammount = ammount;
    new_atm_transaction->comment = "Withdrow using ATM";
    new_atm_transaction->prev = mp[customer_id]->customer_accounts[account_number].last_transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction->next = new_atm_transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction = mp[customer_id]->customer_accounts[account_number].last_transaction->next;

    cout<<"-----------------------------\n";
    cout<<"ATM transaction successfull\n";  


    transaction* temp = mp[customer_id]->customer_accounts[account_number].last_transaction;
    while(temp){
        cout<<"1. "<<temp->ammount <<" "<<temp->comment<<endl;
        temp=temp->prev;
    }

   // account this_account = this_customer->customer_accounts[account_number];

}
void deposit_money_in_bank_account(long customer_id){
    print_user_info(customer_id);
    long account_number = give_account_option(customer_id);

   // customer *this_customer = mp[customer_id];
   // account this_account = (this_customer)->customer_accounts[account_number];

    long ammount;
    cout<<"Enter ammount that you want to deposit\n";
    cin>>ammount;

    mp[customer_id]->customer_accounts[account_number].total_ammount += ammount;
    mp[customer_id]->customer_accounts[account_number].total_transaction +=1;
    
    transaction* new__transaction = new transaction;
    new__transaction->ammount = ammount;
    new__transaction->comment = "Deposit money in bank account";
    new__transaction->prev = mp[customer_id]->customer_accounts[account_number].last_transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction->next = new__transaction;
    mp[customer_id]->customer_accounts[account_number].last_transaction = mp[customer_id]->customer_accounts[account_number].last_transaction->next;

    cout<<"-----------------------------\n";
    cout<<"You deposit money successfully\n";

}

void select_transaction_type(long customer_id){
    cout<<"Select transction type:\n";
    cout<<"1. to other user\n";
    cout<<"2. withdrow money using atm\n";
    cout<<"3. deposit money in bank account\n";
    cout<<"4. back\n";
    int responce;
    cin>>responce;

    if(responce==1) Make_an_transaction(customer_id);
    else if(responce==2) withdrow_money_using_atm(customer_id);
    else if(responce==3) deposit_money_in_bank_account(customer_id);
    else if(responce==4) return;
    else{
        cout<<"type correct key"<<endl;
        select_transaction_type(customer_id);
    }


}


void logined(long customer_id){
    cout<< "Select_an_option\n";

    cout<<"1. Customer Details\n";
    cout<<"2. Make an Transaction\n";
    cout<<"3. logout\n";

    int n;
    cin>>n;
    if(n==1){
        Customer_Details(customer_id);
    }
    else if(n==2){
        select_transaction_type(customer_id);
        logined(customer_id);
    }
    else if(n==3){
        //services_();
    }
    else{
        cout<<"Select Correct Key\n";
        logined(customer_id);
    }

}

void services_(){
    cout << "Welcome to bank \n";
    cout<<"Select One Option \n";
    print_services();

    int service;
    cin >> service;

    if(service == 1){
        open_account();
        services_();
    }
    else if(service == 2){
        cout<<"Enter Your Customer ID\n";
        long customer_id;
        cin >> customer_id;

        cout<<"Enter your password\n";
        string password;
        cin >> password;

        if(mp.find(customer_id) == mp.end() || mp[customer_id]->password != password){
            cout<< "Authentication Failed!!!  customer id and password are not correct\n";
            services_();
        }

        cout << "Login Successfully\nSelect One Option\n";
        logined(customer_id);

        
        
    }
    else if (service == 3){
        cout<<"Thank you \n";
        return ;
    }
    else{
        cout << "Please Type correct key \n";
        services_();
    }
    
   services_();
}



void print_customer(){
    cout<<"entered in print function";
    for(auto cu : mp){
        cout << (cu.second)->first_name<<" ";
    }
    
}

void Bank_employ_view(){
    cout<<"What you want to see\n";
    cout<<"1. print all customer\n";
    cout<<"2. exit";
    
    print_customer();
}

void who_are_you(){
    cout<<"Who are you\n";
    cout<<"1. Customer\n";
    cout<<"2. Bank Employ\n";

    int user;
    cin>>user;

    if(user==2){
        cout<<"enter password: \n";
        string p;
        cin>>p;
        if(p==PASS){
            Bank_employ_view();
        }
        else {
            cout<<"password is wrong\n";
        }
    }
    else if(user==1){
        services_();
    }
    else if(user==3) return;
    else cout<<"Select Correct Key";
    who_are_you();
}
int main(){
    PASS = "admin";
    char_value.clear();
    set_char_value();
    AN=5433789245;
    mp.clear();
    account_type.clear();
   // account_type = {"Saving Account", "Current Account", "Home Loan", "Car loan", "Personal loan", "Business Loan"};
    account_type.push_back("Saving Account");
    account_type.push_back("Current Account");
    account_type.push_back("Home Loan");
    account_type.push_back("Car Loan");
    account_type.push_back("Personal Loan");
    account_type.push_back("Business Loan");
    //interest_rate = {6.0 ,0.0 ,7.0 ,8.0 ,12.0 ,15.0 };

    who_are_you();
    

    cout<<"Thank you \n";
    return 0;
}