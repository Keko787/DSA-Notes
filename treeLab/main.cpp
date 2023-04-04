#include <iostream>
#include <cmath>
// the tree node struct
struct TreeNode {
    int info;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};
// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have search, delete etc.
class BinSearchTree {
public:
    bool insert(int newInt);
    void inorderTrav(TreeNode* rt);
    void allTraverseNodes();
    void treeStats();
    bool remove(int key);
    int sumNode(TreeNode* rt);
    double treeDepth(TreeNode* rt);
    int count(TreeNode* rt);
    void postorderTrav(TreeNode* rt);
    void preorderTrav(TreeNode* rt);


private:
    TreeNode* root = nullptr;
};
// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* currNode = root;
    TreeNode* trailNode = nullptr;
    while (currNode != nullptr) { //will the currNode existing
        if (currNode->info == newInt) { // if newinfo match with a node cancel
            return false;
        }
        trailNode = currNode; // trailNode mem is currNode mem, trailNode trailing currentNode
        if (newInt < currNode->info) { //if new node is less than the current node
            currNode = currNode->left; // traverse to the left
        }
        else { // if new node is more than the current node
            currNode = currNode->right; // traverse to the right
        }
    }
// new node
    TreeNode* v = new TreeNode;
    v->info = newInt;
    if (trailNode == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < trailNode->info) {
        std::cout << "Insert " << v->info << " left to " << trailNode->info <<
                  std::endl;
        trailNode->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << trailNode->info <<
                  std::endl;
        trailNode->right = v;
    }
    return true;
}
// traversal
void BinSearchTree::allTraverseNodes() { //shows each traversal order of the tree
    std::cout << "inorder traversal: ";
    inorderTrav(root); // call the traversal with the root, which is private
    std::cout << "\n";
    std::cout << "preorder traversal: ";
    preorderTrav(root);
    std::cout << "\n";
    std::cout << "postorder traversal: ";
    postorderTrav(root);
}

void BinSearchTree::treeStats() { // show the stat of the tree
    std::cout << "Sum all the nodes: " << sumNode(root); // call the traversal with the root, which is private
    std::cout << "\n";
    std::cout << "Level of the tree: " << treeDepth(root);
    std::cout << "\n";
    std::cout << "Count of the nodes: " << count(root);
}

void BinSearchTree::inorderTrav(TreeNode* rt) { //left to right, left most node goes first
    if (rt == nullptr) // if the node does not exist
        return; // pop the rec call stack, then proceed to next command line
    inorderTrav(rt->left); // search for left child and push the rec call stack, after end/pop the rec call stack it will proceed to next line
    std::cout << rt->info << " "; // print
    inorderTrav(rt->right); // search for right child and push the rec call stack, after end/pop the rec call stack it will proceed to next line
}

void BinSearchTree::postorderTrav(TreeNode* rt) { // water fall or pachinko machine, root node goes first
    if (rt == nullptr) // if the node does not exist
        return; // pop the rec call stack, then proceed to next command line
    postorderTrav(rt->left); // search for left child and push the rec call stack, after end/pop the rec call stack it will proceed to next line
    postorderTrav(rt->right); // search for right child and push the rec call stack, after end/pop the rec call stack it will proceed to next line
    std::cout << rt->info << " "; // print and pop/end rec call stack
}

void BinSearchTree::preorderTrav(TreeNode* rt) { // left brother, right youngest node, parent, left most leaf node goes first
    if (rt == nullptr) // if the node does not exist
        return; // pop the rec call stack, then proceed to next command line
    std::cout << rt->info << " "; // print
    preorderTrav(rt->left); // search for left child and push the rec call stack, after end/pop the rec call stack it will proceed to next line
    preorderTrav(rt->right); // search for right child and push the rec call stack, after end/pop the rec call stack it will end/pop the rec call stack for this one too
}



// sums the data of the nodes
int BinSearchTree::sumNode(TreeNode* rt) { // will return a sum of the data from all the nodes made by the rec call stack, will return the sum of the current amount of data in the tree, it will add it with info + leftPTR + rightPTR for each node
    if (rt == nullptr) // if the node does not exist
        return 0; // will add 0 to the sum
    return rt->info/*adds the data of the node to add to the sum recursively*/ + sumNode(rt->left) /*will search for a left child to add to the sum*/+ sumNode(rt->right)/*will search for a right child to add to the sum*/; // makes two rec calls at once, once calls to add the data of the left and another to add the dat of the right

}

//states the depth of the tree
double BinSearchTree::treeDepth(TreeNode* rt) { // will return a count of the level made by the rec call stack, will find the max between the left and right side of the tree to find the level
    if(rt == nullptr) // if the node does not exist
        return 0; //will add 0 to the count of either param
    return fmax(1/*increment the Count of the first param for the left side of tree to find the max and depth*/ + treeDepth(rt->left)/*will search for a left child to add 1 to the level count inside the first param*/, 1 /*increment the Count of the second param for the right side of tree to find the max and depth*/ +
                                                                                                                            treeDepth(rt->right))/*will search for a right child to add 1 to the level count inside the second param*/; // makes two recursive calls at once, would this be exponential? one recursive call, calls the left, while the other one calls the right
}

// count the nodes in the tree
int BinSearchTree::count(TreeNode* rt) { // will return a count of the level made by the rec call stack, will find the max between the left and right side of the tree to find the level
    if (rt == nullptr) // if the node does not exist
        return 0; // add 0 to the rec call stack counter
    return 1/*increment the Count of the first param for the left side of tree to find the max and depth*/ + count( rt->left)/*will search for a left child to add 1 to the level count inside the first param*/ + count(rt->right)/*will search for a right child to add 1 to the level count inside the second param*/;
}

// this is a BST delete function
// in lieu of comments, see the corresponding slides
bool BinSearchTree::remove(int key){
    TreeNode* remNode = root;
    TreeNode* trailNode = nullptr; // will follow remNode
    while (remNode != nullptr && remNode->info != key) { // loop will stop on the condition if remNode doesnt exist (at the end) and it equals to the key
        trailNode = remNode;
        if (key < remNode->info) {
            remNode = remNode->left;
        }
        else {
            remNode = remNode->right;
        }
    }
    if (remNode == nullptr) {
        return false;
    }
    TreeNode* rp;
    if (remNode->left == nullptr) {
        rp = remNode->right;
    }
    else if (remNode->right == nullptr) {
        rp = remNode->left;
    }
    else {
        TreeNode* f = remNode;
        rp = remNode->right;
        TreeNode* s = rp->left;
        while (s != nullptr) {
            f = rp;
            rp = s;
            s = rp->left;
        }
        if (f != remNode) {
            f->left = rp->right;
            rp->right = remNode->right;
        }
        rp->left = remNode->left;
    }
    if (trailNode == nullptr) {
        root = rp;
    }
    else if (remNode == trailNode->left) {
        trailNode->left = rp;
    }
    else {
        trailNode->right = rp;
    }
    delete remNode;
    return rp != nullptr;
}



////////////////////////////////////////////
int main() {
    BinSearchTree st = BinSearchTree(); // the tree object
    st.insert(8); //the root
// where will each of this go in the BST?
    st.insert(3); // root, left
    st.insert(11); // root, right
    st.insert(9); // root, right , left
    st.insert(10); // root, right, left, right
    st.insert(14); // root, right, right

// now traverse and show stats of the tree
    st.allTraverseNodes();
    std::cout << "\n";
    st.treeStats();
}
