bool backtrack(parameters) {
    if (base case condition) return true;

    for (all possible choices) {
        if (is_valid(choice)) {
            make_choice();
            if (backtrack(next_state)) return true; // Recurse
            undo_choice(); // Backtrack
        }
    }
    return false; // No valid choice found
}
