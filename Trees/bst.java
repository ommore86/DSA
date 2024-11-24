class Node {
    int key;
    Node left, right;

    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}

class bst {
    // Insert
    static Node insert(Node root, int key)
    {
        // Tree is empty
        if (root == null)
            return new Node(key);

        // Key is already present
        if (root.key == key)
            return root;

        if (key < root.key)
            root.left = insert(root.left, key);
        else
            root.right = insert(root.right, key);

        return root;
    }

    static Node minValueNode(Node node)
    {
        Node current = node;

        while (current.left != null)
            current = current.left;

        return current;
    }

    // Deletion
    static Node deleteNode(Node root, int key)
    {
        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteNode(root.left, key);
        else if (key > root.key)
            root.right = deleteNode(root.right, key);
        else {
            // Node with only one child or no child
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            // Node with two children: Get smallest in the right subtree
            root.key = minValueNode(root.right).key;

            // Delete the inorder successor
            root.right = deleteNode(root.right, root.key);
        }

        return root;
    }

    // Inorder
    static void inorder(Node root)
    {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);
        }
    }

    // Preorder
    static void preorder(Node root)
    {
        if (root != null) {
            System.out.print(root.key + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    // Postorder
    static void postorder(Node root)
    {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.key + " ");
        }
    }

    // Searching
    static boolean search(Node root, int key)
    {
        if (root == null)
            return false; // Key not found

        if (root.key == key)
            return true; // Key found

        if (key < root.key)
            return search(root.left, key);
        else
            return search(root.right, key);
    }


    public static void main(String[] args)
    {
        Node root = null;

        // Building the tree
        root = insert(root, 50);
        root = insert(root, 30);
        root = insert(root, 20);
        root = insert(root, 40);
        root = insert(root, 70);
        root = insert(root, 60);
        root = insert(root, 80);

        System.out.print("Inorder traversal: ");
        inorder(root);
        System.out.println();

        System.out.print("Preorder traversal: ");
        preorder(root);
        System.out.println();

        System.out.print("Postorder traversal: ");
        postorder(root);
        System.out.println();

        // Searching for key 40 and 90 in the BST
        boolean isFound = search(root, 40);
        System.out.println("Search for 40: " + (isFound ? "Found" : "Not Found"));
        isFound = search(root, 90);
        System.out.println("Search for 90: " + (isFound ? "Found" : "Not Found"));

        System.out.println("\nDeleting 50 from the BST.");
        root = deleteNode(root, 50);

        System.out.print("Inorder traversal after deletion: ");
        inorder(root);
        System.out.println();
    }
}

        //      50
        //     /  \
        //    30   70
        //   / \   / \
        //  20 40 60 80