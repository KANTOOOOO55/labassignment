# labassignment
Simulations of a hospital queue management system that processes and tracks patients based on their urgency and arrival time are built into this program. The time struct is used to handle time-related operations. The Patient class stores ID, gender type (urgent or normal), and arrival time details. Random or manually added patients are generated and put in the ready queue, according to their arrival time, and moved to an urgent queue when a simulation time is equal to their arrival time, or in a normal queue or back to the ready queue. We use these queues to manage them with the QueueSys class, serving patients first based on priority and logging in the completed cases. To keep functionality robust we incorporate exception handling for empty queues. The simulation progresses minute by minute, shows the current state of queues at a given moment, and ends at midnight to provide insights into the queue operations and patient flow.
