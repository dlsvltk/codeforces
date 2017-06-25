#include<bits/stdc++.h>
int table[51][51];
int main(){
    int n;
	bool check;
	scanf("%d", &n);
	for(int i=0;i<n;i++){	
	    for(int j=0;j<n;j++){
		    scanf("%d", &table[i][j]);
		}
	}
	if(check) printf("YES");
	else printf("NO");
	
    return 0;
}
