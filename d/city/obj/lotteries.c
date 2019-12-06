// by wind
//本程序纯属个人使用, 严禁外传, 违者必究.

#include <ansi.h>
inherit ITEM;
int do_check(string arg);
int do_tear(string arg);
void create()
{       
string file;

file=read_file("log/totalmoney",1);

        set_name(HIM "中国体育彩票" NOR, ({"lotteries", "caipiao"}));
        set("unit", "张");   
        set("value",1000);
        set("no_get",1);
        set("no_drop",1);
        set("long", "这是一张中国体育彩票，你只觉得它象一张巨额支票。(可check lotteries No.\n");
        setup();

}

void init()
{
       add_action("do_tear", "tear");
       add_action("do_check","check");
}

int do_tear(string arg)
{
	object ob,me;
        string file,file1,file2,name,id,number;
	string* lot_list;
	int turn,i;

if (!arg||strsrch(arg, "lotteries")<0)  return notify_fail("你要撕什么？\n");

me=this_player();
if( (ob = present(arg, me))) 
 {       
        file=read_file("/log/turnrec");
	sscanf(file,"%d",turn);
        if(ob->query("turn")==turn)
        {
	file1=read_file("/log/LOTTERY");
	if(!file1) return 1;
	lot_list=explode(file1,"\n");
        for(i=0;i<sizeof(lot_list);i++) {
        if(sscanf(lot_list[i], "%s(%s) buy 第%d期彩票 %s at %*s", name,id,turn,number) == 5 )
          {
          if(id==me->query("id")&&number==ob->query("number"))
           {
           lot_list[i]="风云(wind) buy 第1期彩票 aaaaaaa at (Thu Jun 17 12:00:00 1999)";
	   write_file("/log/LOTTERY","风云(wind) buy 第1期彩票 aaaaaaa at (Thu Jun 17 12:00:00 1999)\n",1);
           for(i=1;i<sizeof(lot_list);i++) log_file("LOTTERY",lot_list[i]+"\n");
           break;
           }
	}
	}
        this_player()->add("lotteries",-1);
        }

        if(ob->query("turn")==(turn-1))
        {
	file2=read_file("/log/LOTTERYOLD");
	if(!file2) return 1;
	lot_list=explode(file2,"\n");
        for(i=0;i<sizeof(lot_list);i++) {
        if(sscanf(lot_list[i], "%s(%s) buy 第%d期彩票 %s at %*s", name,id,turn,number) == 5 )
          {
          if(id==me->query("id")&&number==ob->query("number"))
          {
          lot_list[i]="风云(wind) buy 第1期彩票 aaaaaaa at (Thu Jun 17 12:00:00 1999)";
          write_file("/log/LOTTERYOLD","风云(wind) buy 第1期彩票 aaaaaaa at (Thu Jun 17 12:00:00 1999)\n",1);
          for(i=1;i<sizeof(lot_list);i++) log_file("LOTTERYOLD",lot_list[i]+"\n");
          break;
          }
        }
	}
        this_player()->add("lotteriesold",-1);
        }
	message_vision("$N气急败坏, 一把把手中的彩票撕得粉碎.\n", this_player());
        destruct(ob);
	return 1;
 }
else  return notify_fail("你身上没有这样东西。\n");
}

int do_check(string arg)
{
object ob,me;
string l_turn,l_master,l_time,l_number, line;
if (!arg)  return notify_fail("你要查什么？\n");
me=this_player();
if( (ob = present(arg, me)) || (ob = present(arg, environment(me)))) 
{
        l_turn   = ob->query("turn");
        l_time   = ob->query("time");
        l_master = ob->query("master");
        l_number = ob->query("number");
        line = sprintf("中国体育彩票(第%d期)：\t\t原始购买人：%s\n购买时间： %s\n猜奖号码： %s\n",
                       l_turn, l_master,l_time,l_number);
        write(line);
        return 1;
}
else  return notify_fail("你身上没有这样东西。\n");
}

