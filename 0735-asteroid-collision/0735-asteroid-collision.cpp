class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int i=0;
        while(i<asteroids.size())
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
                i++;
            }
            else
            {
                if((asteroids[i]>0 && st.top()>0) || (asteroids[i]<0 && st.top()<0) || (asteroids[i]>0 && st.top()<0))
                {
                    st.push(asteroids[i]);
                    i++;
                }
                else if(asteroids[i]<0 && st.top()>0) //collision
                {
                    int val = st.top();//2
                    st.pop();
                    if(val == abs(asteroids[i]))
                    {
                        i++;
                    }
                    else if(abs(asteroids[i])<val)
                    {
                        st.push(val);
                        i++;
                    }
                    else if(abs(asteroids[i])>val)
                    {
                        continue;
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};