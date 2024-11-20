#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <exception>
using namespace std;

struct timee 
{
    int hour;
    int minutes;
    int toMinutes() const 
    {
        return hour*60+minutes;
    }

    void printTime() const 
    {
    if (hour<10) 
    {
        cout<<"0";
    }
    cout<<hour<<":";

    if (minutes<10) 
    {
        cout<<"0";
    }
    cout<<minutes;
}

};

class EmptyQueueExeption:public exception{
    
};

class Patient 
{
    string id;
    char gender;
    string type;
    timee Time;

public:
    Patient(string i, char g, string t, int h, int m) 
    {
    id = i;
    gender = g;
    type = t;
    Time.hour = h;
    Time.minutes = m;
    }


    void printDetails() const 
    {
        cout <<"ID: " <<id<<", Gender: "<<gender<<", Arrival Time: ";
        Time.printTime();
        cout<<", Type: "<< type<<endl;
    }

    int getArrivalTimeInMinutes() const 
    {
        return Time.toMinutes();
    }

    string getType() const 
    {
        return type;
    }

    string getID() const 
    {
        return id;
    }
};

class QueueSys {
    queue<Patient> urgentQueue;
    queue<Patient> normalQueue;
    vector<Patient> patientList;
    vector<string> donePatients;
    Patient* inService = nullptr;

public:
    void addUserPatient(const Patient& userPatient) 
    {
        patientList.push_back(userPatient);
    }

    void generatePatients(int count) 
    {
        for (int i = 0; i < count; i++) 
        {
            string id = "2850" + to_string(rand() % 90000000 + 10000000);
            char gender = (rand() % 2 == 0) ? 'M' : 'F';
            string type = (rand() % 2 == 0) ? "Urgent" : "Normal";
            int hour = rand() % 24;
            int minutes = rand() % 60;
           try{ 
               
               patientList.emplace_back(id, gender, type, hour, minutes);
               
           }
           catch(const bad_alloc& e){
               cout<<"Queue is full now"<<endl;
               
           }
        }
    }

    void transferToQueues(int currentMinutes) 
    {
        for (auto it=patientList.begin();it!=patientList.end();) 
        {
            if (it->getArrivalTimeInMinutes()<=currentMinutes) 
            {
                if (it->getType()=="Urgent")
                    urgentQueue.push(*it);
                else
                    normalQueue.push(*it);
                it = patientList.erase(it);
            } else 
            {
                ++it;
            }
        }
    }

void servePatients(int N) {
        int served = 0;

        while (served < N) {
            
            if (!urgentQueue.empty()) {
                if (inService) {
                    donePatients.push_back(inService->getID());
                    delete inService;
                }

                inService = new Patient(urgentQueue.front());
                try{
                if(urgentQueue.empty()){throw EmptyQueueExeption();}
                }catch(const EmptyQueueExeption& e){
                    cout<<"No Urgent Patients "<<endl;
                    
                }
                urgentQueue.pop();
                served++;
            } else if (!normalQueue.empty()) {
                if (inService) {
                    donePatients.push_back(inService->getID());
                    delete inService;
                }

                inService = new Patient(normalQueue.front());
                try{if(normalQueue.empty()){throw EmptyQueueExeption();}}
                
                catch(const EmptyQueueExeption& e){
                    cout<<"No Normal Patients "<<endl;
                    
                }
                normalQueue.pop();
                served++;
            } else {
                break;
            }
        }

        if (served == 0 && inService) {
            donePatients.push_back(inService->getID());
            delete inService;
            inService = nullptr;
        }
    }
    void displayState() const 
    {
        int N = rand()%6+5;
        cout << "Current State:  " << endl;

        cout << "Waiting Urgent Patient IDs: "<<endl;
        queue<Patient> tempUrgent = urgentQueue;
        
        while (!tempUrgent.empty()) 
        {
            try{if(tempUrgent.empty()){throw EmptyQueueExeption();}}
            catch(const EmptyQueueExeption& e){
                    cout<<"No Urgent Patients to Display "<<endl;
                    
                }
            
            cout<<tempUrgent.front().getID()<<" ";
            tempUrgent.pop();
            cout<<endl;
         
        }
        cout<< "Total number of Urgent Patients is : "<<urgentQueue.size()<<endl;
        cout<<endl;

        cout<<"Waiting Normal Patient IDs: "<<endl;
        queue<Patient> tempNormal = normalQueue;
        
        while (!tempNormal.empty()) 
        {
            try{if(tempNormal.empty()){throw EmptyQueueExeption();}}
             catch(const EmptyQueueExeption& e){
                    cout<<"No Normal Patients to Display "<<endl;
                    
                }
            cout<<tempNormal.front().getID()<<endl;
            tempNormal.pop();
        }
        cout<< "Total number of Normal Patients is : "<<normalQueue.size()<<endl;
        cout<<endl;

        if (inService) 
        {
            cout<<"In-Service Patient: "<<endl;
            for(int i=0; i<N; i++){
            inService->printDetails();
            }
            cout<<"Total number of In Service Patients is : "<<N<<endl;
        } else 
        {
            cout<<"In-Service Patient: None"<< endl;
        }

        cout<<"Done Patient IDs: "<<endl;
        int counter =0;
        for (const string& id : donePatients) 
        {
            cout<<id<<endl;
            counter++;
        }
         cout<< "Total number of Done Patients is : "<<counter<<endl;
        cout <<endl;
    }
};

int main() 
{
    srand(time(0));
    QueueSys queueSystem;

    char scenario;
    cout<<"Choose a scenario (S: Simple, M: Moderate, C: Crowded): ";
    cin>>scenario;

    int patientCount;
    switch (scenario) 
    {
        case 'S':
        case 's':
            patientCount = 100;
            break;
        case 'M':
        case 'm':
            patientCount = 300;
            break;
        case 'C':
        case 'c':
            patientCount = 700;
            break;
        default:
            cout << "Invalid scenario selected. Defaulting to Simple (100 patients)."<<endl;
            patientCount = 100;
    }

    queueSystem.generatePatients(patientCount);
    cout<<patientCount<<" patients generated."<<endl;

    

    int currentMinutes =8*60; // initial time is  at 8:00 AM
    cin.ignore();

    while (currentMinutes<24*60) 
    {
        cout <<"Current Time:";
        timee{currentMinutes/60,currentMinutes%60}.printTime();
        cout << endl;

        queueSystem.transferToQueues(currentMinutes);

        int N = rand()%6+5; // generating random  number between 5 and 10
        queueSystem.servePatients(N);

        queueSystem.displayState();

        cout << "Press Enter to advance 1 minute...";
        cin.get();

        currentMinutes++;
    }



    cout << "Simulation ended at midnight." << endl;
    return 0;
}
