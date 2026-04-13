#include <iostream>
#include <string>
#include <random>
using namespace std;

class Account
{
private:
    string name;
    string id;
    double balance;
    string account_number = "";

protected:
    int accounttype;

public:
    string generate_account_number()
    {
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
                       "wxyz0123456789";
        random_device rd;
        mt19937 generator(rd());

        uniform_int_distribution<> distribution(
            0, chars.size() - 1);
        string account_num;
        for (int i = 0; i < 10; ++i)
        {
            account_num += chars[distribution(generator)];
        }
        return account_num;
    }

    Account()
    {
        name = "";
        id = "";
        balance = 0;
        account_number = generate_account_number();
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setId(string i)
    {
        id = i;
    }

    string getId()
    {
        return id;
    }

    double getBalance()
    {
        return balance;
    }

    string getAccountNumber()
    {
        return account_number;
    }
    void deposit(double d)
    {
        balance = balance + d;
    }
    void makeTransaction(double t)
    {
        try
        {
            if (t < balance && accounttype == 1) // Checking Account
            {
                balance = balance - t;
            }
            else if (accounttype == 2) // Savings Account
            {
                balance = balance - t;
                
            }
            else if (accounttype == 3) // Business Account
            {
                balance = balance - t;
                
            }
            else if (accounttype == 0)
            {
                throw 1;
            }
            else
            {
                throw 3;
            }
            if (balance < 0){ // OverDraft Error For Saving And Business Account Types 
                throw 2;
            }
        }
        catch (int e)
        {
            if (e == 1)
                cout << "Please Set Account Type Before Making Transaction" << endl;
            if (e == 2)
                cout << "You Have an Over Draft" << endl;
            if (e == 3)
                cout << "Insufficient Funds" << endl;
        }
    }
    int getAccountType()
    {
        return accounttype;
    }
};

class Checking : public Account
{
public:
    Checking()
    {
        accounttype = 1;
    }
};

class Savings : public Account
{
    private:
    double goal;

public:
    Savings()
    {
        accounttype = 2;
    }
    void setGoal(double g)
    {
        goal = g;
    }
    double getGoal()
    {
        return goal;
    }
    string goalProgress()
    {
        if(goal > getBalance()){
            return "You have not reached your goal yet";

        }else{
            return "You have reached your goal";
        }
    }
    
};

class Business : public Account
{
    private:
    string business_tax_id;
    string business_name;

public:
    Business()
    {
        accounttype = 3;
    }
    void setBusinessName(string n)
    {
        business_name = n;
    }
    string getBusinessName()
    {
        return business_name;
    }
    void setBusinessTaxId(string t)
    {
        business_tax_id = t;
    }
    string getBusinessTaxId()
    {
        return business_tax_id;
    }
    
};

int main()
{
    Checking a;
    a.setName("Hunter Thomas");
    a.deposit(1000);
    a.setId("jgjdhdj12mkcvk");
    a.makeTransaction(100);
    cout << "Balance: $" << a.getBalance() << endl;
    cout << "Account Number: " << a.getAccountNumber() << endl;
    cout << "Name: " << a.getName() << endl;
    cout << "ID: " << a.getId() << endl;
    cout << "Account Type: " << a.getAccountType() << endl;
    cout <<  "\n";

    Business b;
    b.setName("Hunter Thomas");
    b.deposit(30);
    b.setId("jgjdhdj12mkcvk");
    b.setBusinessTaxId("jgjdhdj12mkcvk");
    b.setBusinessName("H&T Development");
    b.makeTransaction(100);
    cout << "Balance: $" << b.getBalance() << endl;
    cout << "Account Number: " << b.getAccountNumber() << endl;
    cout << "Name: " << b.getName() << endl;
    cout << "ID: " << b.getId() << endl;
    cout << "Account Type: " << b.getAccountType() << endl;
    cout << "Business Name: " << b.getBusinessName() << endl;
    cout << "Business Tax ID: " << b.getBusinessTaxId() << endl;
    cout <<  "\n";


    Savings c;
    c.setName("Hunter Thomas");
    c.setGoal(100000);
    c.deposit(1000);
    c.setId("jgjdhdj12mkcvk");
    c.makeTransaction(100);
    cout << "Balance: $" << c.getBalance() << endl;
    cout << "Account Number: " << c.getAccountNumber() << endl;
    cout << "Name: " << c.getName() << endl;
    cout << "ID: " << c.getId() << endl;
    cout << "Account Type: " << c.getAccountType() << endl;
    cout << c.goalProgress() << " for your savings account."<<endl;
    




    return 0;
}
