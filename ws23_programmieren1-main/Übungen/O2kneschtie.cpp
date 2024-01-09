#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

enum presenttype
{
    sock,cat,dog,smartphone
};

class xmas_object
{
    private:
    string name;

    public:
    void do_something()
    {
    }
};

class present : public xmas_object
{
    public:
    presenttype type;
    present()
    {
        type = static_cast<presenttype>(rand() % 4);
    }
};

class xmas_tree : public xmas_object
{   
    public:
    vector<present> list_of_presents;

    void do_something()
    {
        cout << "Xmas tree: " << endl << endl;
        cout << "Presents currently stored: " << endl;

        for(const present &current_present:list_of_presents)
        {
            switch (current_present.type)
            {
            case sock:
                cout << "Sock " << endl;
                break;
            case cat:
                cout << "Cat " << endl;;
                break;
            case dog:
                cout << "Dog " << endl;;
                break;
            case smartphone:
                cout << "Smartphone " << endl;;
                break;
            default:
                cout << "Unknown " << endl;;
            }
        }
        cout << endl;
    }

    void add_present(present &newPresent) 
    {
        list_of_presents.push_back(newPresent);
    }

    present* take_present(size_t index)
    {
        if (index < list_of_presents.size())
        {
            present *taken_present = &list_of_presents[index];
            list_of_presents.erase(list_of_presents.begin() + index);
            return taken_present;
        }
        else
        {
            return nullptr;
        }
    }
};

class santaclaus : public xmas_object
{
    public:
    void do_something(xmas_tree &tree)
    {
        present newPresent;
        add_present_to_tree(tree, newPresent);
        cout << "Santa: " << endl << endl;
        cout << "Ho ho ho! I have come to bring a new present (";
        switch (newPresent.type)
            {
            case sock:
                cout << "Sock";
                break;
            case cat:
                cout << "Cat";
                break;
            case dog:
                cout << "Dog";
                break;
            case smartphone:
                cout << "Smartphone";
                break;
            default:
                cout << "Unknown";;
            }
        cout << ")" << endl<< endl;
    }

    void add_present_to_tree(xmas_tree &tree, present newPresent)
    {
        tree.add_present(newPresent);
    }
};

class child : public xmas_object
{
    private:
    static int total_children;
    vector<present> list_of_presents;
    int child_number;

    public:

    child(){
        if(total_children == nullptr){
            total_children = 0;
        }
        else{
            total_children++;
        }

        child_number = total_children;
        
    }

    present *takenpresent;

    void takepresent(xmas_tree &tree)
    {
        takenpresent = tree.take_present(0);
        if (takenpresent != nullptr)
        {
            // Add the present to the child's list or perform other actions
            list_of_presents.push_back(*takenpresent);
        }
    }
    
    void do_something(xmas_tree &tree)
    {
        cout << "I will try to get a another present!" << endl;
        cout << "Here are all the presents I have so far:" << endl;
        for(const present &current_present:list_of_presents)
        {
            switch (current_present.type)
            {
            case sock:
                cout << "Sock " << endl;
                break;
            case cat:
                cout << "Cat " << endl;;
                break;
            case dog:
                cout << "Dog " << endl;;
                break;
            case smartphone:
                cout << "Smartphone " << endl;;
                break;
            default:
                cout << "Unknown " << endl;;
            }
        }
        
        takepresent(tree);

        if (takenpresent != nullptr)
        {   
            cout << "The new present is ";
            switch (takenpresent->type)
                {
                case sock:
                    cout << "Sock " << endl;
                    break;
                case cat:
                    cout << "Cat " << endl;;
                    break;
                case dog:
                    cout << "Dog " << endl;;
                    break;
                case smartphone:
                    cout << "Smartphone " << endl;;
                    break;
                default:
                    cout << "Unknown " << endl;;
                }    
        }
        else
        {
            cout << "ERROR, NO PRESENT AVAILABLE!" << endl;
        }
        cout << endl;
    }

    int getchildnumber()
    {
        return child_number;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int numchild;

    xmas_tree tree;
    santaclaus santa;
    child bob;

    present p1;
    present p2;
    present p3;
    present p4;
    present p5;

    tree.list_of_presents = {p1,p2,p3,p4,p5};

    vector<child> children;

    cout << "Welcome to the Xmas Simulator!" << endl;
    cout << "How many children do you want to simulate?" << endl;
    scanf("%d",&numchild);
    cout << endl << endl;
    for (int i = 0; i < numchild; i++)
    {
        child newChild;
        children.push_back(newChild);
    }
    
    int j=0;
    while(j<8)
    {
        int chosenclass = rand() % 4;
        int randomindex = rand() % children.size();
        switch (chosenclass)
        {
        case 0:
            tree.do_something();
            break;
        case 1:
            cout << "Child #" << children[randomindex].getchildnumber() << ":" << endl;
            children[randomindex].do_something(tree);
            break;
        case 2:
            santa.do_something(tree);
            break;
        default:
            break;
        }
        j++;
    }
}
