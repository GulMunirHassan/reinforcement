// CDMPerfect.cpp

#include "CDMPerfect.h"

template<typename S, typename A>
CDMPerfect<S, A>::CDMPerfect(int num_states, int num_actions,
                             S* states, A* actions,
                             double** transition_probabilities,
                             double** rewards,
                             S(*reset_func)(int, S*),
                             int(*possible_action_func)(S, A*&),
                             void(*environment_func)(S, A, double&, S&),
                             bool(*is_terminal_func)(S, int))
    : MDP<S, A>(num_states, num_actions, states, actions, reset_func,
                possible_action_func, environment_func, is_terminal_func),
      transition_probabilities(transition_probabilities),
      rewards(rewards) {
}

template<typename S, typename A>
CDMPerfect<S, A>::~CDMPerfect() {
    for (int i = 0; i < this->GetNumStates(); ++i) {
        delete[] transition_probabilities[i];
        delete[] rewards[i];
    }
    delete[] transition_probabilities;
    delete[] rewards;
}

template<typename S, typename A>
CDMPerfect<S, A>::CDMPerfect(const CDMPerfect<S, A>& other)
    : MDP<S, A>(other) {
    // Deep copy transition probabilities and rewards
    transition_probabilities = new double*[this->GetNumStates()];
    rewards = new double*[this->GetNumStates()];
    for (int i = 0; i < this->GetNumStates(); ++i) {
        transition_probabilities[i] = new double[this->GetNumStates()];
        rewards[i] = new double[this->GetNumStates()];
        for (int j = 0; j < this->GetNumStates(); ++j) {
            transition_probabilities[i][j] = other.transition_probabilities[i][j];
            rewards[i][j] = other.rewards[i][j];
        }
    }
}

template<typename S, typename A>
CDMPerfect<S, A>& CDMPerfect<S, A>::operator=(const CDMPerfect<S, A>& other) {
    if (this != &other) {
        MDP<S, A>::operator=(other);
        // Delete existing transition probabilities and rewards
        for (int i = 0; i < this->GetNumStates(); ++i) {
            delete[] transition_probabilities[i];
            delete[] rewards[i];
        }
        delete[] transition_probabilities;
        delete[] rewards;
        // Deep copy transition probabilities and rewards
        transition_probabilities = new double*[this->GetNumStates()];
        rewards = new double*[this->GetNumStates()];
        for (int i = 0; i < this->GetNumStates(); ++i) {
            transition_probabilities[i] = new double[this->GetNumStates()];
            rewards[i] = new double[this->GetNumStates()];
            for (int j = 0; j < this->GetNumStates(); ++j) {
                transition_probabilities[i][j] = other.transition_probabilities[i][j];
                rewards[i][j] = other.rewards[i][j];
            }
        }
    }
    return *this;
}

template<typename S, typename A>
int CDMPerfect<S, A>::FindIndex(int state_index, int action_index) {
    // Implement your logic to find the index
}

template<typename S, typename A>
double CDMPerfect<S, A>::GetTransitionProbability(int state_index, int action_index, int next_state_index) {
    return transition_probabilities[state_index][next_state_index];
}

template<typename S, typename A>
double CDMPerfect<S, A>::GetReward(int state_index, int action_index, int next_state_index) {
    return rewards[state_index][next_state_index];
}

template<typename S, typename A>
void CDMPerfect<S, A>::SetTransitionProbability(int state_index, int action_index, int next_state_index, double probability) {
    transition_probabilities[state_index][next_state_index] = probability;
}

template<typename S, typename A>
void CDMPerfect<S, A>::SetReward(int state_index, int action_index, int next_state_index, double reward) {
    rewards[state_index][next_state_index] = reward;
}
