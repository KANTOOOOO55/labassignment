# labassignment
Simulations of a hospital queue management system that processes and tracks patients based on their urgency and arrival time are built into this program. The time struct is used to handle time-related operations. The Patient class stores ID, gender type (urgent or normal), and arrival time details. Random or manually added patients are generated and put in the ready queue, according to their arrival time, and moved to an urgent queue when a simulation time is equal to their arrival time, or in a normal queue or back to the ready queue. We use these queues to manage them with the QueueSys class, serving patients first based on priority and logging in the completed cases. To keep functionality robust we incorporate exception handling for empty queues. The simulation progresses minute by minute, shows the current state of queues at a given moment, and ends at midnight to provide insights into the queue operations and patient flow.
Code Output : 

Choose a scenario (S: Simple, M: Moderate, C: Crowded): 

-	This is for the user to choose the scenario 


If the user chose simple : 

100 patients generated.
Current Time:08:00
Current State:  
Waiting Urgent Patient IDs: 
285043343240 
285056246371 
285035255879 
285011465516 
285021634994 
285052871934 
285028316762 
Total number of Urgent Patients is : 7

Waiting Normal Patient IDs: 
285073574254
285079154772
285087441199
285036830220
285025663203
285054305589
285040594377
285055187343
285097061858
285054199270
285098907004
285040283610
285014888615
285015821722
285092433117
285060449785
285019242583
285039612790
Total number of Normal Patients is : 18

In-Service Patient: 
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
ID: 285053036968, Gender: M, Arrival Time: 06:19, Type: Urgent
Total number of In Service Patients is : 9
Done Patient IDs: 
285096569422
285031744364
285067395343
285058447023
285070627541
285075150316
285021569821
Total number of Done Patients is : 7

Average Waiting Time: 171.75 minutes.
Press Enter to advance 1 minute...


The code simulates a hospital queue system where patients are categorized as "Urgent" or "Normal" based on their condition and processed accordingly. The output represents the current state of the simulation. At the given time (08:00 AM), 100 patients have been generated, and their IDs are displayed in separate queues for "Urgent" and "Normal" patients. The number of patients in each queue is shown, along with details of the patient currently being served ("In-Service Patient"). Additionally, IDs of patients already processed ("Done Patients") are listed, and the system calculates the average waiting time for all served patients. This output reflects the dynamic state of the queues and patient processing as the simulation progresses minute by minute.



The code models a queuing system in a hospital where patients are given an urgency level and status of either “Urgent” or “Normal” and are attended to in that order. The output is an intermediate state of the simulation. At exactly the given time (08:00 AM), there are 100 patients created and their ID's are now shown separately for queues of “Urgent” and “Normal” patients.The number of patients in each queue is shown, along with details of the patient currently being served “In-Service Patient". More to this is the list of patients that have already been treated, or more correctly state such patients referred as “Done Patients” and the mean waiting time for every treated patient was issued by the system for all patients. This output demonstrates the queues queuing and the treatment of patients as served during the simulation which takes place hour by hour
