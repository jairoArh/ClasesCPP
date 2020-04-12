#include <iostream>
#include "Account.h"

using namespace std;

int main() {

    Account account("486-3454545",500000);
    Account* other = new Account("596-463545",780000);

    account.consign(500000);
    if( account.withDraw( 300000 ) ){
        cout<<"Retiro Hecho..."<<endl;
    }else{
        cout<<"No es Posible el Retiro..."<<endl;
    }

    if( account.withDraw( 151000 ) ){
        cout<<"Retiro Hecho..."<<endl;
    }else{
        cout<<"No es Posible el Retiro..."<<endl;
    }

    if( account.withDraw( 150000 ) ){
        cout<<"Retiro Hecho..."<<endl;
    }else{
        cout<<"No es Posible el Retiro..."<<endl;
    }

    if( account.transfer(other,80000)){
        cout<<"Transferencia Hecha"<<endl;
    }else{
        cout<<"Imposible la Transferencia"<<endl;
    }

    if( other->transfer(&account,30000)){
        cout<<"Transferencia Hecha"<<endl;
    }else{
        cout<<"Imposible la Transferencia"<<endl;
    }

    cout<<"CUENTA-->Saldo Min = "<<Account::minResidue<<" Saldo = "<<account.getResidue()<<endl;
    cout<<account.toString()<<endl;
    cout<<"OTRA CUENTA-->Saldo Min = "<<Account::minResidue<<" Saldo = "<<other->getResidue()<<endl;
    cout<<other->toString()<<endl;

    delete(other);

    return 0;
}
