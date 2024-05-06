// MDP.h

#pragma once

template<typename S, typename A>
class MDP {
private:
    int num_states;
    int num_actions;
    S* states;
    A* actions;
    S(*reset_func)(int, S*);
    int(*possible_action_func)(S, A*&);
    void(*environment_func)(S, A, double&, S&);
    bool(*is_terminal_func)(S, int);

public:
    MDP(int num_states, int num_actions,
        S* states, A* actions,
        S(*reset_func)(int, S*),
        int(*possible_action_func)(S, A*&),
        void(*environment_func)(S, A, double&, S&),
        bool(*is_terminal_func)(S, int));
    ~MDP();
    MDP(const MDP<S, A>& other);
    MDP& operator=(const MDP<S, A>& other);
    int GetNumStates() const;
    int GetNumActions() const;
    S& operator[](int index);
    A& operator()(int index);
};
