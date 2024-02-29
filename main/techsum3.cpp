#include <fstream>
#include <iostream>

#define MAXITEMS 100
using namespace std;

struct item {
    int id;
    string name;
    int price;
};
struct node {
    item itemData;
    node *next;
};

// prints in a new line
template <typename T>
void print(T Value) {
    std::cout << Value << std::endl;
}
// Prints in the same line
template <typename U>
void printLn(U s) {
    std::cout << s;
};
// gets a number from the user
double getNum(std::string prompt = "") {
    std::string num;
    char *p;
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

void update(node *head, item old, item new_data) {
    node *current = head;
    while (current != NULL) {
        if (current->itemData.id == old.id) {
            current->itemData = new_data;
        }
        current = current->next;
    }
}

void printCart(node *head) {
    node *current = head;
    while (current != NULL) {
        cout << "Product Name: " << current->itemData.name << " Price: " << current->itemData.price << endl;
        current = current->next;
    }
    cout << endl;
}
void insert(node *head, item data) {
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new node;
    current = current->next;
    current->itemData = data;
    current->next = NULL;
}
void remove(node *head, item data) {
    node *current = head;
    while (current->next != NULL) {
        if (current->next->itemData.id == data.id) {
            node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }

        current = current->next;
    }
}
void clear(node *head) {
    node *current = head->next;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head->next = NULL;
}
void reverse(node *head) {
    node *current = head->next;
    node *prev = NULL;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
}
void sort(node *head) {
    node *current = head->next;
    node *index = NULL;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->itemData.price > index->itemData.price) {
                temp = current->itemData.price;
                current->itemData.price = index->itemData.price;
                index->itemData.price = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// this function is used to get the products from the store and insert it to the cart
void checkOut(item storeProducts[], node *head) {
    int total = 0;
    // Check if the cart is empty
    if (head == NULL || head->next == NULL) {
        cout << "The cart is empty." << endl;
        return;
    }

    // Get the total price of the items in the cart
    node *current = head->next;
    for (int i = 0; current != NULL; i++) {
        total += current->itemData.price;
        current = current->next;
    }

    // Clear the cart
    clear(head);

    // Show the total price
    cout << "The total price is: " << total << endl;

    // No need to explicitly1 return at the end of a void function
}
// this is just a sample initialization of the store products
void init(item storeProducts[]) {
    for (int i = 0; i < MAXITEMS; i++) {
        storeProducts[i].id = i;
        storeProducts[i].name = "Item " + to_string(i);
        storeProducts[i].price = rand() % 1000 + 1;
    }
}
// this function is used to get the products from the store and insert it to the cart
void getProducts(item storeProducts[], node *head, bool isInsert = true) {
    while (true) {
        for (int i = 0; i < MAXITEMS; i++) {
            printLn(i + 1);
            printLn(". name ");
            print(storeProducts[i].name);
            printLn("price ");
            print(storeProducts[i].price);
        }
        print("Select an item (type 0 to exit): ");
        int choice = (int)getNum("");
        if (choice >= MAXITEMS) {
            print("Invalid choice. Try again!");
            continue;
        }
        if (choice == 0) break;
        if (isInsert && choice != -1)
            insert(head, storeProducts[choice - 1]);
        if (!isInsert && choice != -1)
            remove(head, storeProducts[choice - 1]);
    }
    return;
}
// shows the menu and calls the appropriate function based on the user's choice
void showMenu(item storeProducts[], node *head, int *total) {
    while (true) {
        print("1. Add item to cart");
        print("2. Remove item from cart");
        print("3. View cart");
        print("4. Checkout");
        print("5. Exit");
        int choice = (int)getNum("Enter your choice: ");
        switch (choice) {
            case 1: {
                getProducts(storeProducts, head, true);
                break;
            }

            case 2: {
                getProducts(storeProducts, head, false);
                break;
            }
            case 3: {
                printCart(head);
                break;
            }
            case 4: {
                checkOut(storeProducts, head);
                break;
            }
            case 5: {
                print("Group Name: Ice Cream");
                print("Members:");
                print("Lazaro, John Gabriele R");
                print("Ligutan, Aldrin Lorenz D.");
                print("Maminta, John Angelo A.");
                print("Quemuel, Mary Arwen L.");  // missing semi kanina
                exit(0);
            }
            default:
                print("Invalid input. Try again!");
                break;
        }
    }
}

int main(int argc, char const *argv[]) {
    // create a linked list that would be used as a customer's cart
    int *total = 0;
    node *head = new node;
    head->next = NULL;
    item storeProducts[MAXITEMS];
    init(storeProducts);
    showMenu(storeProducts, head, total);
    cout << "The total price is: " << total << endl;
    return 0;
}