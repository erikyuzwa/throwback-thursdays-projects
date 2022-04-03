// cpp-cupcake-point-of-sale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <list>
#include <ctime>

class SaleItem {
private:
    int id;
    double price;
    std::string description;
    int quantity;

public:
    SaleItem() : id(0), price(0.0), description(""), quantity(1) {

    }

    ~SaleItem() = default;

    bool create(std::string new_description) {
        // generate a random id for this instance between 1 - 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    void setPrice(double new_price) { price = new_price; }
    void setQuantity(double new_quantity) { quantity = new_quantity; }
    std::string getDescription() { return description; }

    void purchase(int new_quantity) {
        quantity = quantity - new_quantity;
    }

};

int main()
{
    std::list<SaleItem> inventory;
    std::list<SaleItem>::iterator it;
    std::string version = "v0.2.0";
    char input_option;
    double tax_rate = 0.0;

    srand(time(NULL));

    inventory.clear();

    //SaleItem test1;
    //test1.create("vanilla");
    //test1.setPrice(4.95);
    //test1.setQuantity(5);
    //inventory.push_back(test1);

    while (1) {
        system("cls");
        std::cout << "Cupcake POS - " << version << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "id | description | price | quantity in stock" << std::endl;
        for (it = inventory.begin(); it != inventory.end(); it++) {
            std::cout
                << it->getId() << " | "
                << it->getDescription() << " | "
                << it->getPrice() << " | "
                << it->getQuantity()
                << std::endl;
        }

        if (inventory.empty()) {
            std::cout << "Add a new cupcake!" << std::endl;
        }

        std::cout << std::endl << std::endl;

        std::cout << "Tax Rate: " << tax_rate << "%" << std::endl;
        std::cout << "====================================" << std::endl;

        std::cout << "[a]dd a new cupcake" << std::endl;
        std::cout << "[c]omplete a cupcake purchase" << std::endl;
        std::cout << "[n]ew tax rate" << std::endl;
        std::cout << "[u]pdate cupcake quantity" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;
        if (input_option == 'q') {
            std::cout << "Have a great day now!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::string new_description;
            double new_price;

            std::cout << "Enter new cupcake description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, new_description);

            std::cout << "Set new cupcake price: ";
            std::cin >> new_price;

            SaleItem item;
            item.create(new_description);
            item.setPrice(new_price);
            inventory.push_back(item);
        }
        else if (input_option == 'c') {
            int checkout_id, checkout_quantity;
            double total_amount, total_tax;

            std::cout << "Enter id of cupcake to purchase: ";
            std::cin >> checkout_id;

            for (it = inventory.begin(); it != inventory.end(); it++) {
                if (checkout_id == it->getId()) {
                    std::cout << "Enter quantity: ";
                    std::cin >> checkout_quantity;

                    if (checkout_quantity > it->getQuantity()) {
                        std::cout << "Sorry, not enough in stock" << std::endl;
                        system("pause");
                    }
                    else {
                        it->purchase(checkout_quantity);

                        total_amount = checkout_quantity * it->getPrice();
                        total_tax = total_amount * (tax_rate * 0.01);
                        std::cout << "Total Amount: " << total_amount << std::endl;
                        std::cout << "Tax: " << total_tax << std::endl;
                        std::cout << "Total Sale: " << total_amount + total_tax << std::endl;
                        system("pause");

                    }
                    break;
                }
            }

        }
        else if (input_option == 'n') {
            std::cout << "Enter new tax rate: ";
            std::cin >> tax_rate;
        }
        else if (input_option == 'u') {
            int stock_id;
            int stock_quantity;
            
            std::cout << "Enter id of cupcake to update: ";
            std::cin >> stock_id;

            for (it = inventory.begin(); it != inventory.end(); it++) {
                if (stock_id == it->getId()) {
                    std::cout << "Enter new quantity: ";
                    std::cin >> stock_quantity;

                    it->setQuantity(stock_quantity);
                    break;
                }
            }

        }
        
    }
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
