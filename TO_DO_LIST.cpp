#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Tasks{

    public:
    
    string description;
    bool complete;

    Tasks(const string& desc) : description(desc), complete(false) {}
};

class TO_DO_LIST
{

private:
vector<Tasks> task;

public:

  void Add_Task(const string &desc)
  {
    task.push_back(Tasks(desc));
    cout<<desc<<" is added to list."<<endl;
  }

  void View_Task() const{
    if(task.empty())
    {
        cout<<"No, task is listed"<<endl;
    }
    else
    {
        for(size_t i=0 ; i<task.size() ; i++)
        {
            cout<<i+1<<". "<<task[i].description<<"."<<(task[i].complete ? "[complete]" : "[Pending]")<<endl;
        }
    }
  }

  void Remove_Task(size_t index)
  {
    if(index>=1 && index<=task.size())
    {
        task.erase(task.begin() + index - 1);
        cout<<"Task "<<index<<" removed"<<endl;;
    }
    else
    {
        cout<<"Invalid task index"<<endl;
    }
  }

  void Complete_Task(size_t index)
  {
    if(index>=1 && index<=task.size())
    {
        task[index-1].complete = true;

        cout<<"Task "<<index<<" mark as completed"<<endl;
    }
    else
    {
        cout<<"Invalid task index"<<endl;
    }
  }

  bool isEmpty()
  {
    return task.empty();
  }
 
};

int main(){
    
    TO_DO_LIST todolist;
    string description;

    int choice;

    do{

        cout<<"-------------------TO-DO-LIST MANAGER--------------------"<<endl;
        cout<<"1. Add the Task"<<endl;
        cout<<"2. View the Task"<<endl;
        cout<<"3. Remove the Task"<<endl;
        cout<<"4. Mark Task as Complete"<<endl;
        cout<<"5. Exit List"<<endl;
        
        cout<<"Enter the number: ";
        cin>>choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout<<"Enter the description: ";
            getline(cin , description);
            todolist.Add_Task(description);
            break;
        case 2:
            todolist.View_Task();
            break;
        case 3:
            todolist.View_Task();
            if(!todolist.isEmpty())
            {
                cout<<"Enter the task number to be remove: ";
                size_t remove_idx;
                cin>>remove_idx;
                todolist.Remove_Task(remove_idx);
            }
            break;
        case 4:
            todolist.View_Task();
            if(!todolist.isEmpty())
            {
                cout<<"Enter the task number to mark as completed: ";
                size_t complete_idx;
                cin>>complete_idx;
                todolist.Complete_Task(complete_idx);
            }
            break;
        case 5:
            cout<<"Exit Program"<<endl;
            break;
        
        default:
            
            cout<<"Invalid number. Please try again."<<endl;
            break;
        }
    }while(choice!=5);

    return 0;
}