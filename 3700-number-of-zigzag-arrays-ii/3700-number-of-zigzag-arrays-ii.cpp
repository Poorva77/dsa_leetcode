class Solution {
public:
    static const int MOD=1e9+7;
    using ll=long long;
    using Matrix=vector<vector<ll>>;

    Matrix multiply(Matrix& A,Matrix& B){
        int n=A.size();
        Matrix C(n,vector<ll>(n));

        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(A[i][k]==0) continue;

                ll x=A[i][k];

                for(int j=0;j<n;j++){
                    C[i][j]=(C[i][j]+x*B[k][j])%MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base,long long exp){
        int n=base.size();

        Matrix res(n,vector<ll>(n));
        for(int i=0;i<n;i++) res[i][i]=1;

        while(exp){
            if(exp&1) res=multiply(res,base);
            base=multiply(base,base);
            exp>>=1;
        }

        return res;
    }

    int zigZagArrays(int n,int l,int r) {
        int m=r-l+1;
        int sz=2*m;

        Matrix T(sz,vector<ll>(sz));

        for(int x=0;x<m;x++){

            for(int y=x+1;y<m;y++){
                T[m+y][x]=1;
            }

            for(int y=0;y<x;y++){
                T[y][m+x]=1;
            }
        }

        Matrix P=power(T,n-1);

        vector<ll> init(sz,1);
        long long ans=0;

        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                ans=(ans+P[i][j])%MOD;
            }
        }

        return ans;
    }
};