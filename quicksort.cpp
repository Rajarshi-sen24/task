#include<bits/stdc++.h>
using namespace std;
int a[1000];
int quick(int b,int e)
{
    int l,r,temp,loc1;
    l=b;
    r=e;
    loc1=b;
    while(1)
    {
        while(a[loc1]<=a[r]&&loc1!=r)
            r--;
        if(loc1==r)
            return(loc1);
        if(a[loc1]>a[r])
        {
            swap(a[loc1],a[r]);
            loc1=r;
        }
        while(a[loc1]>=a[l]&&loc1!=l)
            l++;
         if(loc1==l)
            return(loc1);
        if(a[loc1]<a[l])
        {
            swap(a[loc1],a[l]);
            loc1=l;
        }
    }

}
main()
{
    int b,e,l[50],u[50],t,loc,n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    t=-1;
    if(n>1)
    {
        t=t+1;
        l[0]=0;
        u[0]=n-1;
    }
    while(t!=-1)
    {
        b=l[t];
        e=u[t];
        t=t-1;
        loc=quick(b,e);
        if(b<loc-1)
        {
            t=t+1;
            l[t]=b;
            u[t]=loc-1;
        }
        if(e>loc+1)
        {
            t=t+1;
            l[t]=loc+1;
            u[t]=e;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

