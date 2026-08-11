class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0;
        int count=0;
        while(q.size()>0 && q.size()!=count){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                count=0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
            
        }
         return q.size();
    }
};