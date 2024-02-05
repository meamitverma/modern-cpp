#include <iostream>

// base class
class RBI_Bank
{
public:
    virtual void deposit(int amt) = 0;
    virtual void withdraw(int amt) = 0;

protected:
    int balance;
};

class CitiBank : public RBI_Bank
{
public:
    CitiBank(int inital_balance)
    {
        balance = inital_balance;
    }
    void deposit(int amt) override
    {
        balance += amt;
        std::cout << "Deposited amount to Citi Bank: Rs." << amt << std::endl;
        std::cout << "Available Balance: Rs." << balance << std::endl;
    }

    void withdraw(int amt) override
    {
        if (balance <= 0 || balance < amt)
        {
            std::cout << "Unable to withdraw!, Not enough balance." << std::endl;
            return;
        }

        balance -= amt;
        std::cout << "Withdrawed amount from Citi Bank: Rs." << amt << std::endl;
        std::cout << "Available Balance: Rs." << balance << std::endl;
    }

private:
    void illegal_Withdraw(int amt)
    {
        std::cout << "Illegal withdrawel of " << amt << std::endl;
    }
};

class HDFC_Bank : public RBI_Bank
{
public:
    HDFC_Bank(int inital_balance)
    {
        balance = inital_balance;
    }

    void deposit(int amt) override
    {
        balance += amt;
        std::cout << "Deposited amount to HDFC Bank: Rs." << amt << std::endl;
        std::cout << "Available Balance: Rs." << balance << std::endl;
    }

    void withdraw(int amt) override
    {
        if (balance <= 0 || balance < amt)
        {
            std::cout << "Unable to withdraw!, Not enough balance." << std::endl;
            return;
        }

        balance -= amt;
        std::cout << "Withdrawed amount from HDFC Bank: Rs." << amt << std::endl;
        std::cout << "Available Balance: Rs." << balance << std::endl;
    }
};

class User
{
private:
    RBI_Bank *bank;

public:
    User(RBI_Bank *_bank)
    {
        bank = _bank;
    }

    void deposit(int amt)
    {
        bank->deposit(amt);
    }
    void withdraw(int amt)
    {
        bank->withdraw(amt);
    }
};

int main()
{

    RBI_Bank *citi = new CitiBank(1000);
    RBI_Bank *hdfc = new HDFC_Bank(1300);

    User citi_user(citi);
    User hdfc_user(hdfc);


    citi_user.deposit(200);
    citi_user.withdraw(2000);
    hdfc_user.deposit(2400);
    hdfc_user.withdraw(234234);

    return 0;
}