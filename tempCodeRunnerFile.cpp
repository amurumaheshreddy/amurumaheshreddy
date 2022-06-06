#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
string name;
double price;
Node* left;
Node* right;
Node* parent;
double key;
Node(string name, double pr){
name = name;
price = pr;
left = NULL;
right = NULL;
parent = NULL;
key = price;
}
};
Node* Insert(Node * node, Node* temp)
{
// If BST doesn't exist
// create a new node as root
// or it's reached when
// there's no any child node
// so we can insert a new node here
int key = temp->key;
if(node == NULL)
{
node = temp;
} 
// If the given key is greater than
// node's key then go to right subtree
else if(node->key < key){
node->right = Insert(node->right, temp);
node->right->parent = node;
}
// If the given key is smaller than
// node's key then go to left subtree
else
{
node->left = Insert(node->left, temp);
node->left->parent = node;
}
return temp;
}
void print(Node* root){
if(root){
cout<<"name: "<<root->name<<" "<<" price: "<<root->price<<endl;
}else{
return;
}
if(root->left){
print(root->left);
}
if(root->right){
print(root->right);
}
return;
}
int main()
{ 
string name;
double price; 
Node* root = new Node("Lemon",3.00);
//root->name = "Lemon";
//root->price = 3.00;  
vector<string> names;
vector<int> prices;
names.push_back("Lemon");
prices.push_back(3.00);
for( int i = 0; i<15; i++){
cout<<"please enter the name of the "<<i<<"st fruit: "<<endl;
cin>>name;
cout<<"please enter the price of the "<<i<<"st fruit: "<<endl;
cin>>price;
names.push_back(name);
prices.push_back(price);
Node* node = new Node(name,price);
Insert(root,node);
}  
print(root); 
double sum = 0.0;
for(double i: prices){
sum+=i;
}
cout<<"average price is: "<<sum/(double)16<<endl;
return 0;
}