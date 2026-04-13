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
    void setBalance(double b)
    {
        balance = b;
    }

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
        if (d > 0)
            balance = balance + d;
    }
    virtual void withdraw(double t)
    {
        cout << "Account Type: Base Account Can't Make Withdraws.";
    }
    virtual string getAccountType()
    {
        return "Base Account";
    }
};

class Checking : public Account
{
public:
    void withdraw(double t) override
    {
        setBalance(getBalance() - t);
        if (getBalance() < 0)
        {
            cout << "Warning: Checking account is overdrawn." << endl;
        }
    }
    string getAccountType() override
    {
        return "Checking Account";
    }
};

class Savings : public Account
{
private:
    double goal = 0;

public:
    void withdraw(double t) override
    {
        if (getBalance() - t < 0)
        {
            cout << "Warning: Savings account Cannot Be Overdrawn." << endl;
        }
        else
        {
            setBalance(getBalance() - t);
        }
    }
    string getAccountType() override
    {
        return "Savings Account";
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
        if (goal > getBalance())
        {
            return "You have not reached your goal yet";
        }
        else
        {
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
    void withdraw(double t) override
    {
        if (getBalance() - t < 0)
        {
            cout << "Warning: Business account Cannot Be Overdrawn." << endl;
        }
        else
        {
            setBalance(getBalance() - t);
        }
    }
    string getAccountType() override
    {
        return "Business Account";
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
    a.withdraw(10000);
    cout << "Balance: $" << a.getBalance() << endl;
    cout << "Account Number: " << a.getAccountNumber() << endl;
    cout << "Name: " << a.getName() << endl;
    cout << "ID: " << a.getId() << endl;
    cout << "Account Type: " << a.getAccountType() << endl;
    cout << "\n";

    Business b;
    b.setName("Hunter Thomas");
    b.deposit(30);
    b.setId("jgjdhdj12mkcvk");
    b.setBusinessTaxId("jgjdhdj12mkcvk");
    b.setBusinessName("H&T Development");
    b.withdraw(100);
    cout << "Balance: $" << b.getBalance() << endl;
    cout << "Account Number: " << b.getAccountNumber() << endl;
    cout << "Name: " << b.getName() << endl;
    cout << "ID: " << b.getId() << endl;
    cout << "Account Type: " << b.getAccountType() << endl;
    cout << "Business Name: " << b.getBusinessName() << endl;
    cout << "Business Tax ID: " << b.getBusinessTaxId() << endl;
    cout << "\n";

    Savings c;
    c.setName("Hunter Thomas");
    c.setGoal(100000);
    c.deposit(1000);
    c.setId("jgjdhdj12mkcvk");
    c.withdraw(100);
    cout << "Balance: $" << c.getBalance() << endl;
    cout << "Account Number: " << c.getAccountNumber() << endl;
    cout << "Name: " << c.getName() << endl;
    cout << "ID: " << c.getId() << endl;
    cout << "Account Type: " << c.getAccountType() << endl;
    cout << c.goalProgress() << " for your savings account." << endl;

    return 0;
}
