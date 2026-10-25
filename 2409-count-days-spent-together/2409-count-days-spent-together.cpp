
class Solution {
public:
    int dateToDayOfYear(const string& date) {
        vector<int> daysInMonth={31,28,31,30,31,30,31,31,30,31,30,31};
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        int totalDays=day;
        for(int i=0;i<month-1;i++){
            totalDays+=daysInMonth[i];
        }
        return totalDays;
    }

    int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob) {
        int aStart=dateToDayOfYear(arriveAlice);
        int aEnd=dateToDayOfYear(leaveAlice);
        int bStart=dateToDayOfYear(arriveBob);
        int bEnd=dateToDayOfYear(leaveBob);

        int ans=0;
        for(int i=aStart;i<=aEnd;i++){
            if(i>=bStart&&i<=bEnd){
                ans++;
            }
        }
        return ans;
    }
};
