// Joseph Valdez
// 4/30/2026
//  This is an updated version of the program that takes daily quiz scores and displays the highest and lowest scores. 
// This program now contains a menu that allows the user to choose whether to look at the data currently saved, add new student names,
// search for students by name and save new data added by the user.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Class {
string name;
int score;
};

void displayData(const Class students[], int count);
int addEntry(Class students[], int count, int maxSize);
void searchEntry(const Class students[], int count);
void saveData(const Class students[], int count, string filename);
int loadData(Class students[], int maxSize, string filename);
void processScores(const Class students[], int count);

int main() {

  const int MAX_SIZE = 100;
  Class students[MAX_SIZE];
  string filename = "input.txt";
  int currentCount = loadData(students, MAX_SIZE, filename);
  int choice;

  do {
      cout << "\n --- Daily Quiz Menu --- \n";
      cout << "1. View Data\n2. Add Entry\n3. Search Entry\n4. Save Data\n5. Exit\n";
      cout << "Enter Choice: ";
      cin >> choice;

      switch (choice) {
        case 1:
              displayData(students, currentCount);
              processScores(students, currentCount);
              break;
        case 2:
              currentCount = addEntry(students, currentCount, MAX_SIZE);
              break;
        case 3:
              searchEntry(students, currentCount);
              break;
        case 4:
              saveData(students, currentCount, filename);
              break;
        case 5:
              cout << "Exit Program... Goodbye \n";
              break;
      default:
          cout << "Invalid selection. Please try again. \n";
    }
  } while (choice != 5);

  return 0;
}

void displayData(const Class students [], int count) {
  if (count == 0) {
    cout << "No data available.\n";
    return;
  }
  cout << left << setw(20) << "Name" << "Score" << endl;
    for (int i = 0; i < count; i++) {
          cout << left << setw(20) << students[i].name << students[i].score << endl;
    }
}

int addEntry(Class students[], int count, int maxSize) {





