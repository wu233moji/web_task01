#include<iostream>
using namespace std;
const int TABLE_SIZE = 128;
 

class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};
 

class HashMap
{
    private:
        HashEntry **table;
    public:   
        HashMap()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        
        
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
      
      
	void Insert(int key, int value)
	{
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
      
      
        int Search(int key)
	{
	    int  hash = HashFunc(key);
	    while (table[hash] != NULL && table[hash]->key != key)
	    {
	        hash = HashFunc(hash + 1);
	    }
	    if (table[hash] == NULL)
	        return -1;
	    else
	        return table[hash]->value;
        }
 

        void Remove(int key)
	{
	    int hash = HashFunc(key);
	    while (table[hash] != NULL)
	    {
	        if (table[hash]->key == key)
	            break;
	        hash = HashFunc(hash + 1);
	    }
            if (table[hash] == NULL)
	    {
                cout<<"没有找到关键值"<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"元素"<<endl;
        }
        ~HashMap()
	{
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};

int main()
{
    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"哈希表的各项操作命令："<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.插入元素到表中"<<endl;
        cout<<"2.按关键值寻找元素"<<endl;
        cout<<"3.删除关键值"<<endl;
        cout<<"4.退出"<<endl;
        cout<<"请选择: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"输入要插入的元素: ";
            cin>>value;
            cout<<"输入元素插入的关键值: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"输入要寻找元素对应的关键值: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
	        cout<<"没有找到关键值"<<key<<endl;
	        continue;
	    }
	    else
	    {
	        cout<<"元素于关键值"<<key<<"是"<<" : ";
	        cout<<hash.Search(key)<<endl;
	    }
            break;
        case 3:
            cout<<"输入要删除的关键值: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"\n请输入正确的命令\n";
       }
    }
    return 0;
}
