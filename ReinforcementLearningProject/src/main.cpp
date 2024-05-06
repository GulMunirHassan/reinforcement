// main.cpp

#include <iostream>
#include "MDP.h" // Include the MDP header file

// Sample functions for MDP reset, possible actions, environment, and is terminal
int ResetFunction(int state_index, int* states) {
    return states[state_index];
}

int PossibleActionFunction(int state, int*& actions) {
    actions = new int[3];
    actions[0] = 0; // Action 0
    actions[1] = 1; // Action 1
    actions[2] = 2; // Action 2
    return 3; // Number of possible actions
}

void EnvironmentFunction(int state, int action, double& reward, int& next_state) {
    // Sample environment function
    // You can define your own logic here
    reward = 1.0; // Sample reward
    next_state = state + action; // Sample next state
}

bool IsTerminalFunction(int state, int n) {
    // Sample terminal condition
    return state >= n;
}

int main() {
    // Sample states and actions
    int states[2] = {0, 1};
    int actions[3] = {0, 1, 2};

    // Instantiate MDP object
    MDP<int, int> mdp(2, 3, states, actions,
                      ResetFunction,
                      PossibleActionFunction,
                      EnvironmentFunction,
                      IsTerminalFunction);

    // Test MDP functionality
    std::cout << "Number of states: " << mdp.GetNumStates() << std::endl;
    std::cout << "Number of actions: " << mdp.GetNumActions() << std::endl;

    // Accessing states and actions using [] and () operators
    std::cout << "State at index 0: " << mdp[0] << std::endl;
    std::cout << "Action at index 1: " << mdp(1) << std::endl;

    // Accessing states and actions using loop
    for (int i = 0; i < mdp.GetNumStates(); ++i) {
        std::cout << "State at index " << i << ": " << mdp[i] << std::endl;
    }
    for (int i = 0; i < mdp.GetNumActions(); ++i) {
        std::cout << "Action at index " << i << ": " << mdp(i) << std::endl;
    }

    // Testing reset function
    int reset_state = mdp.Reset(0);
    std::cout << "Reset state: " << reset_state << std::endl;

    // Testing possible action function
    int* possible_actions;
    int num_possible_actions = mdp.PossibleActions(0, possible_actions);
    std::cout << "Number of possible actions at state 0: " << num_possible_actions << std::endl;
    std::cout << "Possible actions at state 0: ";
    for (int i = 0; i < num_possible_actions; ++i) {
        std::cout << possible_actions[i] << " ";
    }
    std::cout << std::endl;
    delete[] possible_actions;

    // Testing environment function
    double reward;
    int next_state;
    mdp.Environment(0, 1, reward, next_state);
    std::cout << "Reward after taking action 1 from state 0: " << reward << std::endl;
    std::cout << "Next state after taking action 1 from state 0: " << next_state << std::endl;

    // Testing is terminal function
    bool terminal = mdp.IsTerminal(2, 5); // Assuming terminal state is 5
    std::cout << "Is state 2 terminal? " << (terminal ? "Yes" : "No") << std::endl;

    return 0;
}
