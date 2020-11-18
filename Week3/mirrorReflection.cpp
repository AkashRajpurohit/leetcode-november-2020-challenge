// Ref: https://www.youtube.com/watch?v=_xIBOUWEq1c

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int reflection = p, extension = q;
        
        while(reflection % 2 == 0 && extension % 2 == 0) {
            reflection /= 2;
            extension /= 2;
        }
        
        if(extension % 2 == 0 && reflection % 2 == 1) return 0;
        if(extension % 2 == 1 && reflection % 2 == 0) return 2;
        if(extension % 2 == 1 && reflection % 2 == 1) return 1;
        
        return -1;
    }
};