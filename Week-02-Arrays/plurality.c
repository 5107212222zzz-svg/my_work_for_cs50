
#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // 输出获胜者
    print_winner();
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
void print_winner(void)
{
    // TODO: 需要你自己完成
    return;
}
