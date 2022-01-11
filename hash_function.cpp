

#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int data);

    int checkPrime(int n)
    {
        
        if (n == 1 || n == 0)
        {
            return 0;
        }
      
        return 1;
    }
    int getPrime(int n)
    {
            n++;
        while (!checkPrime(n))
        {
            n += 1;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity);
    }
    void displayHash();
};
HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}
void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    std::cout << index << std::endl;
    while (true) {
        if (!table[index].empty()) {
            index = (index++) % capacity;
        }
        else {
            table[index].push_back(data);
            break;
        }
    }
}

void HashTable::deleteItem(int data)
{
  
    for (int i = 0;i < capacity;++i) {
        for (list<int>::iterator it = table[i].begin();it != table[i].end();) {

            if (*it == data) {
           it=   table[i].erase(it);
        }
            else { it++; }
        }
     }
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity-1; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int key[] = { 231, 321, 212, 321, 433, 262,22,345,678 ,55};
    int data[] = { 123, 123, 523, 43, 423, 111,456,76,89,987};
    int size = sizeof(key) / sizeof(key[0]);

    HashTable h(size);
  
    for (int i = 0; i < size; i++)
        h.insertItem(key[i], data[i]);
    h.deleteItem(456);
   h.displayHash();


  
}