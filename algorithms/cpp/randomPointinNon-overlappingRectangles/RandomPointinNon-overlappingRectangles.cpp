// Source : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Author : Mading
// Date   : 2019-08-12

/*************************************************************************************** 
 * 497. Random Point in Non-overlapping Rectangles [Medium]
 * Given a list of non-overlapping axis-aligned rectangles rects, write a function pick 
 * which randomly and uniformily picks an integer point in the space covered by the rectangles.

 * Note:
 * An integer point is a point that has integer coordinates. 
 * A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
 * ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of 
 * the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
 * length and width of each rectangle does not exceed 2000.
 * 1 <= rects.length <= 100
 * pick return a point as an array of integer coordinates [p_x, p_y]
 * pick is called at most 10000 times.

 * Example 1:
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[[[1,1,5,5]]],[],[],[]]
 * Output: 
 * [null,[4,1],[4,1],[3,3]]

 * Example 2:
 * Input: 
 * ["Solution","pick","pick","pick","pick","pick"]
 * [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
 * Output: 
 * [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

 * Explanation of Input Syntax:
 * The input is two lists: the subroutines called and their arguments. Solution's constructor 
 * has one argument, the array of rectangles rects. pick has no arguments. Arguments are always 
 * wrapped with a list, even if there aren't any.
 *               
 ***************************************************************************************/


// 144 ms, faster than 8.32% of C++, 38.2 MB, less than 12.50% of C++
class Solution {
public:
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>> rects) : rects(rects) {
    }
    
    vector<int> pick() {
        int sum_area = 0;
        vector<int> selected;
        
        /* Step 1 - select a random rectangle considering the area of it. */
        for (auto r : rects) {
            /*
             * What we need to be aware of here is that the input may contain
             * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3, -2].
             * 
             * So, we work around it by adding +1 here. It does not affect
             * the final result of reservoir sampling.
             */
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            
            if (rand() % sum_area < area)
                selected = r;
        }
        
        /* Step 2 - select a random (x, y) coordinate within the selected rectangle. */
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */