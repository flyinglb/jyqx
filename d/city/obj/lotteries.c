// by wind
//������������ʹ��, �Ͻ��⴫, Υ�߱ؾ�.

#include <ansi.h>
inherit ITEM;
int do_check(string arg);
int do_tear(string arg);
void create()
{       
string file;

file=read_file("log/totalmoney",1);

        set_name(HIM "�й�������Ʊ" NOR, ({"lotteries", "caipiao"}));
        set("unit", "��");   
        set("value",1000);
        set("no_get",1);
        set("no_drop",1);
        set("long", "����һ���й�������Ʊ����ֻ��������һ�ž޶�֧Ʊ��(��check lotteries No.\n");
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

if (!arg||strsrch(arg, "lotteries")<0)  return notify_fail("��Ҫ˺ʲô��\n");

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
        if(sscanf(lot_list[i], "%s(%s) buy ��%d�ڲ�Ʊ %s at %*s", name,id,turn,number) == 5 )
          {
          if(id==me->query("id")&&number==ob->query("number"))
           {
           lot_list[i]="����(wind) buy ��1�ڲ�Ʊ aaaaaaa at (Thu Jun 17 12:00:00 1999)";
	   write_file("/log/LOTTERY","����(wind) buy ��1�ڲ�Ʊ aaaaaaa at (Thu Jun 17 12:00:00 1999)\n",1);
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
        if(sscanf(lot_list[i], "%s(%s) buy ��%d�ڲ�Ʊ %s at %*s", name,id,turn,number) == 5 )
          {
          if(id==me->query("id")&&number==ob->query("number"))
          {
          lot_list[i]="����(wind) buy ��1�ڲ�Ʊ aaaaaaa at (Thu Jun 17 12:00:00 1999)";
          write_file("/log/LOTTERYOLD","����(wind) buy ��1�ڲ�Ʊ aaaaaaa at (Thu Jun 17 12:00:00 1999)\n",1);
          for(i=1;i<sizeof(lot_list);i++) log_file("LOTTERYOLD",lot_list[i]+"\n");
          break;
          }
        }
	}
        this_player()->add("lotteriesold",-1);
        }
	message_vision("$N�����ܻ�, һ�Ѱ����еĲ�Ʊ˺�÷���.\n", this_player());
        destruct(ob);
	return 1;
 }
else  return notify_fail("������û������������\n");
}

int do_check(string arg)
{
object ob,me;
string l_turn,l_master,l_time,l_number, line;
if (!arg)  return notify_fail("��Ҫ��ʲô��\n");
me=this_player();
if( (ob = present(arg, me)) || (ob = present(arg, environment(me)))) 
{
        l_turn   = ob->query("turn");
        l_time   = ob->query("time");
        l_master = ob->query("master");
        l_number = ob->query("number");
        line = sprintf("�й�������Ʊ(��%d��)��\t\tԭʼ�����ˣ�%s\n����ʱ�䣺 %s\n�½����룺 %s\n",
                       l_turn, l_master,l_time,l_number);
        write(line);
        return 1;
}
else  return notify_fail("������û������������\n");
}

