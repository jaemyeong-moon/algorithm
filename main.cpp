#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

/*
codility 

https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

*/
// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        List list = new ArrayList();
        int sum = 0, left = 0, right = 0;
        for(int i : A) sum += i;
        right = sum;
        for(int i = 0 ; i < A.length -1 ; i++)
        {
            left += A[i];
            right -= A[i];
            list.add(Math.abs(left - right));
        }
        return (int) Collections.min(list);
    }
}