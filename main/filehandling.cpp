#include <fstream>
#include <iostream>
#include <string>

using namespace std;
/* code */
struct Player {
    string nickname;
    int age;
    double scores[2];
};
struct Node {
    Player player;
    Node* next;
};

// prints in a new line
template <typename T>
void print(T Value) {
    std::cout << Value << std::endl;
}
// gets a number from the user
double getNum(std::string prompt = "") {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}

// gets a string from the user
std::string getStr(std::string prompt = "") {
    std::string s;
    std::cout << prompt;
    getline(std::cin, s);
    return s;
}
Node* head = nullptr;

void addRecord(const Player& player) {
    Node* newNode = new Node;
    newNode->player = player;
    newNode->next = head;
    head = newNode;
}
// lets the user view the records of the players including: nickname, age and scoreaaaaaas
void viewRecords() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Age: " << current->player.age << endl;
        cout << "Scores: ";
        for (int i = 0; i < 2; ++i) {
            cout << current->player.scores[i] << " ";
        }
        cout << endl;
        cout << "----------------------------------" << endl;
        current = current->next;
    }
}
// lets the user compute for the average score of the player
void computeAverage() {
    Node* current = head;
    while (current != nullptr) {
        double sum = 0.0;
        for (int i = 0; i < 2; ++i) {
            sum += current->player.scores[i];
        }
        double average = sum / 5.0;
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Average Score: " << average << endl;
        cout << "----------------------------------" << endl;
        current = current->next;
    }
}
// shows the max average score of each player
void showMaxAverage() {
    Node* current = head;
    double maxAverage = -1;  // Initialize to a non-valid value
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 2; ++i) {
            sum += current->player.scores[i];
        }
        double average = sum / 2.0;
        if (average > maxAverage) {
            maxAverage = average;
        }
        current = current->next;
    }
    // Now, iterate again to display players with the max average
    current = head;
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 2; ++i) {
            sum += current->player.scores[i];
        }
        double average = sum / 2.0;
        if (average == maxAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
    print("maxAverage: " + to_string(maxAverage));
}
// shows the minimum average sore of each player
void showMinAverage() {
    Node* current = head;
    double minAverage = 100;  // Initialize to a value higher than the possible average
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 2; ++i) {
            sum += current->player.scores[i];
        }
        double average = sum / 2.0;
        if (average < minAverage) {
            minAverage = average;
        }
        current = current->next;
    }
    // Now, iterate again to display players with the min average
    current = head;
    while (current != nullptr) {
        double sum = 0;
        for (int i = 0; i < 2; ++i) {
            sum += current->player.scores[i];
        }
        double average = sum / 2.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
    print("minAverage: " + to_string(minAverage));
}
// opens the file to be used for storing the data of the players' records
void openFile() {
    ofstream outFile("player_records.txt");
    Node* current = head;
    while (current != nullptr) {
        outFile << current->player.nickname << endl;
        outFile << current->player.age << endl;
        for (int i = 0; i < 2; ++i) {
            outFile << current->player.scores[i] << " ";
        }
        outFile << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Records saved to 'player_records.txt'." << endl;
}
// Function to indicate closing the file
void closeFile() {
    cout << "File closed." << endl;
}
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Press Enter to continue...' var");
#endif
}

// shows the menu and calls the appropriate function based on the user's choice
void showMenu() {
    while (true) {
        clearScreen();
        print("==========================================");
        print("                    Menu                  ");
        print("==========================================");
        print("1. Add record");
        print("2. View players records");
        print("3. Compute for the average");
        print("4. Show the player(s) who gets the max average");
        print("5. Show the player(s) who gets the min average");
        print("6. Open the file");
        print("7. Close the file");
        print("8. Exit");
        int choice = (int)getNum("Enter your choice: ");
        switch (choice) {
            case 1: {
                double temp[5];
                Player player;
                player.nickname = getStr("Enter nickname: ");
                player.age = (int)getNum("Enter age: ");
                while (true) {
                    print("Enter 5 scores: ");
                    for (int i = 0; i < 5; ++i)
                        player.scores[i] = getNum("Enter score " + to_string(i + 1) + ": ");
                    // gets the two highest scores
                    double max1 = 0, max2 = 0;
                    for (int i = 0; i < 5; ++i) {
                        if (player.scores[i] > max1) {
                            max2 = max1;
                            max1 = player.scores[i];
                        } else if (player.scores[i] > max2) {
                            max2 = player.scores[i];
                        }
                    }
                    player.scores[0] = max1;
                    player.scores[1] = max2;
                    break;
                }
                addRecord(player);
                print("Record added successfully!");

                break;
            }
            case 2: {
                viewRecords();
                break;
            }
            case 3: {
                computeAverage();
                break;
            }
            case 4: {
                showMaxAverage();
                break;
            }
            case 5: {
                showMinAverage();
                break;
            }
            case 6: {
                openFile();
                break;
            }
            case 7: {
                closeFile();
                break;
            }
            case 8: {
                print("Group Name: Hyouka");
                print("Members:");
                print("Maminta, John Angelo A.");
                print("Quemuel, Mary Arwen L.");
                print("Zulueta, Riel Joshua A.");
                exit(0);
            }
            default:
                print("Invalid input. Try again!");
                break;
        }
        pause();
    }
}

int main(int argc, char const* argv[]) {
    showMenu();

    return 0;
}