#include<iostream>
#include<algorithm>
#include<vector>

class interfaceComponent {
    protected:
    std::string name;
    static int indent;
    
    public:
    virtual void ls() = 0;
    std::string getName() {
        return name;
    }

};

int interfaceComponent::indent = 0;

class Leaf : public interfaceComponent {
    public:
    Leaf(std::string n) {
        name = n;
    }

    void ls() {
        for (int i = 0; i < indent; i++) {
            std::cout << ' ';
        }
        std::cout << name << std::endl;
    }
};

class Composite : public interfaceComponent {
    protected:
    std::vector<interfaceComponent*> files;

    public:   
    Composite(std::string n) {
        name = n;
    }

    void ls() {
        for (int i = 0; i < indent; i++) {
            std::cout << ' ';
        }

        std:: cout << files.size() << "Composit found under ( " << name << " ) " <<  std::endl;
        std::cout << name << " : " << std::endl;
        indent += 5;


        for (int i = 0; i < files.size(); i++) {
            std::cout << "Getting the file name : " << std::endl;
            files[i]->ls();
        }

        indent -= 5;
    }

    void display() {
        std::cout << name << "All child : " << std::endl;
        for (int i = 0; i < files.size(); i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << ' ';
                std::cout << files[i]->getName() << std::endl;
            }
        }
    }
};

// concrete class -> communicate from main() to composite block
// cannot become anything 
class Menu : public Composite{
    public:
    Menu(std::string s) : Composite(s) {} 

    void Add(interfaceComponent *file) {
        files.emplace_back(file);
    }

    void AddComp(std::string s) {
        Add(new Composite(s));
    }

    void AddLeaf(std::string s) {
        Add(new Leaf(s));
    }

    Menu *GetHandle(std:: string s) {
        for (int i = 0; i < files.size(); i++) {
            if (files[i]->getName() == s) {
                // not a typical way for typecasting
                return (Menu*)files[i];
            }
        }

        std::cout << "Directory " << s << " not found in " << name << std::endl;
        // exit(1); // dont use
        return nullptr;
    }

    void remove(interfaceComponent *ic) {
        // std::vector< interfaceComponent*>::iterator it = files.begin();
        // points to the first element of the vector
        // for (int index = 0; index < files.size(); index++, it++) {
        //     if (s == files[index]->getName()) {
        //         files.erase(it);
        //     }
        // }

        auto it = std::find(files.begin(), files.end(), ic);
        if(it != files.end())
            files.erase(it);
    }
};


int main(int argv, char *argc[]) {

    std::cout << "Composing a menu\n" << std::endl;
    
    Menu m("Menu");
    m.AddComp("File");
    m.AddComp("Search");

    m.GetHandle("File")->AddLeaf("New");
    m.GetHandle("File")->AddLeaf("Open");
    m.GetHandle("File")->AddComp("Run");
    m.GetHandle("File")->GetHandle("Run")->AddLeaf("Compile");
    m.GetHandle("File")->GetHandle("Run")->AddLeaf("build");
    m.GetHandle("File")->remove(m.GetHandle("Open"));


    Composite *mgetHandle = m.GetHandle("File");
    mgetHandle->ls();

    return 0;
}