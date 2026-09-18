class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1)
            return false;
        
        int n= s.length(); 
        stack<int>Space;
        Space.push(s[0]);
       
        for(int i=1; i<n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                Space.push(s[i]);
            else{
                if(s[i] == ')'){
                    if(Space.empty())
                        return false;
                    else if(Space.top() == '('){
                        Space.pop();
                    }
                    else{
                        return false;
                    }
                }

                else if(s[i] == ']'){
                    if(Space.empty())
                        return false;
                    else if(Space.top()== '['){
                        Space.pop();
                    }
                    else{
                        return false;
                    }
                }

                else if(s[i] == '}'){
                    if(Space.empty())
                        return false;
                    else if(Space.top() == '{'){
                        Space.pop();
                    }
                    else{
                        return false;
                    }
                }
            }   
        }

       return Space.empty(); 
    }
};