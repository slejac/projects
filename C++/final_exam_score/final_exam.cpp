#include <iostream>
using std::cout, std::endl, std::cin;

void MessagePrinter(const double &needed, const double &target) {
  cout << "You need to earn at least " << needed << " on your final";
  cout << " if you would like to score at least " << target << endl;
}

int main() {
  int repeat = 0;
  do {
    cout << "What is your current grade?" << endl;
    double current_grade;
    cin >> current_grade;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Invalid Input! Please enter your current grade." << endl;
      cin >> current_grade;
    }
    cout << "What would you like your final grade to be?" << endl;
    double target_grade;
    cin >> target_grade;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Invalid Input! Please enter your target grade." << endl;
      cin >> target_grade;
    }
    cout << "What percentage of your grade is your final worth?" << endl;
    double final_weight;
    cin >> final_weight;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Invalid Input! Please enter the percentage weight of your";
      cout << "final." << endl;
      cin >> final_weight;
    }
    double current_points = ((100 - final_weight) * current_grade)/100;
    double needed_grade = ((target_grade - current_points)/final_weight) * 100;
    if (needed_grade > 100) {
      cout << "Uh oh, that's impossible" << endl;
    } else if(needed_grade > 75) {
      cout << "Make sure to study on this one!" << endl;
    } else {
      cout << "You got this!" << endl;
    }
    MessagePrinter(needed_grade, target_grade);
    cout << "Would you like to repeat the calculations? ";
    cout << "Enter a number of than zero to continue." << endl;
    cin >> repeat;
  } while (repeat != 0);
}