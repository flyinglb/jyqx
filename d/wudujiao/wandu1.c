// by mayue

inherit ROOM;

void create()
{
	set("short", "�򶾿���");
	set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ������
�������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ����һ����
�����ڵĿ����ϸ������ڶ��ߴ�� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
		"south" : __DIR__"wandu2",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wdsl3",
	]));
        set("objects", ([
                  __DIR__"npc/hehongyao": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="south")
      {
     if( !present("tie shao", me)
        & objectp(present("he hongyao", environment(me))))
          return notify_fail("�κ�ҩ����һ�Σ���Ȼ��ס�㣬����˵������λ" +
           RANK_D->query_respect(me) + "û�н���׼�����ý��뱾��ʥ�ء�\n");
      }
  return ::valid_leave(me, dir);
}
