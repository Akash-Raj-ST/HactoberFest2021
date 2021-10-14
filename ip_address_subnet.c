#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int decimal(int *arr,int s){
    int ans = 0;
    int p = 7;
    for(int i=s;i<s+8;i++){
        ans = ans +(arr[i]*pow(2,p));
        p--;
    }
    return ans;
}
int main() {

    int w,x,y,z,a;
    int net[35];
    scanf("%d.%d.%d.%d/%d",&w,&x,&y,&z,&a);
    int n=32-a;
    
    for(int i=0;i<a;i++){
        net[i]=1;
    }
    for(int i=a;i<32;i++){
        net[i]=0;
    }
    
    //first add
    printf("First address: ");
    int part,ans;
    part = decimal(net,0);
    ans = part&w;
    printf("%d.",ans);
    
    part = decimal(net,8);
    ans = part&x;
    printf("%d.",ans);
    
    part = decimal(net,16);
    ans = part&y;
    printf("%d.",ans);
    
    part = decimal(net,24);
    ans = part&z;
    printf("%d",ans);
    printf("\n");
    
    //sec add
    for(int i=0;i<32;i++){
        if(net[i]==0)
            net[i]=1;
        else
            net[i]=0;
    }
    printf("Last address: ");
    part = decimal(net,0);
    ans = part|w;
    printf("%d.",ans);
    
    part = decimal(net,8);
    ans = part|x;
    printf("%d.",ans);
    
    part = decimal(net,16);
    ans = part|y;
    printf("%d.",ans);
    
    part = decimal(net,24);
    ans = part|z;
    printf("%d",ans);
    
    printf("\n");
    
//no of conn
    int no = pow(2,n);
    printf("No of devices: %d",no);
    return 0;
}

// Sample Input 0

// 192.68.5.5/24

// Sample Output 0

// First address: 192.68.5.0
// Last address: 192.68.5.255
// No of devices: 256