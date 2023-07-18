Electronic Voting Simulation
The Republic of Banana is planning to upgrade its voting process by introducing electronic voting stations for the upcoming presidential election. However, the election committee intends to test the new electronic voting system with a simulator before implementing it in
the actual elections.

1. In main.cpp we have multiple threads, including voter threads, a polling station thread, and a maintenance thread. Every individual element has a distinct role in replicating the operations of a polling station.The main function initializes the simulation parameters, creates the necessary threads, and runs the simulation for a specified duration (total_simulation_time set to 30 seconds in the provided code) using the pthread_sleep function.
2. In sleep.cpp, we can see an alternative implementation of the pthread_sleep function which uses a combination of mutex, condition variable, and a timeout mechanism to achieve the sleep functionality.

