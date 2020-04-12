//
// Created by Jairo Riaño on 12/04/20.
//

#ifndef UNTITLED_ACCOUNT_H
#define UNTITLED_ACCOUNT_H

#include <string>

using namespace std;

class Account {


public:

    const static double minResidue;

    Account(const string &number, double residue);

    void setNumber(const string &number);

    const string &getNumber() const;

    double getResidue() const;

    short getConsignments() const;

    short getWithDrawals() const;

    void consign(double);

    bool withDraw( double );

    bool transfer( Account*, double );

    string toString();

    virtual ~Account();

private:
    string number;
    double residue;
    short int consignments;
    short int withDrawals;

    string parseString(double);
    void setResidue( double value );
};


#endif //UNTITLED_ACCOUNT_H
