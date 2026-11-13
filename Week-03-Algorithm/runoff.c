




#include<stdio.h>
#include<cs50.h>
#include<string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // 检查参数的有效性
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // 后续人的数量
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    //初始化结构体
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    //选民数量
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // 查询投票信息，i表示选民，j表示一个选民的第j的志愿
        //有几个候选人就写几个
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // 检查第i个选民的第j个志愿是否有效
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // 接着反复执行runoff淘汰操作
    while (true)
    {
        // 根据选民的意愿登记票
        tabulate();

        // 检查是否有人半数获胜
        bool won = print_winner();
        if (won)
        {
            break;//有人赢就停止
        }

        // 找出最小值，检查是否tie，所有人都同票
        int min = find_min();
        bool tie = is_tie(min);

        //检查 最后是否tie，所有人都赢，打印获胜者名字
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // 最少票淘汰
        eliminate(min);

        // 把所有人的票归零，这里是一把抓，不必区分是否淘汰
        //在这里已经确认未结束，重置进行下一把选举
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// 开始记录偏好
//vote在上面检查有效的同时已经进入了一次函数，一举两得
bool vote(int voter, int rank, string name)
{
    
    for (int k = 0;k < candidate_count;k++)
    {
        if (!strcmp(name, candidates[k].name))//注意字符串相同返回0
        {
            //这个voter是i，rank是j，这里是跟着main里的两层循环进行的
      preferences[voter][rank] = k;
      return true;//这里遇到一个有效名字就返回，不认为有两个同名选手
            
        }
    }
    return false;//如果不在上面返回，那就是找不到，名字无效
}

// 把偏好转化为票数，无参数无输出，只是对main里的局部变量进行操作
void tabulate(void)
{

    //因为这里是在一个循环体里，不能只考虑第一次循环的情况
    //这里并不会给淘汰的的人加票
    for (int p = 0;p < voter_count;p++)
    {
        for (int q = 0;q < candidate_count;q++)
        {
            //这里是看每个voter的第“一”志愿
            //如果未淘汰，直接votes加1，直接break
            //这里对于已淘汰的未设置操作，直接q++，总不能都淘汰吧hh
            if (candidates[preferences[p][q]].eliminated == false)
            {
                candidates[preferences[p][q]].votes++;
                break;
            }

           
        }
    }
     return;//这里还写错了，豆姐威武
}

        // 如果有获胜者则打印姓名
        //这里直接运用了，int截断小数，直接n/2
        bool print_winner(void)
        {
            for (int p = 0;p < candidate_count;p++)
            {
                if (candidates[p].votes > (voter_count / 2))
                {
                    printf("The winner is %s ", candidates[p].name);
                    return true;
                }
            }
            //走完一圈后没有就没有
            return false;
        }

        // 能到这一步就说明没有break
        int find_min(void)
        {
            int  tem=candidate_count;//这里初始化tem是一个易错点，不要为0
            //能作为票数比较初始值，一定要未淘汰
            //这里可以说的是，最后初始化未0，第二个函数又重新搞了票数

            //第一个循环是找初始值，第二个是为了遍历后续的未淘汰人
            //在第一个for内部直接提前返回，结束循环
            for (int m = 0;m < candidate_count;m++)
            {
                
        if (!candidates[m].eliminated && candidates[m].votes < tem)
        {
            tem = candidates[m].votes;
        }
    }
    return tem;

            }

          
        }

        // 检查是否tie结束
        bool is_tie(int min)
        {

            for (int i = 0;i < candidate_count;i++)
            {
                //只要有个为淘汰人的票数不是min，就不是tie
                //一个比较难想到的边界
                if (candidates[i].eliminated == false && candidates[i].votes != min)
                {
                    return false;
                }
            }

            return true;
        }

        // 淘汰最小票数的人
        //一层层if一次判断
        void eliminate(int min)
        {
            for (int i=0;i<candidate_count;i++)
            {
                if(candidates[i].eliminated==false)
                {
                    if(candidates[i].votes==min)
                    {
                        candidates[i].eliminated = true;
                    }
                }
            }

            return;
        }
