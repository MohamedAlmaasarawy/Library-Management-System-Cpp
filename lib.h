#ifndef LIB_H
#define LIB_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Member
{
private:
    string name;
    int age;
    string email;
    string phone;
public:
    // SETTER
    void setname(const string& n);
    void setage(int a);
    void setemail(const string& e);
    void setphone(const string& p);
    // GETTER
    string getname() const;
    int getage() const;
    string getemail() const;
    string getphone() const;
    void display() const;
    Member(string n, int a, string e, string p);
    Member();
    ~Member();
};

class mod
{
private:
    vector<Member> members;
public:
    void addmember(const Member& info);
    void searchbyemail(const string& email) const;
    void displaymem() const;
    void orderingbyage();
    void deletmember(const string& email);
    void clearallmembers();
    mod();
    ~mod();
};

class books
{
private:
    string auther;
    string name_of_book;
    string genre;
    int date_of_creation;
    string price;
    string num_of_purchers;
public:
    // SETTER
    void setauther(const string& a);
    void setname_of_book(const string& nb);
    void setgenre(const string& g);
    void setdate_of_creation(int dc);
    void setprice(const string& p);
    void setnum_of_purchers(const string& np);
    // GETTER
    string getauther() const;
    string getname_of_book() const;
    string getgenre() const;
    int getdate_of_creation() const;
    string getprice() const;
    string getnum_of_purchers() const;
    void displaybooksbygenre() const;
    books(string a, string nb, string g, int dc, string p, string np);
    books();
    ~books();
};

class fantasy
{
private:
    vector<books> fan;
public:
    void addfan(const books& book);
    void delfan(const string& name_of_book);
    void displayfan() const;
    void searchbynbfan(const string& name_of_book) const;
};

class science_fiction
{
private:
    vector<books> sf;
public:
    void addsf(const books& book);
    void delsf(const string& name_of_book);
    void displaysf() const;
    void searchbynbsf(const string& name_of_book) const;
};

class history
{
private:
    vector<books> his;
public:
    void addhis(const books& book);
    void delhis(const string& name_of_book);
    void displayhis() const;
    void searchbynbhis(const string& name_of_book) const;
};

class horror
{
private:
    vector<books> hor;
public:
    void addhor(const books& book);
    void delhor(const string& name_of_book);
    void displayhor() const;
    void searchbynbhor(const string& name_of_book) const;
};

class romance
{
private:
    vector<books> rom;
public:
    void addrom(const books& book);
    void delrom(const string& name_of_book);
    void displayrom() const;
    void searchbynbrom(const string& name_of_book) const;
};

class main_class
{
public:
    // Controlled system functions
    void mainfun(int choice);
    void mainaddmembers(); // 1
    void mainsearchmembers(); // 2
    void maindisplaymemberes(); // 3
    void maingetcountofmembers(); // 4
    void maindeletmembers(); // 5
    void mainclearallmembers(); // 6
    void maindisplayallbooks(); // 7
    void mainsearchbooks(); // 8
    void addbooks();
};

#endif
