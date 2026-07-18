class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
            string s=details[i];
            string s1="";
            s1+=s[11];
            s1+=s[12];
            int age=stoi(s1);
            if(age>60)
            count++;
        }
        return count;
    }
};