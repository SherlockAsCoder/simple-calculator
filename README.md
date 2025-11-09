### simple-calculator

A basic C++ calculator that evaluates arithmetic expressions containing non-negative integers and operators `+`, `-`, `*`, `/`, and parentheses `()`.

#### Features

* Supports basic arithmetic operations
* Handles parentheses correctly using the **Shunting Yard Algorithm**
* Evaluates expressions like `3+(2*4)-5`

#### How to Run

1. Compile the program:

   ```bash
   g++ calculator.cpp -o calculator
   ```
2. Run the executable:

   ```bash
   ./calculator
   ```
3. Enter an expression when prompted, for example:

   ```
   3+(2*4)-5
   ```

#### Example Output

```
Enter an expression (e.g. 3+(2*4)-5): 3+(2*4)-5
Result: 6
```

#### Description

This project implements a **simple infix expression calculator** using:

* **Stacks** for operators and operands
* **Queues** for postfix notation conversion

Perfect for learning **expression parsing**, **operator precedence**, and **data structures** in C++.
