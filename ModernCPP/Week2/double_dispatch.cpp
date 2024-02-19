#include<iostream>
#include<vector>
#include<variant>
// mondayat
 
class House;  //pre declaration
class StudentLoan;
 
//auditor
class Visitor{
    public:
    virtual double visit(House&)=0;
    virtual double visit(StudentLoan&)=0;
};
 
class Visitable{
    public:
    virtual double accept(Visitor&)=0;
};
 
class House : public Visitable{
    public:
    House(double v): value(v){}
    double getValue(){ return value; }
    double accept(Visitor& v) override{
        return v.visit(*this);
    }
 
    private:
    double value;
};
 
class StudentLoan: public Visitable{
    public:
    StudentLoan(double v): amount(v){}
    double getAmount(){ return amount; }
    double accept(Visitor& v) override{
        return v.visit(*this);
    }
 
    private:
    double amount;
};
 
//implementing the auditor class
class TaxVisitor: public Visitor{
    public:
    double visit(House& house) override{
        std::cout<<"Housing loan -----> ";
        return house.getValue() * 0.1;
    }
    double visit(StudentLoan& studentLoan) override{
        std::cout<<"student loan -----> ";
        return studentLoan.getAmount() * 0.05;
    }
};
 
int main(int argc, const char* argv[]){
    std::cout<<"Starting...";
    std::vector <Visitable*> visitable;
    visitable.emplace_back(new House(500));
    visitable.emplace_back(new StudentLoan(300));
 
    TaxVisitor taxvisitor;
    double totalTax =0.0;
    for(auto asset: visitable){
        totalTax+=asset->accept(taxvisitor);
    }
    std::cout<<"Total tax "<<totalTax<<std::endl;
 
    std::vector < std::variant <House,StudentLoan>> loans = {
        House(50000),
        StudentLoan(10000)
    };
    TaxVisitor taxvisitor2;
    double tax;
    for(auto& loan: loans){
        tax = std::visit( [&taxvisitor2 ] (auto&& s)
        {
            return s.accept(taxvisitor2);
        }, loan);
    }
    std::cout << "Total Tax: " << tax << std::endl;
 
    return 0;
};