// MDP.cpp

#include "MDP.h"

template<typename S, typename A>
MDP<S, A>::MDP(int num_states, int num_actions,
               S* states, A* actions,
               S(*reset_func)(int, S*),
               int(*possible_action_func)(S, A*&),
               void(*environment_func)(S, A, double&, S&),
               bool(*is_terminal_func)(S, int))
    : num_states(num_states), num_actions(num_actions),
      states(states), actions(actions),
      reset_func(reset_func),
      possible_action_func(possible_action_func),
      environment_func(environment_func),
      is_terminal_func(is_terminal_func) {
}

template<typename S, typename A>
MDP<S, A>::~MDP() {
    delete[] states;
    delete[] actions;
}

template<typename S, typename A>
MDP<S, A>::MDP(const MDP<S, A>& other)
    : num_states(other.num_states), num_actions(other.num_actions),
      states(new S[num_states]), actions(new A[num_actions]),
      reset_func(other.reset_func),
      possible_action_func(other.possible_action_func),
      environment_func(other.environment_func),
      is_terminal_func(other.is_terminal_func) {
    for (int i = 0; i < num_states; ++i)
        states[i] = other.states[i];
    for (int i = 0; i < num_actions; ++i)
        actions[i] = other.actions[i];
}

template<typename S, typename A>
MDP<S, A>& MDP<S, A>::operator=(const MDP<S, A>& other) {
    if (this != &other) {
        num_states = other.num_states;
        num_actions = other.num_actions;
        delete[] states;
        delete[] actions;
        states = new S[num_states];
        actions = new A[num_actions];
        reset_func = other.reset_func;
        possible_action_func = other.possible_action_func;
        environment_func = other.environment_func;
        is_terminal_func = other.is_terminal_func;
        for (int i = 0; i < num_states; ++i)
            states[i] = other.states[i];
        for (int i = 0; i < num_actions; ++i)
            actions[i] = other.actions[i];
    }
    return *this;
}

template<typename S, typename A>
int MDP<S, A>::GetNumStates() const {
    return num_states;
}

template<typename S, typename A>
int MDP<S, A>::GetNumActions() const {
    return num_actions;
}

template<typename S, typename A>
S& MDP<S, A>::operator[](int index) {
    return states[index];
}

template<typename S, typename A>
A& MDP<S, A>::operator()(int index) {
    return actions[index];
}
