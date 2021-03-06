/*Each year, employees of an organization are rated based on their performance. The employees are then ranked based on the ratings. Enployees with the same ratings will have the same rankings, but the next employee with the next lowest score will be rated based on the position within the list of all rankings. Employees below the cutoff rank are placed in a layoff list.
Give the ratings each employee receives and the cutoff rank, return the number of employees who are not in the layoff list.

The input to the function/method consists of three arguments:
cutOffRank, an integer representing the cutoff rank;
num, an integer representing the total number of scores;
scores, a list of integers representing the scores of the employees.

Return an integer representing the number of employees who are not in the layoff list.

Constraints
1 <= num <= 10^5
0 <= scores[i] <= 100
0 <= i < num
cutOffRank <= num

Example 1:
Input: 
cutoffrank = 2
num = 5
scores = [100, 90, 80, 70, 60]
Output: 2
Explanation:
The employee rankings are [1, 2, 3, 4, 5]. And with a cutoff rank of two, only the first 2 employees are not in the layoff list.

Example 2:
Input: 
cutoffrank = 4
num = 5
scores = [100, 100, 80, 70, 60]
Output: 4
Explanation:
The first two employees have equal rating and both receives a ranking of 1. Employee with score 80 has 2 employees in front of him so he receives a ranking of 3. The final employee rankings are [1, 1, 3, 4, 5]. With a cutoff rank of 4, the first 4 employees are out of the layoff list.

Example 3:
Input:
cutOffRank = 3
num= 4
scores=[100, 50, 50, 25 ]
Output:
3
Explanation:
There are num= 4 employees, where the cutOffRank is 3 and scores = [100, 50,50, 25]. These employees' ranks are [1, 2, 2, 4]. Because the players need to have a rank of at least 3, return first three employees.
So, the output is 3.

Example 4:
Input:
cutOffRank = 4
num=5
scores=[2,2,3,4,5]
Output:
5
Explanation:
In order, the players achieve the ranks [4,4,3,2,1]. Since the cutOffRank is 4, all 5 employees will be left.
So, the output is 5.*/




//Code:-(Java)

 public static int levelUp(int k, List<Integer> score) {
        if(k <= 0) return 0;
        Collections.sort(score, Collections.reverseOrder());
        int rank = 1;
        int res = 0;
        for(int i = 0; i < score.length(); i++) {
            if(i == 0) {
                rank = 1;
            } else if(score.get(i) != score.get(i - 1)) {
                rank = i + 1;
            }
            if(rank <= k && score.get(i) > 0) res++;
            else break;
        }
        return res;
    }

//Code:-(C++)

public int levelUp(int k,vector<int>score)
{
 if(k<=0)
 {
  return 0;
 }
 score.sort(score.begin(),score.end(),greater<int>());
 int rank=1;
 int res=0;
 for(int i=0;i<score.size();i++)
 {
  if(i == 0) 
  {
      rank = 1;
  } 
  else if(score.get(i) != score.get(i - 1)) 
  {
   rank = i + 1;
  }
   if(rank <= k && score.get(i) > 0) 
   {
    res++;
   }
   else 
   {
    break;
   }
 }
 return res;
}
  
