class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.first = None
        self.last = None

    def insert_at_beg(self, ele):
        new_node = Node(ele)
        if self.first is None:
            self.first = self.last = new_node
        else:
            new_node.next = self.first
            self.first = new_node

    def insert_at_end(self, ele):
        new_node = Node(ele)
        if self.first is None:
            self.first = self.last = new_node
        else:
            self.last.next = new_node
            self.last = new_node

    def insert_at_pos(self, ele, pos):
        new_node = Node(ele)
        if pos == 1:
            self.insert_at_beg(ele)
            return

        if self.first is None:
            print("List is empty. Inserting at position 1.")
            self.first = self.last = new_node
            return

        temp = self.first
        i = 1
        while i < pos - 1 and temp is not None:
            temp = temp.next
            i += 1

        if temp is None:
            print("Invalid position.")
            return

        new_node.next = temp.next
        temp.next = new_node
        if new_node.next is None:
            self.last = new_node

    def delete_beg(self):
        if self.first is None:
            print("List is empty")
        else:
            temp = self.first
            self.first = self.first.next
            if self.first is None:
                self.last = None
            del temp

    def delete_end(self):
        if self.first is None:
            print("List is empty")
        elif self.first.next is None:
            del self.first
            self.first = self.last = None
        else:
            temp = self.first
            while temp.next != self.last:
                temp = temp.next
            del self.last
            self.last = temp
            self.last.next = None

    def delete_pos(self, pos):
        if self.first is None:
            print("List is empty")
            return

        if pos == 1:
            self.delete_beg()
            return

        temp = self.first
        i = 1
        while i < pos - 1 and temp is not None:
            temp = temp.next
            i += 1

        if temp is None or temp.next is None:
            print("Invalid position")
            return

        to_delete = temp.next
        temp.next = to_delete.next
        if to_delete == self.last:
            self.last = temp
        del to_delete

    def search(self, s):
        temp = self.first
        while temp is not None:
            if temp.data == s:
                print("Element Found")
                return
            temp = temp.next
        print("Element Not Found!")

    def display(self):
        if self.first is None:
            print("EMPTY LIST!")
        else:
            temp = self.first
            while temp:
                print(f"{temp.data} -> ", end='')
                temp = temp.next
            print("NULL")


def main():
    ll = LinkedList()

    while True:
        print("\n---------------Menu----------------")
        print("1. Insert at the beginning")
        print("2. Insert at the end")
        print("3. Insert at a specific position")
        print("4. Delete from the beginning")
        print("5. Delete from the end")
        print("6. Delete from a specific position")
        print("7. Search for an element")
        print("8. Display the list")
        print("9. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            ele = int(input("Enter element to insert at beginning: "))
            ll.insert_at_beg(ele)
        elif choice == '2':
            ele = int(input("Enter element to insert at end: "))
            ll.insert_at_end(ele)
        elif choice == '3':
            ele = int(input("Enter element: "))
            pos = int(input("Enter position: "))
            ll.insert_at_pos(ele, pos)
        elif choice == '4':
            ll.delete_beg()
        elif choice == '5':
            ll.delete_end()
        elif choice == '6':
            pos = int(input("Enter position to delete: "))
            ll.delete_pos(pos)
        elif choice == '7':
            ele = int(input("Enter element to search: "))
            ll.search(ele)
        elif choice == '8':
            ll.display()
        elif choice == '9':
            print("Exiting...")
            break
        else:
            print("Invalid choice, please try again!!")


if __name__ == "__main__":
    main()
