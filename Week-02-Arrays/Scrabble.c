/*更加熟悉了字符串的输入和数组
以及自定义函数的输入输出
y1s1大肥鱼给出的数组映射，好像是这么叫的
确定26个字母的分值，然后定义一个新的point数组
通过ASCII码值（-‘a'）来实现，真的太好了
不然我就得一个一个输入或的条件，整整26个！
不太了解这个游戏可以长度不一样，算了*/


#include<string.h>
#include <stdio.h>
int score(int n,char word[]);//记得写分号！
int main (void)
{
    //输入长度
    printf("Please choose your length of words in this game\n");

    int n;

    //检查输入，防止用户输入其他字符使得读取失败，n变为垃圾值
  if(scanf("%d",&n)!=1)
  {
    printf("Input error!");

    return 1;
  }
//声明数组
  char word1[n+1];
  char word2[n+1];

  printf("Player 1 , please enter your word \n");

  scanf("%101s",word1);

  if (strlen(word1)!=n)
  {
    printf("The length of word is %d",n);

    return 1;
  }

  
//检查用户输入全为小写字母
  for (int i=0;i<n;i++)
  {
    if (word1[i]<97||word1[i]>122)
   {
     printf("Please enter lowercase");
    return 1;
   }
  }

  printf("Player 2 ,please enter your word \n");

  scanf("%101s",word2);

   if (strlen(word2)!=n)
  {
    printf("The length of word is %d",n);

    return 1;
  }
  //还是得检验一下长度，不然进缓冲区，会给第二个玩家带来麻烦的
 

  for (int i=0;i<n;i++)
  {
    if (word2[i]<97||word2[i]>122)
    {
      printf("Please enter lowercase");

    return 1;
    }
    
  }


    //得分
    int score1=score(n,word1);
    int score2=score(n,word2);

    //输出分数
    printf("Player 1 gets %d\n",score1);

    printf("Player2 gets %d\n",score2);

    //比较
    if (score1<score2)
    {
        printf("Player 2 wins!");
    }

    else if (score1>score2)
    {
        printf("Player 1 wins!");
    }
    else{
        printf("Ties");
    }

    return 0;


  }

//定义的记分函数，返回分数
int score(int n,char word[])

{
    int points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int score=0;
    for (int i=0;i<n;i++)
{
    int index=word[i]-'a';

    score+=points[index];
}

    return score;
}