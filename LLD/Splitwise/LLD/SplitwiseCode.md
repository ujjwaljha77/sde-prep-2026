#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class User {
public:
    int userId;
    string name;

    User(int id, string name) {
        this->userId = id;
        this->name = name;
    }
};

class Expense {
public:
    int expenseId;
    double amount;
    User* paidBy;
    vector<User*> participants;

    Expense(int id, double amount, User* paidBy,
            vector<User*> participants) {
        this->expenseId = id;
        this->amount = amount;
        this->paidBy = paidBy;
        this->participants = participants;
    }
};

class Group {
public:
    int groupId;
    string groupName;
    vector<User*> users;
    vector<Expense*> expenses;

    Group(int id, string name) {
        groupId = id;
        groupName = name;
    }

    void addUser(User* user) {
        users.push_back(user);
    }

    void addExpense(Expense* expense) {
        expenses.push_back(expense);
    }
};

class Splitwise {
public:
    unordered_map<string,
    unordered_map<string,double>> balanceSheet;

    void addExpense(User* paidBy,
                    vector<User*> participants,
                    double amount) {

        double share = amount / participants.size();

        for(auto user : participants) {

            if(user == paidBy)
                continue;

            balanceSheet[user->name][paidBy->name] += share;
        }
    }

    void showBalances() {

        for(auto &borrower : balanceSheet) {

            for(auto &lender : borrower.second) {

                cout << borrower.first
                     << " owes "
                     << lender.first
                     << " Rs "
                     << lender.second
                     << endl;
            }
        }
    }
};

int main() {

    User* u1 = new User(1, "A");
    User* u2 = new User(2, "B");
    User* u3 = new User(3, "C");

    Splitwise app;

    app.addExpense(
        u1,
        {u1,u2,u3},
        900
    );

    app.showBalances();

    return 0;
}