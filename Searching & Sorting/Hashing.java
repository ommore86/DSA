import java.util.Scanner;

public class Hashing {
    int[] arr = new int[10];
    final int DELETED = -1;
    private int EMPTY = 0;

    public int HashFunction(int key) {
        return key % 10;
    }

    public void insert(int key) {
        int pos = HashFunction(key);
        while (arr[pos] != EMPTY && arr[pos] != DELETED) {
            pos = (pos + 1) % arr.length;
        }
        arr[pos] = key;
        System.out.println("Element " + key + " inserted at position " +
                pos);
    }

    public void delete(int key) {
        int pos = HashFunction(key);
        while (arr[pos] != EMPTY) {
            if (arr[pos] == key) {
                arr[pos] = DELETED;
                System.out.println("Element " + key + " deleted from position" + pos);
                return;
            }
            pos = (pos + 1) % arr.length;
        }
        System.out.println("Element " + key + " not found.");
    }

    public void search(int key) {
        int pos = HashFunction(key);
        while (arr[pos] != EMPTY) {
            if (arr[pos] == key) {
                System.out.println("Element " + key + " found at position " +
                        pos);
                return;
            }
            pos = (pos + 1) % arr.length;
        }
        System.out.println("Element " + key + " not found.");
    }

    public void display() {
        System.out.println("Hash Table Contents:");
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == DELETED) {
                System.out.println("Index " + i + ": Deleted");
            } else if (arr[i] == EMPTY) {
                System.out.println("Index " + i + ": Empty");
            } else {
                System.out.println("Index " + i + ": " + arr[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Hashing hashTable = new Hashing();
        int choice;
        do {
            System.out.println("\nHashing Operations: ");
            System.out.println("1. Insert");
            System.out.println("2. Delete");
            System.out.println("3. Search");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            System.out.print("Select a choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Insert a number: ");
                    int number = sc.nextInt();
                    hashTable.insert(number);
                    break;
                case 2:
                    System.out.print("Delete a number: ");
                    int deleteNo = sc.nextInt();
                    hashTable.delete(deleteNo);
                    break;
                case 3:
                    System.out.print("Search a number: ");
                    int searchNo = sc.nextInt();
                    hashTable.search(searchNo);
                    break;
                case 4:
                    hashTable.display();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 5);
        sc.close();
    }
}