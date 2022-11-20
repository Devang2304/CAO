#include<bits/stdc++.h>
#include<cmath>
using namespace std;

typedef struct _address_
{
    int PAGE_BITS;
    int BLOCK_BITS;
    int BYTE_BITS;
}
address_bus;

typedef struct _memory_
{
   int PAGE_SIZE;
   int BLOCK_SIZE;
   int NO_OF_PAGE;
   int NO_OF_BLOCK;
}
memory_data;

typedef struct _cache_
{
    int NO_OF_LINES;
    int LINE_SIZE;
    int TAG_BITS;
    int BYTE_BITS;
    int LINE_ENTRY_BITS;
}
cache_data;

address_bus ADDRESS;
memory_data MAIN;
cache_data CACHE_DIR;

void configure_main(int mem_size,int cache_size,int block_size){
    MAIN.NO_OF_PAGE =(mem_size/cache_size);
    MAIN.NO_OF_BLOCK = (cache_size/block_size);
    ADDRESS.PAGE_BITS = log((mem_size/cache_size))/log(2);
    ADDRESS.BLOCK_BITS = log(cache_size/block_size)/log(2);
    ADDRESS.BYTE_BITS = log(block_size)/log(2);
    MAIN.PAGE_SIZE = cache_size;
    MAIN.BLOCK_SIZE = block_size;
}

void configure_cache(int mem_size, int cache_size, int block_size){

    CACHE_DIR.NO_OF_LINES = (cache_size/block_size);
    CACHE_DIR.LINE_SIZE = block_size;
    CACHE_DIR.BYTE_BITS = log(block_size)/log(2);
    CACHE_DIR.TAG_BITS = ADDRESS.PAGE_BITS;
    CACHE_DIR.LINE_ENTRY_BITS = log(CACHE_DIR.NO_OF_LINES)/log(2);
}

int main(){
    int main_mem_size;
    int cache_size;
    int block_size;
    int n;

    cout<<"Enter n for n-way set associate: ";
    cin>>n;

    cout<<"Enter Main Memory Size: ";
    cin>>main_mem_size;
    cout<<"Enter Cache Size: ";
    cin>>cache_size;
    cout<<"Enter Block Size: ";
    cin>>block_size;

    cache_size/=n;
    configure_main(main_mem_size, cache_size,block_size);

cout<<"\n**********MAIN MOMORY CONFIGURATION**********";
cout<<"\nPAGE SIZE => "<<MAIN.PAGE_SIZE;
cout<<"\nBLOCK SIZE => "<<MAIN.BLOCK_SIZE;
cout<<"\nNO. OF PAGES => "<<MAIN.NO_OF_PAGE;
cout<<"\nNO. OF BLOCKS IN PAGES => "<<MAIN.NO_OF_BLOCK;
cout<<"\nNO OF PAGE BITS => "<<ADDRESS.PAGE_BITS;
cout<<"\nNO OF BLOCK BITS => "<<ADDRESS.BLOCK_BITS;
cout<<"\nNO OF BYTE BITS => "<<ADDRESS.BYTE_BITS;

configure_cache(main_mem_size,cache_size,block_size);
cout<<"\n**********CACHE MOMORY CONFIGURATION**********";
cout<<"\nCACHE SIZE =>"<<cache_size;
cout<<"\nLINE SIZE =>"<<CACHE_DIR.LINE_SIZE;
cout<<"\nNO OF LINES =>"<<CACHE_DIR.NO_OF_LINES;
cout<<"\nNO OF LINES ENTRIES =>"<<CACHE_DIR.NO_OF_LINES;
cout<<"\nNO OF LINES ENTRY BITS =>"<<CACHE_DIR.LINE_ENTRY_BITS;
cout<<"\nNO OF TAG BITS =>"<<CACHE_DIR.TAG_BITS;
cout<<"\nNO OF BYTE BITS =>"<<CACHE_DIR.BYTE_BITS;
}
