#include<stdio.h>

#define size 7
#define PRIME 7

int arr[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

int h1(int value) {
  return (value % size);
}

int h2(int value) {
  return (PRIME - (value % PRIME));
}

void insert(int value)
{
    int key = h1(value);

    if(arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {
        int key2 = h2(value);
        int i;
        for(i=1;i<size;i++){
             int newkey = (key + i * key2) % size;
             if(arr[newkey] == -1){
                arr[newkey]=value;
                break;
             }
        }
        if(i == size)
        printf("\nelement cannot be inserted\n");
    }
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)
    insert(17);  //key = 17 % 7  ==> 3 (collision)
    insert(24);  //key = 24 % 7  ==> 3 (collision)
    insert(31);  //key = 31 % 7  ==> 3 (collision)
    insert(38);  //key = 38 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

#define TABLE_SIZE 7
#define PRIME 7

vector < int > hash_table(TABLE_SIZE, -1);
int size = 0;

int h1(int key) {
  return (key % TABLE_SIZE);
}

int h2(int key) {
  return (PRIME - (key % PRIME));
}

void insert(int key) {
  if (size == TABLE_SIZE)
    return;

  int idx = h1(key);

  if (hash_table[idx] != -1) {
    int idx2 = h2(key);
    int i = 1;
    while (1) {
      int newidx = (idx + i * idx2) % TABLE_SIZE;

      if (hash_table[newidx] == -1) {
        hash_table[newidx] = key;
        break;
      }
      i++;
    }
  } else
    hash_table[idx] = key;
  size++;
}

void display() {
  cout << "Hash Table" << endl;
  for (int i = 0; i < TABLE_SIZE; i++)
    if (hash_table[i] != -1)
      cout << i << " --> " << hash_table[i] << endl;
    else
      cout << i << " --> ∅" << endl;
}

int main() {
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    insert(x);
  }

  display();
  return 0;
}
*/
