#include <iostream>
using namespace std;
#define Count 10

class Node {
public:

	int data;
	Node* left;
	Node* right;

	Node(int value) {
		left = nullptr;
		right = nullptr;
		data = value;
	}
};
void display2D(Node* root, int space) {

	if (root == nullptr)
	{
		return;
	}
	space += Count;

	display2D(root->right, space);
	cout << endl;
	for (int i = Count; i < space; i++)
	{
		cout << " ";
	}
	cout << root->data;

	display2D(root->left, space);
}
void createNewNode(Node* root, int value) {
	if (root == nullptr)
	{
		return;
	}
	if (value > root->data && root->right == nullptr)
	{
		root->right = new Node(value);
		return;

	}
	if (value < root->data && root->left == nullptr)
	{
		root->left = new Node(value);
		return;

	}
	if (value > root->data)
	{
		root = root->right;
	}
	else {
		root = root->left;
	}
	createNewNode(root, value);
}
bool binSearch(Node* root, int value) {
	if (root == nullptr)
	{
		return false;
	}
	if (value == root->data)
	{
		return true;
	}
	else
	{
		if (value > root->data)
		{
			root = root->right;
		}
		else
		{
			root = root->left;
		}
	}

	binSearch(root, value);
}
int countTwoEl(Node* root, int& count) {
	
	if (root == nullptr)
	{
		return 0;
	}
	if (root->left != nullptr && root->right != nullptr)
	{
		count++;
	}

	countTwoEl(root->right, count);
	countTwoEl(root->left, count);

	return count;
}
int sum(Node* root, int& sumValue) {
	if (root == nullptr) {
		return sumValue; 
	}
	sumValue += root->data; 

	sumValue = sum(root->left, sumValue);
	sumValue = sum(root->right, sumValue);

	return sumValue; 
}
int maxDepth(Node* root) {
	if (root == nullptr) {
		return 0; 
	}

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return 1 + max(leftDepth, rightDepth);
}

int main()
{
	Node* root = new Node(10);

	createNewNode(root, 15);
	createNewNode(root, 7);
	createNewNode(root, 20);
	createNewNode(root, 13);
	createNewNode(root, 8);
	createNewNode(root, 6);
	createNewNode(root, 25);

	display2D(root, 10); cout << endl;

	int searchNum = 0;
	cout << "Enter number to search: "; cin >> searchNum;
	if (binSearch(root, searchNum) == true)
	{
		cout << "Number " << searchNum << " is present" << endl;
	}
	else
	{
		cout << "Number "<< searchNum << " is missing" << endl;
	}
	int count = 0;
	cout << "\nNumbers of elements that have two child elements: ";
	cout << countTwoEl(root, count) << endl;

	int mySum = 0;
	cout << "\nThe sum of all elements is " 
		<< sum(root, mySum) << endl;


	int depth = maxDepth(root);
	cout << "\nMaximum depth of the binary tree: " << depth << endl;

	return 0;
}