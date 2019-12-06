// kufang.c
// written by tree

inherit ROOM;

void create()
{
	set("short", "�ⷿ");
	set("long", @LONG
����һ�䲻�ܴ���߷��������������������л���һ�����ӣ��������Ÿ���ͷ��
�ڲ�ͣ������һ��ľͷ�����ﻹ������ţ���Щ���ӣ���ô����С������ϲ����Щ
ľͷ���?�����������һЩ�Ѿ����õ���ߡ������ڿ�������Ҫľ��(yaodao)��
����Ҫľ��(yaojian)��
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaoyuan",
        ]));
	set("no_clean_up", 0);
        set("count_dao",6);
        set("count_jian",6);
	setup();
}
void init()
{
        add_action("do_yaodao","yaodao");
        add_action("do_yaojian","yaojian");
}

int do_yaodao(string arg)
{
       object me;
	object mudao;
       me=this_player();
//       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
       if (query ("count_dao")>0)
       {
       message_vision("����û�п�����������������һ��ľ����$N\n",me);
	mudao=new(__DIR__"obj_mudao");
	mudao->move(me);
	add("count_dao",-1);
        }
	else
	message_vision("ľ���Ѿ�û�ˡ�\n",me);
       return 1; 
}
int do_yaojian(string arg)
{
       object me;
	object mujian;
       me=this_player();
//       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
       if (query ("count_jian")>0)
       {
       message_vision("����û�п�����������������һ��ľ����$N\n",me);
	mujian=new(__DIR__"obj_mujian");
	mujian->move(me);
	add("count_jian",-1);
        }
	else
	message_vision("ľ���Ѿ�û�ˡ�\n",me);
       return 1; 
}
