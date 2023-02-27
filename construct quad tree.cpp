/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/


/*

    T.C:- n^2longn
    
    S.C:- o(logn) -> bcz of recursive stack

*/

/*
        STEPS FOR SOLVING THIS QUESTION USING RECURSION
        
        1. Check if all the give value in grid are same or not 
            if(same) return root node by putting value of grid and true.
        
        2. If grid have diffrent values than we have to create a new root node and
           give ((0/1) or false ) and do resursion for the same 
        
*/

// class Solution { // USING  RECURSION 
// public:
// //     checking for the all value in the grid same or not
//     bool sameValue(vector<vector<int>>&grid,int x1,int y1 ,int len){
//         for(int i=x1;i<x1+len;i++){
//             for(int j=y1;j<y1+len;j++){
//                 if(grid[i][j]!=grid[x1][y1]){ // n^2-T.C
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
// //     main funtion which give us the quad tree
//     Node*solve(vector<vector<int>>&grid,int i,int j,int n){
//         if(sameValue(grid,i,j,n)){ // same
//             return new Node(grid[i][j],true);
//         }else {//(not same)
//             Node*root=new Node(false,false);
            
//             // all the four leaf node
//             root-> topLeft=solve(grid,i,j,n/2);
//             root-> topRight=solve(grid,i,j+n/2,n/2);  // this divide into 4 so divede by 4
//             root-> bottomLeft=solve(grid,i+n/2,j,n/2);
//             root-> bottomRight=solve(grid,i+n/2,j+n/2,n/2);
            
//             return root;
//         }
        
//     }
    
//     Node* construct(vector<vector<int>>& grid) {
//         return solve(grid,0,0,grid.size());
//     }
// };

/*``````````````````````````````````optimized recursion``````````````````````````````*/


class Solution { // USING  RECURSION  
    /*
    T.C-> O(n*n)
    S.C-> O(logn) recursive stack
    */
public:

//     main funtion which give us the quad tree
    Node*solve(vector<vector<int>>&grid,int i,int j,int n){
      
            if(n==1) return new Node(grid[i][j],true);
        
            // all the four leaf node
            Node* topLeft=solve(grid,i,j,n/2);
            Node* topRight=solve(grid,i,j+n/2,n/2);  // this divide into 4 so divede by 4
            Node* bottomLeft=solve(grid,i+n/2,j,n/2);
            Node* bottomRight=solve(grid,i+n/2,j+n/2,n/2);
            
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
           && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
           && bottomLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
     
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
    }
};