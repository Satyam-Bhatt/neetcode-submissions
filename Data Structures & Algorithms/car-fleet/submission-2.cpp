class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::map<int,int,std::greater<int>> positionSpeed;
        stack<int> max;

        for(int i = 0; i < position.size(); i++)
        {
            positionSpeed[position[i]] = speed[i];
        }

        for(auto[k,h] : positionSpeed)
        {
            if(max.empty())
            {
                max.push(k);
            }
            else
            {
                int pos = max.top();
                int speed = positionSpeed[pos];

                float timeTop = (float)(target - pos)/speed;
                float timeCurrent = (float)(target - k)/h;

                if(timeCurrent <= timeTop)
                {
                    positionSpeed.erase(k);
                }
                else
                {
                    max.push(k);
                }
            }
        }

        return max.size();
    }
};
