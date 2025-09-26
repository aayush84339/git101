#include<bits/stdc++.h>
using namespace std;
int global =  900;

void printPattern1(int n){
    for (int i = 0; i<n; i++){
        char ch = 'A';
        for (int j = 1; j<=n-1-i; j++){
            cout << ' ';
        }
        for (int j = 1; j<=2*i+1; j++){
            cout << ch;
            if (j < i+1) ch++;
            else ch--; 
        }
        cout << "\n";
    }
}

void printPattern2(int n){
    for (int i = 0; i<n/2; i++){
        for (int j = 1; j <= n/2-i; j++){
            cout << '*';
        }
        for (int j = 0; j<2*i; j++){
            cout << ' ';
        }
        for (int j = 1; j <= n/2-i; j++){
            cout << '*';
        }
        cout << "\n";
    }
    for (int i = 0; i<n/2; i++){
        for (int j = 1; j <= 1+i; j++){
            cout << '*';
        }
        for (int j = 0; j<2*(n/2-1-i); j++){
            cout << ' ';
        }
        for (int j = 1; j <= i+1; j++){
            cout << '*';

        }
        cout << "\n";
    }
}

void printPattern3(int n){
    for (int i = 1; i<=2*n-1; i++){
        for (int j = 1; j<=2*n-1; j++){
            cout << 1 + max(abs(n-i),abs((n-j)));
            1 + max(i-n,i-j);
        }
        cout << endl;
    }

}

void nextday(){
    int y, m, d;
    cin >> d >> m >> y;
    if (m==1|m==3|m==5|m==7|m==8|m==10){
        if (d != 31) {d++;}
        else {d = 1; m++;}
    }
    else if (m==4|m==6|m==9|m==11){
        if (d != 30) {d++;}
        else {d = 1; m++;}
    }
    else if (m==12){
        if (d==31){d=1; m=1; y++;}
        else{d++;}
    }
    else if (m==2){
        if (1<=d && d<=27){d++;}
        else{
            if ((y%4 == 0 && y%100 != 0)|y%400==0){
                if (d==28){d=29;}
                else if (d==29){d=1;m=3;}
            }
            else{
                if (d==28){d=1;m=3;}
            }
        }
    }
    cout << d << ' ' << m << ' ' << y;
}

void min_coins(vector<int> coins, int cash){
    vector<int> noOfCoins = {0};
    for (int i=1; i<=cash; i++){
        vector<int> v = {};
        for (int c:coins){
            if (i >= c){
                int x = noOfCoins[i-c]+1;
                v.emplace_back(x);
            }
        }
        int min = cash;
        for (int x:v){
            if (x < min){
                min = x;
            }
        }
        noOfCoins[i]=min;
    }

    cout << noOfCoins[cash];
}

int power(int a,int b){
    if (b==0){return 1;}
    else if (b%2==0){return power(a,b/2)*power(a,b/2);}
    else{return a*power(a,b-1);}
}

void hanoi(int n, char A, char B, char C){
    if (n==0){return;}
    hanoi(n-1, A, C, B);
    cout << A << " to " << B << endl;
    hanoi(n-1, C, B, A);
}

bool nimgame(int n1, int n2, int n3){
    if (n1==0 && n2==0 && n3==0){
        return false;
    }
    for (int i=1; i<=n1; i++){
        if (nimgame(n1-i, n2, n3)==false){
            return true;
        }
    }
    for (int i=1; i<=n2; i++){
        if (nimgame(n1, n2-i, n3)==false){
            return true;
        }
    }
    for (int i=1; i<=n3; i++){
        if (nimgame(n1, n2, n3-i)==false){
            return true;
        }
    }
    return false;
}

int digitSum(int n){
    int sum = 0;
    while (n!=0){
        sum += n%10;
        n = n/10;
    return sum;
  }
}


vector<int> acmTeam(vector<string> topic) {
    vector<int> nums;
    for (int i=0; i<topic.size(); i++){
        for (int j=i+1; j<topic.size(); j++){
            string s1 = topic[i];
            string s2 = topic[j];
            int c = 0;
            for (int k=0; k<s1.size(); k++){
                if ((s1[k]=='1')||(s2[k]=='1')){c++;}
            }
            nums.emplace_back(c);
        }
    }

    int max=0;
    int count=0;
    for (int i:nums){
        if (i>max){
            max=i;
            count=1;
        }
        else if(i==max){
            count++;
        }
    }
    return {max, count};

}



int main(){

    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int z;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (j%2==0){
                z = n*j - i + 1;
            }
            else{
                z = n*(j-1)+i;
            }
            if (z/10==0){cout << 0 << z << ' ';}
            else {cout << z << ' ';}
        }
        cout << endl;
    }
    
    return 0;
}
