/*
Problem Description:
A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        if(commands.size()==0) return 0;
        set<pair<int,int>> s;
        for(auto ob:obstacles) 
            s.insert(make_pair(ob[0],ob[1]));
        vector<int> pos(2,0);
        vector<int> offset_x={0,1,0,-1};
        vector<int> offset_y={1,0,-1,0};
        int direction=0;
        int result=0;
        for(auto command:commands)
        {
            if(command==-2){
                direction=(direction+3)%4;
                continue;
            }
            if(command==-1){
                direction=(direction+1)%4;
                continue;
            }
            for(int i=0;i<command;i++)
            {
                int x=pos[0]+offset_x[direction];
                int y=pos[1]+offset_y[direction];
                if(s.find(make_pair(x,y))!=s.end()) break;
                else{
                    pos[0]=x;
                    pos[1]=y;
                    result=max(x*x+y*y,result);
                }
            }
        }
        return result;
    }
};