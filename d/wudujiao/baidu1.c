// by mayue


inherit ROOM;

void create()
{
	set("short", "�ٶ�����");
	set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ������
�������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ�������м�
���嶾�̵����������ġ� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
		"south" : __DIR__"baidu2",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wdsl4",
	]));
        set("objects", ([
                 __DIR__"npc/jiaotu": 4,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="south")
      {
  if ((string)me->query("family/family_name")!="�嶾��"
        & objectp(present("jiao tu", environment(me))))
          return notify_fail("�嶾��ͽ��Ȼ��ס�㣬�����ȵ�����λ" +
           RANK_D->query_respect(me) + "��ͷ���Ե����ʲô��\n");
      }
  return ::valid_leave(me, dir);
}

