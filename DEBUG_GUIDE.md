# Debugging Guide for C_DataStructures Project

## Debugger Configuration Complete! 🎉

Your VS Code debugger is now configured for your C projects. Here's how to use it:

## Available Debug Configurations:

1. **Debug AVL Tree** - Specifically for your auto-balancing binary search tree
2. **Debug Link List** - For your linked list implementation  
3. **Debug Current File** - For debugging any C file you're currently working on

## How to Debug:

### Method 1: Using the Debug Panel
1. Open the Run and Debug panel (Ctrl+Shift+D)
2. Select the appropriate configuration from the dropdown
3. Click the green play button or press F5

### Method 2: Quick Debug
1. Open the file you want to debug (e.g., main.c in autoBalancingBinarySearchTree)
2. Press F5 to start debugging with the current file configuration

## Setting Breakpoints:

1. Click in the gutter (left of line numbers) to set a breakpoint
2. Red dots indicate active breakpoints
3. Common places to set breakpoints in your AVL tree:
   - Line 78: `if (node == NULL)` in insert function
   - Line 88: `node->height = uptHeight(node);` to check height updates
   - Line 95-104: The rotation logic
   - Line 114: Inside inOrder function to watch traversal

## Debug Features Available:

- **Step Over (F10)**: Execute current line
- **Step Into (F11)**: Step into function calls
- **Step Out (Shift+F11)**: Step out of current function
- **Continue (F5)**: Continue execution until next breakpoint
- **Variables Panel**: Watch local variables and their values
- **Call Stack**: See the sequence of function calls
- **Watch Panel**: Add expressions to monitor specific values

## Useful Watch Expressions for AVL Tree:

Add these in the Watch panel to monitor your tree:
- `root->key` - Current node's value
- `getHeight(node)` - Node height
- `getBalance(node)` - Balance factor
- `node->leftSon` - Left child pointer
- `node->rightSon` - Right child pointer

## Tips:

1. **Compile with debug info**: The build tasks are configured with `-g` flag
2. **Use pretty printing**: GDB pretty printing is enabled for better struct display
3. **Memory debugging**: Use tools like Valgrind for memory leak detection:
   ```bash
   valgrind --tool=memcheck --leak-check=yes ./main
   ```

## Fixed Issues:

- ✅ Added `static` keyword to inline functions to avoid linker errors
- ✅ Configured proper build tasks with debug symbols (-g flag)
- ✅ Set up multiple debug configurations for different projects
- ✅ Added compiler warnings (-Wall -Wextra) for better code quality

## Example Debugging Session:

1. Set a breakpoint at line 78 in the insert function
2. Start debugging with "Debug AVL Tree" configuration
3. The program will stop when inserting the first value (30)
4. Use F10 to step through the insertion logic
5. Watch how the tree gets balanced as you continue

Happy debugging! 🐛🔍
