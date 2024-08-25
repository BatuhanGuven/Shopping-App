

# Project Name: Shopping-App

## Project Description

This project is an online shopping system developed in C++. The system allows users to add products to their cart, place orders, and view invoices. The project includes various classes representing users, managers, carriers, and products. It also evaluates the strength of user passwords and calculates invoices based on discount codes.

## Classes and Functions

### `Zaman`
- **Description**: Stores date and time information used in the system.
- **Members**:
  - `int hour`: Hour information.
  - `int minute`: Minute information.
- **Functions**:
  - `ostream& operator<<(ostream& os, const Zaman& dt)`: Outputs the `Zaman` object to the screen.

### `Clothes`
- **Description**: Holds general clothing product information.
- **Members**:
  - `int index`: Product number.
  - `string size`: Product size.
  - `string color`: Product color.
  - `string category`: Product category.
  - `double price`: Product price.
- **Functions**: Contains various setter and getter functions to set and get product information.

### `Siparis` (Derived from `Clothes`)
- **Description**: Stores order information.
- **Members**:
  - `int order_no`: Order number.
  - `double order_price`: Order price.
  - `Zaman order_start`: Order start time.
  - `Zaman order_delivery`: Order delivery time.
- **Functions**: Contains various setter and getter functions to set and get order information.

### Clothing Classes
- **Dress, Tshirt, Pants, Shirt, Skirt, Shoes**: Derived from the `Clothes` class, representing different types of clothing. Each has default and parameterized constructors.

### `Person`
- **Description**: Holds personal information.
- **Members**:
  - `string name_surname`: Person's name and surname.
  - `string phone_no`: Person's phone number.

### `User` (Derived from `Person`)
- **Description**: Holds user information and manages cart and orders.
- **Members**:
  - `string username`, `email`, `district_address`, `password`, `discount_code`, `birthdate`: User information.
  - `vector<Clothes> cart`: Products in the user's cart.
  - `vector<Siparis> orders`: Orders placed by the user.
  - `vector<vector<Siparis>> orderHistory`: Orders organized by their time.
- **Functions**: Contains various setter and getter functions for user information.

### `Manager` (Derived from `Person`)
- **Description**: Holds manager information.
- **Members**:
  - `string password`: Manager's password.

### `Carrier` (Derived from `Person`)
- **Description**: Holds carrier information and delivery details.
- **Members**:
  - `Zaman delivery_end`: Delivery end time.
  - `int order_number`: Order number assigned to the carrier.

### `Invoice`
- **Description**: Stores invoice information.
- **Members**:
  - `int order_no`: Order number.
  - `string username`: User's name.
- **Functions**: Contains setter and getter functions for invoice information.

## Functions

### `convertToString(char* a, int size)`
- **Description**: Converts a character array to a string.
- **Parameters**:
  - `char* a`: Character array.
  - `int size`: Size of the array.

### `printStrongNess(string& input)`
- **Description**: Evaluates and prints the strength of a password.
- **Parameters**:
  - `string& input`: Password.

### `calculateBillAmount(vector<Siparis> orders, User& user)`
- **Description**: Calculates the total amount of orders and applies discounts.
- **Parameters**:
  - `vector<Siparis> orders`: Orders.
  - `User& user`: User information.

### `calculateBasketAmount(vector<Clothes> basket, User user)`
- **Description**: Calculates the total amount of items in the cart.
- **Parameters**:
  - `vector<Clothes> basket`: Cart.
  - `User user`: User information.

### `showBill(User user)`
- **Description**: Displays the user's invoice and order details.
- **Parameters**:
  - `User user`: User information.

### `showBasket(User user)`
- **Description**: Displays the user's cart items and cart total.
- **Parameters**:
  - `User user`: User information.

## Usage

1. **Compilation**

   Compile the project using a C++ compiler:
   ```bash
   g++ -o shopping_system main.cpp
   ```

2. **Execution**

   Run the compiled application:
   ```bash
   ./shopping_system
   ```

3. **User Interface**

   - When the application starts, users can add products to their cart, place orders, and view invoices.
