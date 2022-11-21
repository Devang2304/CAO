#include<bits/stdc++.h>
using namespace std;

int n,no_frame;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcount=0;
 
void input()
{
    cout<<"\nEnter length of page reference sequence:";
    cin>>n;
    cout<<"\nEnter the page reference sequence:";
    for(i=0; i<n; i++) cin>>in[i];
    cout<<"\nEnter no of frames:";
    cin>>no_frame;
}
 
void initialize()
{
    pgfaultcount=0;
    for(i=0; i<no_frame; i++)
        p[i]=9999;
}
 
int isHit(int data)
{
    hit=0;
    for(j=0; j<no_frame; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
 
int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<no_frame; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
 
void dispPages()
{
    for (k=0; k<no_frame; k++)
    {
        if(p[k]!=9999)
            cout<<p[k];
    }
 
}
 
void dispPgFaultCount()
{
    cout<<"\nTotal no of page faults:"<<pgfaultcount;
    cout<<"\nTotal no. of page hit: "<<(n-pgfaultcount);
}
 
void FIFO()
{
    initialize();
    for(i=0; i<n; i++)
    {
        cout<<"\nFor"<<":"<<in[i]<<" ";
 
        if(isHit(in[i])==0)
        {
 
            for(k=0; k<no_frame-1; k++)
                p[k]=p[k+1];
 
            p[k]=in[i];
            pgfaultcount++;
            dispPages();
        }
        else
            cout<<"No page fault";
    }
    dispPgFaultCount();
}
 
void LRU()
{
    initialize();
 
    int least[50];
    for(i=0; i<n; i++)
    {
 
        cout<<"\nFor"<<":"<<in[i];
 
        if(isHit(in[i])==0)
        {
 
            for(j=0; j<no_frame-1; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<no_frame; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcount++;
 
            dispPages();
        }
        else
            cout<<"No page fault!";
    }
    dispPgFaultCount();
}
 
int main()
{
    int choice;
    while(1)
    {
        cout<<"\nPage Replacement Algorithms\n1.Enter data\n2.FIFO\n3.LRU\n4.Exit\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            input();
            break;
        case 2:
            FIFO();
            break;
        case 3:
            LRU();
            break;
        default:
            return 0;
            break;
        }
    }
}