class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones ={a,b,c};
        sort(stones.begin(), stones.end());
        int x = stones[0], y = stones[1], z = stones[2];
        //Calculate max moves(moving 1 step at a time)
        int max_moves=0;
        int curr_x =x, curr_y =y,curr_z=z;
        while((curr_z-curr_x)>2){
            if((curr_y-curr_x)>=(curr_z-curr_y)){
                curr_x++;
            } else{
                curr_z--;
            }
            max_moves++;
        }
        //calculate Minimum Moves
        int min_moves;
        if(x+1==y && y+1==z){
            min_moves=0;
        }else if((y-x<=2) || (z-y<=2)){
            min_moves = 1;
        }else{
            min_moves =2;
        }

        return {min_moves,max_moves};
    }
};