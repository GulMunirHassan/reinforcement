// CDMPerfect.h

#pragma once
#include "MDP.h" // Include the MDP header file

template<typename S, typename A>
class CDMPerfect : public MDP<S, A> {
private:
    double** transition_probabilities;
    double** rewards;
    int FindIndex(int state_index, int action_index);

public:
    CDMPerfect(int num_states, int num_actions,
               S* states, A* actions,
               double** transition_probabilities,
               double** rewards,
               S(*reset_func)(int, S*),
               int(*possible_action_func)(S, A*&),
               void(*environment_func)(S, A, double&, S&),
               bool(*is_terminal_func)(S, int));
    ~CDMPerfect();
    CDMPerfect(const CDMPerfect<S, A>& other);
    CDMPerfect<S, A>& operator=(const CDMPerfect<S, A>& other);
    double GetTransitionProbability(int state_index, int action_index, int next_state_index);
    double GetReward(int state_index, int action_index, int next_state_index);
    void SetTransitionProbability(int state_index, int action_index, int next_state_index, double probability);
    void SetReward(int state_index, int action_index, int next_state_index, double reward);
};
