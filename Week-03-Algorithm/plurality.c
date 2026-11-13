
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int *merge(int *num,int n);

int* print_winner(int *num,int n);

// 最多 9 名候选人
#define MAX 9

// 候选人的结构体
typedef struct
{
    string name;
    int votes;
} candidate;

// 全局变量
candidate candidates[MAX];
int candidate_count;

// 函数声明
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // 检查命令行参数
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // 计算候选人数量
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // 初始化候选人
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // 输入选民人数
    int voter_count = get_int("Number of voters: ");

    // 依次让选民投票
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))//如果是错的，则函数返回0
        {
            printf("Invalid vote.\n");
        }
    }

    // 输出获胜者
   int *sort= print_winner(candidate.votes,candidate_count);

   printf(" The winner is %s",candidate.votes[candidate_count]);
    return 0;
}

// 根据名字记录一票
bool vote(string name)
{
    if (int i=0;i<candidate_cout;i++)

    {
      bool how=strcmp(name,candidates[i].name);

      if(how=0)
      {
        candidates[i].votes++;

        return how;
      }
    } 




    // TODO: 需要你自己完成
    
}

// 输出得票最多的候选人

int *merge(int *num,int n)
{
    if(n==2)
    {
        if (num[0]>num[1])
        {
            int tem;
            tem=num[0];
            num[0]=num[1];
            num[1]=tem;
        }
        return num;
    }


    else if(n==3)
    {
        for(int i=0;i<2;i++)
        {
            for (int j=0;j<(2-i);j++)
            {
                 if (num[j]>num[j+1])
                 {
                    int tem;
                    tem=num[j];
                    num[j]=num[j+1];
                    num[j+1]=tem;
                 }
            }
        }

        return num;
    }

    int mid=n/2;
    int L=mid;
    int R=n-mid;
    int left[L];
    int right[R];


    for(int i=0;i<L;i++)
    {
        left[i]=num[i];
    }
    for (int i=0;i<R;i++)
    {
        right[i]=num[L+i];
    }

    int *releft=merge(left,L);
    int *reright=merge(right,R);

    int *tems=malloc((L+R)*sizeof(int));

    int i=0,j=0,k=0;

    while(k<(R+L))
    {
        if(i>=L)
        {
            tems[k++]=reright[j++];
        }
        else if(j>=R)
        {
            tems[k++]=releft[i++];
        }

         else   if (releft[i]<reright[j])
        {
            tems[k++]=releft[i++];//优化一波
        }
        else if(releft[i]>reright[j])
        
            tems[k++]=reright[j++];
        
        else if(releft[i]==reright[j])
        {
            printf("Don't enter repeated number");
        
        }

    
            
    }

    return tems;

    }

int* print_winner(int *num,int n)
{
    int *sort=merge(num,n)
    // TODO: 需要你自己完成
    return sort;
}

