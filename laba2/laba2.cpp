#include <iostream>
using namespace std;

// узел односвязного списка
struct Node {
    int data;
    Node* next = nullptr;
};

//структура очередь
struct Queue {
    int cnt;
    Node* first = nullptr;
    Node* last = nullptr;

    //функция добавления элемента в очередь
    void queue(int data){
        cnt = count();
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        cnt++;
    }

    //функция извлечения элемента из очереди
    int unqueue(){
        cnt = count();
        if (first == nullptr) {
            return -1;
        }
        int data = first->data;
        Node* temp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete temp;
        cnt--;
        return data;
    }

    //функция подсчета количества значений в очереди
    int count() {
        return cnt;
    }

    //функция вставки перед каждым отрицательным числом элемента со значением 1
    void insertBeforeNegative() {
        if (count() > 0) {
            Node* temp = first;
            if (temp->data < 0) {
                Node* newNode = new Node();
                newNode->data = 1;
                newNode->next = temp;
                first = newNode;
                cnt++;
            }
            while (temp != last) {
                if (temp->next->data < 0) {
                    Node* newNode = new Node();
                    newNode->data = 1;
                    newNode->next = temp->next;
                    temp->next = newNode;
                    temp = temp->next;
                    cnt++;
                }
                temp = temp->next;
            }
        }
    }

    //функция удаления из очереди всех элементов с отрицательной информационной частью
    void removeNegative(){
        while (first != nullptr && first->data < 0) {
            Node* temp = first;
            first = first->next;
            delete temp;
            cnt--;
        }
        if (count() > 0) {
            Node* current = first->next;
            Node* prev = first;
            while (current != nullptr) {
                if (current->data < 0) {
                    Node* temp = current;
                    prev->next = current->next;
                    current = current->next;
                    delete temp;
                    cnt--;
                }
                else {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }

    //функция подсчета количества вхождений переданного значения в коллекцию
    int count(int number) {
        int sumEl;
        sumEl = 0;
        Node** temp = &first;
        while (*temp != nullptr) {
            if ((*temp)->data == number) {
                sumEl++;
            }
            temp = &((*temp)->next);
        }
        return sumEl;
    }

    //функция удаления всех элементов коллекции
    void clear() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        last = first = nullptr;
        cnt = 0;
    }
};

//функция вывода очереди
void printQueue(Queue q) {
    Node* temp = q.first;
    if (temp == nullptr) {
        cout << "Queue is empty" << endl;
    }
    else {
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    Queue GeneratedQueue{};
    while (true) {
        cout << "Enter number for:" << endl;
        cout << "1. adding an item to the queue" << endl << "2. retrieving an item from the queue" << endl;
        cout << "3. item count output" << endl << "4. inserts before each negative element of the unit" << endl;
        cout << "5. removing all negative elements from the queue " << endl << "6. counting the amount of an element" << endl;
        cout << "7. deleting all items from the queue" << endl << "8. queue output to the console" << endl;
        cout << "9. program termination" << endl;
        int numb, number, data;
        cin >> numb;
        switch (numb) {
        case 1:
            cout << "   Enter numbers. Enter 0 to end the input" << endl;
            while (true) {
                cin >> data;
                if (data == 0) {
                    break;
                }
                GeneratedQueue.queue(data);
            }
            break;
        case 2:
            GeneratedQueue.unqueue();
            break;
        case 3:
            
            cout << "Number of items in the queue: " << endl;
            cout << GeneratedQueue.count() << endl;
            break;
        case 4:
            GeneratedQueue.insertBeforeNegative();
            break;
        case 5:
            GeneratedQueue.removeNegative();
            break;
        case 6:
            cout << "What number in the queue you want to count?" << endl;
            cin >> number;
            cout << GeneratedQueue.count(number) << endl;
            break;
        case 7:
            GeneratedQueue.clear();
            cout << "Queue is empty." << endl;
            break;
        case 8:
            printQueue(GeneratedQueue);
            break;
        case 9:
            return 0;
        default:
            cout << "Error! Enter the correct command number!";
            break;
        }
    }
}