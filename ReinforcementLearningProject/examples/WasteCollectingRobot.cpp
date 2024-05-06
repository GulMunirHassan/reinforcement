// WasteCollectingRobot.cpp

#include <iostream>
#include "CDMPerfect.h"

int main() {
    // Sample states and actions
    int states[2] = {0, 1};
    int actions[3] = {0, 1, 2};

    // Sample transition probabilities
    double** transition_probabilities = new double*[2];
    transition_probabilities[0] = new double[2]{0.9, 0.1};
    transition_probabilities[1] = new double[2]{0.1, 0.9};

    // Sample rewards
    double** rewards = new double*[2];
    rewards[0] = new double[2]{2, -3};
    rewards[1] = new double[2]{1, 0};

    // Instantiate CDMPerfect object
    CDMPerfect<int, int> robot(2, 3, states, actions,
                               transition_probabilities, rewards,
                               nullptr, nullptr, nullptr, nullptr);

    // Example usage
    std::cout << "Transition probability from state 0 to state 1 with action 0: "
              << robot.GetTransitionProbability(0, 0, 1) << std::endl;
    std::cout << "Reward from state 1 to state 0 with action 1: "
              << robot.GetReward(1, 1, 0) << std::endl;

    // Cleanup
    for (int i = 0; i < 2; ++i) {
        delete[] transition_probabilities[i];
        delete[] rewards[i];
    }
    delete[] transition_probabilities;
    delete[] rewards;

    return 0;
}
