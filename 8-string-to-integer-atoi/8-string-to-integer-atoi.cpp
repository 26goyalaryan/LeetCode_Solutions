class Solution {
public:
    int myAtoi(string str){ 
        int i=0;
        while(str[i]==' ')
                i++;
        long result = 0;
        int flag = 1;
        if(str[i] == '-' || str[i] == '+'){
                flag = (str[i] == '-')? -1 : 1;
                i++;
            }
        while(i<str.size()){
            while('0'<= str[i] && str[i] <= '9') 
            {
                result = result*10 + (str[i]-'0');
                i++;
                if(result*flag >= INT_MAX) 
                    return INT_MAX;
                if(result*flag <= INT_MIN) 
                    return INT_MIN;                
            }
            break;
        }
        return result*flag;
    }
};