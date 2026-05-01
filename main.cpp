// Joseph Valdez
// 4/30/2026
//  This is an updated version of the first program that takes daily quiz scores and displays the highest and lowest scores. 
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
  string filename = "output.txt";
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
              cout << "Exiting... See you tomorrow! \n";
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
  if (count >= maxSize) {
    cout << "Error: List Full.\n";
    return count;
  }
  cout << "Enter student name: ";
  cin.ignore();
  getline(cin, students[count].name);
  cout << "Enter quiz score: ";
  cin >> students[count].score;
  return count + 1;
}

void searchEntry(const Class students[], int count) {
  string searchName;
  cout << "Please enter a name: ";
  cin.ignore();
  getline(cin, searchName);
  for (int i = 0; i < count; i++) {
      if (students[i].name == searchName) {
        cout << "Name Found" << students[i].name << " - Score: " << students[i].score << endl;
        return;
      }
  } 
  cout << "No record of student.\n";
}

void saveData(const Class students[], int count, string filename) {
  ofstream outFile(filename);
  if (outFile.is_open()) {
      for (int i = 0; i < count; i++) {
          outFile << students[i].name << "\n" << students[i].score << "\n";
      }
      outFile.close();
      cout << "Data Saved to " << filename << endl;
  } else {
    cout << "Error: Cannot open file to save.\n";
  }
}

int loadData(Class students[], int maxSize, string filename) {
  ifstream inFile(filename);
  int count = 0;
  if (inFile.is_open()) {
      while (count < maxSize && getline(inFile, students[count].name)) {
            inFile >> students[count].score;
            inFile.ignore();
            count++;
      }
      inFile.close();
  }
  return count;
}

void processScores(const Class students[], int count) {
  if (count == 0) return;
  int maxIdx = 0, minIdx = 0;
  for (int i = 0; i < count; i++) {
      if (students[i].score > students[maxIdx].score) 
        maxIdx = i;
      if (students[i].score < students[minIdx].score)
        minIdx = i;
  }
  cout << "\n--- Daily Quiz Stats ---\n";
  cout << "Todays Highest Quiz Score is: " << students[maxIdx].score << " (" << students[maxIdx].name << ")\n";
  cout << "Todays Lowest Quiz Score is: " << students[minIdx].score << " (" << students[minIdx].name << ")\n";
}





