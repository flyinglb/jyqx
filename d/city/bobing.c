//bobing.c -搏饼屋
#include <room.h>
#include <ansi.h>

inherit ROOM;

int Maxperson,minperson;
int allow_leave,allow_start;
int Max1,Max2,Max3,Max4,Max5,Max6;
int Realmode;
object* member,leader,dutang1,dutang2,winner;
string roomname;

int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
void do_yao();
string getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
int pass_token(int,int);
int startreal();
int stopreal();
int givegift();
int qianbing(object,int);

void create()
{
    Maxperson=10;
    minperson=2;
    allow_leave=1;
    allow_start=0;
    Max1=32;//一秀的个数
    Max2=16;//二举的个数
    Max3=8; //四进的个数
    Max4=4; //三红的个数
    Max5=2; //对堂的个数
    Max6=1; //状元的个数
    Realmode=0;
    roomname="搏饼屋";
    set("no_fight","1");
    set("no_magic","1");
    set("no_steal","1");
    set("no_beg","1");
    set("short","搏饼屋");
    set("long", @LONG
这是一间古朴典雅的的搏饼屋。房间的装修充满了盛明时候的风味，满屋子
的琳琅玉石衬着柔和的光线，洋溢着温馨的气氛，真是个温暖而热闹的地方。房
间的四周点着一溜松明子，中间一张楠木桌，大家都席地而坐 (sit)，看着桌面
上一个大海碗，碗里面滴溜溜转着六颗玉制的骰子！南边的墙上贴着一张发黄的
陈纸(paper)。
LONG);
    set("item_desc", ([
        "paper" : "介绍和命令请 help bobing。\n",
    ]));
    set("objects",([
        __DIR__"npc/dog":1,
    ]));
    set("exits", ([
        "north"  :  __DIR__"duchang",
    ]));
    set("no_clean_up",1);
    setup();
}

void init()
{
    add_action("fsit","sit");
    add_action("fleave","leave");
    add_action("fleader","leader");
    add_action("fview","view");
    add_action("fyao","throw");
    add_action("startreal","start");
    add_action("stopreal","stop");
}

int fleader(string id)
{
    int i;
    object ob;
    ob=this_player();
    if (wizardp(ob) && (ob->query("id") == "wind" || ob->query("id") == "long" ||ob->query("id") == "super"))
    {
        if (arrayp(member))
        {
            for (i=0;i<sizeof(member);i++)
            {
                if (member[i]->query("id")==id)
                {
                    leader=member[i];
                    tell_room(environment(leader),"现在轮到"+
                              leader->query("name")+"掷了。\n");
                    return 1;
                }
            }
            notify_fail("这个人不在这里搏饼\n");
        }
        else
            notify_fail("没人在这搏饼\n");
    }
    else
        return 0;
}

int startreal()
{
    int i;
    object ob;
    object* pl;
    ob=this_player();
//    if (wizardp(ob))
    if (wizardp(ob) && (ob->query("id") == "java" || ob->query("id") == "solomon"))
    {
        Realmode=1;
        pl=users();
        message("vision",HIY+ob->query("name")+"宣布："+roomname+
                "正式开放，奖品立即兑现！\n"NOR,pl);
        if (arrayp(member))
        {
            for (i=0;i<sizeof(member);i++)
            {
                member[i]->set_temp("bobing/g1",0);
                member[i]->set_temp("bobing/g2",0);
                member[i]->set_temp("bobing/g3",0);
                member[i]->set_temp("bobing/g4",0);
                member[i]->set_temp("bobing/g5",0);
                member[i]->set_temp("bobing/g6",0);
                member[i]->set_temp("bobing/dest","");
                member[i]->set_temp("bobing/maxaward",0);
                member[i]->set_temp("bobing/maxscore",0);
            }
        }
        Max1=32;//一秀的个数
        Max2=16;//二举的个数
        Max3=8; //四进的个数
        Max4=4; //三红的个数
        Max5=2; //对堂的个数
        Max6=1; //状元的个数
        return 1;
    }
    return 0;
}

int stopreal()
{
    int i;
    object ob;
    object* pl;
    ob=this_player();
//    if (wizardp(ob))
    if (wizardp(ob) && (ob->query("id") == "java" || ob->query("id") == "solomon"))
    {
        pl=users();
        Max1=32;//一秀的个数
        Max2=16;//二举的个数
        Max3=8; //四进的个数
        Max4=4; //三红的个数
        Max5=2; //对堂的个数
        Max6=1; //状元的个数
        if (Realmode==1)
        {
            message("vision",
                    HIY+ob->query("name")+"宣布："+roomname+
                    "兑奖已结束，下次努力了！\n"NOR,pl);
            givegift();  //分饼
            Realmode=0;
            if (arrayp(member))
            {
                for (i=0;i<sizeof(member);i++)
                {
                    member[i]->set_temp("bobing/g1",0);
                    member[i]->set_temp("bobing/g2",0);
                    member[i]->set_temp("bobing/g3",0);
                    member[i]->set_temp("bobing/g4",0);
                    member[i]->set_temp("bobing/g5",0);
                    member[i]->set_temp("bobing/g6",0);
                    member[i]->set_temp("bobing/dest","");
                    member[i]->set_temp("bobing/maxaward",0);
                    member[i]->set_temp("bobing/maxscore",0);
                }
            }
        }
        return 1;
    }
    return 0;
}

int givegift()
{
    object ob;
    int i;
    int j;
    int num;
    if (!arrayp(member)||sizeof(member)==0)
        notify_fail("没人在这搏饼，就别分啦。\n");
    else
    {
        for (i=0;i<sizeof(member);i++)
        {
            num=member[i]->query_temp("bobing/g1");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing1");
                    ob->set_amount(1);
                    ob->move(member[i]);
                }
            }
            num=member[i]->query_temp("bobing/g2");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing2");
                    ob->set_amount(num);
                    ob->move(member[i]);
                }
            }
            num=member[i]->query_temp("bobing/g3");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing3");
                    ob->set_amount(num);
                    ob->move(member[i]);
                }
            }
            num=member[i]->query_temp("bobing/g4");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing4");
                    ob->set_amount(num);
                    ob->move(member[i]);
                }
            }
            num=member[i]->query_temp("bobing/g5");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing5");
                    ob->set_amount(num);
                    ob->move(member[i]);
                }
            }
            num=member[i]->query_temp("bobing/g6");
            if (num>0)
            {
                for (j=0;j<num;j++)
                {
                    ob=new(__DIR__"obj/bing6");
                    ob->set_amount(num);
                    ob->move(member[i]);
                }
            }
//            member[i]->set("marks/bobing",1);
        }
        return 1;
    }
}

int pass_token(int index,int passmode)
{
    int me,i,passok;
    me=index-1;
    allow_leave=0;
    passok=0;
    if (passmode==0)
    {
        for (i=0;i<sizeof(member)-1;i++)
        {
            index=index+i;
            if (index>=sizeof(member))
                index=index-sizeof(member);
            if (interactive(member[index]))
            {
                passok=1;
                leader=member[index];
                break;
            }
        }
        if ((!passok)||(sizeof(member)<minperson))
        {
            allow_start=0;
            tell_room(environment(leader),"陪你玩的人还不够，等人来了吧。\n");
        }
        else
            tell_room(environment(leader),"现在轮到"+
                      leader->query("name")+"掷了。\n");
    }
    if (passmode==1)
    {
        if (index>=sizeof(member))
            index=index-sizeof(member);
        passok=1;
        leader=member[index];
    }
    allow_leave=1;
}

int fyao()
{
    object ob;
    int i;
    ob=this_player();
    i=query_member(ob);
    if (allow_start )
    {
        if (i>0)
        {
            if(ob==leader)
            {
                do_yao();
                pass_token(i,0);
                return 1;
            }
            else
                notify_fail(HIC"还没轮到你呢，瞎嚷嚷个啥劲呢！\n"NOR);
        }
        else notify_fail(HIC"你要先坐下来才能和大家一起搏饼。\n"NOR);
    }
    else
        notify_fail(HIY"现在人还不够，悠着点吧。\n"NOR);
}

int fview()
{
    object ob;
    int i;
    ob=this_player();
    if (!arrayp(member)||sizeof(member)==0)
        notify_fail("没人在这搏饼。\n");
    else
    {
        printf("玩家          最高奖        一秀  二举  四进  三红  对堂  状元\n");
        printf("==============================================================\n");
        for (i=0;i<sizeof(member);i++)
        {
            printf("%-14s%-12s%6d%6d%6d%6d%6d%6d\n",
                   member[i]->query("name"),
                   member[i]->query_temp("bobing/dest"),
                   member[i]->query_temp("bobing/g1"),
                   member[i]->query_temp("bobing/g2"),
                   member[i]->query_temp("bobing/g3"),
                   member[i]->query_temp("bobing/g4"),
                   member[i]->query_temp("bobing/g5"),
                   member[i]->query_temp("bobing/g6"),);
        }
        printf("==============================================================\n");
        printf("目前还有一秀饼%i块,二举饼%i块,四进饼%i块,三红饼%i块,对堂饼%i块\n",
                Max1,Max2,Max3,Max4,Max5);
        if (objectp(winner))
            printf("现在的状元是由%s保持..\n",winner->query("name"));
        if (objectp(leader))
            printf("现在该轮到%s掷了\n",leader->query("name"));
        return 1;
    }
}

int fleave(string id)
{
    int i;
    int num;
    object ob;
    object nil;
    ob=this_player();
    if (wizardp(ob) && (ob->query("id") == "java" || ob->query("id") == "solomon"))
    {
        if (arrayp(member))
        {
            for (i=0;i<sizeof(member);i++)
            {
                if (member[i]->query("id")==id)
                    ob=member[i];
            }
            if (i==sizeof(member))
                notify_fail("这个人不在这里搏饼\n");
        }
        else
            notify_fail("没人在这搏饼\n");
    }
    num=query_member(ob);
    if (num)
    {
        if (leader==ob)
        {
            if (num==sizeof(member))
                num=1;
            else
                num++;
            leader=member[num-1];
        }
    }
    else
        return 1;
    if (sizeof(member)>minperson)
        message_vision(HIG"$N离开了大家少了一个伙伴了！\n"NOR,ob);
    else
        message_vision(HIG"$N离开了大家玩不成了！\n"NOR,ob);
    Maxperson++;
    if (ob==winner)
    {
        winner->set_temp("bobing/g6",0);
        winner=nil;
    }
    delete_member(ob);
    return 1;
}

int fsit()
{
    object ob;
    ob=this_player();
    if ((int)ob->query("mud_age") <18000)
    {
            tell_object(ob,HIY"你年纪太小了，等不会是dummy吧？\n"NOR);
            return 1;
    }
//    if ((int)ob->query("marks/bobing"))
//    {
//            tell_object(ob,HIY"今天你搏过了，等下次机会吧。\n"NOR);
//            return 1;
//    }
    if (!(query_member(ob)))
    {
        if (Maxperson>0)
        {
            message_vision(HIC"$N坐下来和大家一起搏饼。\n"NOR,ob);
            Maxperson--;
            add_member(ob);
            ob->set_temp("bobing/dest","");
            ob->set_temp("bobing/g1",0);
            ob->set_temp("bobing/g2",0);
            ob->set_temp("bobing/g3",0);
            ob->set_temp("bobing/g4",0);
            ob->set_temp("bobing/g5",0);
            ob->set_temp("bobing/g6",0);
            ob->set_temp("bobing/maxscore",0);
            ob->set_temp("bobing/maxaward",0);
        }
        else
            tell_object(ob,HIY"这一桌满了，你去别处看看吧。\n"NOR);
    }
    return 1;
}

int valid_leave(object me, string dir)
{
    if (query_member(me))
        return notify_fail(HIB"你要先离开搏饼桌才能离开这里。\n"NOR);
    return 1;
}

int delete_member(object ob)
{
    int i;
    if (!arrayp(member))
        return 0;
    for (i=0;i<sizeof(member);i++)
    {
        if (member[i]==ob)
        {
            member-=({ob});
            Max1+=ob->query_temp("bobing/g1");
            Max2+=ob->query_temp("bobing/g2");
            Max3+=ob->query_temp("bobing/g3");
            Max4+=ob->query_temp("bobing/g4");
            Max5+=ob->query_temp("bobing/g5");
            Max6+=ob->query_temp("bobing/g6");
            ob->delete_temp("bobing");
            break;
        }
    }
}

int add_member(object ob)
{
    if (!arrayp(member))
    {
        member=({ob});
        leader=ob;
    }
    else
    {
        member+=({ob});
        if (sizeof(member)>=minperson)
        {
            allow_start=1;
            tell_room(environment(leader),"太好了，人凑够了，可以开始玩了。\n");
            tell_room(environment(leader),leader->query("name")+"先掷吧。\n");
        }
    }
    return 1;
}

int query_member(object ob)
{
    int i;
    if (!arrayp(member))
        return 0;
    for (i=0;i<sizeof(member);i++)
    {
        if (member[i]==ob)
        {
            return i+1;
        }
    }
    return 0;
}

void do_yao()
{
    int t1,s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore;
    object ob;
    string result,dest;
    ob=this_player();
    getscore=0;
    dest="";
// 加大对堂概率
    t1=random(50)+1;
    if (t1==25)
    {
        s1=5;
        s2=2;
        s3=6;
        s4=4;
        s5=3;
        s6=1;
    }
    else
    {
        s1=random(5)+1;
        s2=random(5)+1;
        s3=random(5)+1;
        s4=random(5)+1;
        s5=random(5)+1;
        s6=random(5)+1;
    }
//按点数统计
    c1=countit(s1,s2,s3,s4,s5,s6,1);//一的个数
    c2=countit(s1,s2,s3,s4,s5,s6,2);//二的个数
    c3=countit(s1,s2,s3,s4,s5,s6,3);//三的个数
    c4=countit(s1,s2,s3,s4,s5,s6,4);//四的个数
    c5=countit(s1,s2,s3,s4,s5,s6,5);//五的个数
    c6=countit(s1,s2,s3,s4,s5,s6,6);//六的个数

    if (c1==6||c2==6||c3==6||c4==6||c5==6||c6==6)
    {
        getaward=6;
        if (c1==6)
        {
            dest="六  黑(一)";
            getscore=1201;
        }
        else if (c2==6)
        {
            dest="六  黑(二)";
            getscore=1202;
        }
        else if (c3==6)
        {
            dest="六  黑(三)";
            getscore=1203;
        }
        else if (c5==6)
        {
            dest="六  黑(五)";
            getscore=1204;
        }
        else if (c6==6)
        {
            dest="六  黑(六)";
            getscore=1205;
        }
        else if (c4==6)
        {
            dest="六  红(通吃)";
            getscore=1207;
        }
    }
    else if (c4==5)
    {
        getaward=6;
        if (c1==1)
        {
            dest="五红带一";
            getscore=1102;
        }
        else if (c2==1)
        {
            dest="五红带二";
            getscore=1103;
        }
        else if (c3==1)
        {
            dest="五红带三";
            getscore=1104;
        }
        else if (c5==1)
        {
            dest="五红带五";
            getscore=1105;
        }
        else if (c6==1)
        {
            dest="五红带六";
            getscore=1106;
        }
    }
    else if (c6==5)
    {
        getaward=6;
        if (c1==1)
        {
            dest="五主(六)带一";
            getscore=1046;
        }
        else if (c2==1)
        {
            dest="五主(六)带二";
            getscore=1056;
        }
        else if (c3==1)
        {
            dest="五主(六)带三";
            getscore=1066;
        }
        else if (c4==1)
        {
            dest="五主(六)带四";
            getscore=1076;
        }
        else if (c5==1)
        {
            dest="五主(六)带五";
            getscore=1086;
        }
    }
    else if (c5==5)
    {
        getaward=6;
        if(c1==1)
        {
            dest="五主(五)带一";
            getscore=1045;
        }
        else if(c2==1)
        {
            dest="五主(五)带二";
            getscore=1055;
        }
        else if(c3==1)
        {
            dest="五主(五)带三";
            getscore=1065;
        }
        else if(c4==1)
        {
            dest="五主(五)带四";
            getscore=1075;
        }
        else if(c6==1)
        {
            dest="五主(五)带六";
            getscore=1096;
        }
    }
    else if(c3==5)
    {
        getaward=6;
        if(c1==1)
        {
            dest="五主(三)带一";
            getscore=1043;
        }
        else if(c2==1)
        {
            dest="五主(三)带二";
            getscore=1053;
        }
        else if(c4==1)
        {
            dest="五主(三)带四";
            getscore=1073;
        }
        else if(c5==1)
        {
            dest="五主(三 )带五";
            getscore=1083;
        }
        else if(c6==1)
        {
            dest="五主(三)带六";
            getscore=1093;
        }
    }
    else if(c2==5)
    {
        getaward=6;
        if(c1==1)
        {
            dest="五主(二)带一";
            getscore=1042;
        }
        else if(c3==1)
        {
            dest="五主(二)带三";
            getscore=1062;
        }
        else if(c4==1)
        {
            dest="五主(二)带四";
            getscore=1072;
        }
        else if(c5==1)
        {
            dest="五主(二)带五";
            getscore=1082;
        }
        else if(c6==1)
        {
            dest="五主(二)带六";
            getscore=1092;
        }
    }
    else if(c1==5)
    {
        getaward=6;
        if(c2==1)
        {
            dest="五主(一)带二";
            getscore=1051;
        }
        else if(c3==1)
        {
            dest="五主(一)带三";
            getscore=1061;
        }
        else if(c4==1)
        {
            dest="五主(一)带四";
            getscore=1071;
        }
        else if(c5==1)
        {
            dest="五主(一)带五";
            getscore=1081;
        }
        else if(c6==1)
        {
            dest="五主(一)带六";
            getscore=1091;
        }
    }
    else if (c4==4)
    {
        getaward=6;
        if((s1+s2+s3+s4+s5+s6-16)==2)
        {
            dest="状元插金花";
            getscore=1206;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==12)
        {
            dest="状元带十二";
            getscore=512;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==11)
        {
            dest="状元带十一";
            getscore=511;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==10)
        {
            dest="状元带十";
            getscore=510;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==9)
        {
            dest="状元带九";
            getscore=509;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==8)
        {
            dest="状元带八";
            getscore=508;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==7)
        {
            dest="状元带七";
            getscore=507;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==6)
        {
            dest="状元带六";
            getscore=506;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==5)
        {
            dest="状元带五";
            getscore=505;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==4)
        {
            dest="状元带四";
            getscore=504;
        }
        else if((s1+s2+s3+s4+s5+s6-16)==3)
        {
            dest="状元带三";
            getscore=503;
        }
    }
    else if (c1==4||c2==4||c3==4||c5==4||c6==4)
    {
        getaward=3;
        if (c4==2)
        {
            getscore=302;
            dest="四进带二举";
        }
        else if(c4==1)
        {
            getscore=301;
            dest="四进带一秀";
        }
        else if(c4==0)
        {
            getscore=300;
            dest="四进";
        }
    }
    else if(c4==3)
    {
        getaward=4;
        getscore=400;
        dest="三红";
    }
    else if(c4==2)
    {
        getaward=2;
        getscore=200;
        dest="二举";
    }
    else if (c4==1)
    {
        if (c1==1&&c2==1&&c3==1&&c5==1&&c6==1)
        {
            getaward=5;
            getscore=500;
            dest="对堂";
        }
        else
        {
            getaward=1;
            getscore=100;
            dest="一秀";
        }
    }
    else
    {
        getaward=0;
        getscore=0;
        dest="………哇塞！居然什么都不是哦！？真同情你，呵呵呵呵。";
    }
    result= " -------  -------  -------  -------  -------  -------\n"+
            "|       ||       ||       ||       ||       ||       |\n"+
            "|   "+checkcolor(s1)+"%d"+NOR+
            "   ||   "+checkcolor(s2)+"%d"+NOR+
            "   ||   "+checkcolor(s3)+"%d"+NOR+
            "   ||   "+checkcolor(s4)+"%d"+NOR+
            "   ||   "+checkcolor(s5)+"%d"+NOR+
            "   ||   "+checkcolor(s6)+"%d"+NOR+
            "   |\n"+
            "|       ||       ||       ||       ||       ||       |\n"+
            " -------  -------  -------  -------  -------  -------\n";
    result=sprintf(result,s1,s2,s3,s4,s5,s6);
    result=result+"\n居然是个"+dest+"加油啊。\n";
    message_vision(HIC"$N抓起六个骰子放在手心里拼命摇，然后团起手来向手\n"+
                   "中吹了口气，口中还神神叨叨地念念有词：天灵灵，地灵灵……来来来，开了……\n"NOR+result,ob);
    getit(ob,getaward,getscore,dest);
}

string checkcolor(int i)
{
    if (i==1||i==4)
        return RED;
    else
        return GRN;
}

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
{
    int i;
    i=0;
    if (s1==sd)
        i++;
    if (s2==sd)
        i++;
    if (s3==sd)
        i++;
    if (s4==sd)
        i++;
    if (s5==sd)
        i++;
    if (s6==sd)
        i++;
    return i;
}

string getit(object ob,int getaward,int getscore,string dest)
{
    object* play;
    if (getaward>(ob->query_temp("bobing/maxaward")))
    {
        ob->set_temp("bobing/maxaward",getaward );
        ob->set_temp("bobing/dest",dest);
    }
    if (getscore>(ob->query_temp("bobing/maxscore")))
        ob->set_temp("bobing/maxscore",getscore);
    if (getaward==1)
    {
        if (Max1<=0 )
        {
            qianbing(ob,getaward);
        }
        else
        {
            ob->set_temp("bobing/g1",ob->query_temp("bobing/g1")+1);
            Max1=(Max1==0)?0:Max1-1;
            if (Realmode)
                message_vision(HIY"$N搏到一秀一个，奖一秀饼一块！\n"NOR,ob);
            else
                message_vision(CYN"$N搏到一秀一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
        }
    }
    if (getaward==2)
    {
        if (Max2<=0 )
        {
            qianbing(ob,getaward);
        }
        else
        {
            ob->set_temp("bobing/g2",ob->query_temp("bobing/g2")+1);
            Max2=(Max2==0)?0:Max2-1;
            if (Realmode)
                message_vision(HIY"$N搏到二举一个，奖二举饼一块！\n"NOR,ob);
            else
                message_vision(CYN"$N搏到二举一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
        }
    }
    if (getaward==3)
    {
        if (Max3<=0 )
        {
            qianbing(ob,getaward);
        }
        else
        {
            ob->set_temp("bobing/g3",ob->query_temp("bobing/g3")+1);
            Max3=(Max3==0)?0:Max3-1;
            if (Realmode)
                message_vision(HIY"$N搏到四进一个，奖四进饼一块！\n"NOR,ob);
            else
                message_vision(CYN"$N搏到四进一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
        }
    }
    if (getaward==4)
    {
        if (Max4<=0 )
        {
            qianbing(ob,getaward);
        }
        else
        {
            ob->set_temp("bobing/g4",ob->query_temp("bobing/g4")+1);
            Max4=(Max4==0)?0:Max4-1;
            if (Realmode)
                message_vision(HIY"$N搏到三红一个，奖三红饼一块！\n"NOR,ob);
            else
                message_vision(CYN"$N搏到三红一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
        }
    }
    if (getaward==5)
    {
        if (Max5<=0 )
        {
            qianbing(ob,getaward);
        }
        else
        {
            ob->set_temp("bobing/g5",ob->query_temp("bobing/g5")+1);
            Max5=(Max5==0)?0:Max5-1;
            if (Realmode)
                message_vision(HIY"$N搏到对堂一个，奖对堂饼一块！\n"NOR,ob);
            else
                message_vision(CYN"$N搏到对堂一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
        }
    }
    if (getaward==6)
    {
        if(Realmode)
            Max6=(Max6==0)?0:Max6-1;
        else
            message_vision(CYN"$N搏到状元一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
    }
    if(getaward>=6)
    {
        if(!objectp(winner))
        {
            winner=ob;
            ob->set_temp("bobing/g6",1);
            play=users();
            message("vision",
                    HIY"\n\n[搏饼最新消息]\n=================================="+
                    "============\n恭喜！恭喜！"+ob->query("name")+
                    "搏到了"+dest+"！成为"+roomname+"的状元！！！\n"NOR,play);
        }
        else
        {
            if (ob!=winner&&getscore>winner->query_temp("bobing/maxscore"))
            {
                winner->set_temp("bobing/g6",0);
                winner=ob;
                winner->set_temp("bobing/g6",1);
                play=users();
                message("vision",
                        HIY"\n\n[搏饼最新消息]\n=================================="+
                        "============\n恭喜！恭喜！"+ob->query("name")+
                        "搏到了"+dest+"！成为"+roomname+"的新状元！！！\n"NOR,play);
            }
            else
                message_vision(CYN"$N搏到状元一个，真是可惜你的状元没有奖品……\n"NOR,ob);
        }
    }
}

int qianbing(object ob,int getaward)
{
    int i;
    int flag;
    for (i=0;i<sizeof(member);i++)
    {
        if (member[i]->query("name")==ob->query("name"))
        {
            flag=i;
            for (i=flag-1;i!=flag;i--)
            {
                if (i<0)
                    i=sizeof(member)-1;
                switch (getaward)
                {
                    case 1:
                        if (member[i]->query_temp("bobing/g1"))
                        {
                            member[i]->add_temp("bobing/g1",-1);
                            ob->add_temp("bobing/g1",1);
                            message_vision(HIY"$N搏到一秀一个，抢了$n一秀饼一块！\n"NOR,ob,member[i]);
                            return 1;
                        }
                        break;
                    case 2:
                        if (member[i]->query_temp("bobing/g2")>0)
                        {
                            member[i]->add_temp("bobing/g2",-1);
                            ob->add_temp("bobing/g2",1);
                            message_vision(HIY"$N搏到二举一个，抢了$n二举饼一块！\n"NOR,ob,member[i]);
                            return 1;
                        }
                        break;
                    case 3:
                        if (member[i]->query_temp("bobing/g3"))
                        {
                            member[i]->add_temp("bobing/g3",-1);
                            ob->add_temp("bobing/g3",1);
                            message_vision(HIY"$N搏到四进一个，抢了$n四进饼一块！\n"NOR,ob,member[i]);
                            return 1;
                        }
                        break;
                    case 4:
                        if (member[i]->query_temp("bobing/g4"))
                        {
                            member[i]->add_temp("bobing/g4",-1);
                            ob->add_temp("bobing/g4",1);
                            message_vision(HIY"$N搏到三红一个，抢了$n三红饼一块！\n"NOR,ob,member[i]);
                            return 1;
                        }
                        break;
                    case 5:
                        if (member[i]->query_temp("bobing/g5"))
                        {
                            member[i]->add_temp("bobing/g5",-1);
                            ob->add_temp("bobing/g5",1);
                            message_vision(HIY"$N搏到对堂一个，抢了$n对堂饼一块！\n"NOR,ob,member[i]);
                            return 1;
                        }
                        break;
                    default:
                        message_vision(HIY"$N搏到一块没有用的饼！\n"NOR,ob);
                        break;
                }
            }
            message_vision(HIY"$N抢不到一块有用的饼！\n"NOR,ob);
            return 0;
        }
    }
    message_vision(HIY"$N居然找不到自己座位！\n"NOR,ob);
    return 0;
}
