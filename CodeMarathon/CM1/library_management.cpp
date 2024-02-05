#include<iostream>
#include<vector>
#include<algorithm>

class Library {
    private:
    std::vector<Book*> books;

    public:
    virtual void borrow() = 0;
    virtual void returnBook() = 0;
    virtual void addBook() = 0;

};

class Book {
    private:
    std::string name;
    std::string author;
    std::string isbn;
    bool isAvailable;

    public:
    Book(std::string _name, std::string _isbn) {
        name =_name;
        isbn = _isbn;
        isAvailable = true;
    }
    void displayDetails() {
        std::cout << "Book name: " << this->name << std::endl;
        std::cout << "Book name: " << this->name << std::endl;
        std::cout << "Book name: " << this->name << std::endl;
        
    }

    std::string getBookName() {
        return this->name;
    }

    void setAvailble() {
        isAvailable = !isAvailable;
    }
};

class Member : public Library {
    // public:
    // void borrow(std::string name) {
    //     auto itr = std::find(books.begin(), books.end(), )
    // }
};

int main() {

    return 0;
}