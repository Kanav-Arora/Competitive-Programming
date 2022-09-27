// EASY

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int energyneed = 0;
        int expneed = 0;
        
        for(int i=0; i<energy.size(); i++)
        {
            if(initialEnergy<=energy[i])
            {
                energyneed+=(energy[i]+1-initialEnergy);
                initialEnergy = 1;
            }
            else
            {
                initialEnergy-=energy[i];
            }
            
            if(initialExperience<=experience[i])
            {
                expneed+=(experience[i]+1-initialExperience);
                initialExperience = experience[i]+1 + experience[i];
            }
            else
            {
                initialExperience+=experience[i];
            }
            
            cout<<initialEnergy<<" "<<initialExperience<<endl;
        }
        
        return energyneed+expneed;
    }
};