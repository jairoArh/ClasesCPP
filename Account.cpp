//
// Created by Jairo Riaño on 12/04/20.
//

#include <iostream>
#include <sstream>
#include "Account.h"

const double Account::minResidue = 50000;

Account::Account(const string &number, double residue) : number(number), residue(residue) {
    setNumber( number );
    setResidue( residue );
    withDrawals = 0;
    consignments = 0;
}

void Account::setNumber(const string &number) {
    Account::number = number;
}

void Account::setResidue(double value) {
    residue = value;
}

const string &Account::getNumber() const {
    return number;
}

double Account::getResidue() const {
    return residue;
}

short Account::getConsignments() const {
    return consignments;
}

short Account::getWithDrawals() const {
    return withDrawals;
}

bool Account::withDraw(double value) {
    if( value <= residue - minResidue ){
        setResidue( getResidue() - value );
        withDrawals++;

        return true;
    }

    return false;
}

void Account::consign(double value) {
    setResidue( getResidue() + value );
    consignments++;
}

bool Account::transfer(Account *account, double value) {
    if( account->withDraw( value ) ){
        consign( value );

        return true;
    }

    return false;
}

string Account::parseString(double value) {
    std::ostringstream aux;
    aux << value;

    return aux.str();
}

string Account::toString() {
    return "Account[number=" + number + ", Saldo=" + parseString(residue) + ", Consignaciones=" +
    parseString( consignments) + ", Retiros=" + parseString( withDrawals ) + "]";
}

Account::~Account() {
    std::cout<<"Good Bye!!! "<<number<<endl;
}
