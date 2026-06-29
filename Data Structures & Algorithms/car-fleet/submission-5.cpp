class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    map<int, int, greater<int>> posSpeed;
    for (int i = 0; i < position.size(); i++)
        posSpeed[position[i]] = speed[i];

    stack<float> st;

    for (auto [pos, spd] : posSpeed) {
        float time = (float)(target - pos) / spd;
        // Only forms a new fleet if it can't catch the one ahead
        if (st.empty() || time > st.top())
            st.push(time);
        // else: merges into the fleet ahead, don't push
    }

    return st.size();
}
};
