# 🔗 Singly Linked List Implementation in C

A comprehensive menu-driven program implementing a singly linked list data structure in C with various operations including insertion, deletion, traversal, and utility functions.

## 👩‍💻 Author

**Sneha Rathod**  
📫 [LinkedIn Profile](https://www.linkedin.com/in/thesneharekt/)
🛠️ [GitHub: @snehaRekt](https://github.com/snehaRekt)

## 📋 Table of Contents

- [Features](#features)
- [Operations Supported](#operations-supported)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Program Structure](#program-structure)
- [Example Output](#example-output)
- [Memory Management](#memory-management)
- [Contributing](#contributing)

## ✨ Features

- **Interactive Menu System**: User-friendly menu-driven interface
- **Complete CRUD Operations**: Create, Read, Update, and Delete operations on linked list
- **Input Validation**: Robust error handling for invalid inputs
- **Memory Management**: Proper allocation and deallocation of memory
- **Position-based Operations**: Insert and delete at specific positions
- **Utility Functions**: Count nodes, traverse list, and more

## 🔧 Operations Supported

| Operation               | Description                                       |
| ----------------------- | ------------------------------------------------- |
| **Append Node**         | Add a new node at the end of the list             |
| **Insert at Beginning** | Add a new node at the start of the list           |
| **Insert at End**       | Add a new node at the end (alternative to append) |
| **Insert at Position**  | Add a new node at a specific position             |
| **Delete First Node**   | Remove the first node from the list               |
| **Delete Last Node**    | Remove the last node from the list                |
| **Delete by Value**     | Remove a node with a specific value               |
| **Delete at Position**  | Remove a node at a specific position              |
| **Traverse List**       | Display all nodes in the list                     |
| **Count Nodes**         | Get the total number of nodes in the list         |

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or any C compiler)
- Terminal/Command Prompt

### Installation & Compilation

1. **Clone the repository**

   ```bash
   git clone https://github.com/snehaRekt/singly-linked-list-operations.git
   cd singly-linked-list-operations
   ```

2. **Compile the program**

   ```bash
   gcc index.c
   ```

3. **Run the program**
   ```bash
   ./a.out
   ```

## 💡 Usage

When you run the program, you'll see an interactive menu:

```
🔗 Singly Linked List - Menu Driven Program

========= MENU =========
1. Append Node
2. Insert At Beginning
3. Traverse List
4. Delete First Node
5. Delete Last Node
6. Insert At End
7. Delete Node By Value
8. Delete Node At Position
9. Add Node At Position
10. Count Nodes
11. Exit
========================
```

Simply enter the number corresponding to your desired operation and follow the prompts.

## 📁 Program Structure

### Core Data Structure

```c
struct Node {
    int value;
    struct Node *next;
};
```

### Key Functions

- **Insertion Operations**

  - `appendNode()`: Add node at end
  - `insertAtBeginning()`: Add node at start
  - `insertAtEnd()`: Add node at end (wrapper)
  - `AddAtPosition()`: Add node at specific position

- **Deletion Operations**

  - `deleteFirst()`: Remove first node
  - `deleteLast()`: Remove last node
  - `deleteNode()`: Remove node by value
  - `deleteAtPosition()`: Remove node at position

- **Utility Functions**
  - `traverse()`: Display all nodes
  - `countNodes()`: Count total nodes
  - `freeList()`: Free all allocated memory
  - `getUserChoice()`: Get valid user input
  - `getIntegerInput()`: Get integer input with validation

## 📊 Example Output

```
Enter your choice: 1
Enter value to append: 10

Enter your choice: 2
Enter value to insert at beginning: 5

Enter your choice: 3
5 -> 10 -> NULL

Enter your choice: 10
✅ Total Nodes: 2
```

## 🧠 Memory Management

The program includes proper memory management:

- **Dynamic Allocation**: Uses `malloc()` for creating new nodes
- **Memory Cleanup**: `free()` function calls to prevent memory leaks
- **Exit Handler**: `freeList()` function cleans up all nodes before program termination

## 🛡️ Error Handling

- **Input Validation**: Prevents invalid input types
- **Boundary Checks**: Handles out-of-bounds position operations
- **Null Pointer Checks**: Prevents segmentation faults
- **User-Friendly Messages**: Clear error messages with emoji indicators

## 🤝 Contributing

Contributions are welcome! Here are some ways you can contribute:

1. **Fork the repository**
2. **Create a feature branch** (`git checkout -b feature/AmazingFeature`)
3. **Commit your changes** (`git commit -m 'Add some AmazingFeature'`)
4. **Push to the branch** (`git push origin feature/AmazingFeature`)
5. **Open a Pull Request**

### Ideas for Contributions

- Add more linked list operations (reverse, sort, merge)
- Implement doubly linked list variant
- Add unit tests
- Improve documentation
- Optimize existing functions

## 🎯 Learning Objectives

This implementation helps understand:

- **Pointer manipulation** in C
- **Dynamic memory allocation**
- **Linked list data structure concepts**
- **Menu-driven programming**
- **Error handling and input validation**
- **Memory management best practices**

---

⭐ **Don't forget to star this repository if you found it helpful!**

📫 **Questions or suggestions?** Feel free to reach out via [LinkedIn](https://www.linkedin.com/in/thesneharekt/) or open an issue on GitHub!
