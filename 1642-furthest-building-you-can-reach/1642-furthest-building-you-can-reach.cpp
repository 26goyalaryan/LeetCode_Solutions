class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        // the whole intution is to use bricks first\
        // if bricks went in negative, then we will use ladder
        // and we will place ladder wherever the difference is largest
        // also after placing the ladder, we are getting some bricks back
        
        priority_queue<int,vector<int>> pq;
        
        int i;
        
        for(i=0;i<h.size()-1;i++){
            
            int diff=h[i+1]-h[i];
            
            // next building is greater than previous once
            
            if(diff>0){
                bricks-=diff;
                
                // pushing the difference in case we need to use the ladder
                pq.push(diff);
                
                // no sufficient bricks are left ---> we have to use a ladder
                
                if(bricks<0){
                    
                    // we will stop when both bricks and ladder are in negative
                    
                    if(ladders<=0)
                        return i;
                    
                    int getbricks = pq.top();
                    bricks+=getbricks;
                    
                    // we are using a ladder
                    ladders--;
                    
                    pq.pop(); // since we placed ladder at the largest difference
                }
            }
        }
        
        return i;
    }
};