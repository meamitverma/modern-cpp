#include<iostream>

// convention put 'i' as prefix for the interface
// interface
class iCurrencyConvertor {
    public:
    virtual std::string getCurrency() const = 0;
    
    // default constructor
    iCurrencyConvertor() = default; 
    // iCurrencyConvertor() = delete; // creation of default constructor is forbidden by the compiler 

    // virtual destructor
    virtual ~iCurrencyConvertor() = default; // enforcing the 'default' destructor to be used
};


// component: provider
class CurrencyAsString : public iCurrencyConvertor {
    
    private:
    std::string cur;

    public:
    CurrencyAsString(const std::string tcur) {
        this->cur = tcur;
    }
    std::string getCurrency() const override {
        return cur;
    }

};

// component: receiver
class CurrencyFormatter {

    private:
    // implementing interface -> works like a object
    const iCurrencyConvertor *convertor;

    public:
    CurrencyFormatter ( const iCurrencyConvertor *convertor ): convertor( convertor ) {}


    // write in the another class
    // BUG!!!!!!!!!!!
    void const displayCurrency() {
        std::cout << "Formatted Currency" << std::endl;
        std::string cur = convertor->getCurrency();

        if ( cur == "Rs") {
            std::cout << "Rs = \u20b9" << std::endl;
        }
        else if ( cur == "$") {
            std::cout << "Dollar = $" << std::endl;
        }
        else if ( cur == "Yen") {
            std::cout << "Yen = \u00A5" << std::endl; 
        }
        else if ( cur == "Arab") {
            std::cout << "Yen = \u6041" << std::endl; 
        }
        else {
            std::cout << "Unknown currency..." << std::endl; 
        }
    }

};




int main(int argsc, const char *argv[]) {

    std::cout << "Currency Convertor" << std::endl;

    CurrencyAsString currencyAsString("Rs");
    CurrencyFormatter currencyFormatter(&currencyAsString); // aggregation -> compulsary to pass the interface7777777777777777777777777777777777777777777777777777777
    currencyFormatter.displayCurrency();

    return 0;
}