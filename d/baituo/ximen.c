// ximen.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
       "���Ǹ�ɽׯ�����š������ε����ŷ������£����Ϲ���\n"
   "һ������(pai)�����������Ӳݴ�����\n"
      );
  set("exits",([
      "west" : __DIR__"cao1",
      "east" : __DIR__"changlang",
     ]));
  set("item_desc",([
  "pai" : "���������ж��߳�û�����С�\n" ,
  ]));
  set("objects",([
    __DIR__"npc/menwei" : 1,
    ]));
//  set("no_clean_up", 0);
  set("outdoors", "baituo");
  setup();
}

int valid_leave(object me, string dir)
{
       if (  (dir == "east")
	   && ((int)me->query("shen")>300)
	   && objectp(present("men wei", environment(me))) )
	 return notify_fail
		("��������һ�����㲻�ܽ�ȥ��\n");
	if (  (dir == "west")
	   && ((int)me->query("combat_exp") < 300)
	   && objectp(present("men wei", environment(me))) )
	 return notify_fail
		("��������һ������ľ���̫�ͣ��ᱻ����ҧ���ģ����ǲ�Ҫ�Ҵ��ĺá�\n");
	return ::valid_leave(me, dir);
}






