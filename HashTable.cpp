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
                cout<<"û���ҵ��ؼ�ֵ"<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Ԫ��"<<endl;
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
        cout<<"��ϣ��ĸ���������"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.����Ԫ�ص�����"<<endl;
        cout<<"2.���ؼ�ֵѰ��Ԫ��"<<endl;
        cout<<"3.ɾ���ؼ�ֵ"<<endl;
        cout<<"4.�˳�"<<endl;
        cout<<"��ѡ��: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"����Ҫ�����Ԫ��: ";
            cin>>value;
            cout<<"����Ԫ�ز���Ĺؼ�ֵ: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"����ҪѰ��Ԫ�ض�Ӧ�Ĺؼ�ֵ: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
	        cout<<"û���ҵ��ؼ�ֵ"<<key<<endl;
	        continue;
	    }
	    else
	    {
	        cout<<"Ԫ���ڹؼ�ֵ"<<key<<"��"<<" : ";
	        cout<<hash.Search(key)<<endl;
	    }
            break;
        case 3:
            cout<<"����Ҫɾ���Ĺؼ�ֵ: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"\n��������ȷ������\n";
       }
    }
    return 0;
}
