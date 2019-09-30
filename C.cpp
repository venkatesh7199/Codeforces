#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n;
    cin>>n;

    string x,y;

    cin>>x>>y;

    int bctr[n];
    int unb=0;

    REP(i,0,n){

        if(x[i]=='a'){
            if(y[i]=='b'){
                bctr[i]=1;
                unb++;
            }
            else{
                bctr[i]=0;
            }
        }

        else{
            if(y[i]=='b'){
                bctr[i]=0;
            }
            else{
                bctr[i]=-1;
                unb++;
            }
        }

    }

    int sum=0;
    int mov=0;

    REP(i,0,n){
        sum+=bctr[i];
    }

    unb-=abs(sum);
    mov=abs(sum/2);

    if(sum%2==1){
        cout<<"-1";
    }

    else{

        int flag=0;
        int ctr2=0;

        if(unb%4==0){
            mov+=unb/2;
        }
        else{
            mov+=unb/2+1;
        }

        cout<<mov<<endl;

        REP(i,0,n){

            while(ctr2<abs(sum)){
                if(sum<0){
                    if(flag==0 && bctr[i]<0){
                        cout<<i<<" ";
                        flag=1;
                        ctr2++;
                        bctr[i]=0;
                        x[i]='a';
                    }
                    else if(flag==1 && bctr[i]<0){
                        cout<<i<<endl;
                        flag=0;
                        ctr2++;
                        bctr[i]=0;
                        y[i]='b';
                    }
                }
                else{
                    if(flag==0 && bctr[i]>0){
                        cout<<i<<" ";
                        flag=1;
                        ctr2++;
                        bctr[i]=0;
                        x[i]='b';
                    }
                    else if(flag==1 && bctr[i]>0){
                        cout<<i<<endl;
                        flag=0;
                        ctr2++;
                        bctr[i]=0;
                        y[i]='a';
                    }
                }
            }

        }

        int a;
        int b;

        int fp=0;
        int fn=0;
        //cout<<"hello"<<endl;
        REP(i,0,n){

            if(bctr[i]==1){
                //cout<<i<<endl;
                if(fp==0){
                    a=i;
                    fp=1;
                    bctr[i]=0;
                    x[i]='b';
                }
                else{
                    fp=0;
                    cout<<a<<" "<<i<<endl;
                    bctr[i]=0;
                    y[i]='a';
                }
            }

            else if(bctr[i]==-1){
                //cout<<i<<endl;
                if(fn==0){
                    b=i;
                    bctr[i]=0;
                    fn=1;
                    x[i]='a';
                }
                else{
                    fn=0;
                    bctr[i]=0;
                    cout<<b<<" "<<i<<endl;
                    y[i]='b';
                }
            }

        }
        cout<<"unb"<<" "<<unb<<endl;
        if(unb%4==2){
            //cout<<"unb"<<endl;
            char bf;
            int bfc;
            REP(i,0,n){
                if(bctr[i]==0){
                    bfc=i;
                    if(x[i]=='a'){
                        bf='a';                        
                    }
                    else{
                        bf='b';
                    }
                    break;
                }
            }

            cout<<bf<<" "<<bfc<<endl;

            REP(i,0,n){
                int f;
                int flag2=0;
                if(bctr[i]==0)continue;
                if(flag2==0){
                    cout<<i<<"udsyhfguyfd"<<endl;
                    if (bf=='a'){
                        cout<<"blank"<<endl;
                        if(bctr[i]==1){
                            cout<<bfc<<" "<<i<<endl;
                            flag2=1;
                        }
                        else{
                            f=i;
                            flag2=1;

                        }
                    }
                    else{
                        if(bctr[i]==-1){
                            cout<<bfc<<" "<<i<<endl;
                            flag2=1;
                        }
                        else{
                            f=i;
                            flag2=1;
                        }
                    }

                }
                else{
                    if (bf=='a'){
                        cout<<"blanka"<<endl;
                        if(bctr[i]==-1){
                            cout<<bfc<<" "<<i<<endl;
                            flag2=0;
                        }
                        else{
                            cout<<bfc<<" "<<i<<endl;
                            cout<<bfc<<" "<<f<<endl;
                            flag2=0;
                        }
                        
                    }
                    else{
                        if(bctr[i]==1){
                            cout<<bfc<<" "<<i<<endl;
                            flag2=0;
                        }
                        else{
                            cout<<bfc<<" "<<i<<endl;
                            cout<<bfc<<" "<<f<<endl;
                            flag2=0;
                        }
                    }

                }
            }
        }

    }

    

return 0;
}