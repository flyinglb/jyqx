//made by wind for fuzhou lottery
// version 1.2, worse than 1.0
//本程序纯属个人使用, 严禁外传, 违者必究.

inherit NPC;
#include <ansi.h>

float* prob=allocate(56);
int*  sort=allocate(56);

string ask0();
string ask1();
string ask2();
int caculate();
int getone();


void create()
{
	set_name("开奖机", ({"lottery"}));
	set("nickname", HIM "中国体育彩票" NOR);
	set("long", HIC "\n它是一个看上去极笨重的家伙,然而却牵动着亿万人的心.\n" NOR);
	set("title", HIC "福州大富翁电脑" NOR);
	set("inquiry" , ([
	"统计数据" : (: ask0 :),
	"随机彩票" : (: ask1 :),
	"统计彩票" : (: ask2 :),
	]));
        caculate();
        setup();
}

string ask0()
{
caculate();
return ("这就是以前的统计数据.\n");
}

string ask1()
{
int i,j,checkflag;
int* number=allocate(6);

for (i=0;i<6;i++)
{
checkflag=1;
while(checkflag)
 {
number[i]=1+random(56);
for(j=0;j<i;j++)
  {
if (number[i]==number[j])
checkflag=1;
  }
if (j==i) checkflag=0;
 }
}

for(i=0;i<6;i++) printf("%2d,",number[i]);
printf("\n");
return ("这就是这次的随机彩票.\n");
}

int caculate()
{
	string file;
        string *rec_list;
        int i,j, k,total;
        int* count=allocate(56);

        float* probd=allocate(56);


        float temp;
        string* code=allocate(114);
	code[0]="01";
	code[1]="02";
	code[2]="03";
	code[3]="04";
	code[4]="05";
	code[5]="06";
	code[6]="07";
	code[7]="08";
	code[8]="09";
	code[9]="10";
	code[10]="11";
	code[11]="12";
	code[12]="13";
	code[13]="14";
	code[14]="15";
	code[15]="16";
	code[16]="17";
	code[17]="18";
	code[18]="19";
	code[19]="20";
	code[20]="21";
	code[21]="22";
	code[22]="23";
	code[23]="24";
	code[24]="25";
	code[25]="26";
	code[26]="27";
	code[27]="28";
	code[28]="29";
	code[29]="30";
	code[30]="31";
	code[31]="32";
	code[32]="33";
	code[33]="34";
	code[34]="35";
	code[35]="36";
	code[36]="37";
	code[37]="38";
	code[38]="39";
	code[39]="40";
	code[40]="41";
	code[41]="42";
	code[42]="43";
	code[43]="44";
	code[44]="45";
	code[45]="46";
	code[46]="47";
	code[47]="48";
	code[48]="49";
	code[49]="50";
	code[50]="51";
	code[51]="52";
	code[52]="53";
	code[53]="54";
	code[54]="55";
	code[55]="56";


        total=0;

	for(i=0;i<56;i++) count[i]=0;
	for(i=0;i<56;i++) sort[i]=0;

        file=read_file("/u/wind/lotrec2");
        if(!file)
                return notify_fail("目前没有任何开奖记录。\n");
        rec_list = explode(file,"\n");
        total=6*sizeof(rec_list);

        for(i=0;i<sizeof(rec_list);i++) {
        for(j=0;j<56;j++){
        for(k=0;k<14;k=k+2){
        if ((rec_list[i][k..k+1])==code[j]) count[j]++;
        }
        }
        }


printf("\n");
for(i=0;i<sizeof(rec_list);i++) 
printf("第%d次开奖记录:%s\n ",i+1,rec_list[i]);
       
for(i=0;i<56;i++) 
printf("其中数字%d出现的总次数为%d\n ",i+1,count[i]);

reset_eval_cost();        
        for(i=0;i<56;i++)
        prob[i]=to_float(count[i])/to_float(total);

for(i=0;i<56;i++) probd[i]=prob[i];


       for(i=0;i<56;i++)
         for(j=i;j<56;j++)
        if(prob[i]<prob[j]) 
          {
            temp=prob[i]; 
            prob[i]=prob[j];
            prob[j]=temp;
	  }


       for(i=0;i<56;i++)
       for(j=0;j<56;j++)
       {
        if(prob[i]==probd[j]&&((i==0)||(i==1&&j!=sort[i-1])||(i>1&&j!=sort[i-1]&&j!=sort[i-2])))
          {
	  sort[i]=j;
          }
       }

for(i=0;i<56;i++) 
printf("统计数字%d出现的总概率为%f\n ",i+1,probd[i]);
for(i=0;i<56;i++) 
printf("排序后依次出现的第%d位概率为%f\n ",i+1,prob[i]);
for(i=0;i<6;i++) 
printf("统计数字按概率由高到低最易出现的前%d位为%2d\n ",i+1,sort[i]);
  		
return 1;          
}

string ask2()
{
int i,j,checkflag;
int* number=allocate(6);


for (i=0;i<6;i++)
{
checkflag=1;
while(checkflag)
 {
number[i]=getone();
for(j=0;j<i;j++)
  {
if (number[i]==number[j])
checkflag=1;
  }
if (j==i) checkflag=0;
 }
}

for(i=0;i<6;i++) printf("%2d,",number[i]);
printf("\n");
return ("这就是这次的统计彩票.\n");
} 


int getone()
{
int i,one;
int proba;
proba=random(100);
one=1+random(56);
for(i=5;i>-1;i--)
{
if(proba<prob[i]*100)
  {one=sort[i]; break;}
else continue;
}
return one;
}

