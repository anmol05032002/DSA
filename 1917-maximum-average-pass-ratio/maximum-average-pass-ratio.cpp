class Solution {
public:
   typedef pair<double,double> P;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<pair<double,P>> pq;

       double n  = classes.size();

       for(int i =0; i<n; i++){
          double pass = classes[i][0];
          double total = classes[i][1];
          double ratio = (double)(total - pass) /
                          (total * (total + 1.0));

          pq.push({ratio,{pass,total}});
       }


       while(extraStudents!=0){
          auto temp = pq.top();
          pq.pop();
          double ratio = temp.first;
          double num = temp.second.first;
          double total = temp.second.second;
          num++;
          total++;
          extraStudents--;
          ratio =  (total - num) / (total * (total + 1.0));
          pq.push({ratio,{num,total}});
       }
       double ans = 0;
       while(!pq.empty()){
          auto temp = pq.top();
          pq.pop();
          double num = temp.second.first;
          double total = temp.second.second;
          ans+= (double)num/total;
       }
       return (double)ans/n;
    }
};