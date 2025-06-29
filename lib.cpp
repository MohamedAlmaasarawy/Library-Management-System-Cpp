#include "lib.h"

// All methods specific to class Member
Member::Member(): name(""), age(0), email(""), phone("")
{
    cout << "____________________________________________________________" << endl;
    cout << "|                                                           |" << endl;
    cout << "|           WELCOME TO THE CULTURAL LIBRARY                 |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|  CHOOSE WHICH OPERATION YOU NEED                          |" << endl;
    cout << "|  1. ADD NEW MEMBERS                                       |" << endl;
    cout << "|  2. SEARCH FOR A MEMBER                                   |" << endl;
    cout << "|  3. DISPLAY ALL MEMBERS IN LIBRARY                        |" << endl;
    cout << "|  4. DELETE MEMBERS                                        |" << endl;
    cout << "|  5. DELETE ALL MEMBERS                                    |" << endl;
    cout << "|  6. DISPLAY ALL BOOKS IN LIBRARY                          |" << endl;
    cout << "|  7. SEARCH FOR A BOOK                                     |" << endl;
    cout << "|  8. EXIT                                                  |" << endl;
    cout << "|  ENTER NUMBER AMONG 1 TO 8                                |" << endl;
    cout << "____________________________________________________________" << endl;

    int choice;
    cin >> choice;
    cin.ignore();
    main_class mainObj;
    mainObj.mainfun(choice);
}

Member::Member(string n, int a, string e, string p): name(n), age(a), email(e), phone(p) {}

Member::~Member() {}

// Setters
void Member::setname(const string& n)
{
    name = n;
}
void Member::setage(int a)
{
    age = a;
}
void Member::setemail(const string& e)
{
    email = e;
}
void Member::setphone(const string& p)
{
    phone = p;
}

// Getters
string Member::getname() const
{
    return name;
}
int Member::getage() const
{
    return age;
}
string Member::getemail() const
{
    return email;
}
string Member::getphone() const
{
    return phone;
}

// Display
void Member::display() const
{
    cout << "The name: " << name << endl;
    cout << "The age: " << age << endl;
    cout << "The email: " << email << endl;
    cout << "The phone number: " << phone << endl;
}

// All methods specific to class mod
mod::mod() {}

mod::~mod() {}

void mod::addmember(const Member& info)
{
    members.push_back(info);
}

void mod::searchbyemail(const string& email) const
{
    auto it = find_if(members.begin(), members.end(), [email](const Member& em)
    {
        return em.getemail() == email;
    });
    if (it != members.end())
    {
        it->display();
    }
    else
    {
        cout << "The member does not exist" << endl;
    }
}

void mod::displaymem() const
{
    for (const auto& it : members)
    {
        it.display();
    }
}

void mod::orderingbyage()
{
    sort(members.begin(), members.end(), [](const Member& a, const Member& b)
    {
        return a.getage() < b.getage();
    });
}

void mod::deletmember(const string& email)
{
    auto it = remove_if(members.begin(), members.end(), [email](const Member& del)
    {
        return del.getemail() == email;
    });
    if (it != members.end())
    {
        members.erase(it, members.end());
    }
    else
    {
        cout << "Member not found" << endl;
    }
}

void mod::clearallmembers()
{
    members.clear();
}

// Methods for class books
books::books() : auther(""), name_of_book(""), genre(""), date_of_creation(0), price(""), num_of_purchers("") {}
books::books(string a,string nb, string g,int dc, string p, string np) : auther(a), name_of_book(nb), genre(g), date_of_creation(dc), price(p), num_of_purchers(np) {}
books::~books() {}

// Setters
void books::setauther(const string& a)
{
    auther = a;
}
void books::setname_of_book(const string& nb)
{
    name_of_book = nb;
}
void books::setgenre(const string& g)
{
    genre = g;
}
void books::setdate_of_creation(int dc)
{
    date_of_creation = dc;
}
void books::setprice(const string& p)
{
    price = p;
}
void books::setnum_of_purchers(const string& np)
{
    num_of_purchers = np;
}

// Getters
string books::getauther() const
{
    return auther;
}
string books::getname_of_book() const
{
    return name_of_book;
}
string books::getgenre() const
{
    return genre;
}
int books::getdate_of_creation() const
{
    return date_of_creation;
}
string books::getprice() const
{
    return price;
}
string books::getnum_of_purchers() const
{
    return num_of_purchers;
}

void books::displaybooksbygenre() const
{
    cout << "The author: " << auther << endl;
    cout << "The name of book: " << name_of_book << endl;
    cout << "The genre: " << genre << endl;
    cout << "The date of creation: " << date_of_creation << endl;
    cout << "The price: " << price << endl;
    cout << "The number of purchasers: " << num_of_purchers << endl;
}

// Methods for class fantasy
void fantasy::addfan(const books& book)
{
    fan.push_back(book);
}

void fantasy::delfan(const string& name_of_book)
{
    auto it = remove_if(fan.begin(), fan.end(), [name_of_book](const books& del)
    {
        return del.getname_of_book() == name_of_book;
    });
    if (it != fan.end())
    {
        fan.erase(it, fan.end());
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void fantasy::displayfan() const
{
    for (const auto& it : fan)
    {
        it.displaybooksbygenre();
    }
}

void fantasy::searchbynbfan(const string& name_of_book) const
{
    auto it = find_if(fan.begin(), fan.end(), [name_of_book](const books& bk)
    {
        return bk.getname_of_book() == name_of_book;
    });
    if (it != fan.end())
    {
        it->displaybooksbygenre();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

// Methods for class science_fiction
void science_fiction::addsf(const books& book)
{
    sf.push_back(book);
}

void science_fiction::delsf(const string& name_of_book)
{
    auto it = remove_if(sf.begin(), sf.end(), [name_of_book](const books& del)
    {
        return del.getname_of_book() == name_of_book;
    });
    if (it != sf.end())
    {
        sf.erase(it, sf.end());
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void science_fiction::displaysf() const
{
    for (const auto& it : sf)
    {
        it.displaybooksbygenre();
    }
}

void science_fiction::searchbynbsf(const string& name_of_book) const
{
    auto it = find_if(sf.begin(), sf.end(), [name_of_book](const books& bk)
    {
        return bk.getname_of_book() == name_of_book;
    });
    if (it != sf.end())
    {
        it->displaybooksbygenre();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

// Methods for class history
void history::addhis(const books& book)
{
    his.push_back(book);
}

void history::delhis(const string& name_of_book)
{
    auto it = remove_if(his.begin(), his.end(), [name_of_book](const books& del)
    {
        return del.getname_of_book() == name_of_book;
    });
    if (it != his.end())
    {
        his.erase(it, his.end());
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void history::displayhis() const
{
    for (const auto& it : his)
    {
        it.displaybooksbygenre();
    }
}

void history::searchbynbhis(const string& name_of_book) const
{
    auto it = find_if(his.begin(), his.end(), [name_of_book](const books& bk)
    {
        return bk.getname_of_book() == name_of_book;
    });
    if (it != his.end())
    {
        it->displaybooksbygenre();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

// Methods for class horror
void horror::addhor(const books& book)
{
    hor.push_back(book);
}

void horror::delhor(const string& name_of_book)
{
    auto it = remove_if(hor.begin(), hor.end(), [name_of_book](const books& del)
    {
        return del.getname_of_book() == name_of_book;
    });
    if (it != hor.end())
    {
        hor.erase(it, hor.end());
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void horror::displayhor() const
{
    for (const auto& it : hor)
    {
        it.displaybooksbygenre();
    }
}

void horror::searchbynbhor(const string& name_of_book) const
{
    auto it = find_if(hor.begin(), hor.end(), [name_of_book](const books& bk)
    {
        return bk.getname_of_book() == name_of_book;
    });
    if (it != hor.end())
    {
        it->displaybooksbygenre();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

// Methods for class romance
void romance::addrom(const books& book)
{
    rom.push_back(book);
}

void romance::delrom(const string& name_of_book)
{
    auto it = remove_if(rom.begin(), rom.end(), [name_of_book](const books& del)
    {
        return del.getname_of_book() == name_of_book;
    });
    if (it != rom.end())
    {
        rom.erase(it, rom.end());
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void romance::displayrom() const
{
    for (const auto& it : rom)
    {
        it.displaybooksbygenre();
    }
}

void romance::searchbynbrom(const string& name_of_book) const
{
    auto it = find_if(rom.begin(), rom.end(), [name_of_book](const books& bk)
    {
        return bk.getname_of_book() == name_of_book;
    });
    if (it != rom.end())
    {
        it->displaybooksbygenre();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

// Methods for class main_class
void main_class::mainfun(int choice)
{
    switch (choice)
    {
    case 1:
        mainaddmembers();
        break;
    case 2:
        mainsearchmembers();
        break;
    case 3:
        maindisplaymemberes();
        break;
    case 4:
        maindeletmembers();
        break;
    case 5:
        mainclearallmembers();
        break;
    case 6:
        maindisplayallbooks();
        break;
    case 7:
        mainsearchbooks();
        break;
    case 8:
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void main_class::mainaddmembers()
{
    // Implementation for adding members
    string name, email, phone;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter phone: ";
    cin >> phone;
    Member new_member(name, age, email, phone);
    mod library_mod;
    library_mod.addmember(new_member);
    cout << "Member added successfully!" << endl;
}

void main_class::mainsearchmembers()
{
    // Implementation for searching members
    string email;
    cout << "Enter email to search: ";
    cin >> email;
    mod library_mod;
    library_mod.searchbyemail(email);
}

void main_class::maindisplaymemberes()
{
    // Implementation for displaying members
    mod library_mod;
    library_mod.displaymem();
}


void main_class::maindeletmembers()
{
    // Implementation for deleting members
    string email;
    cout << "Enter email to delete: ";
    cin >> email;
    mod library_mod;
    library_mod.deletmember(email);
    cout << "Member deleted successfully!" << endl;
}

void main_class::mainclearallmembers()
{
    // Implementation for clearing all members
    mod library_mod;
    library_mod.clearallmembers();
    cout << "All members cleared successfully!" << endl;
}

void main_class::maindisplayallbooks()
{
    // Implementation for displaying all books
    fantasy fan;
    science_fiction sf;
    history his;
    horror hor;
    romance rom;
    fan.displayfan();
    sf.displaysf();
    his.displayhis();
    hor.displayhor();
    rom.displayrom();
}

void main_class::mainsearchbooks()
{
    // Implementation for searching books
    string name_of_book;
    cout << "Enter name of book to search: ";
    cin >> name_of_book;
    fantasy fan;
    science_fiction sf;
    history his;
    horror hor;
    romance rom;
    fan.searchbynbfan(name_of_book);
    sf.searchbynbsf(name_of_book);
    his.searchbynbhis(name_of_book);
    hor.searchbynbhor(name_of_book);
    rom.searchbynbrom(name_of_book);
}

void main_class::addbooks()
{
    // Implementation for adding books
    string auther, name_of_book, genre, price, num_of_purchers;
    int date_of_creation;
    cout << "Enter author: ";
    cin >> auther;
    cout << "Enter name of book: ";
    cin >> name_of_book;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter date of creation: ";
    cin >> date_of_creation;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter number of purchasers: ";
    cin >> num_of_purchers;
    books new_book(auther, name_of_book, genre, date_of_creation, price, num_of_purchers);
    if (genre == "fantasy")
    {
        fantasy fan;
        fan.addfan(new_book);
    }
    else if (genre == "science fiction")
    {
        science_fiction sf;
        sf.addsf(new_book);
    }
    else if (genre == "history")
    {
        history his;
        his.addhis(new_book);
    }
    else if (genre == "horror")
    {
        horror hor;
        hor.addhor(new_book);
    }
    else if (genre == "romance")
    {
        romance rom;
        rom.addrom(new_book);
    }
    cout << "Book added successfully!" << endl;
}
