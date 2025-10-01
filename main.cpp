#include <iostream>
#include <string>
using namespace std;

// Class to hold employee data
class EmployeeInfo
{
public:
    int id;
    string name;

    EmployeeInfo(int empID = 0, string empName = "")
    {
        id = empID;
        name = empName;
    }
};

// Binary tree class to hold EmployeeInfo nodes
class BinaryTree
{
private:
    struct TreeNode
    {
        EmployeeInfo data;
        TreeNode *left, *right;

        TreeNode(EmployeeInfo emp, TreeNode *l = nullptr, TreeNode *r = nullptr)
            : data(emp), left(l), right(r) {}
    };

    TreeNode *root;

    // Recursive insert
    void insert(TreeNode *&node, EmployeeInfo emp)
    {
        if (node == nullptr)
            node = new TreeNode(emp);
        else if (emp.id < node->data.id)
            insert(node->left, emp);
        else
            insert(node->right, emp);
    }

    // Recursive size
    int size(TreeNode *node)
    {
        if (node == nullptr) return 0;
        return size(node->left) + size(node->right) + 1;
    }

    // Recursive search
    string search(TreeNode *node, int id)
    {
        if (node == nullptr)
            return "Employee not found.";
        else if (id == node->data.id)
            return node->data.name;
        else if (id < node->data.id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

public:
    BinaryTree() { root = nullptr; }

    void add(EmployeeInfo emp) { insert(root, emp); }

    int size() { return size(root); }

    string search(int id) { return search(root, id); }
};

// Driver program
int main()
{
    BinaryTree tree;

    // Insert required employee data
    tree.add(EmployeeInfo(1021, "John Williams"));
    tree.add(EmployeeInfo(1057, "Bill Witherspoon"));
    tree.add(EmployeeInfo(2487, "Jennifer Twain"));
    tree.add(EmployeeInfo(3769, "Sophia Lancaster"));
    tree.add(EmployeeInfo(1017, "Debbie Reece"));
    tree.add(EmployeeInfo(1275, "George McMullen"));
    tree.add(EmployeeInfo(1899, "Ashley Smith"));
    tree.add(EmployeeInfo(4218, "Josh Plemmons"));

    // Show size
    cout << "The current size of the tree is: " << tree.size() << endl;

    // Search for employee
    int searchID;
    cout << "Enter an ID number to search: ";
    cin >> searchID;

    string result = tree.search(searchID);
    cout << "Search result: " << result << endl;

    return 0;
}

