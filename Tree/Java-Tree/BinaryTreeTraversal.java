//Two ways to create the binary tree(source gpt)
//1. takes user input for n size array and create it's tree
//2. take input from user for each node and -1 for for leaf nodes(we are using)

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Define the structure for a binary tree node
class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BinaryTreeTraversal {

    // Build the binary tree using level-order insertion
    static Node buildTree(Scanner sc) {
        System.out.print("Enter root value (-1 for NULL): ");
        int val = sc.nextInt();

        if (val == -1) return null;
        Node root = new Node(val);

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            System.out.print("Enter left child of " + current.data + " (-1 for NULL): ");
            val = sc.nextInt();
            if (val != -1) {
                current.left = new Node(val);
                queue.add(current.left);
            }

            System.out.print("Enter right child of " + current.data + " (-1 for NULL): ");
            val = sc.nextInt();
            if (val != -1) {
                current.right = new Node(val);
                queue.add(current.right);
            }
        }

        return root;
    }

    // Inorder traversal
    static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    // Preorder traversal
    static void preorder(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    // Postorder traversal
    static void postorder(Node root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    // ✅ Level Order traversal (Breadth-First)
    static void levelOrder(Node root) {
        if (root == null) return;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            System.out.print(current.data + " ");

            if (current.left != null) queue.add(current.left);
            if (current.right != null) queue.add(current.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = buildTree(sc);

        System.out.print("\nInorder Traversal   : ");
        inorder(root);

        System.out.print("\nPreorder Traversal  : ");
        preorder(root);

        System.out.print("\nPostorder Traversal : ");
        postorder(root);

        System.out.print("\nLevel Order Traversal: ");
        levelOrder(root);

        sc.close();
    }
}
